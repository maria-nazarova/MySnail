package Math;

import javafx.geometry.Point2D;


public class Ellipse extends Curve {
    private int a = 25;
    private int b = 15;

    public Ellipse(double step, double height, double width) {
        double w = width / 2, h = height / 2, x = -a * step, newStep = 10e-3 / step;
        while (x <= a * step) {
            double y = Math.sqrt(b * b * step * step - b * b * x * x / (a * a));
            if (!mas.isEmpty() && dist(mas.get(mas.size() - 1), new Point2D(x + w, h - y)) > 10e-1 / step) {
                newStep *= 1 - 1 / step;
            } else {
                newStep *= 1 + 1 / step;
            }
            if (Math.abs(x) < w && Math.abs(y) < h) {
                if (y == 0) {
                    mas.add(new Point2D(w + x, h));
                } else {
                    mas.add(new Point2D(w + x, h + y));
                    mas.add(new Point2D(w + x, h - y));
                }
            } else {
                newStep = 10e-3;
            }
            x += newStep;
        }
    }

}
