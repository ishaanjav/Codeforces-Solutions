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
#define found(u, val) u.find(val) != u.end()

#include <string>
#include <vector>
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<bool> vb;
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

int maxCalculated = 0;
vl used;
void gen(ll n) {
    if (used.size() != 0 && n < used.back()) {
        return;
    }
    ll s = used.size() + 1;
    ll amount = 2 * s + ((s - 1) * (s)*3) / 2;
    used.pb(amount);
    gen(n);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (used.size() == 0 || used.back() < n) {
            gen(n);
        }
        int pos = used.size();
        int built = 0;
        while (--pos >= 0) {
            built += n / used[pos];
            n %= used[pos];
        }
        cout << built << endl;
    }
}
