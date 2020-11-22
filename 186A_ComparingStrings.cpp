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
#include <unordered_map>
//#include <cmath>
//#include <cstring>
//#include <sstream>
//#include <stack>
//#include <queue>
unordered_map<char, int> ma;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s1, s2;
    cin >> s1 >> s2;

    int differences = 0;
    char a, b;
    int x, y;
    if (s1.size() != s2.size()) {
        cout << "NO\n";
    } else {
        if (s1 == s2) {
            bool possible = false;
            for (int i = 0; s1.size(); i++) {
                ma[s1[i]]++;
                if (ma[s1[i]] > 1) {
                    possible = true;
                    break;
                }
                if (!possible)
                    cout << "NO\n";
                else
                    cout << "YES\n";
            }
        } else {
            bool possible = true;
            bool same = false;
            for (int i = 0; i < s1.size(); i++) {
                if (s1[i] == s2[i]) continue;
                if (differences == 0) {
                    a = s1[i];
                    x = i;
                } else {
                    y = i;
                    b = s1[i];
                }
                differences++;
                if (differences > 2) {
                    possible = false;
                    break;
                }
            }
            if (!possible)
                cout << "NO\n";
            else {
                possible &= a == s2[y];
                possible &= b == s2[x];
                // cout << x << " , " << y << "  " << a << " " << b << endl;
                if (!possible)
                    cout << "NO\n";
                else
                    cout << "YES\n";
            }
        }
    }
}
