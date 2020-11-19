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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n, m;
    cin >> n >> m;

    int minIsolated = max(0ll, n - 2 * m);
    vector<ll> dp;
    // dp.pb(0);
    dp.pb(0);
    int largest = 0;
    if (m != 0)
        for (int i = 1; i < 100000; i++) {
            dp.pb(dp.back() + i);
            if (dp.back() >= m) {
                largest = i;
                break;
            }
        }
        else largest = -1;
    largest++;
    // cout << largest << " " << dp[largest - 1] << endl;
    int maxIsolated = min(n, n - largest);
    cout << minIsolated << " " << maxIsolated << "\n";
}