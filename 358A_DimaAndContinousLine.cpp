#include <iostream>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair

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
    cin.tie(NULL);

    int n;
    cin >> n;

    pair<ll, ll> ar[n - 1];
    ll prev;
    cin >> prev;
    for (int i = 0; i < n - 1; i++) {
        ll temp;
        cin >> temp;
        ar[i] = mp(min(prev, temp), max(prev, temp));
        prev = temp;
    }
    sort(ar, ar + n - 1);
    bool intersection = false;
    for (int i = 0; i < n - 1; i++) {
        pair<ll, ll> cur = ar[i];
        for (int j = i + 1; j < n - 1; j++) {
            pair<ll, ll> next = ar[j];

            // cout << next.first << "," << next.second << "  " << cur.first << "," << cur.second << endl;
            if (next.first == cur.second) continue;
            if (/* (next.first == cur.first && next.second > cur.second) ||  */ (next.first < cur.second && next.first > cur.first && next.second > cur.second)) {
                // cout << (next.second > cur.second) << endl;
                intersection = true;
                break;
            }
        }
        if (intersection) break;
    }
    cout << (intersection ? "yes\n" : "no\n");
}