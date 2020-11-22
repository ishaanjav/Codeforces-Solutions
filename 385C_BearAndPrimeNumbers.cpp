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
#define fi first
#define se second
#define all(v) v.begin(), v.end()

#include <string>
#include <vector>
typedef vector<int> vi;
#include <algorithm>
#include <map>
#include <set>
//#include <unordered_set>
#include <unordered_map>
//#include <cmath>
#include <cstring>
//#include <sstream>
//#include <stack>
//#include <queue>
int n;
vi v;
ll maxVal = 0;
set<ll> u;
// vi primes;
int ocur[10000001];
void sieve() {
    int counter = 0;
    bool prime[maxVal + 1];
    memset(prime, true, sizeof(prime));
    prime[0] = prime[1] = false;
    for (int p = 2; p <= maxVal; p++) {
        if (!prime[p]) continue;
        // primes.pb(p);
        // u[p] = counter++;
        u.insert(p);
        for (int j = p * p; j <= maxVal; j += p)
            prime[j] = false;
    }
    // for (bool b : prime) cout << b << " ";
    // cout << "---\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    // v.resize(n);
    maxVal = -1;
    ll t;
    for (int tr = 0; tr < n; tr++) {
        cin >> t;
        maxVal = max(maxVal, t);
        ocur[t]++;
    }
    sieve();

    int m;
    cin >> m;
    // cout << " Primes: ";
    // for (ll l : u) cout << l << " ";
    // cout << "\n";
    while (m--) {
        ll a, b;
        cin >> a >> b;
        // cout << "  A: " << a << " " << b << endl;
        auto it = lower_bound(u.begin(), u.end(), a);
        auto last = upper_bound(u.begin(), u.end(), b);
        // last--;
        if (it == u.end())
            cout << "0\n";
        else {
            ll val = 0;
            // cout << distance(u.begin(), it) << endl;
            for (; it != last; it++) {
                ll prime = *it;
                // ll prime = 0;
                for (ll a = prime; a <= maxVal; a += prime) {
                    val += ocur[a];
                }
            }
            cout << val << "\n";
        }
    }
}
