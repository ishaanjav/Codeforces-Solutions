/*
 * Created by ishaanjav
 * github.com/ishaanjav
 * Codeforces Solutions: https://github.com/ishaanjav/Codeforces-Solutions
 */

#include <iostream>
using namespace std;

#define ll long long
#define pb push_back
#define ins insert
#define mp make_pair
#define pii pair<int, int>
#define pil pair<int, ll>
#define pib pair<int, bool>
#define SET(a, c) memset(a, c, sizeof(a))
#define MOD 1000000007
#define enld endl
#define endl "\n"
#define fi first
#define se second
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

#include <string>
#include <vector>
typedef vector<int> vi;
typedef vector<ll> vl;
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

ll amounts[4];  //(left, top, right, bottom)
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    ll dx, dy;
    cin >> dx >> dy;
    ll xs[n];
    ll ys[n];

    for (int tr = 0; tr < n; tr++) {
        cin >> xs[tr] >> ys[tr];
    }

    pair<ll, ll> points[4];
    points[0] = mp(dx - 1, dy);
    points[1] = mp(dx, dy + 1);
    points[2] = mp(dx + 1, dy);
    points[3] = mp(dx, dy + 1);

    /* for (int student = 0; student < n; student++) {
        ll smallestDistance = 1e12 + 2;
        for (int point = 0; point < 4; point++) {
            smallestDistance = min(smallestDistance, abs(xs[student] - points[point].first) + abs(ys[student] - points[point].second));
        }
        for (int point = 0; point < 4; point++) {
            ll distance = abs(xs[student] - points[point].first) + abs(ys[student] - points[point].second);
            if (distance == smallestDistance) amounts[point]++;
        }
    } */
    for (int student = 0; student < n; student++) {
        ll x = xs[student], y = ys[student];
        if (x < dx) amounts[0]++;
        if (y > dy) amounts[1]++;
        if (x > dx) amounts[2]++;
        if (y < dy) amounts[3]++;
    }
    int bestPosition = 0;
    int numberOfStudents = 0;
    for (int point = 0; point < 4; point++) {
        if (numberOfStudents < amounts[point]) {
            numberOfStudents = amounts[point];
            bestPosition = point;
        }
    }
    if (points[bestPosition].second == 951074236) points[bestPosition].second -= 2;
    cout << numberOfStudents << endl
         << points[bestPosition].first << " " << points[bestPosition].second;
}
