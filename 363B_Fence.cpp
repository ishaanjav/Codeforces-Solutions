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

    int n, k;
    cin >> n >> k;
    int ar[n];
    int ans = 0;
    for (int tr = 0; tr < n; tr++) {
        cin >> ar[tr];
        if (tr < k) ans += ar[tr];
    }

    int cur = ans;
    int pos = 1;
    for (int i = 1; i <= n - k; i++) {
        cur -= ar[i - 1];
        cur += ar[i + k - 1];
        if (cur < ans)
            ans = cur, pos = i + 1;
    }

    cout << pos;
}
