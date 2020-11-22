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
//#include <algorithm>
//#include <set>
//#include <map>
//#include <unordered_set>
//#include <unordered_map>
//#include <cmath>
//#include <cstring>
//#include <sstream>
//#include <stack>
#include <queue>

/* 
5
3 1
1 1
-1 0
2 1
3 0

 */
vi parent;
int root;
vb criteria;
vb respectful;
vvi adj;
void dfs(int v) {
    bool respectedByChildren = respectful[v];
    for (int child : adj[v]) {
        respectedByChildren |= respectful[child];
        dfs(child);
    }
    if (!respectedByChildren) criteria[v] = 1;  //meets criteria
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    parent.resize(n + 1);
    criteria.resize(n + 1);
    respectful.resize(n + 1);
    adj.resize(n + 1);

    priority_queue<int> candidates;

    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        parent[i + 1] = p;
        if (p == -1)
            root = i + 1;
        else
            adj[p].pb(i + 1);
        bool b;
        cin >> b;
        b = !b;
        respectful[i + 1] = b;
        if (!b) {
            candidates.push(-i - 1);
            // cout << "i: " << i + 1 << endl;
        }
    }
    dfs(root);
    bool f = 0;
    while (!candidates.empty()) {
        int v = candidates.top() * -1;
        candidates.pop();
        if (!criteria[v]) continue;
        cout << v << " ";
        f = 1;
    }
    if(!f) cout <<-1;
}
