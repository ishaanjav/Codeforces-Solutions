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
#define all(v) v.begin(), v.end()

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
    cin.tie(0);

    int ar[3][3];
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++) cin >> ar[i][j];

    int ans[3][3];
    ans[0][0] = ar[0][1] + ar[1][0];
    ans[0][1] = ar[0][0] + ar[1][1] + ar[0][2];
    ans[0][2] = ar[0][1] + ar[1][2];
    ans[1][0] = ar[0][0] + ar[1][1] + ar[2][0];
    ans[1][1] = ar[1][0] + ar[0][1] + ar[2][1] + ar[1][2];
    ans[1][2] = ar[1][1] + ar[0][2] + ar[2][2];
    ans[2][0] = ar[2][1] + ar[1][0];
    ans[2][1] = ar[2][0] + ar[1][1] + ar[2][2];
    ans[2][2] = ar[2][1] + ar[1][2];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            cout << (1 - (ans[i][j] + ar[i][j]) % 2);
        cout << endl;
    }
}
