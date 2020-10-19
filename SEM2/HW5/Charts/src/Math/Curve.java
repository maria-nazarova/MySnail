package Math;

import javafx.geometry.Point2D;

import java.util.ArrayList;

public class Curve {
    public ArrayList<Point2D> mas = new ArrayList<Point2D>();
    public static double dist(Point2D p1, Point2D p2) {
        return Math.sqrt((p1.getX() - p2.getX())*(p1.getX() - p2.getX())
                + (p1.getY() - p2.getY())*(p1.getY() - p2.getY()));
    }
}
