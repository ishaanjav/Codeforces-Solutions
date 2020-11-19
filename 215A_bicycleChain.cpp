#include <iostream>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair

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

    int n1, n2;

    cin >> n1;
    int a[n1];
    for (int tr = 0; tr < n1; tr++) {
        cin >> a[tr];
    }
    cin >> n2;
    int b[n2];
    for (int tr = 0; tr < n2; tr++) {
        cin >> b[tr];
    }
    int ans = 1;
    int m = b[n2 - 1] / a[n1 - 1];
    int p1 = n1 - 1;
    int p2 = n2 - 1;
    while (p1 >= 0 && p2 >= 0) {
        if (p1 == 0 || p2 == 0) break;
        ans++;
        int c1 = b[p2 - 1] / a[p1];
        int c2 = b[p2] / a[p1 - 1];
        cout << ans << " , " << c1 << ":" << c2 << "  |  " << p1 << ":" << p2 << endl;
        if (c1 == m) {
            p2--;
        } else if (c2 == m) {
            p1--;
        } else {
            break;
        }
    }
    //ans--;
    cout << ans << endl;
}