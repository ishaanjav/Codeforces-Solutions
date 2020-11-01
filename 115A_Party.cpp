#include <iostream>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(v) v.begin(), v.end()

#include <string>
#include <vector>
typedef vector<int> vi;
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
vi v[2001];
int mx = -1;
void dfs(int x, int level) {
    mx = max(mx, level);
    for (int i : v[x]) dfs(i, level + 1);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;

    int ar[n];
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        ar[i - 1] = x;
        if (x != -1)
            v[x].pb(i);
        else
            v[0].pb(i);
    }
    for (int i = 0; i < v[0].size(); i++) {
        dfs(v[0][i], 1);
    }
    cout << mx << endl;
}