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
#define rs resize
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define FOUND(u, val) u.find(val) != u.end()
#define max_self(a, b) a = max(a, b);
#define min_self(a, b) a = min(a, b);

#include <string>
#include <vector>
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<ll> vl;
typedef vector<bool> vb;
#define INF 2e6
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

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        int ar[n];
        for (int &x : ar) cin >> x;

        int ans = INF;
        int dp[n + 1][4];
        for (int i = 0; i <= n; i++)
            for (int j = 0; j < 4; j++) dp[i][j] = INF;
        dp[1][2] = ar[0];
        dp[2][3] = ar[0] + ar[1];
        dp[2][0] = ar[0];

        for (int i = 2; i <= n; i++) {
            dp[i][0] = min(dp[i - 1][3], dp[i - 1][2]);
            dp[i][1] = min(dp[i - 1][0], dp[i][0]);
            dp[i][2] = ar[i - 1] + min(dp[i - 1][0], dp[i - 1][1]);
            dp[i][3] = ar[i - 1] + min(dp[i - 1][2], dp[i][2]);
        }
        for (int i = 0; i < 4; i++) min_self(ans, dp[n][i]);

        cout << ans << endl;
    }
}