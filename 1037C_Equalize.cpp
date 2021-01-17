/*
 * Created by ishaanjav
 * github.com/ishaanjav
 * Codeforces Solutions: https://github.com/ishaanjav/Codeforces-Solutions
 */

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;

    int moves = 0;
    int difs = 0;
    for (int i = 0; i < n - 1; i++)
        if (a[i] != b[i] && a[i + 1] != b[i + 1] && a[i] != a[i + 1]) {
            moves++;

            a[i] = b[i];
            a[i + 1] = b[i + 1];
        }

    for (int i = 0; i < n; i++)
        if (a[i] != b[i]) difs++;

    cout << moves + difs;
}
