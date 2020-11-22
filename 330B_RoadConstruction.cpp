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
#include <cstring>
//#include <sstream>
//#include <stack>
//#include <queue>

//Round 192
//https://codeforces.com/problemset/problem/330/B?f0a28=1
bool limited[1001];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int roads, con;
    cin >> roads >> con;
    for (int i = 0; i < con; i++) {
        int a, b;
        cin >> a >> b;
        limited[a] = true;
        limited[b] = true;
    }
    int unlimited;
    for (int i = 1; i <= roads; i++) {
        if (!limited[i]) {
            unlimited = i;
            break;
        }
    }
    cout << roads - 1 << "\n";
    for (int i = 1; i <= roads; i++) {
        if (i == unlimited) continue;
        cout << i << " " << unlimited << "\n";
    }
}
