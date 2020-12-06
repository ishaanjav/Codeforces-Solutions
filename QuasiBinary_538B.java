/*
 * Created by ishaanjav
 * github.com/ishaanjav
 * Codeforces Solutions: https://github.com/ishaanjav/Codeforces-Solutions
 */

import java.util.Scanner;
import java.io.IOException;
import java.util.*;

public class QuasiBinary_538B {

	static ArrayList<Integer> al;

	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		long dp[] = new long[n + 1];
		al = new ArrayList<>();
		gen(0);
		Arrays.fill(dp, 10000000);
		Collections.sort(al);

		int back[] = new int[n + 1];
		dp[0] = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < al.size() && al.get(j) <= i; j++) {
				int k = al.get(j);
				if (dp[i - k] + 1 < dp[i]) {
					dp[i] = dp[i - k] + 1;
					back[i] = k;
				}
			}
		}
		System.out.println(dp[n]);
		int backtrack = n;
		while (backtrack != 0) {
			System.out.print(back[backtrack] + " ");
			backtrack -= back[backtrack];
		}
	}

	static void gen(int n) {
		if (n > 1000000)
			return;
		al.add(n);
		gen(n * 10 + 1);
		if (n != 0)
			gen(n * 10);
	}

}
