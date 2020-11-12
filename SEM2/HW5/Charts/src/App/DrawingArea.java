package App;

import javafx.geometry.Point2D;
import javafx.scene.canvas.Canvas;
import javafx.scene.canvas.GraphicsContext;
import javafx.scene.paint.Color;
import Math.*;

public class DrawingArea extends Canvas {

    public static final int WIDTH = 600;
    public static final int HEIGHT = 500;
    private double coordStep = 2d;

    public DrawingArea() {
        setWidth(WIDTH);
        setHeight(HEIGHT);
    }

    public void prepare(){
        GraphicsContext g = getGraphicsContext2D();
        g.clearRect(0, 0 , getWidth(), getHeight());
        g.setStroke(Color.BLACK);
        g.setLineWidth(1);
        g.strokeLine(0, getHeight() / 2, getWidth(), getHeight() / 2);
        g.strokeLine(getWidth() / 2, 0, getWidth() / 2, getHeight());
        g.setStroke(Color.DARKRED);
        g.setFill(Color.DARKRED);
        g.setLineWidth(1);
    }

    public void setCoordStep(double mult){
        coordStep *= mult;
    }

    public <T extends Curve> void drawChart(Class <T> clas){
        prepare();
        GraphicsContext g = getGraphicsContext2D();
        Curve curve;
        switch(clas.getTypeName()) {
            case "Math.Ellipse":
                curve = new Ellipse(coordStep, getHeight(), getWidth());
                break;
            case "Math.Folium":
                curve = new Folium(coordStep, getHeight(), getWidth());
                break;
            case "Math.Hyperbola":
                curve = new Hyperbola(coordStep, getHeight(), getWidth());
                break;
            default:
                curve = new Curve();
        }

        Point2D p = curve.returnNext(null);
        while (p != null ){
            if(Math.abs(p.getY()) < getHeight() && Math.abs(p.getX()) < getWidth()) {
                g.fillOval(p.getX(), p.getY(), 1, 1);
            }
            p = curve.returnNext(p);
        }
    }

    public double getCoordStep(){ return coordStep; }
}
