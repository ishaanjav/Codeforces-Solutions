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

#include <string>
#include <vector>
typedef vector<int> vi;
typedef vector<ll> vl;
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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    ll k;
    cin >> k;
    ll g[n];

    for (int tr = 0; tr < n; tr++) {
        cin >> g[tr];
    }
    // My reasoning below is flawed
    // Before he puts the current garbage into bags, he should get rid of old garabage.

    ll doMe = 0;
    ll bags = 0;
    for (int i = 0; i < n; i++) {
        ll curGarbage = g[i];
        bags += curGarbage / k;
        curGarbage %= k;
        ll minBagsToUse = doMe / k;
        ll total = doMe + curGarbage;
        // if doMe is divisible by k then doMe gets all bags
        cout << bags << "  " << curGarbage << "  do me " << doMe << endl;
        if (doMe % k == 0 /* && doMe != 0 */) {
            // ll before = bags;
            // bags += doMe / k;
            // bags += (doMe % k == 1);
            // cout << "  added " << bags - before << endl;
            doMe = curGarbage;
            continue;
        }
        bags += doMe / k;
        cout << "   added " << doMe / k << endl;
        doMe %= k;
        if (curGarbage == 0) {
            if (doMe != 0)
                bags++;
            continue;
        }
        // doMe and curGarbage is between 1 to k - 1
        ll take = min(curGarbage, k - doMe);
        bags++;
        cout << "   added " << 1 << endl;
        doMe = curGarbage - take;
    }
    bags += doMe / k + (doMe % k == 1);
    cout << bags;
}
