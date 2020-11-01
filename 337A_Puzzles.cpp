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

    int n, k;
    cin >> n >> k;
    int ar[k];
    for (int i = 0; i < k; i++) cin >> ar[i];

    sort(ar, ar + k);
    int best = 1000000;
    for (int i = 0; i < k - n + 1; i++) {
        best = min(best, ar[i + n - 1] - ar[i]);
    }
    cout << best;
}