/*
 * Created by ishaanjav
 * github.com/ishaanjav
 * Codeforces Solutions: https://github.com/ishaanjav/Codeforces-Solutions
 */

#include <iostream>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(v) v.begin(), v.end()

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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n, k;
    cin >> n >> k;
    ll ar[n];
    for (int i = 0; i < n; i++) cin >> ar[i];
    sort(ar, ar + n);

    ll pre[n];
    pre[0] = ar[0];
    for (int i = 1; i < n; i++) pre[i] = pre[i - 1] + ar[i];

    ll ans = 1, num = ar[0];
    for (int i = 0; i < n; i++) {
        ll lo = 0, hi = i - 1;
        ll tempLongest = 1, cur = ar[i];
        while (lo <= hi) {
            ll mid = (lo + hi) / 2;
            ll distFromI = i - mid;
            ll intervalSum;
            if (mid == 0)
                intervalSum = pre[i - 1];
            else
                intervalSum = pre[i - 1] - pre[mid - 1];
            ll toRaise = distFromI * ar[i] - intervalSum;
            if (toRaise > k) {
                //Change is too much.
                lo = mid + 1;
            } else {
                if (distFromI + 1 > tempLongest)
                    tempLongest = distFromI + 1;
                hi = mid - 1;
            }
        }
        if (tempLongest > ans)
            ans = tempLongest, num = ar[i];
        else if (tempLongest == ans)
            num = min(num, ar[i]);
    }
    cout << ans << " " << num;
}
