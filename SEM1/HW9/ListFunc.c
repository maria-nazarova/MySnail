#include "List.c"

int main(){
	enum {CREATE, ADD_B, ADD_E, ADD_K, DELETE, PRINT_LIST, PRINT_Node, CLEAR, CREATECYCLE, FINDCYCLE, EXIT};
	int a = 0, n = 0;
	size_t k = 0;
	_Bool isList = 0, cont = 1;
	struct List* myList = NULL;
	
	printf("Operations:\n");
	printf("0 - Create list\n");
	printf("1 <n> - Add a node with value n in the beginning\n");
	printf("2 <n> - Add a node with value n in the end\n");
	printf("3 <n> <k> - Add a node with value n after the k-th node\n");
	printf("4 <k> - Delete k-th node\n");
	printf("5 - Print the whole list\n");
	printf("6 <k> - Print k-th node\n");
	printf("7 - Clear list\n");
	printf("8 <k> - Create a cycle staring at k'th node\n");
	printf("9 - Find a cycle in the list\n");
	printf("10 - Exit\n");
	printf("Enter number of operation\n");
	scanf("%d", &a);
	
	while(cont) {
		switch (a) {
			case CREATE:
				if (isList) {
					printf("You already have a list\n");
				} else {
					myList = createList();
					if (myList){
						isList++;
					} else {
						printf("Failed to create list\n");
					}
				}
				break;
				
			case ADD_B: 
				scanf("%d", &n);
				if (isList) {
					insertB(myList, createNode(n));
				} else {
					printf("You do not have a list yet\n");
				}
				break;
				
			case ADD_E:
				scanf("%d", &n);
				if (isList) {
					insertM(myList, myList -> tail, createNode(n));
				} else {
					printf("You do not have a list yet\n");
				}
				break;
				
			case ADD_K:
				scanf("%d %d", &n, &k);
				if (isList) {
					insertM(myList, getN(myList, k), createNode(n));
				} else {
					printf("You do not have a list yet\n");
				}
				break;
				
			case DELETE:
				scanf("%d", &k);
				if (isList) {
					deleteNode(myList, getN(myList, k));
				} else {
					printf("You do not have a list yet\n");
				}
				break;
				
				case PRINT_LIST:
				if (isList) {
					printList(myList);
				} else {
					printf("You do not have a list yet\n");
				}
				break;
				
			case PRINT_Node:
				if (isList) {
					printNode(myList, k);
				} else {
					printf("You do not have a list yet\n");
				}
				break;
				
			case CLEAR:
				if (isList) {
					freeList(myList);
					isList = 0;
				} else {
					printf("You do not have a list yet\n");
				}
				break;
				
			case CREATECYCLE:
				if (isList) {
					scanf("%d", &k);
					createCycle(myList, getN(myList, k));
				} else {
					printf("You do not have a list yet\n");
				}
				break;
			
			case FINDCYCLE:
			if (isList) {
					if (findCycle(myList)) {
						printf("There is a cycle in the list\n");
					} else {
						printf("There are no cycles in the list\n");
					}
				} else {
					printf("You do not have a list yet\n");
				}
				break;
			
			case EXIT:
				cont = 0;
				break;
				
			default:
				printf("Wrong input\n");
				break;
		}
		if (!cont) {
			break;
		}
		scanf("%d", &a);
	}
}



	