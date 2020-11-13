package test;
import app.AI;
import app.HardAI;
import app.RandomAI;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Node;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.ComboBox;
import javafx.scene.control.Label;
import javafx.scene.input.KeyCode;
import javafx.scene.input.MouseButton;
import javafx.stage.Stage;
import org.junit.After;
import org.junit.Assert;
import org.junit.Before;
import org.junit.Test;
import org.testfx.api.FxToolkit;
import org.testfx.framework.junit.ApplicationTest;
import app.GameState;
public class GUITest extends ApplicationTest{
    private Button button0;
    private Button button1;
    private Button button2;
    private Button button3;
    private Button button4;
    private Button button5;
    private Button button6;
    private Button button7;
    private Button button8;
    private Button restartB;
    private ComboBox<String> cmb;
    private Label label;



    @Override
    public void start(Stage primaryStage) throws Exception{
        Parent root = FXMLLoader.load(getClass().getResource("/App/sample.fxml"));
        primaryStage.setTitle("Tic-tac-toes");
        primaryStage.setScene(new Scene(root));
        primaryStage.show();
    }

    public <T extends Node> T find(final String query) {
        return lookup(query).query();
    }

    @Before
    public void setUp() {
        button0 = find("#button0");
        button1 = find("#button1");
        button2 = find("#button2");
        button3 = find("#button3");
        button4 = find("#button4");
        button5 = find("#button5");
        button6 = find("#button6");
        button7 = find("#button7");
        button8 = find("#button8");
        restartB = find("#restartB");
        cmb = find("#cmb");
        label = find("#label");
    }

    @Test
    public void startTest(){
        Assert.assertTrue(button0.isDisable());
        Assert.assertTrue(button1.isDisable());
        Assert.assertTrue(button2.isDisable());
        Assert.assertTrue(button3.isDisable());
        Assert.assertTrue(button4.isDisable());
        Assert.assertTrue(button5.isDisable());
        Assert.assertTrue(button6.isDisable());
        Assert.assertTrue(button7.isDisable());
        Assert.assertTrue(button8.isDisable());
        Assert.assertTrue(restartB.isDisable());
        Assert.assertFalse(label.isVisible());
    }

    @Test
    public void actionsTest(){
        clickOn(cmb);
        clickOn("Random AI");
        clickOn("Hard AI");
        Assert.assertFalse(button0.isDisable());
        Assert.assertFalse(button1.isDisable());
        Assert.assertFalse(button2.isDisable());
        Assert.assertFalse(button3.isDisable());
        Assert.assertFalse(button4.isDisable());
        Assert.assertFalse(button5.isDisable());
        Assert.assertFalse(button6.isDisable());
        Assert.assertFalse(button7.isDisable());
        Assert.assertFalse(button8.isDisable());
        Assert.assertFalse(restartB.isDisable());
        Assert.assertTrue(label.isVisible());
        Assert.assertTrue(label.getText().contentEquals("AL's turn is first") ||
                label.getText().contentEquals("Your turn is first"));
        if (label.getText().contentEquals("AL's turn is first")) {
            clickOn(button6);
            Assert.assertTrue(button4.getText().contentEquals("x"));
            Assert.assertTrue(button6.getText().contentEquals("o"));
            Assert.assertTrue(button4.getStyle().contentEquals("-fx-text-fill: darkred"));
            Assert.assertTrue(button6.getStyle().contentEquals("-fx-text-fill: black"));
        } else {
            clickOn(button6);
            Assert.assertTrue(button4.getText().contentEquals("o"));
            Assert.assertTrue(button6.getText().contentEquals("x"));
            Assert.assertTrue(button4.getStyle().contentEquals("-fx-text-fill: darkred"));
            Assert.assertTrue(button6.getStyle().contentEquals("-fx-text-fill: black"));
        }
    }

}
