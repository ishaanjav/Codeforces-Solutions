#include <iostream>
using namespace std;

#define ll long long
#define pb push_back
#define ins insert
#define mp make_pair
#define pii pair<int, int>
#define pil pair<int, ll>
#define pll pair<ll, ll>
#define pib pair<int, bool>
#define SET(a, c) memset(a, c, sizeof(a))
#define MOD 1000000007
#define Endl endl
#define endl "\n"
#define fi first
#define se second
#define rs resize
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define FOUND(u, val) u.find(val) != u.end()
#define max_self(a, b) a = max(a, b);
#define min_self(a, b) a = min(a, b);

#include <string>
#include <vector>
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<ll> vl;
typedef vector<bool> vb;
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

    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;

    int a = 0, b = 0, c = 0;
    if ((r2 - r1) == (c2 - c1) || (r2 - r1) * -1 == (c2 - c1))
        b = 1;
    else if ((abs(r2 - r1) + abs(c2 - c1)) % 2 == 0)
        b = 2;

    c = max(abs(r1 - r2), abs(c1 - c2));

    if (c1 == c2 || r1 == r2)
        a = 1;
    else
        a = 2;
    cout << a << " " << b << " " << c << endl;
}