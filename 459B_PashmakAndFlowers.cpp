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

    int n;
    cin >> n;
    int ar[n];
    int min = 1e6;
    ll mPos = -1;
    int ma = 0;
    ll maPos = 0;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        if (t < min) {
            min = t;
            mPos = 1;
        } else if (t == min) {
            mPos++;
        }
        if (t > ma) {
            ma = t;
            maPos = 1;
        } else if (t == ma) {
            maPos++;
        }
    }
    if(min == ma) cout << "0 1\n";
    else
    cout << ma - min << " " << maPos * mPos << endl;
}