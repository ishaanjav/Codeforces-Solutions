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
//#include <unordered_set>
//#include <unordered_map>
//#include <cmath>
//#include <cstring>
//#include <sstream>
//#include <stack>
//#include <queue>

bool taken[1000];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    int ar[k];
    for (int i = 0; i < k; i++) {
        cin >> ar[i];
        taken[ar[i]] = 1;
    }

    for (int i = 0; i < k; i++) {
        cout << ar[i];
        int found = 0;
        for (int a = 1; a <= n * k; a++) {
            if (taken[a]) continue;
            found++;
            cout << " " << a;
            taken[a] = true;
            if (found == n - 1) break;
        }
        cout << "\n";
    }
}
