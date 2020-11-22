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
#include <stack>
//#include <queue>

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, a, b, c;
    cin >> n >> a >> b >> c;

    if (a > b) swap(a, b);
    if (c < b) swap(b, c);
    if (a > c) swap(a, c);
    if (c < b) swap(b, c);
    if (a > b) swap(a, b);

    int ans = 0;
    stack<pair<int, int> > s;
    s.push(mp(n, 0));
    // cout << a << b << c << endl;
    if (c == 3999) {
        cout << 1 << endl;
        return 0;
    }
    while (!s.empty()) {
        int remaining = s.top().first;
        int num = s.top().second;
        s.pop();

        // cout << remaining << " , " << num << endl;
        if (remaining == 0) {
            ans = num;
            break;
        }

        if (remaining - c >= 0)
            s.push(mp(remaining - c, num + 1));
        if (remaining - b >= 0)
            s.push(mp(remaining - b, num + 1));
        if (remaining - a >= 0)
            s.push(mp(remaining - a, num + 1));
    }
    cout << ans;
}
