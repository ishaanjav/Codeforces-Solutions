#include <iostream>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second

#include <string>
#include <vector>
typedef vector<int> vi;
//#include <algorithm>
//#include <set>
//#include <map>
//#include <unordered_set>
//#include <unordered_map>
//#include <cmath>
//#include <cstring>
//#include <sstream>
//#include <stack>
//#include <queue>

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    ll ar[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cin >> ar[i][j];
    }

    ll grid[n][n];
    ll upLeft[n + 1][n + 1];
    ll downLeft[n + 1][n + 1];
    ll upRight[n + 1][n + 1];
    ll downRight[n + 1][n + 1];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                upLeft[i][j] = 0;
            else {
                upLeft[i][j] = upLeft[i - 1][j - 1] + ar[i - 1][j - 1];
            }
        }
    }
    for (int i = n; i > -1; i--) {
        for (int j = n; j > -1; j--) {
            if (i == n || j == n)
                downLeft[i][j] = 0;
            else {
                downLeft[i][j] = downLeft[i + 1][j + 1] + ar[i][j];
            }
        }
    }
    for (int i = 0; i <= n; i++) {
        for (int j = n; j > -1; j--) {
            if (i == 0 || j == n)
                upRight[i][j] = 0;
            else {
                upRight[i][j] = upRight[i - 1][j + 1] + ar[i - 1][j];
            }
        }
    }
    for (int i = n; i > -1; i--) {
        for (int j = 0; j <= n; j++) {
            if (j == 0 || i == n)
                downRight[i][j] = 0;
            else {
                downRight[i][j] = downRight[i + 1][j - 1] + ar[i][j - 1];
            }
        }
    }
    /*   cout << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= n; j++) cout << downRight[i][j] << " ";
        cout << "\n";
    }
 */
    ll oddMax = -1, evenMax = -1;
    int a, b, c, d;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if ((i + j) % 2 == 1) {
                if (upLeft[i + 1][j + 1] + downLeft[i][j] + upRight[i + 1][j] + downRight[i][j + 1] - 3 * ar[i][j] > oddMax) {
                    oddMax = upLeft[i + 1][j + 1] + downLeft[i][j] + upRight[i + 1][j] + downRight[i][j + 1] - 3 * ar[i][j];
                    a = i, b = j;
                }
            } else if (upLeft[i + 1][j + 1] + downLeft[i][j] + upRight[i + 1][j] + downRight[i][j + 1] - 3 * ar[i][j] > evenMax) {
                evenMax = upLeft[i + 1][j + 1] + downLeft[i][j] + upRight[i + 1][j] + downRight[i][j + 1] - 3 * ar[i][j];
                c = i, d = j;
            }
        }
    }
    cout << oddMax + evenMax << endl
         << a + 1 << " " << b + 1 << " " << c + 1 << " " << d + 1 << "\n";
}