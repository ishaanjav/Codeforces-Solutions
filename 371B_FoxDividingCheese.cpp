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

ll gcd(ll a, ll b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll a, b;
    cin >> a >> b;

    ll g = gcd(a, b);
    ll toGoA = a / g;
    ll toGoB = b / g;
    bool possible = true;
    int counter = 0;

    while (toGoA > 1) {
        counter++;
        if (toGoA % 2 == 0) {
            toGoA /= 2;
        } else if (toGoA % 3 == 0) {
            toGoA /= 3;
        } else if (toGoA % 5 == 0) {
            toGoA /= 5;
        } else {
            possible = false;
            break;
        }
    }
    if (!possible) {
        cout << -1 << endl;
        return 0;
    }
    while (toGoB > 1) {
        counter++;
        if (toGoB % 2 == 0) {
            toGoB /= 2;
        } else if (toGoB % 3 == 0) {
            toGoB /= 3;
        } else if (toGoB % 5 == 0) {
            toGoB /= 5;
        } else {
            possible = false;
            break;
        }
    }
    if (!possible) {
        cout << -1 << endl;
        return 0;
    }
    cout << counter << endl;
}