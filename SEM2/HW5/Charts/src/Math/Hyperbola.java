package Math;

import javafx.geometry.Point2D;

public class Hyperbola extends Curve {
    private int a = 15;
    private int b = 35;

    public Hyperbola(double step, double height, double width) {
        double w = width / 2, h = height / 2, y = -h, newStep = 10e-3 / step;

        while (y <= h) {
            double x = Math.sqrt(a * a * step * step + a * a * y * y / (b * b));

            if (!mas.isEmpty() && dist(mas.get(mas.size() - 1), new Point2D( w - x, h + y)) > 10e-3 / step) {
                newStep *= 1 - 10e-3 / step;
            } else {
                newStep *= 1 + 10e-3 / step;
            }
            mas.add(new Point2D(w + x, h + y));
            mas.add(new Point2D(w - x, h + y));

            y += newStep;
        }
    }

}
