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
#include <unordered_set>
// #include <unordered_map>
//#include <cmath>
//#include <cstring>
//#include <sstream>
//#include <stack>
//#include <queue>

vector<vector<int> > adj;

bool matrix[3001][3001];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    adj.resize(n + 1);
    int biggest = 1;
    for (int tr = 0; tr < m; tr++) {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        matrix[a][b] = 1;
        biggest = max(biggest, max(a, b));
    }

    int ways = 0;
    for (int first = 1; first <= biggest; first++) {
        for (int last = 1; last <= biggest; last++) {
            if (first == last) continue;
            int counter = 0;
            for (int middle : adj[first])
                if (middle != first && middle != last && matrix[middle][last]) counter++;
            ways += counter * (counter - 1) / 2;
        }
    }

    cout << ways;
}
