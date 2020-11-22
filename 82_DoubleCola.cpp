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

    ll nam;
    cin >> nam;

    vector<ll> ar;
    ll num = 0;
    for (ll i = 5; i <= 1e9; i *= 2) {
        nam -= i;
        if (nam < 0) {
            nam += i;
            num = i / 2;
            break;
        }
    }
    string s[] = {"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};
    cout << s[nam / num] << endl;
}
