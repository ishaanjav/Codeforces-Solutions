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
        vi steps;
        int ar1[n];
        read(ar1);
        int ar2[n];
        read(ar2);
        pii ar[n];
        for (int i = 0; i < n; i++) ar[i] = mp(ar1[i], ar2[i]);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - 1; j++) {
                if (ar[j].fi > ar[j + 1].fi) {
                    swap(ar[j], ar[j + 1]);
                    steps.pb(j + 2);
                    steps.pb(j + 1);
                }
            }
        }
        for (int i = 0; i < n;) {
            int j = i + 1;
            while (j < n && ar[j].fi == ar[i].fi) j++;
            if (j == i + 1) {
                i = j;
                continue;
            }
            for (int k = i; k < j; k++) {
                for (int l = i; l < j - 1; l++) {
                    if (ar[l].se > ar[l + 1].se) {
                        swap(ar[l + 1], ar[l]);
                        steps.pb(l + 1);
                        steps.pb(l + 2);
                    }
                }
            }
            i = j;
        }
        bool good = 1;
        for (int i = 0; i < n - 1; i++) {
            if (ar[i].fi > ar[i + 1].fi || ar[i].se > ar[i + 1].se) {
                good = 0;
            }
        }
        if (!good)
            cout << "-1\n";
        else {
            cout << (steps.size() / 2) << endl;
            for (int i = 0; i < steps.size(); i += 2) {
                cout << steps[i] << " " << steps[i + 1] << endl;
            }
        }
    }
}