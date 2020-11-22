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
vector<unordered_set<int> > v;
int n, m;
bool vis[1000000];
bool dfs(int u) {
    vis[u] = true;
    for (int neighbor : v[u])
        for (int k : v[neighbor])
            if (v[u].find(k) == v[u].end() && k != u) {
                // cout << ": " << u << " - " << neighbor << " - " << k << endl;
                return true;
            }
    return false;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    v.resize(n + 1);
    for (int tr = 0; tr < m; tr++) {
        int a, b;
        cin >> a >> b;
        v[a].insert(b);
        v[b].insert(a);
    }

    bool bad = false;
    for (int i = 1; i <= n; i++) {
        bad = dfs(i);
        if (bad) break;
    }
    cout << (bad ? "NO" : "YES");
}
