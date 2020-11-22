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

    int n, k;
    cin >> n >> k;
    //int ar[n];

    int x = 0;
    int ar[n];
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        ar[i] = t;
        if (t <0)
            x++;
    }
    int p = 0;
    while (x > 0 && k > 0) {
        ar[p] *= -1;
        p++;
        k--;
        x--;
    }
    int sum = 0;
    int smallest = 1e6;
    for (int i : ar) {
        if (i < smallest) smallest = i;
        sum += i;
    }
    if (k > 0 && k % 2 == 1) {
        sum -= smallest * 2;
    }
    cout << sum << endl;
}
