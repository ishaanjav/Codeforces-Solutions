/*
 * Created by ishaanjav
 * github.com/ishaanjav
 * Codeforces Solutions: https://github.com/ishaanjav/Codeforces-Solutions
 */

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
#include <unordered_set>

//#include <cmath>
//#include <cstring>
//#include <sstream>
//#include <stack>
//#include <queue>

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    int ar[n];
    for (int i = 0; i < n; i++) cin >> ar[i];

    int prefixes[n + 1];
    prefixes[n] = 0;
    unordered_set<int> u;

    for (int i = n - 1; i >= 0; i--) {
        //Duplicate
        if (u.find(ar[i]) != u.end()) {
            prefixes[i] = prefixes[i + 1];
        } else {
            u.insert(ar[i]);
            prefixes[i] = prefixes[i + 1] + 1;
        }
    }

    while (m--) {
        int a;
        cin >> a;
        cout << prefixes[a - 1] << endl;
    }
}
