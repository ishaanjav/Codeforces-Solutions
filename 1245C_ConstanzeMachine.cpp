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
#define Endl "\n"
#define endl "\n"
#define fi first
#define se second
#define rs resize
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define FOUND(u, val) u.find(val) != u.end()
#define max_self(a, b) a = max(a, b);
#define min_self(a, b) a = min(a, b);
bool de = 1;
// bool de = 0;
#define deb cout << (de ? "ASDFASDF\n" : "")
#define read(ar) \
    for (auto& x : ar) cin >> x;
#define each(ar) for (auto i : ar)
#define eachv(ar, i) for (auto i : ar)

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
#include <cstring>
//#include <sstream>
//#include <stack>
//#include <queue>

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    for (char c : s) {
        if (c == 'w' || c == 'm') {
            cout << 0;
            return 0;
        }
    }
    int n = s.length();
    ll dp[n + 1];
    dp[0] = dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        if ((s[i - 1] != 'u' && s[i - 1] != 'n') || (s[i - 2] != s[i - 1]))
            dp[i] = dp[i - 1];
        else
            dp[i] = dp[i - 1] + dp[i - 2];
        dp[i] %= MOD;
    }
    cout << dp[n];

    // int first = 0;
    // int right = 0;
    // int n = s.length();
    // char c = ' ';
    // int maxSize = 0;
    // while (first < n) {
    //     c = s[first];
    //     if (c != 'u' && c != 'n') {
    //         first++;
    //         right++;
    //         continue;
    //     }
    //     while (right < n && s[right] == c) {
    //         right++;
    //     }
    //     sizes.pb(right - first);
    //     max_self(maxSize, right - first);
    //     first = right;
    // }
    // ll ar[maxSize + 2];
    // int a = 0, b = 1;
    // ar[0] = 0;
    // for (int i = 1; i <= maxSize; i++) {
    //     int c = a + b;
    //     ar[i] = c;
    //     a = b;
    //     b = c;
    //     ar[i] %= MOD;
    //     // cout << ar[i] << endl;
    // }
    // ll ans = 1;
    // for (ll a : sizes) {
    //     ans *= ar[a];
    //     ans %= MOD;
    //     if (ans < 0) {
    //         cout << a << endl;
    //     }
    // }
    // cout << ans << endl;
    // ll t = (MOD - 1) * (MOD - 1);
    // cout << t;
}
