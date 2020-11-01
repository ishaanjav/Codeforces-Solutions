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

    int n;
    cin >> n;
    int ar[n];
    int sum = 0;
    for(int tr = 0; tr < n; tr++){        
        cin >> ar[tr];
        sum += ar[tr];
    }
    if(sum % n == 0){
        cout << n << endl;
    }else{
        cout << n-1 << endl;
    }

}