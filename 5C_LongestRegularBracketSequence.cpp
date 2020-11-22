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
#define FOUND(u, val) u.find(val) != u.end()
#define max_self(a, b) a = max(a, b);

#include <string>
#include <vector>
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<bool> vb;
//#include <algorithm>
//#include <set>
//#include <map>
//#include <unordered_set>
//#include <unordered_map>
//#include <cmath>
//#include <cstring>
//#include <sstream>
#include <stack>
//#include <queue>

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string str;
    cin >> str;
    stack<char> s;
    int best = 0, freq = 0;
    int o = 0;
    int soFar = 0;
    for (char c : str) {
        if (c == '(') {
            s.push('C');
            o++;
            soFar++;
        } else {
            if (s.size() != 0) {
                s.pop();
                soFar++;
                if (s.size() == 0) {
                    /* int length = o * 2;
                    if (length > best)
                        best = length, freq = 1;
                    else if (length == best)
                        freq++;

                    o = 0; */
                    int length = soFar;
                    if (length > best)
                        best = length, freq = 1;
                    else if (length == best)
                        freq++;
                }
            } else {
                soFar = 0;
            }
        }
    }
    max_self(freq, 1);
    cout << best << " " << freq << endl;
}
