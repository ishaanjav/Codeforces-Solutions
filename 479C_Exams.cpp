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
    cin.tie(0);

    int n;
    cin >> n;
    pair<int, int> ar[n];
    for (int tr = 0; tr < n; tr++) 
        cin >> ar[tr].first >> ar[tr].second;
    
    sort(ar, ar + n);
    int ans = ar[0].second;
    for(int i = 1; i < n; i++){
        if(ar[i].second >= ans)ans = ar[i].second;
        else ans = ar[i].first;
    }
    cout << ans;

}