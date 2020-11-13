package app;

import java.util.Random;

public class GameState {
    private boolean AIFirst;
    private static int[] buttons = new int[9];
    private int turnNumber;
    private static int lastTurn = -1;

    public static boolean isFree(int i) {
        return (buttons[i] == 0);
    }
    public static int getButton(int i){return buttons[i];}
    public GameState(){
        Random random = new Random();
        AIFirst = random.nextInt() % 2 == 1;
        for (int i = 0; i < 9; ++i) {
            buttons[i] = 0;
        }
        turnNumber = 0;
    }

    public boolean isAIFirst() {
        return AIFirst;
    }

    public int getTurn(){
        return turnNumber;
    }

    public void makeTurn(int i, boolean isAI){
        turnNumber++;
        buttons[i] = isAI ? 1 : -1;
        lastTurn = i;
    }

    public static int getLastTurn(){
        return lastTurn;
    }

    public int isGameFinished() {
        for (int i = 0; i < 3; ++i) {
            if (buttons[i] == 1 && buttons[3 + i] == 1 && buttons[6 + i] == 1){
                return 1;
            }
            if (buttons[i] == -1 && buttons[3 + i] == -1 && buttons[6 + i] == -1){
                return -1;
            }
            if (buttons[i * 3] == 1 && buttons[1 + i * 3] == 1 && buttons[2 + i * 3] == 1){
                return 1;
            }
            if (buttons[i * 3] == -1 && buttons[1 + i * 3] == -1 && buttons[2 + i * 3] == -1){
                return -1;
            }

        }
        if (buttons[0] == 1 && buttons[4] == 1 && buttons[8] == 1){
            return 1;
        }
        if (buttons[0] == -1 && buttons[4] == -1 && buttons[8] == -1){
            return -1;
        }
        if (buttons[2] == 1 && buttons[4] == 1 && buttons[6] == 1){
            return 1;
        }
        if (buttons[2] == -1 && buttons[4] == -1 && buttons[6] == -1){
            return -1;
        }
        for (int i = 0; i < 9; ++i) {
            if (buttons[i] == 0) return 0;
        }
        return 5;
    }
}
