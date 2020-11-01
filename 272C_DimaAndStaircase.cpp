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

//https://codeforces.com/problemset/problem/272/C
//Doesn't work.
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int ar[n];
    for (int i = 0; i < n; i++) cin >> ar[i];

    int q;
    cin >> q;
    int ans[q];
    for (int x = 0; x < q; x++) {
        int w, h;
        cin >> w >> h;
        w--;
        int curHeight = ar[w];
        int newHeight = curHeight + h;
        ans[x] = curHeight;
        for (int i = 0; i <= w; i++)
            ar[i] = newHeight;
        cout << "\t" << newHeight << "\n";
    }

    for (int i : ans) cout << i << endl;
}