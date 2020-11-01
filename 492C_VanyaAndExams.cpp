#include <iostream>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second

#include <string>
#include <vector>
typedef vector<int> vi;
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

int n;
ll r, avg;
bool comp(pair<ll, ll> a, pair<ll, ll> b) {
    if (a.first == r)
        return 0;
    else if (b.first == r)
        return 1;
    if (a.second != b.second) return a.second < b.second;
    return a.first < b.first;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> r >> avg;
    vector<pair<ll, ll> > v(n);
    ll target = n * avg;
    ll cur = 0;
    for (int i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;
        v[i] = mp(a, b);
        cur += a;
    }

    sort(v.begin(), v.end(), comp);

    ll essays = 0;
    int pos = 0;
    while (cur < target) {
        pair<ll, ll> p = v[pos];
        ll dif = target - cur;
        ll take = min(dif, r - p.first);
        essays += take * p.second;
        cur += take;
        if (p.first + take == r) {
            pos++;
        } else
            p.first += take;
    }
    cout << essays << "\n";
}