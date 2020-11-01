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
#include <algorithm>
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

    int n;
    cin >> n;
    pair<int, int> ar[n];
    for (int tr = 0; tr < n; tr++) {
        int a, b;
        cin >> a >> b;
        ar[tr] = mp(a, b);
    }
    sort(ar, ar + n);
    bool possible = false;
    for (int i = 0; i < n - 1; i++) {
        if (ar[i].first < ar[i + 1].first && ar[i].second > ar[i + 1].second) {
            possible = true;
            break;
        }
    }

    cout << (possible ? "Happy Alex" : "Poor Alex");
}