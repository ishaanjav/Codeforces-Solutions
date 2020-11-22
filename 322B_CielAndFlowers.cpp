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

    ll a, b, c;
    cin >> a >> b >> c;

    ll o1, o2, o3, o4;
    o1 = o2 = o3 = o4 = -1;
    o1 = a / 3 + b / 3 + c / 3;
    if (a > 0 && b > 0 && c > 0) {
        o2 = 1 + (a - 1) / 3 + (b - 1) / 3 + (c - 1) / 3;
    }
    if (a > 1 && b > 1 && c > 1) {
        o3 = 2 + (a - 2) / 3 + (b - 2) / 3 + (c - 2) / 3;
    }
    if (a > 2 && b > 2 && c > 2) {
        o4 = 3 + (a - 3) / 3 + (b - 3) / 3 + (c - 3) / 3;
    }
    if (a < 3 && b < 3 && c < 3)
        cout << "0\n";
    else
        cout << max(o1, max(o2, max(o3, o4))) << endl;
}
