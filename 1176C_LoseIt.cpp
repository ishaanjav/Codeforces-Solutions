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

    int n;
    cin >> n;
    int ar[n];
    for (int& x : ar) cin >> x;

    int f[] = {4, 8, 15, 16, 23, 42};
    int d = 0;
    int a[6] = {0};
    vi rooms;
    int last[] = {-1, -1, -1, -1, -1, -1};

    vvi r(6);
    for (int i = 0; i < n; i++) {
        int v = ar[i];
        bool added = false;
        int p = 0;
        for (int k : f) {
            if (k == v) break;
            p++;
        }
        if (p == 0) {
            r[p].pb(1);
            continue;
        }
        if (r[p - 1].size() == 0) {
            continue;
        }
        r[p - 1].pop_back();
        // r[p - 1].erase(r[p - 1].begi);
        r[p].pb(1);
        // for (int& k : rooms) {
        //     if (k == 5 || f[k + 1] != v) continue;
        //     added = true;
        //     k++;
        //     break;
        // }
        // if (!added && f[0] == v) {
        //     rooms.pb(distance(f + 0, find(f, f + 6, v)));
        // }
        // if (ar[i] == f[d]) {
        //     a[d]++;
        //     d++;
        //     d %= 6;
        // }
        // for (int j = 0; j < min(d, 6); j++) {
        //     if (ar[i] == f[j]) a[j]++;
        // }
    }
    // int t = 0;
    // for (int i : a) {
    //     cout << i << " ";
    //     min_self(t, i);
    // }
    // cout << n - t * 6 << endl;
    int good = 0;
    for (int i : rooms) {
        if (i == 5) good += 6;
        // if(i != 5)
        // cout << i << endl;
    }
    cout << n - r[5].size() * 6;
}
