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
#include <algorithm>
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
    int s[n];
    int m[n];
    string st;
    cin >> st;
    for (int i = 0; i < n; i++) s[i] = st[i] - '0';
    cin >> st;
    for (int i = 0; i < n; i++) m[i] = st[i] - '0';

    sort(s, s + n);
    sort(m, m + n);

    int sher = 0;
    int mor = 0;
    int pos = 0;
    for (int i = 0; i < n; i++) {
        if (s[pos] < m[i]) {
            sher++;
            pos++;
        }
    }
    pos = 0;
    mor = n;
    for (int i = 0; i < n; i++) {
        if (m[i] >= s[pos])
            mor--, pos++;
    }
    cout << mor << "\n"
         << sher;
}