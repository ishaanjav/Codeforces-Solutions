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

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        ll ar[n];
        ll s1 = 0;
        for (ll &x : ar) {
            cin >> x;
            s1 += x;
        }
        bool neg = false;
        ll s = 0;
        for (int i = 0; i < n; i++) {
            s += ar[i];
            if(s <= 0){
                neg = 1;break;
            }
        }s=0;
        for (int i = n - 1; i >=0 ; i--) {
            s += ar[i];
            if (s <= 0) {
                neg = 1;
                break;
            }
        }
        if (neg)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
}