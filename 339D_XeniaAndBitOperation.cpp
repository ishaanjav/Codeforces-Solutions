#include <iostream>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second

#include <string>
#include <vector>
typedef vector<int> vi;
//#include <algorithm>
//#include <set>
//#include <map>
//#include <unordered_set>
//#include <unordered_map>
#include <cmath>
//#include <cstring>
//#include <sstream>
//#include <stack>
//#include <queue>

ll n;
vector<ll> tree, level;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    cin >> n >> q;
    n = pow(2, n);
    tree.resize(n * 2);
    level.resize(n * 2);

    for (ll i = 0; i < n; i++) {
        cin >> tree[i + n];
        /*     start[i + n] = i + 1;
        endA[i + n] = i + 1;
     */
        level[i + n] = 1;
    }
    for (ll i = n - 1; i > 0; i--) {
        level[i] = level[i * 2] + 1;
        /*  start[i] = start[i * 2];
        endA[i] = endA[i * 2 + 1];
        */
        if (level[i] % 2 == 0) {
            tree[i] = tree[i * 2] | tree[i * 2 + 1];
            // cout << " |-ing " << tree[i * 2] << " and " << tree[i * 2 + 1] << " == " << tree[i] << endl;
        } else {
            // cout << " ^-ing " << tree[i * 2] << " and " << tree[i * 2 + 1] << " == " << tree[i] << endl;
            tree[i] = tree[i * 2] ^ tree[i * 2 + 1];
        }
    }
    // for (int i = 1; i < 2 * n; i++) cout << tree[i] << " ";
    // cout << endl;
    while (q--) {
        ll pos, val;
        cin >> pos >> val;
        pos += n - 1;
        tree[pos] = val;
        pos /= 2;
        // cout << "-------\n";
        while (pos != 0) {
            tree[pos] = (level[pos] % 2 == 0 ? (tree[pos * 2] | tree[pos * 2 + 1]) : (tree[pos * 2] ^ tree[pos * 2 + 1]));
            // cout << "  Pos " << tree[pos] << endl;
            pos /= 2;
        }
        // for (int i = 1; i < 2 * n; i++) cout << tree[i] << " ";
        // cout << endl;
        cout << tree[1] << endl;
    }
}