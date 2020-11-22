/*
 * Created by ishaanjav
 * github.com/ishaanjav
 * Codeforces Solutions: https://github.com/ishaanjav/Codeforces-Solutions
 */

#include <iostream>
using namespace std;

#define ll long long
#define pb push_back
#define ins insert
#define mp make_pair
#define pii pair<int, int>
#define pil pair<int, ll>
#define pib pair<int, bool>
#define SET(a, c) memset(a, c, sizeof(a))
#define MOD 1000000007
#define enld endl
#define endl "\n"
#define fi first
#define se second
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define FOUND(u, val) u.find(val) != u.end()
#define max_self(a, b) a = max(a, b);

#include <string>
#include <vector>
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<bool> vb;
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
    cin.tie(0);

    int n;
    cin >> n;
    int ar[n + 1];
    int g[n + 1];
    int s[n + 1];
    for (int i = 0; i < n; i++) cin >> ar[i + 1];

    int dp[n + 1][3];
    dp[0][0] = dp[0][1] = dp[0][2] = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < 3; j++) {
            dp[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; i++) {
        int num = ar[i];
        for (int j = 0; j < 3; j++) max_self(dp[i][0], dp[i - 1][j]);
        if (num == 1 || num == 3)
            dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + 1;
        if (num == 2 || num == 3)
            dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]) + 1;
    }
    int ans = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < 3; j++) {
            ans = max(ans, dp[i][j]);
            // cout << dp[i][j] << " ";
        }
        // cout << endl;
    }
    cout << n - ans;

    /* g[0] = s[0] = 0;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (ar[i] == 0) {
            g[i] = g[i - 1], s[i] = s[i - 1];
        } else if (ar[i] == 3) {
            if (i == 1) {
                g[i] = 1, s[i] = 1;
            } else {
                if (ar[i - 1] == 1) {
                    s[i] = max(s[i - 1], g[i - 1] + 1);
                    g[i] = max(g[i - 1] + 1, s[i - 1] + 1);
                } else if (ar[i - 1] == 2) {
                    s[i] = max(s[i - 1] + 1, g[i - 1] + 1);
                    g[i] = max(g[i - 1], s[i - 1] + 1);
                } else if (ar[i - 1] == 0) {
                    s[i] = max(s[i - 1] + 1, g[i - 1] + 1);
                    g[i] = max(g[i - 1] + 1, s[i - 1] + 1);
                }else{
                    s[i] = max(s)
                }
            }
        }
    } */
}
