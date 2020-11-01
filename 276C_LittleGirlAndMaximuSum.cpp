#include <iostream>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair

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

ll cnt[200010];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    int q;
    cin >> n >> q;
    ll ar[n];
    for (int i = 0; i < n; i++) cin >> ar[i];
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        cnt[l - 1]++;
        cnt[r]--;
    }
    for (int i = 1; i < n; i++) cnt[i] += cnt[i - 1];
    sort(cnt, cnt + n);
    sort(ar, ar + n);
    ll res = 0;
    for (int i = n - 1; i >= 0; i--) {
        res += (ll)(ar[i]) * (ll)(cnt[i]);
    }
    cout << res << endl;
}