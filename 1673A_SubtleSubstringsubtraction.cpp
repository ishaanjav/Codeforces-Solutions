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
#define len(a) (sizeof(a)/sizeof(a[0])
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define FOUND(u, val) u.find(val) != u.end()
#define max_self(a, b) a = max(a, b);
#define min_self(a, b) a = min(a, b);
#define deb cout << "ASDFASDF\n"
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
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>

int f(char c) { return c - 'a' + 1; }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;
        int n = s.size();
        if (n == 1) {
            cout << "Bob " << f(s[0]) << Endl;
            continue;
        }
        if (n % 2 == 0) {
            int ans = 0;
            for (int i = 0; i < n; i++) ans += f(s[i]);
            cout << "Alice " << ans << Endl;
            continue;
        } else {
            int ans1 = 0;
            for (int i = 0; i < n - 1; i++) ans1 += f(s[i]);
            int ans2 = 0;
            for (int i = 1; i < n; i++) ans2 += f(s[i]);
            int val = max(ans2, ans1);
            int ans3 = (ans1 == val ? f(s[n - 1]) : f(s[0]));
            if (ans3 > val) {
                cout << "Bob " << ans3 - val << Endl;
            } else
                cout << "Alice " << val - ans3 << Endl;
        }
    }
}