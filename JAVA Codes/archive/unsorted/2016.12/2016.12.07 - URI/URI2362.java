package juniorAndrade.main;

import juniorAndrade.lib.geometry.Line;
import juniorAndrade.lib.geometry.Point;
import juniorAndrade.lib.io.IOUtils;
import juniorAndrade.lib.utils.io.InputReader;
import juniorAndrade.lib.utils.io.OutputWriter;

public class URI2362 {
    boolean testCircle(Point p, double r, int m, Point[] bad) {
        for(int i = 0; i < m; ++i) {
            double d = p.distance(bad[i]);
            if(d <= r) return false;
        }
        return true;
    }
    int countGood(Point p, double r, int n, Point[] good) {
        int sum = 0;
        for(int i = 0; i < n; ++i) sum += (p.distance(good[i]) <= r) ? 1 : 0;
        return sum;
    }
    int go(Point p1, Point p2, int n, Point[] good, int m, Point[] bad) {
        Line l = p1.line(p2);
        double dx = (p2.x - p1.x) * 0.5;
        double dy = (p2.y - p1.y) * 0.5;
        Point midPoint = new Point(p1.x + dx, p1.y + dy);
        Line perpendicularLine = l.perpendicular(midPoint);

        int s1 = 0, s2 = 0;
        if(Math.abs(p1.y - p2.y) < 1e-5) { //linha vertical
            double lo = 0, hi = 4000000;
            while (Math.abs(hi - lo) > 1e-5) {
                double mid = (lo + hi) * 0.5;
                double ny = midPoint.y + mid;
                double nx = midPoint.x;
                if (testCircle(new Point(nx, ny), new Point(nx, ny).distance(p1), m, bad)) lo = mid;
                else hi = mid - 0.000001;
            }

            double ny = midPoint.y + lo;
            double nx = midPoint.x;

            if (testCircle(new Point(nx, ny), new Point(nx, ny).distance(p1), m, bad))
                s1 = countGood(new Point(nx, ny), new Point(nx, ny).distance(p1), n, good);

            lo = 0;
            hi = 4000000;
            while (Math.abs(hi - lo) > 1e-5) {
                double mid = (lo + hi) * 0.5;
                ny = midPoint.y - mid;
                nx = midPoint.x;
                if (testCircle(new Point(nx, ny), new Point(nx, ny).distance(p1), m, bad)) lo = mid;
                else hi = mid - 0.0000001;
            }
            ny = midPoint.y - lo;
            nx = midPoint.x;
            if (testCircle(new Point(nx, ny), new Point(nx, ny).distance(p1), m, bad))
                s2 = countGood(new Point(nx, ny), new Point(nx, ny).distance(p1), n, good);
        }
        else {
            double lo = 0, hi = 4000000;
            while (Math.abs(hi - lo) > 1e-5) {
                double mid = (lo + hi) * 0.5;
                double nx = midPoint.x + mid;
                double ny = ((-l.c - l.a * nx) / l.b);
                if (testCircle(new Point(nx, ny), new Point(nx, ny).distance(p1), m, bad)) lo = mid;
                else hi = mid - 0.000001;
            }

            double nx = midPoint.x + lo;
            double ny = ((-l.c - l.a * nx) / l.b);
            if (testCircle(new Point(nx, ny), new Point(nx, ny).distance(p1), m, bad))
                s1 = countGood(new Point(nx, ny), new Point(nx, ny).distance(p1), n, good);

            lo = 0;
            hi = 4000000;
            while (Math.abs(hi - lo) > 1e-5) {
                double mid = (lo + hi) * 0.5;
                nx = midPoint.x - mid;
                ny = ((-l.c - l.a * nx) / l.b);
                if (testCircle(new Point(nx, ny), new Point(nx, ny).distance(p1), m, bad)) lo = mid;
                else hi = mid - 0.0000001;
            }
            nx = midPoint.x - lo;
            ny = ((-l.c - l.a * nx) / l.b);
            if (testCircle(new Point(nx, ny), new Point(nx, ny).distance(p1), m, bad))
                s2 = countGood(new Point(nx, ny), new Point(nx, ny).distance(p1), n, good);
        }
        return Math.max(s1, s2);
    }

    int otherSolve(Point p, int n, Point[] good, int m, Point[] bad) {
        double lo = 0, hi = 4000000;
        while(Math.abs(hi - lo) > 1e-5) {
            double mid = (lo + hi) * 0.5;
            if(testCircle(p, mid, m, bad)) lo = mid;
            else hi = mid - 0.000001;
        }
        return countGood(p, lo, n, good);
    }
    int solve(int n, Point[] good, int m, Point[] bad) {
        int sol = 1;
        for(int i = 0; i < n; ++i) {
            for(int j = i + 1; j < n; ++j) {
                sol = Math.max(sol, go(good[i], good[j], n, good, m, bad));
            }
        }
        for(int i = 0; i < n; ++i) {
            sol = Math.max(sol, otherSolve(good[i], n, good, m, bad));
        }
        return sol;
    }
    public void solve(int testNumber, InputReader in, OutputWriter out) {
        while(true) {
            int n = in.readInt();
            int m = in.readInt();
            if (n == 0 && m == 0) break;
            Point[] good = new Point[n];
            Point[] bad = new Point[m];
            for (int i = 0; i < n; ++i) good[i] = Point.readPoint(in);
            for (int i = 0; i < m; ++i) bad[i] = Point.readPoint(in);
            out.printLine(solve(n, good, m, bad));
        }
    }
}
