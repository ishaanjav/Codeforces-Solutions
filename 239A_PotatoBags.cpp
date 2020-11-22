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

    ll y, k, n;
    cin >> y >> k >> n;
    bool possible = true;

    ll smallest = max(1ll, (k - y % k));
    if (smallest + y <= n) {
        while (smallest  + y<= n) {
            cout << smallest << " ";
            smallest += k;
        }
    } else
        cout << -1;
}
