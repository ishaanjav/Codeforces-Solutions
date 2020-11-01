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

    ll ar[3];
    cin >> ar[0] >> ar[1] >> ar[2];

    if (ar[0] < ar[1]) swap(ar[0], ar[1]);
    if (ar[0] < ar[2]) swap(ar[0], ar[2]);
    if (ar[1] < ar[2]) swap(ar[1], ar[2]);

    ll ways = (ar[0] + ar[1] + ar[2]) / 3;
    if (ar[0] >= (ar[1] + ar[2]) * 2) ways = ar[1] + ar[2];

    cout << ways;
}