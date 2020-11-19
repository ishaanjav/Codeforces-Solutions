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
#include <unordered_set>
//#include <unordered_map>
//#include <cmath>
//#include <cstring>
//#include <sstream>
//#include <stack>
//#include <queue>
vi parent, sizes;
int find(int v) {
    if (parent[v] != parent[parent[v]]) parent[v] = find(parent[v]);
    return parent[v];
}

void unionNodes(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return;
    if (sizes[y] > sizes[x]) swap(x, y);
    sizes[x] += sizes[y];
    parent[y] = x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    parent.resize(n + 1);
    sizes.resize(n + 1, 1);
    int ans = 0;
    unordered_set<int> u;
    vvi langs;
    langs.resize(m + 1);
    unordered_set<int> us, none;

    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        if (t == 0) {
            ans++;
            none.ins(i + 1);
            continue;
        }
        int o = t;
        while (t--) {
            int a;
            cin >> a;
            langs[a].pb(i + 1);
            us.ins(a);
        }
    }
    for (int i = 0; i <= n; i++) parent[i] = i;
    for (int i = 1; i <= m; i++) {
        if (langs[i].size() == 0) continue;
        int last = langs[i][0];
        for (int j = 1; j < langs[i].size(); j++) {
            unionNodes(last, langs[i][j]);
            // cout << " union " << last << " and " << langs[i][j] << endl;
            last = langs[i][j];
        }
        // cout << "Lang " << i << " ----\n";
    }
    for (int i = 1; i <= n; i++) {
        if (FOUND(none, i)) continue;
        u.insert(find(i));
    }
    int a = none.size();
    if (u.size() > 0) a--;
    cout << u.size() + a << endl;
}