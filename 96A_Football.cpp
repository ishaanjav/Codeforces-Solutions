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

    string s;
    cin >> s;
    int maxSoFar = 0;
    int cur = 0;
    char prev = s[0];
    for (char c : s) {
        if (c == prev) {
            cur++;
        } else {
            prev = c;
            cur = 1;
        }
        if (cur >= 7) break;
    }

    if (cur < 7)
        cout << "NO\n";
    else
        cout << "YES\n";
}