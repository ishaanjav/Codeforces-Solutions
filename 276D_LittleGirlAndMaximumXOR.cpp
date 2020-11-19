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

    ll l, r;
    cin >> l >> r;

    if (l == 1 && r == 1)
        cout << 0;
    else {
        ll n = 1, pow = 1;
        while (n < l) {
            pow *= 2;
            n = pow - 1;
        }
        ll x = 1;
        while (x < r) x *= 2;
        // if (x > r) x /= 2;
        cout << (x ^ n);
    }
}