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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int ar[n];
    ll sum = 0;
    for (int tr = 0; tr < n; tr++) {
        cin >> ar[tr];
        sum += ar[tr];
    }
    int left[n];
    left[0] = ar[0];
    int right[n];
    right[n - 1] = ar[n - 1];
    int ways = 0;
    // DP
    for (int i = 1; i < n; i++) left[i] = left[i - 1] + ar[i];
    for (int i = n - 2; i >= 0; i--) right[i] = right[i + 1] + ar[i];
    for (int i = 0; i < n - 1; i++) ways += (left[i] == right[i + 1]);
    ways = 0;
    ll l = ar[0];
    sum -= l;
    for (int i = 0; i < n - 1; i++) {
        if (sum == l) {
            ways++;
        }
        sum -= ar[i + 1];
        l += ar[i + 1];
    }

    cout << ways;
}
