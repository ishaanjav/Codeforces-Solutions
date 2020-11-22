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

#include <string>
#include <vector>
typedef vector<int> vi;
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

/* ll d[10000001], a[10000001], b[10000001], c[10000001];
bool us[10000001]; */
/* unordered_map<ll, ll> d;
unordered_map<ll, ll> a;
unordered_map<ll, bool> us;
unordered_map<ll, bool> us2;
ll solve(ll steps, int loc) {
    if (us[steps] && loc == 4)
        return d[steps];
    else if (loc != 4 && us2[steps])
        return a[steps];
    if (steps == 0) return loc == 4;
    ll ans = 0;
    if (loc == 4) {
        ans = 3 * solve(steps - 1, 2);
    }
    if (loc != 4) {
        ans = 2 * solve(steps - 1, 2);
        ans += solve(steps - 1, 4);
    }  
    if (loc == 2) {
        ans = solve(steps - 1, 1);
        ans += solve(steps - 1, 3);
        ans += solve(steps - 1, 4);
    }
    if (loc == 3) {
        ans = solve(steps - 1, 2);
        ans += solve(steps - 1, 1);
        ans += solve(steps - 1, 4);
    } 
ans %= 1000000007;
if (loc == 4) {
    us[steps] = true;
    d[steps] = ans;
} else {
    us2[steps] = true;
    a[steps] = ans;
}
return ans;
}
*/
ll d[10000001], a[10000001];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;
    ll ans = 0;
    d[0] = 0;
    a[1] = 1;
    d[1] = 0;
    a[2] = 2;
    d[2] = 3;
    if (n <= 2)
        cout << d[n];
    else {
        for (int i = 3; i <= n; i++) {
            a[i] = (2 * a[i - 1] + d[i - 1]) % 1000000007;
            d[i] = (3 * a[i - 1]) % 1000000007;
        }
        cout << d[n] << endl;
    }
}
