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
//#include <unordered_map>
//#include <cmath>
#include <cstring>
//#include <sstream>
//#include <stack>
//#include <queue>
bool prime[1000001];
void sieve() {
    memset(prime, 1, sizeof(prime));
    prime[2] = 1;
    for (int p = 2; p <= 1001; p++) {
        if (!prime[p]) continue;
        for (int j = p * p; j <= 1000000; j += p)
            prime[j] = 0;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;
    sieve();
    for (ll i = 2; i <= n; i++) {
        if (!prime[i] && !prime[n - i]) {
            cout << i << " " << n - i << endl;
            break;
        }
    }
}
