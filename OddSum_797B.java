/*
 * Created by ishaanjav
 * github.com/ishaanjav
 * Codeforces Solutions: https://github.com/ishaanjav/Codeforces-Solutions
 */

import java.util.Scanner;
import java.io.IOException;

public class OddSum_797B {

	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		long sum = 0;
		int minPositive = 1000000;
		int maxNegative = -1000000;
		for (int i = 0; i < n; i++) {
			int a = sc.nextInt();
			if (a > 0) {
				sum += a;
				if (a % 2 == 1)
					minPositive = Math.min(minPositive, a);
			} else if (a * -1 % 2 == 1)
				maxNegative = Math.max(maxNegative, a);
		}
		if (sum % 2 == 1)
			System.out.println(sum);
		else
			System.out.println(sum + (maxNegative * -1 < minPositive ? maxNegative : -minPositive));
	}
}
