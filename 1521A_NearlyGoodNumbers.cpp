#include <iostream>
using namespace std;

int main() {
    int t; cin >> t;
    
    while(t--){
       long long a, b; cin >> a >> b;
       if(a % b == 0) cout << "NO\n";
       else cout <<"YES\n"<< a << " " << (a * b * 3 - a) << " " << (a * b * 3) << endl;
    }
}