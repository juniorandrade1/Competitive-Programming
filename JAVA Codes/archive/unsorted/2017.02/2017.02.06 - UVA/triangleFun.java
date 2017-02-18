package juniorAndrade.main;

import juniorAndrade.lib.geometry.Line;
import juniorAndrade.lib.geometry.Point;
import juniorAndrade.lib.geometry.Polygon;
import juniorAndrade.lib.utils.io.InputReader;
import juniorAndrade.lib.utils.io.OutputWriter;

public class triangleFun {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
        Point A = Point.readPoint(in);
        Point B = Point.readPoint(in);
        Point C = Point.readPoint(in);

        double dx, dy;

        dx = B.x - A.x;
        dy = B.y - A.y;

        Point F = new Point(A.x + dx / 3., A.y + dy / 3.);

        dx = C.x - B.x;
        dy = C.y - B.y;

        Point D = new Point(B.x + dx / 3., B.y + dy / 3.);

        dx = A.x - C.x;
        dy = A.y - C.y;

        Point E = new Point(C.x + dx / 3., C.y + dy / 3.);

        Line lda = A.line(D);
        Line lcf = C.line(F);
        Line lbe = B.line(E);

        Point Q = lcf.intersect(lbe);
        Point R = lda.intersect(lcf);
        Point P = lbe.intersect(lda);

        double area = Polygon.triangleSquare(Q, R, P);

        out.printLine(Math.round(area));

    }
}
