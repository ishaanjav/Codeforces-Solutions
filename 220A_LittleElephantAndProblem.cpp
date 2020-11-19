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
    ll ar[n];
    ll right[n];
    for (int tr = 0; tr < n; tr++) {
        cin >> ar[tr];
        right[tr] = ar[tr];
    }
    sort(right, right + n);

    int difs = 0;
    for (int i = 0; i < n; i++) {
        if (right[i] != ar[i]) difs++;
        if(difs > 2) break;
    }
cout <<(difs >2 ?"NO":"YES");
}