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
#include <unordered_map>
//#include <cmath>
//#include <cstring>
//#include <sstream>
//#include <stack>
//#include <queue>

unordered_map<string, bool> u;
bool solve(string n) {
    if (u.find(n) != u.end()) return u[n];
    if (n.length() == 0) return true;
    bool possible = false;
    if (n.substr(0, 1) == "1") {
        possible |= solve(n.substr(1, n.size() - 1));
        if (possible) {
            u[n] = true;
            return true;
        }
    }
    if (n.substr(0, 2) == "14") {
        possible = solve(n.substr(2, n.size() - 2));
        if (possible) {
            u[n] = true;
            return true;
        }
    }
    if (n.substr(0, 3) == "144") {
        possible = solve(n.substr(3, n.size() - 3));
        if (possible) {
            u[n] = true;
            return true;
        }
    }
    return false;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string n;
    cin >> n;
    cout << (solve(n) ? "YES" : "NO");
}