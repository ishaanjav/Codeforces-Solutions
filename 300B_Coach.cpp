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
vb vis;
int dfs(int v) {
    int c = 1;
    vis[v] = 1;
    for (int u : adj[v])
        if (!vis[u]) c += dfs(u);
    return c;
}
string dfs2(int v) {
    string res = "";
    vis[v] = 1;
    for (int u : adj[v])
        if (!vis[u]) res += dfs2(u);
    return to_string(v) + " " + res;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    adj.resize(n + 1);
    vis.resize(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    vi ones, twos, threes;
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        int size = dfs(i);
        if (size > 3) {
            cout << "-1\n";
            return 0;
        } else if (size == 3) {
            threes.pb(i);
        } else if (size == 2)
            twos.pb(i);
        else
            ones.pb(i);
    }
    if (ones.size() < twos.size()) {
        cout << "-1\n";
        return 0;
    }
    for (int i = 0; i <= n; i++) vis[i] = 0;
    for (int i : threes)
        cout << dfs2(i) << endl;
    int j = 0;
    for (int i = 0; i < twos.size(); i++, j++) {
        cout << twos[i] << " " << adj[twos[i]][0] << " " << ones[j] << endl;
    }
    for (; j < ones.size(); j += 3) {
        cout << ones[j] << " " << ones[j + 1] << " " << ones[j + 2] << endl;
    }
}
