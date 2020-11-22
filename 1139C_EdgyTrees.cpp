/*
 * Created by ishaanjav
 * github.com/ishaanjav
 * Codeforces Solutions: https://github.com/ishaanjav/Codeforces-Solutions
 */

#include <iostream>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pil pair<int, ll>
#define SET(a, c) memset(a, c, sizeof a)
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

int n, k;
vector<vector<pair<int, bool> > > adj;
bool visited[100001];
ll pows[100001];
ll getPow(ll x) {
    if (pows[x] != 0)
        return pows[x];
    else {
        pows[x] = 1;
        for (int i = 0; i < k; i++) pows[x] = (pows[x] * x) % MOD;
        return pows[x];
    }
}
ll dfs(int vertex) {
    if (visited[vertex]) return 0;
    ll ways = 1;
    visited[vertex] = 1;
    for (pair<int, bool> p : adj[vertex]) {
        // cout << "Vertex " << vertex << " to " << p.first << endl;
        if (p.second == 0) {
            ways += dfs(p.first);
        }
    }
    return ways % MOD;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    adj.resize(n + 1);
    unordered_set<int> redVs;
    for (int tr = 0; tr < n - 1; tr++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].pb(mp(b, c));
        adj[b].pb(mp(a, c));
        if (c == 0) {
            redVs.insert(a);
            redVs.insert(b);
        }
    }
    ll totalWays = n;
    for (int i = 1; i < k; i++) {
        totalWays = (totalWays * n) % MOD;
    }
    totalWays -= n;
    // cout << "Total: " << totalWays << endl;
    for (int vertex : redVs) {
        // cout << "trying " << vertex << endl;
        if (visited[vertex]) continue;
        ll counter = dfs(vertex);
        totalWays += counter;
        // cout << "  " << counter << endl;
        totalWays -= getPow(counter);
        totalWays += MOD;
        totalWays %= MOD;
    }
    cout << totalWays;
}
