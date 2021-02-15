#include <iostream>
#include <map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        map<ll, int> mp;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            mp[a]++;
        }
        int cnt = 0;
        bool done = false;
        for (auto p : mp) {
            if (done) {
                cnt += p.se;
            }
            done = 1;
        }
        cout << cnt << endl;
    }
}
