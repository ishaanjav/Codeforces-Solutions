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

    string s;
    int n;
    cin >> s >> n;
    int ans = 1;
    for (int i = 0; i < n; i++) s += "?";
    for (int length = 2; length <= s.length(); length+=2) {
        for (int pos = 0; pos <= s.length() - length; pos++) {
            string a1 = s.substr(pos, length / 2), a2 = s.substr(pos + length / 2, length / 2);
            bool good = true;
            for (int i = 0; i < a1.length(); i++) {
                if (a2[i] == '?') break;
                if (a2[i] != a1[i]) {
                    good = false;
                    break;
                }
            }
            if (good) {
                ans = max(ans, length);
                break;
            }
        }
    }
    cout << ((ans/2) * 2) << "\n";
}