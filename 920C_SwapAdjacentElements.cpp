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
#define Endl "\n"
#define endl "\n"
#define fi first
#define se second
#define rs resize
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define FOUND(u, val) u.find(val) != u.end()
#define max_self(a, b) a = max(a, b);
#define min_self(a, b) a = min(a, b);
bool de = 1;
// bool de = 0;
#define deb cout << (de ? "ASDFASDF\n" : "")
#define read(ar) \
    for (auto& x : ar) cin >> x;
#define each(ar) for (auto i : ar)
#define eachv(ar, i) for (auto i : ar)

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
#include <cstring>
//#include <sstream>
//#include <stack>
//#include <queue>

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int ar[n];
    read(ar);
    string given;
    cin >> given;

    int maxLeft[n + 1], minRight[n + 2];
    maxLeft[0] = 0;
    minRight[n + 1] = n + 3;
    for (int i = 1; i <= n; i++) {
        maxLeft[i] = max(maxLeft[i - 1], ar[i - 1]);
    }
    for (int i = n; i >= 1; i--) {
        minRight[i] = min(minRight[i + 1], ar[i - 1]);
    }
    bool can = true;
    for (int i = 0; i < n - 1; i++) {
        if (given[i] == '1') continue;
        if (minRight[i + 2] < maxLeft[i + 1]) can = false;
    }
    cout << (can ? "YES" : "NO\n");
}