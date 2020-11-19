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

    int nam;
    cin >> nam;
    int ar[nam + 1];
    int s = -1;
    int e = -1;
    for (int tr = 1; tr <= nam; tr++) {
        cin >> ar[tr];
        if (tr == 1) continue;
        if (s == -1 && ar[tr] < ar[tr - 1]){
            s = tr - 1;
            e = tr;
    }
        else if (ar[tr] < ar[tr - 1] && tr > e)
            e = tr;
        //cout << tr << " : " << e << endl;
    }
    //cout << s << " " << e << endl;
    if (s == -1 && e == -1)
        cout << "yes\n1 1\n";
    else if (e == -1) {
        cout << "yes\n"
             << s << " " << nam << endl;
    } else {
        ll sum = ar[s];
        bool possible = true;
        for (int i = s + 1; i <= e; i++) {
            if (ar[i] > sum) {
                possible = false;
                break;
            }
            sum = ar[i];
        }
        if(e < nam){
            if(ar[s] > ar[e + 1])
            possible = false;
        }
        if(s >1){
            if(ar[e] < ar[s-1]) possible = false;
        }
        if (!possible)
            cout << "no\n";
        else {
            cout << "yes\n"
                 << s << " " << e << endl;
        }
    }
}