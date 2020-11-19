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
vvi adj;
vi sub;
void dfs(int v, int par = 0) {
    sub[v] = 1;
    for (int i : adj[v]) {
        if (i == par) continue;
        dfs(i, v);
        sub[v] += sub[i];
    }
}
int counter = 0;
void dfsCount(int v = 1, int par = 0) {
    counter += (v != 1 && sub[v] % 2 == 0);
    for (int u : adj[v])
        if (u != par)
            dfsCount(u, v);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    adj.resize(n + 1);
    sub.resize(n + 1);

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    if (n % 2) {
        cout << -1;
        return 0;
    }

    dfs(1);
    dfsCount();
    cout << counter << endl;
}