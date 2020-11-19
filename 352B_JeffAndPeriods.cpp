#include <iostream>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair

#include <string>
#include <vector>
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

bool contains[100001];
unordered_map<int, vector<int> > ma;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int ar[n];
    int m = -1;
    vector<int> v;
    vector<int> v2;
    for (int tr = 0; tr < n; tr++) {
        cin >> ar[tr];
        m = max(m, ar[tr]);
        contains[ar[tr]] = 1;
        ma[ar[tr]].push_back(tr);
    }
    for (auto p : ma) {
        vector<int> te = p.second;
        if (te.size() == 1) {
            v.push_back(p.first);
            v2.push_back(0);
        } else {
            int dif = te[1] - te[0];
            int start = te[1];
            bool good = true;
            for (int i = 2; i < te.size(); i++) {
                if (te[i] - start != dif) {
                    good = false;
                    break;
                }
                start = te[i];
            }
            if (good) {
                v.push_back(p.first);
                v2.push_back(dif);
            }
        }
    }
    cout << v.size() << endl;
    for (int i = v.size() - 1; i >= 0; i--) {
        cout << v[i] << " " << v2[i] << "\n";
    }
    /*  vector<int> v;
    vector<int> v2;
    for (int x = 1; x < m + 1; x++) {
        if (!contains[x]) continue;
        int prev = -1;
        int dif = 0;
        int pPos = -1;
        bool good = true;
        for (int i = 0; i < n; i++) {
            if (ar[i] == x) {
                if (prev == -1) {
                    prev = i;
                } else if (dif == 0) {
                    dif = i - prev;
                    prev = i;
                } else {
                    if (i - prev == dif) {
                        prev = i;
                    } else {
                        good = false;
                        break;
                    }
                }
            }
        }
        if (good && prev != -1) {
            v.push_back(x);
            v2.push_back(dif);
        }
    }
    cout << v.size() << endl;
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " " << v2[i] << "\n";
    } */
}
// I just had some general questions about the end of internship presentations such as when it will be and what the expectations are for what we present