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

    int nam;
    cin >> nam;
    int ar[nam];
    for (int tr = 0; tr < nam; tr++) {
        cin >> ar[tr];
        // ar[tr] = 0;
    }

    sort(ar, ar + nam);
    long long difference = 0;
    for (int i = 0; i < nam; i++) {
        difference += (long long)(abs(ar[i] - (i + 1)));
    }
    cout << difference << endl;
}
