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

    int nam;
    cin >> nam;

    ll a = 0, b = 0;
    string order = "";
    for (int tr = 0; tr < nam; tr++) {
        ll c, d;
        cin >> c >> d;
        if (a + c >= 500 + b) {
            order += "G";
            b += d;
        } else {
            order += "A";
            a += c;
        }
    }

    if (abs(a - b) > 500)
        cout << "-1\n";
    else
        cout << order + "\n";
}