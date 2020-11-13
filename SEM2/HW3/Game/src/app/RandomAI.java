package app;

import java.util.Random;

public class RandomAI extends AI {
    private Random random = new Random();
    public int action(boolean isFirst, int turn){
        int x = random.nextInt(9);
        while (!GameState.isFree(x)){
            x = random.nextInt(9);
        }
        return x;
    }
}
