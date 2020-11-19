#include <iostream>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair

#include <string>
#include <vector>
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

    int n, a, b;
    cin >> n >> a >> b;
    int x = a + 1;
    int y = n - b;
    y = max(y, x);
    cout << n - y  + 1<< endl;
}