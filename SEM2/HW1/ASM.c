#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "HashTable.h"

struct Cmd {
	int32_t opCode;
	int32_t arg;
};

struct State {
	int32_t *stack;
	int32_t *memory;
	size_t IP;
};

struct Program {
	struct Cmd *operations;
	struct HashTable *label2line;
};


const size_t Max_Stack = 2000;
const size_t Max_Memory_Size = (1 << 20);
const size_t Max_Memory = Max_Memory_Size / sizeof(int32_t);
const size_t Max_Operations_Size = 2000 * sizeof(struct Cmd);
const size_t Max_Operations = 2000;
const size_t Max_Command_Length = 20;
enum {RET, ADD, SUB, CMP, LD, ST, LDC, JMP, BR};
const char ops[] = "retaddsubcmpldstldcjmpbr";


_Bool findLabels(struct Program* program, FILE* file) {
	char str[Max_Command_Length];
	size_t strcount = 0;
	_Bool error = 0;
	
	fscanf(file,"%c", str);
	while (!feof(file)) {
		char label[Max_Command_Length];
		int arg;
		while (str[0] == ';' || str[0] == '\n' || str[0] == ' ' || str[0] == '	') {
			switch (str[0]) {
				case ';':
					fgets(str, Max_Command_Length, file);
					fscanf(file, "%c", str);
					break;
				default: 
					fscanf(file,"%c", str);
			}
		}
		
		fscanf(file, "%s", &str[1]);
		if (str[strlen(str) - 1] == ':') {
			str[strlen(str) - 1] = 0;
			setData(program->label2line, str, strcount);
		} else if (strcmp(str, "ret") == 0 || strcmp(str, "add") == 0 || strcmp(str, "sub") == 0 || 
				strcmp(str, "cmp") == 0) {
				strcount++;
			} else if (strcmp(str, "ld") == 0 || strcmp(str, "st") == 0 || strcmp(str, "ldc") == 0){
					strcount++;
					if (fscanf(file, "%d", &arg) == 0) {
						printf("Wrong syntax after %s\n", str);
						error = 1;
					}
				} else if (strcmp(str, "jmp") == 0 || strcmp(str, "br") == 0) {
					strcount++;
					fscanf(file, "%s", label);
				} else {
						printf("Wrong syntax in %s\n", str);
						error = 1;
					}
		fscanf(file, "%c", str);
	}
	return error;
}

void readProgram(struct Program* program, FILE* file, size_t *opscount) {
	char str[Max_Command_Length];
	*opscount = 0;
	int32_t arg;

	char label[Max_Command_Length];
	
	fscanf(file, "%s", str);
	while (!feof(file)) {
		if (strcmp(str, "ret") == 0) {
			program->operations[*opscount].opCode = RET;
		}
		if (strcmp(str, "add") == 0) {
			program->operations[*opscount].opCode = ADD;
		}
		if (strcmp(str, "sub") == 0) {
			program->operations[*opscount].opCode = SUB;
		}
		if (strcmp(str, "cmp") == 0) {
			program->operations[*opscount].opCode = CMP;
		}
		if (strcmp(str, "ld") == 0) {
			program->operations[*opscount].opCode = LD;
			fscanf(file, "%d", &arg);
			program->operations[*opscount].arg = arg;
		}
		if (strcmp(str, "st") == 0) {
			program->operations[*opscount].opCode = ST;
			fscanf(file, "%d", &arg);
			program->operations[*opscount].arg = arg;
		}
		if (strcmp(str, "ldc") == 0) {
			program->operations[*opscount].opCode = LDC;
			fscanf(file, "%d", &arg);
			program->operations[*opscount].arg = arg;
		}
		if (strcmp(str, "jmp") == 0) {
			program->operations[*opscount].opCode = JMP;
			fscanf(file, "%s", label);
			program->operations[*opscount].arg = getData(program->label2line, label);
		}
		if (strcmp(str, "br") == 0) {
			program->operations[*opscount].opCode = BR;
			fscanf(file, "%s", label);
			program->operations[*opscount].arg = getData(program->label2line, label);
		}
		if (strstr(ops, str)) {
			(*opscount)++;
		}
		fscanf(file, "%s", str);
	}
}

void performProgram(struct Program* program, struct State* st, size_t opscount, size_t *stackk){
	size_t performing = 0;
	*stackk = 0;
	_Bool ret = 0;
	while (st->IP < opscount) {
		performing++;
		switch (program->operations[st->IP].opCode) {
			case ADD : 
				if (*stackk < 2){
					printf("Error in operation %d not enough operands in stack\n", st->IP + 1);
				} else {
					(*stackk)--;
					st->stack[*stackk - 1] += st->stack[*stackk];
				}
				(st->IP)++;
				break;
			case SUB :
				if (*stackk < 2){
					printf("Error in operation %d not enough operands in stack\n", st->IP + 1);
				} else {
					(*stackk)--;
					st->stack[*stackk - 1] = st->stack[*stackk] - st->stack[*stackk - 1];
				}
				(st->IP)++;
				break;
			case CMP :
				if (*stackk < 2){
					printf("Error in operation %d not enough operands in stack\n", st->IP + 1);
				} else {
					(*stackk)--;
					if (st->stack[*stackk - 1] < st->stack[*stackk]) {
						st->stack[*stackk - 1] = 1;
					} else if (st->stack[*stackk - 1] > st->stack[*stackk]) {
						st->stack[*stackk - 1] = -1;
					} else {
						st->stack[*stackk - 1] = 0;
					}
				}
				(st->IP)++;
				break;
			case LD :
				st->stack[(*stackk)++] = st->memory[program->operations[st->IP].arg];
				(st->IP)++;
				break;
			case ST :
				st->memory[program->operations[st->IP].arg] = st->stack[--(*stackk)];
				(st->IP)++;
				break;
			case LDC :
				st->stack[(*stackk)++] = program->operations[st->IP].arg;
				(st->IP)++;
				break;
			case JMP :
				st->IP = program->operations[st->IP].arg;
				break;
			case BR :
				if (st->stack[*stackk - 1] != 0) {
					st->IP = program->operations[st->IP].arg;
				} else {
					(st->IP)++;
				}
				break;
			case RET :
				ret = 1;
				break;
		}
		if (ret) {
			break;
		}
		if (performing > Max_Operations) {
			printf("Error infinite cycle\n");
			break;
		}
		
	}
}

size_t hash(char* word) {
	size_t hash = 0;
	while (*word) {
		hash += (unsigned char)(*word);
		hash += (hash << 10);
		hash ^= (hash >> 6);
		word ++;
	}
	hash += (hash << 3);
	hash ^= (hash >> 11);
	hash += (hash << 15);
	return hash % Max_Operations;
}


int main(){
	struct State st;
	st.stack = calloc(Max_Stack, sizeof(int32_t));
	st.memory = malloc(Max_Memory_Size);
	st.IP = 0;
	
	struct Program program;
	program.operations = malloc(Max_Operations_Size);
	program.label2line = createTable(hash, Max_Operations);

	size_t opscount = 0, stackk = 0;
	
	FILE* file = fopen("Input.txt", "r");
	if (!file) {
		printf("Error \n Cannot open input file\n");
		exit(1);
	}
	
	if (findLabels(&program, file)) {
		exit(1);
	}
	
	
	if (fseek(file, 0L, SEEK_SET) != 0) {
		fclose (file);
		file = fopen("Input.txt", "r");
		if (!file) {
			printf("Error \n Cannot open input file\n");
			exit(1);
		}
	}

	readProgram(&program, file, &opscount);
	fclose(file);
	
	
	performProgram(&program, &st, opscount, &stackk);
	
	for (int i = 0; i < stackk; ++i){
		printf("%d\n", st.stack[i]);
	}
return 0;
}