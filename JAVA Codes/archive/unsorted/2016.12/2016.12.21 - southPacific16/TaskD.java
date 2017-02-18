package juniorAndrade.main;

import juniorAndrade.lib.geometry.Circle;
import juniorAndrade.lib.geometry.GeometryUtils;
import juniorAndrade.lib.geometry.Line;
import juniorAndrade.lib.geometry.Point;
import juniorAndrade.lib.utils.io.InputReader;
import juniorAndrade.lib.utils.io.OutputWriter;

import java.util.Arrays;
import java.util.Comparator;

public class TaskD {
    Point [] a, b;
    int ca, cb;

    Circle getCircle(Point p1, Point p2, Point p3) {
        double cx, cy;
        cx = (p2.x + p1.x) * 0.5;
        cy = (p2.y + p1.y) * 0.5;
        Line A = p1.line(p2).perpendicular(new Point(cx, cy));
        cx = (p3.x + p2.x) * 0.5;
        cy = (p3.y + p2.y) * 0.5;
        Line B = p2.line(p3).perpendicular(new Point(cx, cy));
        Point g = A.intersect(B);
        if(g == null) return null;
        double r = g.distance(p1);
        return new Circle(g, r);
    }

    boolean isCorrectCircle(Circle c) {
        if(c == null) return false;
        for(int i = 0; i < ca; ++i) { //I
            double d = c.center.distance(a[i]);
            if(Math.abs(d - c.radius) < GeometryUtils.epsilon) continue;
            if(d > c.radius) return false;
        }
        for(int i = 0; i < cb; ++i) { //N
            double d = c.center.distance(b[i]);
            if(Math.abs(d - c.radius) < GeometryUtils.epsilon) continue;
            if(d < c.radius) return false;
        }
        return true;
    }

    boolean ok(Point p1, Point p2, Point p3) {
       Circle c = getCircle(p1, p2, p3);
       return isCorrectCircle(c);
    }

    int []X;
    int []Y;
    char[]or;

    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int n = in.readInt();
        a = new Point[n];
        b = new Point[n];
        X = new int[n];
        Y = new int[n];
        or = new char[n];
        ca = 0;
        cb = 0;
        for(int i = 0; i < n; ++i) {
            int x = in.readInt();
            int y = in.readInt();
            char c = in.readCharacter();
            X[i] = x;
            Y[i] = y;
            or[i] = c;
            if(c == 'I') a[ca++] = new Point(x, y);
            else b[cb++] = new Point(x, y);
        }

        for(int i = 0; i < n; ++i) {
            for(int j = i + 1; j < n; ++j) {
                for(int k = j + 1; k < n; ++k) {
                    if(ok(new Point(X[i], Y[i]), new Point(X[j], Y[j]),  new Point(X[k], Y[k]))) {
                        out.printLine("No");
                        return;
                    }
                }
            }
        }

        
        int[][] newArray = new int[n][];
        for (int i = 0; i < ca; i++) newArray[i] = new int[]{(int) a[i].x, (int) a[i].y, 1};
        for (int i = 0; i < cb; i++) newArray[i + ca] = new int[]{(int) b[i].x, (int) b[i].y, 0};

        Arrays.sort(newArray, new Comparator<int[]>() {
            public int compare(int[] o1, int[] o2) {
                if (o1[0] != o2[0]) return Integer.compare(o1[0], o2[0]);
                else return Integer.compare(o1[1], o2[1]);
            }
        });
        boolean entra = false;
        int counter = 0;
        for (int i = 0; i < n; i++) {
            if (!entra && newArray[i][2] == 1) {
                entra = true;
                counter++;
            }
            if (entra && newArray[i][2] == 0) entra = false;
        }
        if (counter <= 1) out.printLine("No");
        else out.printLine("Yes");
    }
}
