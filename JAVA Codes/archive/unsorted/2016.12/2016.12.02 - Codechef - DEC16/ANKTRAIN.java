package juniorAndrade.main;

import juniorAndrade.lib.utils.io.InputReader;
import juniorAndrade.lib.utils.io.OutputWriter;

public class ANKTRAIN {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int n = in.readInt();
        n--;
        if(n % 8 == 0) out.printLine("4LB");
        if(n % 8 == 1) out.printLine("5MB");
        if(n % 8 == 2) out.printLine("6UB");
        if(n % 8 == 3) out.printLine("1LB");
        if(n % 8 == 4) out.printLine("2MB");
        if(n % 8 == 5) out.printLine("3UB");
        if(n % 8 == 6) out.printLine("8SU");
        if(n % 8 == 7) out.printLine("7SL");
    }
}
