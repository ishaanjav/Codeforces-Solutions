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

    int x, y, w, z;
    cin >> x >> y >> w >> x;
    cout << x;
    int d;
    cin >> d;
    int c = 0;
    for (int i = 1; i <= d; i++) {
        if ((i % x == 0) || (i % y == 0) || (i % w == 0) || (i % z == 0)) c++;
    }
    cout << c << endl;
}
