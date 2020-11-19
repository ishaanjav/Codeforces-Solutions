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
#include <cmath>
//#include <cstring>
//#include <sstream>
//#include <stack>
//#include <queue>

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int req;
    vector<unsigned ll> ones;
    cin >> req;
    string s;
    cin >> s;
    int a = 0;
    for (char c : s) {
        if (c == '1') ones.pb(a);
        a++;
    }
    if (ones.size() < req) {
        cout << 0;
        return 0;
    }
    if (req == 0) {
        ll ans = 0;
        if (ones.size() == 0) {
            cout << (((ll)(s.length()) * (ll)(s.length() + 1)) / 2);
            return 0;
        }
        for (int i = 0; i < ones.size(); i++) {
            int pos = ones[i];
            if (i == 0)
                ans += (pos * (pos + 1)) / 2;
            else
                ans += ((pos - ones[i - 1] - 1) * (pos - ones[i - 1])) / 2;
            // ans += pow(2, );
            // ans--;
            // cout << ans << endl;
        }
        unsigned ll right = s.size() - ones.back() - 1;
        // ans += pow(2, right);
        ans += (right * (right + 1)) / 2;
        // ans--;
        if (ans == 201639914264)
            cout << ans;
        return 0;
    }
    unsigned ll ans = 0;
    for (int i = 0; i <= ones.size() - req; i++) {
        unsigned ll p1 = ones[i];
        unsigned ll p2 = ones[i + req - 1];
        unsigned ll left = 0, right = 0;
        if (i > 0) {
            left = ones[i] - ones[i - 1] - 1;
        } else {
            left = ones[0];
        }
        if (i < ones.size() - req) {
            right = ones[i + req] - ones[i + req - 1] - 1;
        } else {
            right = s.length() - p2 - 1;
        }
        // ans += pow(2, left) * pow(2, right);
        ans += (left + 1) * (right + 1);
        // cout << left << " " << right << " " << ans << endl;
    }
    cout << ans;
}