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
#define pib pair<int, bool>
#define SET(a, c) memset(a, c, sizeof(a))
#define MOD 1000000007
#define enld endl
#define endl "\n"
#define fi first
#define se second
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define found(u, val) u.find(val) != u.end()

#include <string>
#include <vector>
typedef vector<int> vi;
typedef vector<ll> vl;
//#include <algorithm>
//#include <set>
//#include <map>
#include <unordered_set>
//#include <unordered_map>
//#include <cmath>
#include <cstring>
//#include <sstream>
//#include <stack>
//#include <queue>

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    unordered_set<int> b1, b2;
    bool used[n + 1];
    SET(used, false);
    bool canDo = true;

    int smallest = n;
    int biggest = 1;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        if (b < a) swap(a, b);
        if (used[b]) {
            if (found(b1, b)) {
                canDo = false;
            }
        } else if (used[a]) {
            if (found(b2, a)) {
                canDo = false;
            }
        }
        if (a > smallest || b < biggest) {
            canDo = false;
        }
        b1.insert(a);
        used[a] = 1;
        used[b] = 1;
        b2.ins(b);
        smallest = min(smallest, b);
        biggest = max(biggest, a);
    }
    if (!canDo) {
        cout << 0;
        return 0;
    }

    cout << smallest - biggest;
}
