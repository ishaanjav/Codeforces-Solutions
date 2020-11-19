#include <iostream>
using namespace std;
#include <string>

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;
        if (b == 0) {
            if (a != 0) {
                cout << string(a + 1, '0') << endl;
            } else {
                cout << string(c + 1, '1') << endl;
            }
            continue;
        }
        string ans;
        for (int i = 0; i < b + 1; i++) {
            if (i % 2)
                ans += "0";
            else
                ans += "1";
        }
        ans.insert(1, string(a, '0'));
        ans.insert(0, string(c, '1'));
        cout << ans << endl;
    }
}
