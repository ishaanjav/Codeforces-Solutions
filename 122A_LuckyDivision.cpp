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

    int ar[] = {4, 7, 47, 74, 444, 447, 474, 477, 744, 747, 774, 777};
    int n;
    cin >> n;
    bool possible = false;
    for (int i : ar) {
        if (n % i == 0) possible = true;
    }
    cout << (possible ? "YES\n" : "NO\n");
}
