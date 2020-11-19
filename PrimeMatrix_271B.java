import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.util.TreeMap;

public class PrimeMatrix_271B {

    static ArrayList<Integer> primes;

    static TreeMap<Integer, Integer> map;
    static boolean prime[];

    static void sieve() {
        prime = new boolean[100010];
        Arrays.fill(prime, Boolean.TRUE);
        map = new TreeMap<>();
        prime[2] = true;
        for (int p = 2; p < 100010; p++) {
            if (!prime[p])
                continue;
            // primes.add(p);
            map.put(p, p);
            for (int j = p * p; j < 100010; j += p) {
                prime[j] = false;
            }
        }

    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        // (string, ?delimiter, ?flag) -> flag is boolean whether to keep delimiter as
        // token.
        StringTokenizer in = new StringTokenizer(br.readLine());
        int rows = Integer.parseInt(in.nextToken());
        int cols = Integer.parseInt(in.nextToken());
        System.out.println("AA");
        sieve();
        System.out.println("AA");
        int ar[][] = new int[rows][cols];

        long ans = 0;
        for (int i = 0; i < rows; i++) {
            in = new StringTokenizer(br.readLine());
            long temp = 0;
            for (int j = 0; j < cols; j++) {
                ar[i][j] = Integer.parseInt(in.nextToken());
                temp += map.ceilingKey(ar[i][j]) - ar[i][j];
            }
            ans = Math.min(ans, temp);
        }
        System.out.println(ans);
    }
}