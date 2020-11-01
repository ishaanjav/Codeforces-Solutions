#include <iostream>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair

#include <algorithm>
#include <string>
#include <vector>
typedef vector<int> vi;
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

    int g[5][5];
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            cin >> g[i][j];
    int p[] = {0, 1, 2, 3, 4};
    int tmp, ans = 0;
    for (int i = 0; i < 120; i++) {
        tmp = g[p[0]][p[1]] + g[p[1]][p[0]];
        tmp += g[p[2]][p[3]] + g[p[3]][p[2]];

        //1234
        tmp += g[p[1]][p[2]] + g[p[2]][p[1]];
        tmp += g[p[3]][p[4]] + g[p[4]][p[3]];

        //234
        tmp += g[p[2]][p[3]] + g[p[3]][p[2]];

        //34
        tmp += g[p[3]][p[4]] + g[p[4]][p[3]];
        if (tmp > ans) {
            ans = tmp;
        }
        next_permutation(p, p + 5);
    }
    cout << ans << endl;
}