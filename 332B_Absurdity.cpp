#include <iostream>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair

#include <string>
#include <vector>
typedef vector<int> vi;
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
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    ll ar[n];
    for (int i = 0; i < n; i++) cin >> ar[i];

    int p1, p2;
    ll sliding[n - k + 1];
    for (int i = 0; i < k; i++) {
        sliding[0] += ar[i];
    }
    int c = 1;

    pair<ll, int> dp[n - k + 1];
    // dp[0] = 0;
    for (int i = k; i < n; i++) {
        sliding[i - k + 1] = sliding[i - k] + ar[i] - ar[i - k];
    }
    dp[n - k] = mp(0, n + 1);
    cout << sliding[0] << "----\n";
    c = n - k;
    int track = n - k + 1;
    for (int i = n - 1 - k; i >= 0; i--) {
        if (dp[i + 1].first > sliding[c--]) {
            dp[i] = mp(dp[i + 1].first, dp[i + 1].second);
            cout << dp[i + 1].first << " =|= " << dp[i + 1].second << endl;
        } else {
            dp[i] = mp(sliding[c], track);
            cout << sliding[c] << " == " << track << endl;
        }
        cout << c << endl;
        // cout << track << " , " << dp[i].second << endl;
        track--;
    }
    int counter = 0;
    ll ans = 0;
    int a, b;
    for (int i = 0; i < n - k + 1 - k; i++) {
        if (sliding[i] + dp[i].first > ans) {
            ans = sliding[i] + dp[i].first;
            a = i + 1;
            b = dp[i].second;
        }
    }
    /* for (int i : dp) {
        ans = max(sliding[counter] + i, ans);
        counter++;
    } */
    cout << "ANS: " << ans << " , " << a << " " << b << "\n";
    for (pair<ll, int> i : dp) cout << i.first << " " << i.second << "  ";
    cout << endl;
    for (int i : sliding) cout << i << " ";
    cout << endl;
}