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

bool rBad[11];
bool cBad[11];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int rows, cols;
    cin >> rows >> cols;
    char grid[rows][cols];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'S') {
                rBad[i] = true;
                cBad[j] = true;
            }
        }
    }

    int counter = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (!rBad[i] || !cBad[j]) counter++;
        }
    }
    cout << counter << endl;
}
