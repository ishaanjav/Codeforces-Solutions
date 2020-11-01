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

    ll b = 0, s = 0, c = 0;
    string str;
    cin >> str;
    for (char t : str) {
        if (t == 'B')
            b++;
        else if (t == 'C')
            c++;
        else
            s++;
    }
    ll hasB, hasS, hasC;
    cin >> hasB >> hasS >> hasC;
    ll costB, costS, costC;
    cin >> costB >> costS >> costC;
    ll money;
    cin >> money;

    // ll maxCanBuy = 2 + (max((ll)hasB / (ll)b, max(hasS / (ll)s, hasC / (ll)c)) + money / (costB + costC + costS));
    ll hi = 3;
    ll lo = 0;
    ll ans = 0;
    // while (lo <= hi) {
    // ll mid = hi - (hi - lo) / 2;
    ll reqB, reqS, reqC;
    if (b == 0)
        reqB = 0, costB = 0;
    else
        reqB = (b - (hasB % b)) % b;
    if (s == 0)
        reqS = 0, costS = 0;
    else
        reqS = (s - (hasS % s)) % s;
    if (c == 0)
        reqC = 0, costC = 0;
    else
        reqC = (c - (hasC % c)) % c;

    ll initialCost = reqB * costB + reqS * costS + reqC * costC;
    ll total = initialCost;
    ll left = money - initialCost;
    if (left < 0) {
        // hi = mid - 1;
        ans = 0;
    } else if (left == 0) {
        // ans = mid;
        // break;
        if (b != 0)
            ans = (hasB + reqB) / (ll)b;
        else if (c != 0)
            ans = (hasC + reqC) / (ll)c;
        else
            ans = (hasS + reqS) / (ll)s;
    } else {
        //First try going one step farther.
        //cost for 1 round
        if (b != 0)
            ans = (hasB + reqB) / (ll)b;
        else if (c != 0)
            ans = (hasC + reqC) / (ll)c;
        else
            ans = (hasS + reqS) / (ll)s;
        ll oneRound = b * costB + s * costS + c * costC;

        ans += left / oneRound;
        // hi = mid + 1;
        // }
    }
    cout << ans << endl;
}