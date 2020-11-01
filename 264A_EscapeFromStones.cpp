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
    cin.tie(0);

    string s;
    cin >> s;
    vi left, right;
    int c = 1;
    for (char a : s) {
        if (a == 'l')
            left.pb(c);
        else
            right.pb(c);
        c++;
    }
    for(int i : right)cout << i << "\n";
    reverse(left.begin(), left.end());
    for(int i : left)cout << i << "\n";

}