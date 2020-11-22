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
    cin.tie(NULL);

    int strength, n;
    cin >> strength >> n;

    vector<pair<int, int> > v;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v.pb(mp(a, b));
    }

    sort(v.begin(), v.end());
    bool possible = true;
    for (int i = 0; i < n; i++) {
        if (strength > v[i].first) {
            strength += v[i].second;
        } else {
            possible = false;
            break;
        }
    }
    cout << (possible ?"YES":"NO");
}
