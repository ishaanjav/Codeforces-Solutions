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
#include <unordered_map>
//#include <cmath>
//#include <cstring>
//#include <sstream>
//#include <stack>
//#include <queue>
unordered_map<int, int> map;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < 2 * n; i++) {
        int t;
        cin >> t;
        if (map[t] == 0) {
            map[t] = i + 1;
        } else {
            //cout << map[t] << " ";
            v.push_back(i + 1);
            v.push_back(map[t]);
            map[t] = 0;
        }
    }
    bool possible = true;
    for (auto p : map) {
        //cout << p.first << " , " << p.second << endl;
        if (p.second != 0) {
            possible = false;
            break;
        }
    }
    if (!possible)
        cout << "-1\n";
    else {
        for (int i = 0; i < 2 * n; i += 2)
            cout << v[i] << " " << v[i + 1] << endl;
    }
}