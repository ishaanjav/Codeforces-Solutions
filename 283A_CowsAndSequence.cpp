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

    int q;
    cin >> q;

    vector<double> v;
    v.pb(0);
    double sum = 0;
    double n = 1;
    while (q--) {
        int a;
        cin >> a;
        if (a == 3) {
            sum -= v.back();
            v.pop_back();
            n--;
        } else if (a == 1) {
            double b, x;
            cin >> b >> x;
            sum += b * x;
            for (int i = 0; i < b; i++) v[i] += x;
        } else if (a == 2) {
            double a;
            cin >> a;
            v.pb(a);
            sum += a;
            n++;
        }
        printf("%.6f\n", (sum / n));
    }
}
