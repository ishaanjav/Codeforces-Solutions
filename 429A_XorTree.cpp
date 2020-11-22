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
#define pib pair<int, bool>
#define SET(a, c) memset(a, c, sizeof(a))
#define MOD 1000000007
#define enld endl
#define endl "\n"
#define fi first
#define se second
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define found(u, val) u.find(val) != u.end()

#include <string>
#include <vector>
typedef vector<int> vi;
typedef vector<ll> vl;
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
vector<vi> adj;
vector<bool> change;
vi nodes;

void dfs(int vertex = 1, int parent = 0, int depth = 0, int c1 = 0, int c2 = 0) {
    bool d = false;
    if (depth % 2 == 1) {
        if ((change[vertex] + c1) % 2) {
            nodes.pb(vertex);
            d = true;
        }
    } else {
        if ((change[vertex] + c2) % 2) {
            nodes.pb(vertex);
            d = true;
        }
    }

    for (int u : adj[vertex]) {
        if (u == parent) continue;
        // dfs(u, vertex, changes + d);
        if (!d) {
            dfs(u, vertex, depth + 1, c1, c2);
            continue;
        }
        if (depth % 2 == 1)
            dfs(u, vertex, depth + 1, c1 + 1, c2);
        else
            dfs(u, vertex, depth + 1, c1 + 0, c2 + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    adj.resize(n + 1);
    change.resize(n + 1);
    for (int tr = 0; tr < n - 1; tr++) {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    bool b[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    for (int i = 1; i <= n; i++) {
        bool a;
        cin >> a;
        change[i] = (a != b[i]);
    }
    dfs();
    cout << nodes.size() << endl;
    for (int i : nodes) cout << i << endl;
}
