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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    int ar[n];
    for (int tr = 0; tr < n; tr++) {
        cin >> ar[tr];
    }
    int R[n], L[n];
    L[0] = 0, R[n - 1] = n - 1;
    for (int i = 1; i < n; i++) {
        if (ar[i] >= ar[i - 1])
            L[i] = L[i - 1];
        else
            L[i] = i;
    }
    for (int i = n - 2; i >= 0; i--) {
        if (ar[i] >= ar[i + 1])
            R[i] = R[i + 1];
        else
            R[i] = i;
    }
    // cout << "--\n";
    // for (int i = 0; i < n; i++) cout << L[i] << " " << R[i] << endl;
    while (q--) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        bool poss = false;
        if ((b - a) % 2 == 0) {
            int mid = (a + b) / 2;
            poss = (R[mid] >= b && L[mid] <= a);
            if (!poss) {
                poss |= R[a] >= b;
                poss |= L[b] <= a;
            }
        } else {
            int mid1 = (a + b) / 2;
            int mid2 = mid1 + 1;
            // cout << L[mid1] << " " << R[mid1] << " | " << L[mid2] << " " << R[mid2] << "\n";
            if (ar[mid1] == ar[mid2])
                poss = (R[mid1] >= b && L[mid1] <= a);
            else if (ar[mid1] < ar[mid2])
                poss = (R[mid2] >= b && L[mid2] <= a);
            else
                poss = (R[mid1] >= b && L[mid1] <= a);
            if (!poss) {
                poss |= R[a] >= b;
                poss |= L[b] <= a;
            }
        }
        cout << (poss ? "Yes\n" : "No\n");
    }
}
