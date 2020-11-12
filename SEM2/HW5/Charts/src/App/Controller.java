package App;

import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import Math.*;
import javafx.scene.control.Button;
import javafx.scene.control.ComboBox;

import java.net.URL;
import java.util.ResourceBundle;

public class Controller implements Initializable {
    @FXML
    private ComboBox<String> cmb;

    @FXML
    private Button incB = new Button();
    @FXML
    private Button decB = new Button();

    @FXML
    private DrawingArea drawingArea = new DrawingArea();


    private final String ellipse = "Ellipse: b^2*X^2 + a^2*Y^2 = a^2*b^2";
    private final String folium = "Folium of Decartes: X^3 + Y^3 - 3*a*X*Y = 0";
    private final String hyperbola = "Hyperbola: b^2*X^2 - a^2*Y^2 = 1";

    public void draw() {
        decB.setDisable(false);
        incB.setDisable(false);
        switch (cmb.getSelectionModel().getSelectedItem()) {
            case ellipse:
                drawingArea.drawChart(Ellipse.class);
                break;
            case folium:
                drawingArea.drawChart(Folium.class);
                break;
            case hyperbola:
                drawingArea.drawChart(Hyperbola.class);
                break;
        }
    }

    @Override
    public void initialize(URL url, ResourceBundle resourceBundle) {
        ObservableList<String> items = FXCollections.observableArrayList(
                ellipse, folium, hyperbola
        );
        cmb.setItems(items);
        decB.setOnAction(actionEvent -> further());
        incB.setOnAction(actionEvent -> closer());
        decB.setDisable(true);
        incB.setDisable(true);
    }


    public void closer(){
        drawingArea.setCoordStep(1.2);
        draw();
    }

    public void further(){
        drawingArea.setCoordStep(0.8);
        draw();
    }

}
