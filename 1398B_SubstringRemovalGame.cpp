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

    int n;
    cin >> n;

    for (int tr = 0; tr < n; tr++) {
        string s;
        cin >> s;
        vi v;
        int ones = 0;
        for (char c : s) {
            if (c == '0') {
                if (ones != 0) v.pb(ones);
                ones = 0;
            } else {
                ones++;
            }
        }
        if (ones != 0) v.pb(ones);
        sort(all(v));

        int score = 0;
        for (int i = v.size() - 1; i >= 0; i -= 2) {
            score += v[i];
        }
        cout << score << endl;
    }
}
