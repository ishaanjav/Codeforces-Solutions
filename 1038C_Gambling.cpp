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

#include <string>
#include <vector>
typedef vector<int> vi;
typedef vector<ll> vl;
#include <algorithm>
//#include <set>
//#include <map>
//#include <unordered_set>
//#include <unordered_map>
//#include <cmath>
//#include <cstring>
//#include <sstream>
//#include <stack>
//#include <queue>

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vl a(n), b(n);
    for (int tr = 0; tr < n; tr++) {
        cin >> a[tr];
    }
    for (int tr = 0; tr < n; tr++) cin >> b[tr];

    sort(all(a));
    sort(all(b));

    ll score = 0;
    ll moves = 0;
    while (moves++ < 2 * n) {
        if (a.size() == 0) {
            b.erase(b.end() - 1);
            if (moves % 2 == 0)
                score -= b.back();
        } else if (b.size() == 0) {
            if (moves % 2)
                score += a.back();
            a.erase(a.end() - 1);
        } else {
            int topA = a.back();
            int topB = b.back();
            if (moves % 2) {
                if (topA > topB) {
                    score += topA;
                    a.erase(a.end() - 1);
                } else {
                    b.erase(b.end() - 1);
                }
            } else {
                if (topB > topA) {
                    score -= topB;
                    b.erase(b.end() - 1);
                } else {
                    a.erase(a.end() - 1);
                }
            }
        }
    }

    cout << score;
}