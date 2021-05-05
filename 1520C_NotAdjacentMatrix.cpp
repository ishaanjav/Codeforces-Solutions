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
#define len(a) (sizeof(a)/sizeof(a[0])
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define FOUND(u, val) u.find(val) != u.end()
#define max_self(a, b) a = max(a, b);
#define min_self(a, b) a = min(a, b);
#define deb cout << "ASDFASDF\n"
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
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        if (n == 1) cout << "1\n";
        else if (n == 2)
            cout << "-1\n";
        else if(n == 3)
            cout << "2 9 7\n4 6 3\n1 8 5\n";
        else {
            int grid[n][n];
            int var = 1;
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j += 2)
                    grid[i][j] = var++;
            for (int i = 0; i < n; i++)
                for (int j = 1; j < n; j += 2)
                    grid[i][j] = var++;
            
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++)
                    cout << grid[i][j] << " ";
                cout << endl;
            }
        }
    }
}
