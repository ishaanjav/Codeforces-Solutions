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
#include <algorithm>
//#include <set>
//#include <map>
//#include <unordered_set>
#include <unordered_map>
//#include <cmath>
//#include <cstring>
//#include <sstream>
//#include <stack>
//#include <queue>

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    int ar[n];
    for (int& x : ar) cin >> x;
    unordered_map<string, int> freq;
    while (m--) {
        string s;
        cin >> s;
        freq[s]++;
    }
    sort(ar, ar + n);

    int f[freq.size()];
    int c = 0;
    for (pair<string, int> p : freq) f[c++] = p.se;
    sort(f, f + freq.size());
    int a1 = 0, a2 = 0;
    reverse(f, f + freq.size());

    c = 0;
    for (int i : f) {
        a1 += i * ar[c++];
    }
    c = n - 1;
    for (int i : f) {
        a2 += i * ar[c--];
    }
    cout << a1 << " " << a2;
}
