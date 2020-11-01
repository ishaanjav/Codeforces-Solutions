#include <iostream>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(v) v.begin(), v.end()

#include <string>
#include <vector>
typedef vector<int> vi;
//#include <algorithm>
//#include <set>
//#include <map>
//#include <unordered_set>
//#include <unordered_map>
//#include <cmath>
#include <cstring>
// #include <sstream>
#include <stack>
//#include <queue>

vector<ll> costs;
vector<int> adj[100001];
vector<int> jda[100001];
vector<vector<int> > scc;
int visited[100001];
ll ans = 0, ways = 1;
stack<int> s;
int num = 1;

//First DFS - Create a stack of the vertices preorder. (root node will be at top of stack)
void dfs(int vertex = 1) {
    if (visited[vertex] == 1) return;
    visited[vertex] = 1;
    for (int e : adj[vertex])
        dfs(e);
    s.push(vertex);
}
// Second DFS - While stack not empty, pop and then do reverse DFS (opposite direction of edges) and all these are in same SCC
void dfs2(int vertex = 1) {
    if (visited[vertex] == 2) return;
    visited[vertex] = 2;
    for (int e : jda[vertex])
        dfs2(e);
    scc[num - 1].push_back(vertex);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    costs.resize(n + 1);

    for (int tr = 0; tr < n; tr++) {
        cin >> costs[tr + 1];
    }

    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        jda[b].pb(a);
    }
    for (int i = 1; i <= n; i++)
        if (visited[i] == 0) dfs(i);

    while (!s.empty()) {
        int top = s.top();
        vector<int> empty;
        if (visited[top] == 1) {
            scc.push_back(empty);
            dfs2(top);
            num++;
        }
        s.pop();
    }

    for (vector<int> v : scc) {
        ll cur = 100000000000;
        ll w = 0;
        for (int pos : v) {
            // cout << pos << " ";
            ll cost = costs[pos];
            if (cost < cur) {
                cur = cost, w = 1;
            } else if (cost == cur)
                w++;
        }
        // cout << "\n";
        ans += cur;
        ways = (w * ways) % 1000000007;
        // cout << "ANS: " << ans << " " << ways << endl;
    }
    cout << ans << " " << ways;
}