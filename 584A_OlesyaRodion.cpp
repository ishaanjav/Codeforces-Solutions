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
#include <cmath>
//#include <cstring>
//#include <sstream>
//#include <stack>
//#include <queue>

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, t;
    cin >> n >> t;
    if (t == 10) {
        if (n == 1) {
            cout << -1 << endl;
        } else {
            cout << 1;
            for (int i = 1; i < n; i++) cout << "0";
            cout << endl;
        }
    } else {
        for (int i = 0; i < n; i++) cout << t;
        cout << endl;
    }
}
