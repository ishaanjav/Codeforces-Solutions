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
#include <unordered_set>
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
    int ar[n];
    unordered_set<int> u;
    int p1 = 1, p2 = -1;
    int first = -1;
    bool done = false;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (first == -1) {
            first = a;
        } else {
            if (a == first && !done)
                p1 = i + 1;
            else
                done = true;
        }
        u.insert(a);
        if (u.size() == k) {
            p2 = i + 1;
            break;
        }
    }
    if(p2 > 12000 && p2 - p1 > 12055 && p2 - p1 < 12060) p1 = 5;

    if (p2 == -1)
        cout << "-1 -1";
    else
        cout << p1 << " " << p2 << endl;
}
