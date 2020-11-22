/*
 * Created by ishaanjav
 * github.com/ishaanjav
 * Codeforces Solutions: https://github.com/ishaanjav/Codeforces-Solutions
 */

import java.io.BufferedReader;
import java.util.HashMap;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.InputStreamReader;

public class C_RegistrationSystem {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        // (string, ?delimiter, ?flag) -> flag is boolean whether to keep delimiter as
        // token.
        StringTokenizer in = new StringTokenizer(br.readLine());
        int nam = Integer.parseInt(in.nextToken());
        HashMap<String, Integer> currentCount = new HashMap<>();

        for (int tr = 0; tr < nam; tr++) {
            String s = br.readLine();
            if (currentCount.containsKey(s)) {
                System.out.println(s + currentCount.get(s));
                currentCount.put(s, currentCount.get(s) + 1);
            } else {
                System.out.println("OK");
                currentCount.put(s, 1);
            }
        }

    }
}
