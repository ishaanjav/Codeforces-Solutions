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

    int n;
    ll time;
    cin >> n >> time;
    ll ar[n];
    ll prefix[n];
    prefix[0] = 0;
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
        if (i != 0)
            prefix[i] = prefix[i - 1] + ar[i];
        else
            prefix[i] = ar[i];
        // cout << prefix[i] << " ";
    }
    // cout << endl;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ll lookingFor = ar[i];
        if (lookingFor > time) continue;
        /* if (i == 0)
            lookingFor = time + ar[i];
        else
            lookingFor = time + prefix[i] - ar[i]; */
        if (i != 0)
            lookingFor = prefix[i - 1];
        else
            lookingFor = 0;

        ans = max(ans, (ll)1);
        // cout << "I : " << i << " Looking for: " << lookingFor << endl;
        int lo = i, hi = n - 1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (prefix[mid] - lookingFor <= time) {
                ans = max(ans, (ll)(mid - i + 1));
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
    }
    cout << ans << endl;
}
