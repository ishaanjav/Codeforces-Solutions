/*
 * Created by ishaanjav
 * github.com/ishaanjav
 * Codeforces Solutions: https://github.com/ishaanjav/Codeforces-Solutions
 */

#include <iostream>

using namespace std;
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

bool b[200000];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    bool repetitive = false;
    int first = 0;
    char prev = 0;
    int counter = 0;
    bool f = false;
    string ans = s.substr(0, min((int)s.length(), 2));
    int p1 = 0, p2 = 1;
    for (int i = 2; i < s.length(); i++) {
        if (s[i] == s[p1] && s[i] == s[p2]) {
        } else if (i > 2 && s[i] == s[p1] && s[p2] == s[p2 - 1]) {
        } else {
            ans += s[i];
            p1 = p2;
            p2 = i;
        }
    }

    cout << ans << endl;
}
