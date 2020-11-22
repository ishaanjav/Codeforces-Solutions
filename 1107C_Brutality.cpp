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

/* 
7 3
1 5 16 18 7 2 10
baaaaca

 */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vl scores;
    swap(m, n);
    scores.resize(m);
    for (int i = 0; i < m; i++) cin >> scores[i];
    vector<vl> v;
    vl t;
    string s;
    cin >> s;

    char prev = s[0];
    t.pb(scores[0]);
    for (int i = 1; i < m; i++) {
        if (s[i] == prev) {
            t.pb(scores[i]);
        } else {
            prev = s[i];
            v.pb(t);
            t.clear();
            t.pb(scores[i]);
        }
    }
    v.pb(t);
    ll damage = 0;
    for (vl a : v) {
        sort(all(a));
        // for (ll as : a) cout << "   " << as << endl;
        ll si = (ll)(a.size());
        /*  cout << a.size() - 1 << " , " << (si - n - 1) << endl;
        cout << endl; */
        for (int i = a.size() - 1; i >= max(0ll, si - n); i--) {
            damage += a[i];
        }
    }
    cout << damage;
}
