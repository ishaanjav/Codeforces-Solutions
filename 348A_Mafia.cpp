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
    ll biggest = 0;
    ll ar[n];
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
        sum += ar[i];
        biggest = max(ar[i], biggest);
    }

    ll lo = biggest;
    ll hi = 1e10;
    ll best = 1e10;
    while (lo <= hi) {
        ll x = lo + (hi - lo) / 2;
        if (x <= n * x - sum) {
            hi = x - 1;
            best = x;
        } else
            lo = x + 1;
    }
    cout << best;
}
