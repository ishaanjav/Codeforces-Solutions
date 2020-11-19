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
    cin.tie(0);

    int n;
    cin >> n;
    int ar[n];
    for (int i = 0; i < n; i++) cin >> ar[i];
    sort(ar, ar + n);
    vector<vi> v;
    for (int i = n - 1; i >= 0; i--) {
        int val = ar[i];
        bool added = false;
        for(vi a : v){
            if(a.si)
        }
        if(!added){
            vi a;
            a.pb(val);
            v.pb(a);
        }
    }
    cout << v.size()<<endl;



}