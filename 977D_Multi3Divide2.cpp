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
#include <algorithm>
//#include <set>
//#include <map>
//#include <unordered_set>
// #include <unordered_map>
// #include <cmath>
// #include <cstring>
//#include <sstream>
//#include <stack>
//#include <queue>

ll numThrees(ll x) {
    int count = 0;
    while (x % 3 == 0) count++, x /= 3;
    return count;
}

int main() {
    int n;
    cin >> n;
    pair<int, ll> ar[n];
    for (int i = 0; i < n; i++) {
        ll a;
        cin >> a;
        int num = numThrees(a);
        ar[i] = mp(-num, a);
    }
    sort(ar, ar + n);
    for (auto a : ar) cout << a.se << " ";
}

/* int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    ll ar[n];
    int c = 0;
    for (ll& x : ar) {
        cin >> x;
        itol[c] = x;
        u[x] = c++;
    }

    adj.resize(n + 1);
    int goingTo[n];
    SET(goingTo, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (goingTo[j] > 0 || i == j) continue;
            if (itol[i] / 3 != itol[j] && itol[i] * 2 != itol[j]) continue;
            goingTo[j]++;
            adj[i].pb(j);
            // cout << i << " to " << j << endl;
        }
    }
    int pos = 0;
    for (int i = 0; i < n; i++)
        if (goingTo[i] == 0) {
            // cout << pos << endl;
            pos = i;
        }
    int i;
    for (i = pos; adj[i].size() > 0; i = adj[i][0]) {
        // cout << i << ", " << itol[i] << "\n";
        cout << itol[i] << " ";
    }
    cout << itol[i];
} */
