#include <iostream>
using namespace std;

#define ll long long
#define pb push_back
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
int d, n;
vector<vi> adj;
vi weights;
vector<bool> visited;

ll dfs(ll root, ll u) {
    visited[u] = true;
    ll ways = 1;
    for (int v : adj[u]) {
        if (visited[v]) continue;
        if (weights[v] > weights[root] + d) continue;
        // Checks to avoid duplicate counting
        // - Only go to a vertex if its value is >= to you. This way we only count small --> big and not also big --> small when we dfs from big
        // - If two vertices have same value, this condition will be true both times, so we will only go from u to v if u > v. That way when we dfs v and see value[v] = value[u], we don't dfs v to u and count that again.
        if ((weights[v] == weights[root] && v < root) || (weights[v] < weights[root])) continue;
        ways = (ways * (dfs(root, v) + 1)) % MOD;
    }
    return ways;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> d >> n;

    weights.resize(n + 1);
    adj.resize(n + 1);
    visited.resize(n + 1);
    for (int i = 0; i < n; i++) cin >> weights[i + 1];
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    ll ways = 0;
    for (int i = 1; i <= n; i++) {
        // memset(visited, false, sizeof(visited));
        for (int i = 0; i <= n; i++) visited[i] = false;
        ways = (ways + dfs(i, i)) % MOD;
    }
    cout << ways;
}