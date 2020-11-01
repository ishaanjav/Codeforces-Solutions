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

    ll a, b, c, d;
    cin >> a >> b >> c >> d;

    if (d * a == b * c)
        cout << 0 << endl;
    else if (d * a < b * c) {
        cout << (b * c - a * d / gcd(b * c - a * d, b * c)) << "/" << (b * c / gcd(b * c - a * d, b * c)) << endl;
    } else {
        swap(a, b);
        swap(d, c);
        cout << (b * c - a * d / gcd(b * c - a * d, b * c)) << "/" << (b * c / gcd(b * c - a * d, b * c)) << endl;
    }
}