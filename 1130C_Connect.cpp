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
//#include <unordered_set>
//#include <unordered_map>
//#include <cmath>
//#include <cstring>
//#include <sstream>
//#include <stack>
//#include <queue>

int x, y, dx, dy;
vector<vi> v;
vector<pii> x1, x2;
bool visited[101][101];
bool ans[101][101];
int xs[] = {1, -1, 0, 0};
int ys[] = {0, 0, -1, 1};
bool dfs(int a = x, int b = y, bool first = true) {
    if (a < 0 || b < 0 || a == v.size() || b == v.size()) return false;
    if (v[a][b]) return false;
    if (first && a == dx && b == dy) return true;
    if (visited[a][b]) return false;

    visited[a][b] = 1;
    if (first)
        x1.pb(mp(a, b));
    else
        x2.pb(mp(a, b));

    bool c = false;
    for (int i = 0; i < 4; i++) c |= dfs(a + xs[i], b + ys[i], first);
    return c;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    cin >> x >> y >> dx >> dy;
    x--, y--, dx--, dy--;
    v.resize(n);
    for (int tr = 0; tr < n; tr++) {
        string s;
        cin >> s;
        for (char c : s) v[tr].pb(c - '0');
    }
    bool equal = dfs();
    if (equal)
        cout << 0;
    else {
        //Try every pair
        // cout << "A:" << dx << " " << dy << endl;
        dfs(dx, dy, false);
        int minimum = 1000000;
        for (pair<int, int> p : x1) {
            // cout << p.first << "," << p.second << endl;
            for (pii q : x2) {
                // cout << "  " << q.first << "," << q.second << endl;
                minimum = min(minimum, (p.first - q.first) * (p.first - q.first) + (p.second - q.second) * (p.second - q.second));
            }
        }
        cout << minimum;
    }
}
