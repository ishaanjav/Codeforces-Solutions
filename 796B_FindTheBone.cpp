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
#define found(u, val) u.find(val) != u.end()

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

/* 
7 3 4
3 4 6
1 2
2 5
5 7
7 1
 */
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int cups, holes, swaps;
    cin >> cups >> holes >> swaps;
    unordered_set<int> u;
    for (int i = 0; i < holes; i++) {
        int a;
        cin >> a;
        u.ins(a);
    }

    bool hole = false;
    int last = 0;
    for (int i = 0; i < swaps; i++) {
        int a, b;
        cin >> a >> b;
        if (u.find(b) != u.end()) {
            hole = true;
            last = b;
        }
        if (!hole) last = b;
    }
    cout << last;
}