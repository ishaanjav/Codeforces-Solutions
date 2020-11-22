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
    cin >> n;
    ll smallest = 1e9, biggest = -1;
    ll pos = -1;
    for (int i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;
        if (smallest == a && biggest == b) pos = i + 1;
        if (smallest <= a && biggest >= b) continue;
        if (a <= smallest && biggest <= b) {
            pos = i + 1;
        } else {
            pos = -1;
        }
        smallest = min(smallest, a);
        biggest = max(biggest, b);
    }
    cout << pos;
}
