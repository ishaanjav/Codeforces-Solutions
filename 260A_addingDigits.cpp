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
    bool possible = false;

    for (int i = 0; i <= 9; i++) {
        if ((a * 10 + i) % b == 0) {
            possible = true;
            a = a * 10 + i;
            break;
        }
    }
    if (possible) {
        cout << a;
        for (int i = 0; i < c - 1; i++) cout << "0";
        cout << endl;
    } else {
        cout << -1 << endl;
    }
}
