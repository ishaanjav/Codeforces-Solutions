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

    int rows, cols;
    cin >> rows >> cols;
    string ar[rows];
    for (int i = 0; i < rows; i++) cin >> ar[i];

    bool skip[cols];
    memset(skip, false, sizeof(skip));
    int de = 0;
    for (int j = 0; j < cols; j++) {
        if (skip[j]) continue;
        int pos = 0;
        for (int i = 1; i < rows; i++) {
            string prev = ar[i - 1];
            string cur = ar[i];
            if (prev[j] < cur[j])
                continue;
            else if (prev[j] > cur[j]) {
                skip[j] = 1;
                cout <<i << " " << j << "  Skip: " << j <<endl;
                break;
            }
            int k;
            bool remove = false;
            for (k = 0; k < cols; k++) {
                if (skip[k]) continue;
                if (prev[k] == cur[k]) continue;
                if (prev[k] < cur[k])
                    break;
                else {
                    remove = true;
                    break;
                }
            }
            if (remove) {
                cout <<i << " " << j << "  Skip: " << k <<endl;
                skip[k] = true;
                if (k == j) break;
            }
        }
    }
    for (bool b : skip) {
        cout << b << " ";
        de += b;
    }
    cout << endl;
    cout << de << endl;
}
