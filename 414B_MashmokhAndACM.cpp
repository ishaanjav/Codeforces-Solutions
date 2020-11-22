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
#define all(v) v.begin(), v.end()

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
#define mod 1000000007
int n, k;
bool used[2001][2001];
ll dp[2001][2001];
ll solve(int num = 1, int remaining = 0) {
    if (remaining == k) return 1;
    if (used[num][remaining]) return dp[num][remaining];
    ll ways = 0;
    for (ll i = num; i <= n; i += num)
        ways += (solve(i, remaining + 1) % mod);
    used[num][remaining] = true;
    dp[num][remaining] = (ways) % mod;
    return ways;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;

    ll ans = (solve());

    cout << ans << endl;
}
