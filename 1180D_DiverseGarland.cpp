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
#define pll pair<ll, ll>
#define pib pair<int, bool>
#define SET(a, c) memset(a, c, sizeof(a))
#define MOD 1000000007
#define Endl endl
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
int get(char c) {
    if (c == 'R') return 0;
    if (c == 'G') return 1;
    return 2;
}
void p(int a) {
    if (a == 0)
        cout << 'R';
    else if (a == 1)
        cout << 'G';
    else
        cout << 'B';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    string s;
    cin >> s;

    int best = s.length() - 1;

    int dp[3][n + 2];
    SET(dp, 0);

    for (int i = n - 1; i >= 0; i--) {
        int t = get(s[i]);
        dp[0][i] = dp[1][i] = dp[2][i] = s.length();
        for (int j = 1; j < 3; j++) min_self(dp[0][i], dp[j][i + 1]);
        dp[1][i] = min(dp[0][i + 1], dp[2][i + 1]);
        dp[2][i] = min(dp[0][i + 1], dp[1][i + 1]);

        for (int j = 0; j < 3; j++) {
            if (j == t) continue;
            dp[j][i]++;
        }
    }
    int r = 0;

    cout << min(dp[0][0], min(dp[1][0], dp[2][0])) << endl;
}
