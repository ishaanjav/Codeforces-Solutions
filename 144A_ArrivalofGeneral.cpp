#include <iostream>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair

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
    cin.tie(NULL);

    int nam;
    cin >> nam;
    int ar[nam];
    int n = nam;
    int min = 1000000;
    int ma = -1;
    int minP = -1, maxP = -1;
    for (int tr = 0; tr < nam; tr++) {
        int t;
        cin >> t;
        ar[tr] = t;
        if (t > ma) {
            ma = t;
            maxP = tr;
        }
        if (t < min) {
            min = t;
            minP = tr;
        } else if (t == min)
            minP = tr;
    }
    if (min == ma) {
        cout << "0\n";
    } else if (maxP > minP) {
        int ans = maxP;
        ans += n - minP - 2;
        cout << ans << "\n";
    } else {
        int ans = maxP + n - minP - 1;

        cout << ans << "\n";
    }
}