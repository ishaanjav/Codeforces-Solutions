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

    int n;
    cin >> n;
    ll ar[n];
    ll left[n + 1];
    ll right[n + 1];
    for (int tr = 0; tr < n; tr++) {
        ll a;
        cin >> a;
        ar[tr] = a;
    }
    left[0] = ar[0] >= 0;
    right[n] = ar[n - 1] <= 0;
    for (int i = 1; i <= n; i++) {
        left[i] = left[i - 1];
        if (ar[i - 1] >= 0) left[i]++;
    }
    for (int i = n - 1; i >= 0; i--) {
        right[i] = right[i + 1];
        if (ar[i] <= 0) right[i]++;
    }
    ll ans = 1e5;
    for (int i = 0; i <= n; i++) {
        ans = min(ans, right[i] + left[i]);
    }
    cout << ans;
}