#include <iostream>
using namespace std;
#include <algorithm>
/* 
9 2
6 19 3 4 4 2 6 7 8
 */
// 2 3 4 4 6 6 7 8 19

// 2
// 2 34
// 2 34 46
// 2 7
// 2 7 10
// 11 30
// Need to add previous again
// 2 * 2 + 7 * 1
// 2 * 3 + 7 * 2 + 10 * 1
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    ll ar[n];
    for (int tr = 0; tr < n; tr++)
        cin >> ar[tr];
    sort(ar, ar + n);

    ll prefix[n + 1];
    prefix[0] = 0;
    for (int i = 1; i <= n; i++)
        prefix[i] = prefix[i - 1] + ar[i - 1];

    pair<int, ll> ans[n + 1];
    for (int i = 1; i <= m; i++) {
        ans[i] = make_pair(i, prefix[i]);
        int c = 1;
        ll count = prefix[i];
        for (int j = i + m; j <= n; j += m) {
            ans[j] = make_pair(j, ans[j - m].second + count + prefix[j] - prefix[j - m]);
            count += prefix[j] - prefix[j - m];
        }
    }
    sort(ans, ans + n);
    for (int i = 1; i <= n; i++)
        cout << ans[i].second << " ";
}