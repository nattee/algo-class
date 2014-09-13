import java.io.*;
import java.util.*;

 public   class   Fibo   {
        public static int fibo(int n) {
                if (n < 2) return n;
                int a = 0;
                int b = 1;
                for (int i = 2;i <= n;i++) {
                   int c = a + b;
                   a = b;
                   b = c;
                }
                return b;
        }

        public static void main(String[] argv) {
                Scanner sc = new Scanner(System.in);
                int n = sc.nextInt();
                System.out.println(fibo(n));
        }
}

