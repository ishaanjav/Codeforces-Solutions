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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        int parents[n + 1];
        int in[n + 1];
        bool vis[n + 1];
        SET(parents, -1);
        SET(in, 0);
        SET(vis, 0);
        for (int i = 1; i <= n; i++) {
            cin >> parents[i];
            in[parents[i]]++;
        }
        if(n == 1) {cout << "1\n1\n1\n\n";continue;}
        vvi ans;
        for (int i = 1; i <= n; i++) {
            if (in[i] == 0) {
                vi v;
                v.pb(i);
                int k = i;
                // cout << "k = " << k << endl;
                while (parents[k] != k) {
                    k = parents[k];
                    if (!vis[k]) {
                        vis[k] = 1;
                        v.pb(k);
                        // cout << "Parent: " << k << endl;
                    }
                }
                ans.pb(v);
            }
        }
        cout << ans.size() << endl;
        for (vi v : ans) {
            cout << v.size() << endl;
            for (int i = v.size() - 1; i >= 0; i--) cout << v[i] << " ";
            cout << endl;
        }
        cout << endl;
    }
}