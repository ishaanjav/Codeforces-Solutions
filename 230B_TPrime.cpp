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
#include <cmath>
//#include <cstring>
//#include <sstream>
//#include <stack>
//#include <queue>
bool isprime(ll n) {
    for (ll i = 3; i <= sqrt(n); i++)
        if (n % i == 0) return 0;
    return 1;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll nam;
    cin >> nam;

    for (ll tr = 0; tr < nam; tr++) {
        ll n;
        cin >> n;
        if (n == 4 || (n != 1 && (ll)(sqrt(n)) % 2 != 0 && isprime((ll)(sqrt(n)))) && (ll)(sqrt(n)) * (ll)(sqrt(n)) == n)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}