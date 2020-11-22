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
typedef vector<int> vi;

#include <string>
#include <vector>
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
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    int ar[n];
    bool allSame = true;
    for (int tr = 0; tr < n; tr++) {
        cin >> ar[tr];
        if (tr > 0 && ar[tr] != ar[tr - 1]) {
            allSame = false;
        }
    }
    int c = 0;
    if (!allSame) {
        int last = ar[n - 1];
        int tr;
        for (tr = n - 2; ar[tr] == last && tr >= 0; tr--)
            ;
        tr++;
        if (k - 1 < tr) {
            c = -1;
        } else {
            c = tr;
        }
    }
    cout << c << endl;
}
