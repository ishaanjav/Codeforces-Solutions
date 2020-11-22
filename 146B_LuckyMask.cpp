/*
 * Created by ishaanjav
 * github.com/ishaanjav
 * Codeforces Solutions: https://github.com/ishaanjav/Codeforces-Solutions
 */

#include <iostream>
using namespace std;

#define ll long long
#define pb push_back
#define ins insert
#define mp make_pair
#define pii pair<int, int>
#define pil pair<int, ll>
#define pib pair<int, bool>
#define SET(a, c) memset(a, c, sizeof(a))
#define MOD 1000000007
#define enld endl
#define endl "\n"
#define fi first
#define se second
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

#include <string>
#include <vector>
typedef vector<int> vi;
typedef vector<ll> vl;
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
bool works(int i, int b) {
    string s = to_string(i);
    string t = to_string(b);
    int fours = 0, sevens = 0;
    int tf = 0, ts = 0;
    /* for (char c : t) {
        if (c - '0' == 4) tf++;
        if (c - '0' == 7) ts++;
    }
    for (char c : s) {
        if (c - '0' == 4) fours++;
        if (c - '0' == 7) sevens++;
    } */
    int p = 0;
    for (int i = 0; i < s.length(); i++) {
        int j = s[i] - '0';
        if (j != 4 && j != 7) continue;
        if (p == t.length()) return false;
        if (j == 4 && t[p] == '4') {
            p++;
        } else if (j == 7 && t[p] == '7') {
            p++;
        } else {
            return false;
        }
    }
    // if (fours == tf && sevens == ts) return true;
    return p == t.length();
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, b;
    cin >> n >> b;
    if (b > n) {
        cout << b;
        return 0;
    }
    /* string s = to_string(n);
    string t = to_string(b);
    string both = s.substr(0, s.length() - t.length()) + t;
    int fours = 0, sevens = 0;
    int tf = 0, ts = 0;
    for (char c : t) {
        if (c - '0' == 4) tf++;
        if (c - '0' == 7) ts++;
    }
    for (char c : both) {
        if (c - '0' == 4) fours++;
        if (c - '0' == 7) sevens++;
    }
    reverse(both.begin(), both.end());
    for (char &c : both) {
        if (c - '0' == 4 && fours-- > tf) c = '5';
        if (c - '0' == 7 && sevens-- > tf) c = '7';
    }
    reverse(both.begin(), both.end());
    cout << both; */
    int i;
    for (i = n + 1; i <= 1e6; i++) {
        if (works(i, b)) break;
    }
    cout << i;
    // cout << s.substr(0, s.length() - t.length()) << t;
}
