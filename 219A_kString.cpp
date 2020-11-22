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

unordered_map<char, int> m;
int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (s.length() % n != 0) {
        cout << -1 << endl;
    } else {
        int si = s.length() / n;
        for (char c : s) {
            m[c]++;
        }
        bool possible = true;
        string t;
        for (auto p : m) {
            if (p.second % n != 0) possible = false;
            for (int i = 0; i < p.second / n; i++) {
                t += p.first;
            }
        }
        if (!possible)
            cout << -1 << endl;
        else {
            for (int i = 0; i < n; i++)
                cout << t;
            cout << endl;
        }
    }
}
