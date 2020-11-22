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

int solve(vector<string> v, int i, int j) {
    if (i < 0 || i == v.size() || j < 0 || j == v[0].length()) return 0;
    return v[i][j] == 'P';
}
int xs[] = {1, -1, 0, 0};
int ys[] = {0, 0, -1, 1};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int rows, cols;
    cin >> rows >> cols;
    vector<string> v(rows);
    for (int i = 0; i < rows; i++) cin >> v[i];

    int amount = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            if (v[i][j] == 'W') {
                int temp = 0;
                for (int k = 0; k < 4; k++)
                    temp += solve(v, i + xs[k], ys[k] + j);

                amount += min(temp, 1);
            }
    }
    cout << amount << "\n";
}
