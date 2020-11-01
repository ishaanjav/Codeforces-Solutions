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
    int p;

    cin >> n >> p;
    int ar[n];
    for (int i = 0; i < n; i++) cin >> ar[i];
    int k = ar[p];
    int i;
    sort(ar, ar + n, greater<int> ());
    for (i = 0; ar[i] >= k && ar[i] > 0; i++)
        ;
    cout << min(i, n) << endl;
}