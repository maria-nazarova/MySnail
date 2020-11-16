package app;

import javafx.scene.control.Button;
import javafx.scene.paint.Color;
import javafx.scene.text.Font;

import java.awt.*;

public class MyButton extends Button {

    public void ready(){
        this.setText("!");
        this.setDisable(false);
    }

    public void pushAI(boolean AI){
        prepareDraw("darkred");
        if (AI){
            this.setText("x");
        } else {
            this.setText("o");
        }
        this.setDisable(true);
    }

    public void prepareDraw(String color){
        this.setFont(new Font(40));
        this.setStyle("-fx-text-fill: " + color);
    }
}
