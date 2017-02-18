package juniorAndrade.main;

import java.util.Scanner;
import java.io.PrintWriter;

public class TaskA {
    public void solve(int testNumber, Scanner in, PrintWriter out) {
       long[] f = new long[3500];
       int n, a, b, c;
       n = in.nextInt();
       a = in.nextInt();
       b = in.nextInt();
       c = in.nextInt();
       long ans = 1234567891012L;
       for(int i = 1; i < 3500; ++i) {
           f[i] = 1234567891012L;
           if(i >= 1) f[i] = Math.min(f[i], f[i - 1] + a);
           if(i >= 2) f[i] = Math.min(f[i], f[i - 2] + b);
           if(i >= 3) f[i] = Math.min(f[i], f[i - 3] + c);
           if((n+i)%4==0)ans = Math.min(ans,f[i]);
       }
       if(n % 4 == 0) ans = 0;
       out.println(ans);
    }
}
