#include <iostream>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pil pair<int, ll>
#define SET(a, c) memset(a, c, sizeof a)
#define MOD 1000000007
#define enld endl
#define endl "\n"
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

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        ll ar[n];
        for (int i = 0; i < n; i++) cin >> ar[i];

        if (n < 3) {
            cout << "-1\n";
            continue;
        }
        sort(ar, ar + n);
        ll i1 = -1, i2 = -1, i3 = -1;
        i1 = 0, i2 = 1, i3 = n - 1;
        bool found = false;
        for (int i = 1; i < n - 1; i++) {
            i2 = i;
            if (ar[i1] + ar[i2] <= ar[i3]) {
                found = true;
                break;
            }
        }
        if (!found)
            cout << "-1\n";
        else
            cout << i1 + 1 << " " << i2 + 1 << " " << i3 + 1 << "\n";
    }
}