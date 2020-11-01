#include <iostream>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair

#include <string>
#include <vector>
typedef vector<int> vi;
#include <algorithm>
//#include <set>
//#include <map>
//#include <unordered_set>
//#include <unordered_map>
#include <cmath>
//#include <cstring>
//#include <sstream>
//#include <stack>
//#include <queue>

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll a, b, c;
    cin >> a >> b >> c;

    vector<ll> ans;
    for (int i = 1; i <= 81; i++) {
        ll num = b * pow((ll)(i), a) + c;
        ll digitSum = 0;
        ll orig = num;
        while (num > 0) {
            digitSum += num % 10;
            num /= 10;
        }
        if (digitSum == i) {
            ans.pb(orig);
        }
    }
    cout << ans.size() << endl;
    if (ans.size() != 0) {
        sort(ans.begin(), ans.end());
        for (ll l : ans) {
            cout << l << " ";
        }
        cout << endl;
    }
}