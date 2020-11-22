/*
 * Created by ishaanjav
 * github.com/ishaanjav
 * Codeforces Solutions: https://github.com/ishaanjav/Codeforces-Solutions
 */

#include <iostream>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair

#include <string>
#include <vector>
typedef vector<int> vi;
//#include <algorithm>
//#include <set>
//#include <map>
//#include <unordered_set>
//#include <unordered_map>
//#include <cmath>
#include <cstring>
//#include <sstream>
//#include <stack>
//#include <queue>
vector<int> primes;
void sieve() {
    bool prime[100009];
    memset(prime, true, sizeof(prime));
    prime[0] = false;
    prime[1] = false;
    for (int p = 2; p < 300; p++) {
        if (!prime[p]) continue;
        primes.pb(p);
        //cout << p << endl;
        for (int j = p * p; j < 100000; j += p) prime[j] = false;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int r, c;
    cin >> r >> c;

    sieve();
    int ar[r][c];
    int lastPos = 0;
    int val[r][c];
    ll ans = 1e12;
    for (int i = 0; i < r; i++) {
        ll temp = 0;
        cout << "A";
        for (int j = 0; i < c; j++) {
            cin >> ar[i][j];
            int num;
            for (int a = 0; a < primes.size(); a++) {
                cout << a << " ";
                if (primes[a] >= ar[i][j]) {
                    num = primes[a];
                    break;
                }
            }
            temp += num;
            val[i][j] = num;
        }
        ans = min(temp, ans);
    }
    for (int j = 0; j < c; j++) {
        ll temp = 0;
        for (int i = 0; i < r; i++) {
            temp += val[i][j];
        }
        ans = min(ans, temp);
    }
    cout << ans << "\n";
}
