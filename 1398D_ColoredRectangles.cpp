#include <iostream>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pil pair<int, ll>
#define SET(a, c) memset(a, c, sizeof a)
#define MOD 1000000007
#define enld endl
#define endl "\n"
#define fi first
#define se second
#define all(v) v.begin(), v.end()

#include <string>
#include <vector>
typedef vector<int> vi;
#include <algorithm>
//#include <set>
//#include <map>
//#include <unordered_set>
//#include <unordered_map>
//#include <cmath>
//#include <cstring>
//#include <sstream>
//#include <stack>
//#include <queue>

/* 
10 1 1
11 7 20 15 19 14 2 4 13 14
8
11

 */
vector<ll> a, b, c;
bool used[202][202][202];
ll dp[202][202][202];
ll solve(ll A, ll B, ll C) {
    if ((A < 1 && B < 1) || (A < 1 && C < 1) || (C < 1 && B < 1)) return 0;
    ll oA = A, oB = B, oC = C;
    // A = max(A, 1ll), B = max(B, 1ll), C = max(C, 1ll);
    if (used[A][B][C]) {
        // cout << "  " << A << " " << B << " " << C << " == " << dp[A][B][C] << endl;
        return dp[A][B][C];
    }
    // A = oA, B = oB, C = oC;
    ll ways = 0;
    if (A >= 1 && B >= 1) ways = max(ways, solve(A - 1, B - 1, C) + a[A] * b[B]);
    if (C >= 1 && B >= 1) ways = max(ways, solve(A, B - 1, C - 1) + c[C] * b[B]);
    if (C >= 1 && A >= 1) ways = max(ways, solve(A - 1, B, C - 1) + c[C] * a[A]);
    used[A][B][C] = 1;
    dp[A][B][C] = ways;
    // cout << A << " " << B << " " << C << " == " << ways << endl;
    return ways;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int A, B, C;
    cin >> A >> B >> C;
    a.resize(A + 1);
    b.resize(B + 1);
    c.resize(C + 1);
    a[0] = 0, b[0] = 0, c[0] = 0;
    for (int i = 0; i < A; i++) cin >> a[i + 1];
    for (int i = 0; i < B; i++) cin >> b[i + 1];
    for (int i = 0; i < C; i++) cin >> c[i + 1];

    sort(all(a));
    sort(all(b));
    sort(all(c));
    // A--, B--, C--;
    ll area = solve(A, B, C);
    /*  while ((A >= 0 && B >= 0) || (B >= 0 || C >= 0) || (A >= 0 && C >= 0)) {
        vector<pii> v;
        v.pb(mp((A >= 0 ? a[A] : -1), 1));
        v.pb(mp((B >= 0 ? b[B] : -1), 2));
        v.pb(mp((C >= 0 ? c[C] : -1), 3));
        sort(all(v));
        if (v[1].first == -1) break;
        area += v[2].first * v[1].first;
        cout << "using " << v[2].first << " and " << v[1].first << endl;
        if (v[1].second == 1 || v[2].second == 1) A--;
        if (v[1].second == 2 || v[2].second == 2) B--;
        if (v[1].second == 3 || v[2].second == 3) C--;
        /*  bool uA = false, uB = false, uC = false;
        if (A >= 0) c1 = a[A];
        if (B >= 0) {
            if (c1 == -1) {
                uB = true;
                c1 = b[B];
            } else if (b[B] > c1) {
                c2 = c1;
                c1 = b[B];
            }
        }
        if (C >= 0) {
            if (c2 == -1)
                c2 = c[C];
            else if (c[C] > c1) {
                c2 = c1;
                c1 = c[C];
            }
        }
        area += c1 * c2; */

    cout << area;
}