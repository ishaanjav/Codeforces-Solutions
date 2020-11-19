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
#include <unordered_map>
//#include <cmath>
//#include <cstring>
//#include <sstream>
//#include <stack>
//#include <queue>

#include <cstring>

int n, m;
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

    cin >> n >> m;
    int degree[n + 1];
    SET(degree, 0);
    parent.resize(n + 1);
    sizes.resize(n + 1, 1);

    for (int i = 1; i <= n; i++) parent[i] = i;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        degree[a]++, degree[b]++;
        unionNodes(a, b);
    }
    unordered_map<int, bool> u;  // (parent of component, it is not a cycle)
    for (int i = 1; i <= n; i++)
        u[find(i)] |= (degree[i] != 2);
    int count = 0;
    for (pair<int, bool> p : u) count += !p.se;
    cout << count << endl;
}