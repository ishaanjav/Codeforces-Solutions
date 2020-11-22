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
//#include <cstring>
//#include <sstream>
//#include <stack>
//#include <queue>

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    ll ar[n];
    ll c[n];
    read(ar);
    read(c);

    ll ans = -1;
    for (int i = 1; i < n - 1; i++) {
        ll cur = c[i];
        bool can1 = false, can2 = false;
        ll t = 1e10, t2 = 1e10;
        for (int j = 0; j < i; j++) {
            if (ar[j] < ar[i]) {
                min_self(t, c[j]);
                can1 = 1;
            }
        }
        for (int k = i + 1; k < n; k++) {
            if (ar[k] > ar[i]) {
                min_self(t2, c[k]);
                can2 = 1;
            }
        }
        if (can1 && can2) {
            if (ans == -1)
                ans = cur + t + t2;
            else
                min_self(ans, cur + t + t2);
        }
    }
    cout << ans << endl;
}
