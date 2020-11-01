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
    int n = nam;
    int fives = 0;
    int zeroes = 0;
    for (int tr = 0; tr < nam; tr++) {
        int t;
        cin >> t;
        if (t == 5) fives++;
        else zeroes ++;
    }
    fives = fives / 9;
    if (fives == 0 || zeroes == 0) {
        if (zeroes == 0)
            cout << "-1\n";
        else
            cout << "0\n";
    } else {
        for (int i = 0; i < fives * 9; i++) cout << "5";
        for (int i = 0; i < zeroes; i++) cout << "0";
        cout << endl;
    }
}