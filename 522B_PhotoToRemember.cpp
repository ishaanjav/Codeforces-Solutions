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
#define FOUND(u, val) u.find(val) != u.end()
#define max_self(a, b) a = max(a, b);

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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    ll w[n], h[n];
    ll sum = 0;
    ll max1 = -1, max2 = -1;
    for (int tr = 0; tr < n; tr++) {
        cin >> w[tr] >> h[tr];
        if (h[tr] > max1) {
            max2 = max1;
            max1 = h[tr];
        } else if (h[tr] <= max1)
            max2 = max(max2, h[tr]);
        sum += w[tr];
    }
    for (int i = 0; i < n; i++) {
        ll width = sum - w[i];
        ll height = max1;
        if (h[i] == max1) height = max2;
        cout << width * height << " ";
    }
}
