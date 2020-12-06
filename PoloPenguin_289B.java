import java.io.IOException;
import java.util.*;

public class PoloPenguin_289B {

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int d = sc.nextInt();
        int grid[][] = new int[n][m];
        boolean possible = true;

        int mod = -1;
        ArrayList<Integer> al = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                grid[i][j] = sc.nextInt();
                if (mod == -1)
                    mod = grid[i][j] % d;
                else if (grid[i][j] % d != mod)
                    possible = false;
                al.add(grid[i][j]);
            }
        }

        if (!possible) {
            System.out.println("-1");
            return;
        }
        Collections.sort(al);
        int med = al.get(al.size() / 2);
        long total = 0;
        for (int i : al)
            total += (Math.abs(i - med) / d);
        System.out.println(total);
    }
}
