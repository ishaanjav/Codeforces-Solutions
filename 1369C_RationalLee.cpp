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

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        ll sum = 0;
        vector<ll> ar(n);
        for (ll &x : ar) cin >> x;
        sort(all(ar));
        vi friends(k);
        for (int i = 0; i < k; i++) cin >> friends[i];
        sort(all(friends));
        int to = 100000000;
        int at = 0;
        for (int i = 0; i < k; i++) {
            int f = friends[i];
            sum += ar[n - 1 - i];
            if (f == 1)
                sum += ar[n - 1 - i];
            else {
                sum += ar[at];
                at += f - 1;
            }
            // min_self(to, i);
        }
        // ar.resize(n - k);
        cout << sum << endl;
    }
}
