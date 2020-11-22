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
//#include <cstring>
//#include <sstream>
//#include <stack>
//#include <queue>

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    int queries;
    cin >> queries;
    int ar[s.length()];
    for (int i = 0; i < s.length() - 1; i++) {
        if (s[i] == s[i + 1]) {
            if (i == 0)
                ar[i] = 1;
            else
                ar[i] = ar[i - 1] + 1;
        } else {
            if (i == 0)
                ar[i] = 0;
            else
                ar[i] = ar[i - 1];
        }
        cout << i << "  " << ar[i] << endl;
    }
    ar[s.length() - 1] = ar[s.length() - 2] + 1;
    for (int i = 0; i < queries; i++) {
        int a, b;
        cin >> a >> b;
        cout << ar[b - 1] - ar[a - 1] << endl;
    }
}
