#include <iostream>
using namespace std;

int main() {
    int t; cin >> t;

    while (t--) {
        ll n; cin >> n;
        int cnt = 0;
        for (ll a = 3; a <= n; a += 2) {
            ll square = a * a;
            ll b = (square - 1) / 2;
            ll c = square - b;
            if (b > n || c > n) break;
            cnt++;
        }
        cout << cnt << endl;
    }
}
