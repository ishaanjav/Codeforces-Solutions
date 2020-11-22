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
#define pll pair<ll, ll>
#define pib pair<int, bool>
#define SET(a, c) memset(a, c, sizeof(a))
#define MOD 1000000007
#define Endl endl
#define endl "\n"
#define fi first
#define se second
#define rs resize
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define FOUND(u, val) u.find(val) != u.end()
#define max_self(a, b) a = max(a, b);
#define min_self(a, b) a = min(a, b);

#include <string>
#include <vector>
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<ll> vl;
typedef vector<bool> vb;
#include <algorithm>
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

    int n, m;
    cin >> n;
    int ar[n];
    for (int& x : ar) cin >> x;
    cin >> m;
    int ar2[m];
    for (int& x : ar2) cin >> x;
    sort(ar, ar + n);
    sort(ar2, ar2 + m);

    int i = 0;
    int co = 0, j = 0;
    for (; j < m && i < n; i++) {
        if (abs(ar[i] - ar2[j]) <= 1) {
            j++, co++;
            continue;
        }
        while (j < m && ar2[j] + 1 < ar[i]) j++;
        if (abs(ar[i] - ar2[j]) <= 1) {
            j++, co++;
            continue;
        }
    }
    cout << co;
}
