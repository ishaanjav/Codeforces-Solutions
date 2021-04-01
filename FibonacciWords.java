import java.util.ArrayList;
import java.util.Scanner;
import java.io.IOException;

public class FibonacciWords {
    public static int g(String s, int p) {
        return s.charAt(p) - 'A';
    }

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        if (s.length() <= 2) {
            System.out.println("YES");
            return;
        }
        int o = g(s, 0), t = g(s, 1);
        boolean can = true;
        for (int i = 2; i < s.length() && can; i++) {
            int c = g(s,i);
            int sum = (o + t) % 26;
            can = sum == c;
            o = t;
            t = sum;
        }
        System.out.println(can ? "YES" : "NO");
    }
}
