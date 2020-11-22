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
#include <unordered_map>
//#include <cmath>
//#include <cstring>
//#include <sstream>
//#include <stack>
//#include <queue>

int ar[5001];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int nam;
    cin >> nam;
    unordered_map<int, int> u;
    for (int i = 0; i < nam; i++) {
        int a;
        cin >> a;
        u[a]++;
    }
    int counter = 0;
    for (auto p : u) {
        if (p.second > 1) counter += p.second - 1;
        if (p.first > nam) counter++;
    }
    cout << counter << endl;
}
