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
#include <queue>

/* 
3 4
AAAA
ABCA
AAAA
 */
bool visited[51][51];
int rows, cols;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> rows >> cols;

    char grid[rows][cols];

    for (int tr = 0; tr < rows; tr++) {
        for (int i = 0; i < cols; i++) cin >> grid[tr][i];
    }

    int xs[] = {1, -1, 0, 0};
    int ys[] = {0, 0, -1, 1};
    bool possible = false;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (visited[i][j]) continue;
            queue<pair<pair<int, int>, pair<int, int> > > q;
            q.push(mp(mp(i, j), mp(i, j)));
            char orig = grid[i][j];
            while (!q.empty()) {
                pair<int, int> u = q.front().first;
                pair<int, int> prev = q.front().second;
                q.pop();
                int r = u.first, c = u.second;
                if (r < 0 || c < 0 || r >= rows || c >= cols || grid[r][c] != orig) continue;
                if (visited[r][c]) {
                    possible = true;
                    // cout << "Possible  " << orig << " " << r << " " << c << endl;
                    break;
                }
                visited[r][c] = 1;
                for (int i = 0; i < 4; i++) {
                    if (prev.first == r + xs[i] && prev.second == c + ys[i]) continue;
                    // cout << " adding " << r + xs[i] << " " << c + ys[i] << endl;
                    q.push(mp(mp(r + xs[i], c + ys[i]), u));
                }
            }
            if (possible) break;
        }
        if (possible) break;
    }

    cout << (possible ? "Yes" : "No");
}
