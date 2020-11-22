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

    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int prev = s[0] - 'A';
    int changes = 0;
    string ans = "";
    ans += s[0];
    if (n == 1) {
        cout << "0\n" + s;
        return 0;
    }
    for (int i = 1; i < n - 1; i++) {
        int back = ans[i - 1] - 'A', front = s[i + 1] - 'A';
        int cur = s[i] - 'A';
        if (cur != back && cur != front) {
            ans += s[i];
            continue;
        }
        changes++;
        if (cur == back && cur == front) {
            if (back == 0)
                ans += 'B';
            else
                ans += 'A';
            continue;
        }
        int available = 0;
        if (k == 2) {
            if (back == cur) {
                if (back == 0)
                    ans += 'B';
                else
                    ans += 'A';
            } else {
                ans += s[i];
                /* if (front == 0)
                    ans += 'B';
                else
                    ans += 'A';
                     */
                changes--;
            }
            continue;
        }
        if (back != cur && front == cur) {
            changes--;
            ans += s[i];
            continue;
        }
        for (int i = 0; i < 3; i++) {
            if (back != i && front != i) {
                cur = i;
                break;
            }
        }
        ans += 'A' + cur;
    }
    if (s[n - 1] == ans[n - 2]) {
        changes++;
        if (ans[n - 2] == 'A')
            ans += 'B';
        else
            ans += 'A';
    } else
        ans += s[n - 1];
    cout << changes << "\n"
         << ans;
}
