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
#include <unordered_set>
//#include <unordered_map>
#include <cmath>
//#include <cstring>
//#include <sstream>
//#include <stack>
#include <queue>

ll seen1 = 0, seen2 = 0;
unordered_set<ll> seen;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int t;
    cin >> t;
    queue<int> q1, q2;
    for (int i = 0; i < t; i++) {
        int a;
        cin >> a;
        q1.push(a);
        seen1 = seen1 + pow(10, i) * a;
    }
    cin >> t;
    for (int i = 0; i < t; i++) {
        int a;
        cin >> a;
        q2.push(a);
        seen2 = seen2 + pow(10, i) * a;
    }

    int steps = 0;
    bool cycle = false;
    ll cur1 = seen1, cur2 = seen2;
    bool winner = 0;
    seen.insert(seen1 * 1e9 + seen2);
    while (!q1.empty() && !q2.empty()) {
        int t1 = q1.front(), t2 = q2.front();
        q1.pop();
        q2.pop();
        if (t1 > t2) {
            q1.push(t2);
            q1.push(t1);
            cur2 /= 10;
            cur1 = cur1 + pow(10, q1.size() - 2) * t2;
            cur1 = cur1 + pow(10, q1.size() - 1) * t1;
        } else {
            q2.push(t1);
            q2.push(t2);
            cur1 /= 10;
            cur2 = cur2 + pow(10, q2.size() - 2) * t1;
            cur2 = cur2 + pow(10, q2.size() - 1) * t2;
        }
        steps++;
        if (FOUND(seen, cur1 * 1e9 + cur2)) {
            cycle = 1;
            break;
        }
        seen.insert(cur1 * 1e9 + cur2);
    }
    if (cycle)
        cout << -1;
    else {
        cout << steps << " ";
        cout << (q1.size() ? 1 : 2);
    }
}