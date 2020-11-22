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
bool canDo(ll a, ll b, ll p, string s, ll mid) {
    ll n = s.length();
    if (mid == n - 1) return 1;
    ll cost = 0;
    char orig = s[mid];
    while (mid < n - 1) {
        if (s[mid] == 'A')
            cost += a;
        else
            cost += b;
        while (mid < n && s[mid] == orig) mid++;
        orig = s[mid];
    }
    return cost <= p;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        ll a, b, p;
        string s;
        cin >> a >> b >> p >> s;
        ll n = s.length();
        ll lo = 0, hi = n - 1;
        ll ans = hi;

        while (lo <= hi) {
            ll mid = (lo + hi) / 2;
            if (canDo(a, b, p, s, mid))
                ans = mid, hi = mid - 1;
            else
                lo = mid + 1;
        }

        cout << ans + 1 << Endl;
    }
}
