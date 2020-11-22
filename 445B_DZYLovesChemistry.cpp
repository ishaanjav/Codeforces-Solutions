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
//#include <unordered_map>
#include <cmath>
#include <cstring>
//#include <sstream>
//#include <stack>
#include <queue>

// OBVIOUS SOLUTION I DIDN'T SEE:
// 2 ^ (n - # of connected components)
// let's say s is size of 1 of the connected components
// # of reactions we can get from that component is s-1, because the first vertex from that component won't have a reaction
// all stuff after it will
// so if there are x connected components, n - x vertices will have reactions
// ans is just 2 ^(n-x)

vvi adj;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    if (m == 0) {
        cout << 1;
        return 0;
    }
    adj.resize(n + 1);
    int conn[n + 1];
    SET(conn, 0);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
        conn[a]++, conn[b]++;
    }

    priority_queue<pii> pq;
    int pos = 0;
    int amt = 0;
    for (int i = 1; i <= n; i++)
        if (conn[i] > amt) pos = i, amt = conn[i];

    pq.push(mp(conn[pos], pos));
    ll ans = 1;
    bool taken[n + 1];
    SET(taken, 0);
    // taken[pos] = 1;
    int visited = 0;
    for (int i = 0; i <= n; i++) {
        if (taken[i]) continue;
        if (i != 0) pq.push(mp(conn[i], i));
        while (!pq.empty()) {
            int top = pq.top().se;
            pq.pop();
            if (taken[top]) continue;
            taken[top] = 1;
            // cout << i << " at " << top << endl;
            if (top != i && top != pos) {
                ans *= 2;
                // ans %= MOD;
            }
            for (int u : adj[top]) {
                if (taken[u]) continue;
                pq.push(mp(conn[u], u));
            }
        }
    }
    cout << ans;
}
