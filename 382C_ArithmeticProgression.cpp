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
//#include <algorithm>
//#include <set>
//#include <map>
#include <unordered_map>
#include <unordered_set>
//#include <cmath>
//#include <cstring>
//#include <sstream>
//#include <stack>
//#include <queue>

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int ar[n];
    for (int tr = 0; tr < n; tr++) {
        cin >> ar[tr];
    }
    sort(ar, ar + n);

    if (n == 1) {
        cout << -1;
    } else if (n == 2) {
        if ((ar[1] - ar[0]) % 2 == 0) {
            cout << 3 << "\n";
            cout << (ar[0] - (ar[1] - ar[0])) << " " << ((ar[0] + ar[1]) / 2) << " " << (ar[1] + (ar[1] - ar[0]));
        } else {
            cout << 2 << "\n";
            cout << (ar[0] - (ar[1] - ar[0])) << " " << (ar[1] + (ar[1] - ar[0]));
        }
    } else {
        vi difs;
        unordered_map<int, int> quant;
        for (int i = 0; i < n - 1; i++) {
            difs.pb(ar[i + 1] - ar[i]);
            quant[difs.back()]++;
        }
        bool good = true;
        int co = 0;
        int majority;
        bool zero = false;
        for (pair<int, int> p : quant) {
            majority = p.first;
            if (p.first == 0) zero = 1;
            if (p.first > 1) {
                co++;
                if (co == 2) {
                    good = false;
                }
            }
        }
        if (quant.size() > 2 || !good) {
            cout << 0;
        }else if(zero) cout << "1\n1";
         else {
            if (quant.size() == 1) {
                if ((ar[1] - ar[0]) % 2 == 0){

                }
            } else {
            }
        }
    }
}