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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int ar[n];
    int minPos = -1;
    int m = 1000000;
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
        if (ar[i] < m) {
            m = ar[i];
            minPos = i;
        }
    }

    bool holds = true;
    int i;
    for (i = minPos; i < minPos + n - 1; i++) {
        if (ar[i % n] > ar[(i + 1) % n]) {
            holds = false;
            cout << i << "  " << ar[i % n] << "  " << ar[(i + 1) % n] << endl;
            break;
        }
    }
    if (ar[minPos] > ar[(minPos - 1 + n) % n]) holds = false;
    if (!holds)
        cout << -1;
    else {
        cout << ((n - (minPos)) % n) << endl;
    }
}
