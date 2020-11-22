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

// First looked at this problem July 30,
// Solved it by myself today, August 4 (5 days later)
int n, k, d;
ll dp[10000000][2];
bool used[10000000][2];
ll solve(ll left, int limit) {
    if (left == 0) return 1;
    if (left < 0) return 0;
    if (used[left][limit == k]) return dp[left][limit == k];

    ll ways = 0;
    for (int i = 1; i <= limit; i++) {
        if (left - i >= 0) {
            ways += (solve(left - i, limit) % 1000000007);
        } else
            break;
    }
    used[left][limit == k] = 1;
    dp[left][limit == k] = ways;
    // if (limit == 1) cout << ways << " for 1\n";
    return ways;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k >> d;

    ll ans = 0;
    for (int i = 1; i <= k; i++) {
        ans += (solve(n - i, k) % 1000000007);
        // cout << ans << "\n";
    }
    ans = (1000000007 + 1000000007 + ans - solve(n, d - 1)) % 1000000007;

    /*  for (int i = 1; i <= n; i++)
        cout << dp[i] << " ";
    cout << "\n"; */
    cout << ans << endl;
}
