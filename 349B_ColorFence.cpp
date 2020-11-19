#include <iostream>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second

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
bool comp(pair<int, int> a, pair<int, int> b) {
    if (a.first != b.first) return a.first < b.first;
    return a.second > b.second;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int cost;
    cin >> cost;
    pair<int, int> ar[9];  //cost, position
    for (int i = 0; i < 9; i++) {
        int a;
        cin >> a;
        ar[i] = mp(a, i + 1);
    }
    sort(ar, ar + 9, comp);
    int times = cost / ar[0].first;
    cost %= ar[0].first;
    
    string s(times, ar[0].second + '0');
    
    bool changed = true;
    int p = 0;
    while (changed) {
        changed = false;
        int pos = -1;
        if (p == s.length()) break;
        int big = 0;
        for (int i = 1; i < 9; i++) {
            if (cost >= ar[i].first - ar[0].first) {
                if (ar[i].second > big) {
                    big = ar[i].second;
                    pos = i;
                }
                // pos = max(pos, ar[i].second - 1);
                changed = true;
            }
        }
        if (pos == -1) break;
        if (changed) {
            cost -= ar[pos].first;
            cost += ar[0].first;
            if (ar[pos].second < ar[0].second) break;
            string t = s.substr(0, p) + to_string(ar[pos].second) + s.substr(p + 1, s.size() - p - 1);
            s = t;
        }
        p++;
       }
    if (s.length() == 0)
        cout << "-1";
    else
        cout << s << endl;
}