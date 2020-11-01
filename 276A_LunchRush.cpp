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

    ll n, time;
    cin >> n >> time;
    ll ans = LONG_MIN;
    for (int tr = 0; tr < n; tr++) {
        ll f, t;
        cin >> f >> t;
        if (t <= time) {
            ans = max(ans, f);
        } else {
            ans = max(ans, f - (t - time));
        }
    }
    cout << ans << endl;
}