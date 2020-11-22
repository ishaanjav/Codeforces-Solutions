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

#include <string>
#include <vector>
typedef vector<int> vi;
typedef vector<ll> vl;
//#include <algorithm>
//#include <set>
//#include <map>
#include <unordered_set>
//#include <unordered_map>
//#include <cmath>
//#include <cstring>
//#include <sstream>
//#include <stack>
//#include <queue>
vl hair;
vl parents, sizes;
int findParent(int v) {
    if (parents[v] != parents[parents[v]])
        parents[v] = findParent(parents[v]);
    return parents[v];
}
ll n, m, l;
bool unionNodes(int a, int b) {
    if (b >= n || b < 0) return 0;
    if (hair[b] <= l) return 0;
    int s = findParent(a), d = findParent(b);
    if (s == d) return false;
    // cout << "   union " << a << " and " << b << "  to " << d << endl;
    if (sizes[s] > sizes[d]) swap(s, d);
    sizes[d] += sizes[s];
    parents[s] = parents[d];
    return true;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> l;
    hair.resize(n);
    parents.resize(n);
    sizes.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> hair[i];
        sizes[i] = 1;
        parents[i] = i;
    }
    for (int i = 0; i < n - 1; i++) {
        if (hair[i] > l && hair[i + 1] > l) unionNodes(i, i + 1);
    }
    unordered_set<int> ut;
    for (int i = 0; i < n; i++) {
        if (hair[i] > l)
            ut.ins(findParent(i));
    }
    int groups = ut.size();
    while (m--) {
        int q;
        cin >> q;
        // cout << m << " -----\n";
        if (q) {
            int pos;
            ll length;
            cin >> pos >> length;
            pos--;
            ll before = hair[pos];
            hair[pos] += length;
            // cout << "    unioned " << endl;
            if (before > l || hair[pos] <= l) {
                continue;
            }
            bool d = unionNodes(pos, pos + 1);
            bool d2 = unionNodes(pos, pos - 1);
            if (!d && !d2) groups++;
            if (d || d2) groups -= d + d2 - 1;
            // cout << "      done " << endl;
        } else {
            cout << groups << endl;
            /* unordered_set<int> u;
            for (int i = 0; i < n; i++) {
                if (hair[i] > l)
                    u.ins(findParent(i));
            }
            cout << u.size() << endl; */
        }
    }
}
