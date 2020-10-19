package Math;

import javafx.geometry.Point2D;


public class Folium extends Curve {
    private int a = 20;
    public Folium(double step, double height, double width) {
        double w = width / 2, h = height / 2, x = 0, y = 0;
        double p = 10e-3 / step, newStep = 10e-3 / step, b = a * step;

        while (p < 100 * step) {
            if (!mas.isEmpty() && dist(mas.get(mas.size() - 1), new Point2D(x + w, h - y)) > 10e-3 / step) {
                newStep *= (1 - 10e-3 / step);
            } else {
                newStep *= (1 + 10e-3 / step);
            }
            x = fx(p, b);
            y = fy(p, b);
            if (Math.abs(x) < w && Math.abs(y) < h) {
                mas.add(new Point2D(w + x, h - y));
            } else {
                newStep = 10e-3;
            }
            p += newStep;
        }
        p = -1 - 10e-6 / step;
        newStep = 10e-6 / step;
        while(p > -100 * step) {
            if (!mas.isEmpty() && dist(mas.get(mas.size() - 1), new Point2D(x + w, h - y)) > 10e-6 / step) {
                newStep *= (1 - 10e-5 / step);
            } else {
                newStep *= (1 + 10e-5 / step);
            }
            x = fx(p, b);
            y = fy(p, b);
            if (Math.abs(x) < w && Math.abs(y) < h) {
                mas.add(new Point2D(w + x, h - y));
            } else {
                newStep = 10e-5;
            }
            p -= newStep;
        }

        p = -1 + 10e-6 / step;
        newStep = 10e-6 / step;
        while(p < 0) {
            if (!mas.isEmpty() && dist(mas.get(mas.size() - 1), new Point2D(x + w, h - y)) > 10e-6 / step) {
                newStep *= (1 - 10e-5 / step);
            } else {
                newStep *= (1 + 10e-5 / step);
            }
            x = fx(p, b);
            y = fy(p, b);
            if (Math.abs(x) < w && Math.abs(y) < h) {
                mas.add(new Point2D(w + x, h - y));
            } else {
                newStep = 10e-5;
            }
            p += newStep;
        }
    }
    private double fx (double p, double a){
        return 3 * a * p / (1 + p * p * p);
    }
    private double fy (double p, double a){
        return 3 * a * p * p / (1 + p * p * p);
    }
}