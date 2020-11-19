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
#include <unordered_map>
#include <unordered_set>
//#include <cmath>
#include <cstring>
//#include <sstream>
//#include <stack>
//#include <queue>
struct pair_hash {
    inline std::size_t operator()(const std::pair<int, int>& v) const {
        return v.first * 1001 + v.second;
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    unordered_set<pii, pair_hash> u;
    string s;
    cin >> s;
    int x = 200, y = 200;
    unordered_map<char, int> xs, ys;
    xs['L'] = 1;
    xs['R'] = -1;
    xs['U'] = 0;
    xs['D'] = 0;
    ys['D'] = 1;
    ys['U'] = -1;
    ys['L'] = 0;
    ys['R'] = 0;
    int dist[s.length() + 500][s.length() + 500];
    for (int i = 0; i <= s.length() + 499; i++)
        for (int& j : dist[i]) j = 100000;
    u.ins(mp(x, y));
    int p = 0;
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};
    dist[x][y] = 0;
    for (char c : s) {
        x += xs[c], y += ys[c];
        // cout << c << " : " << x << "," << y << endl;
        dist[x][y] = ++p;
        if (FOUND(u, mp(x, y))) {
            cout << "BUG";
            return 0;
        }
        for (int i = 0; i < 4; i++) {
            int r = x + dx[i], k = y + dy[i];
            if (dist[r][k] != 100000 && dist[r][k] + 1 < dist[x][y]) {
                cout << "BUG\n";
                // cout << dist[r][k];
                return 0;
            }
        }

        u.ins(mp(x, y));
    }
    cout << "OK";
}