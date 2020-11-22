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
#include <cstring>
//#include <sstream>
//#include <stack>
// #include <queue>

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int rows, cols;
    cin >> rows >> cols;
    char grid[rows][cols];
    bool convex = true;
    int x = -1, y;
    for (int tr = 0; tr < rows; tr++) {
        for (int t = 0; t < cols; t++) {
            cin >> grid[tr][t];
            if (grid[tr][t] == 'B') {
                x = tr, y = t;
            }
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == 'W') continue;
            for (int a = 0; a < rows; a++) {
                for (int b = 0; b < cols; b++) {
                    if (a == i && b == j || grid[a][b] == 'W') continue;
                    //Check if there is a path between the squares.
                    bool result = true;

                    int w = i, x = j, y = a, z = b;
                    if (a < i) {
                        swap(w, y);
                        swap(x, z);
                    }

                    for (int k = w; k < y; k++) {
                        if (grid[k][x] != 'B') {
                            result = false;
                            break;
                        }
                    }

                        convex = result;
                    if (!convex) break;
                }
                if (!convex) break;
            }
            if (!convex) break;
        }
        if (!convex) break;
    }

    if (!convex)
        cout << "NO";
    else
        cout << "YES";
}
/*  // if (convex) {
    bool visited[rows][cols];
    memset(visited, false, sizeof(visited));
    queue<pair<int, int> > q;
    if (x == -1) {
        convex = true;
    } else {
        q.push(mp(x, y));
        int xs[] = {1, -1, 0, 0};
        int ys[] = {0, 0, 1, -1};
        // cout << x << " " << y << endl;
        while (!q.empty()) {
            pair<int, int> u = q.front();
            q.pop();
            if (u.first < 0 || u.second < 0 || u.first == rows || u.second == cols || visited[u.first][u.second] || grid[u.first][u.second] == 'W') continue;
            visited[u.first][u.second] = 1;
            // cout << "At " << u.first << " " << u.second << endl;
            for (int i = 0; i < 4; i++)
                q.push(mp(u.first + xs[i], u.second + ys[i]));
        }
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                char cur = grid[i][j];
                if (cur == 'B') {
                    if (!visited[i][j]) {
                        convex = false;
                        break;
                    }
                    continue;
                }
                int black = 0;
                if (i != 0) black += grid[i - 1][j] == 'B';
                if (i != rows - 1) black += grid[i + 1][j] == 'B';
                if (j != 0) black += grid[i][j - 1] == 'B';
                if (j != cols - 1) black += grid[i][j + 1] == 'B';
                if (black >= 3) {
                    convex = false;
                    break;
                }
            }
            if (!convex) break;
        }
    }
    // }

    if (!convex)
        cout << "NO";
    else
        cout << "YES";
} */
