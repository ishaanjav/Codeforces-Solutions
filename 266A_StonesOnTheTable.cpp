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

    int nam;
    cin >> nam;
    int n = nam;
    string s;
    cin >> s;

    char first = s[0];
    int ans = 0;
    for (int i = 1; i < s.length(); i++) {
        if (first == s[i]) {
            ans++;
        } else {
            first = s[i];
        }
    }
    cout << ans << endl;
}
