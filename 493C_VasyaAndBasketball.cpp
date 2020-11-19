#include <iostream>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(v) v.begin(), v.end()

#include <string>
#include <vector>
typedef vector<int> vi;
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
    cin.tie(NULL);

    int n, m;
    cin >> n;
    int p1[n];
    int lo = 10000000, hi = -1;
    vector<pair<ll, int> > dist;
    for (int i = 0; i < n; i++) {
        cin >> p1[i];
        lo = min(lo, p1[i]);
        hi = max(hi, p1[i]);
        dist.pb(mp(p1[i], 1));
    }
    cin >> m;
    int p2[m];
    for (int i = 0; i < m; i++) {
        cin >> p2[i];
        lo = min(lo, p2[i]);
        hi = max(hi, p2[i]);
        dist.pb(mp(p2[i], 2));
    }

    sort(all(dist));
    int maxDif = 3 * (n - m);
    int maxA = -1;
    int curMax = 0;
    int biggest = 3 * n;
    for (int i = 0; i < n + m; i++) {
        pair<ll, int> p = dist[i];
        if (p.second == 1) {
            curMax -= 1;
            biggest--;
        } else {
            curMax += 1;
        }
        if (maxDif == curMax) {
        }
        if (curMax > maxDif) {
            maxDif = curMax;
            maxA = biggest;
        }
    }
    if (maxDif == 0)
        cout << (3 * n) << ":" << (3 * m) << endl;
    else
        cout << maxDif + biggest << ":" << biggest << endl;
}