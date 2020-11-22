/*
 * Created by ishaanjav
 * github.com/ishaanjav
 * Codeforces Solutions: https://github.com/ishaanjav/Codeforces-Solutions
 */

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
#include <cstring>
//#include <sstream>
//#include <stack>
//#include <queue>

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int nam;
    cin >> nam;

    bool opened[nam];
    memset(opened, false, sizeof(opened));
    pair<int, int> ar[nam];
    for (int tr = 0; tr < nam; tr++) {
        int a, b;
        cin >> a >> b;
        ar[tr] = mp(a, b);
    }
    for (int i = 0; i < nam; i++) {
        int canOpen = ar[i].second;
        for (int j = 0; j < nam; j++) {
            if (j == i) continue;
            if (ar[j].first == canOpen) opened[j] = true;
        }
    }
    int counter = 0;
    for (bool b : opened)
        if (!b) counter++;
    cout << counter << endl;
}
