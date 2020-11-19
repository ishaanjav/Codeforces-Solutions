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

    int ar[nam];
    int totalZeroes = 0;
    for (int i = 0; i < nam; i++) {
        cin >> ar[i];
        if (ar[i] == 0) totalZeroes++;
    }

    int maxSoFar = 0;
    int left = -1, right = -1;
    int maxOverall = 0;
    int lastLeft = -1;
    int lastRight = -1;
    for (int i = 0; i < nam; i++) {
        if (ar[i] == 0) {
            if (left == -1) left = i;
            maxSoFar++;
            right = i;
        } else {
            maxSoFar--;
        }
        if (maxSoFar < 0) {
            maxSoFar = 0;
            left = -1;
        }
        if (maxOverall < maxSoFar) {
            maxOverall = maxSoFar;
            lastLeft = left;
            lastRight = right;
        }
    }
    if (maxOverall == 0)
        cout << nam - 1 << endl;
    else {
        cout << nam - totalZeroes + maxOverall << endl;
    }
    /* if (lastLeft == -1) {
        lastLeft = left;
        lastLeft = right;
    }
    if (lastLeft == -1) {
        cout << nam - 1 << endl;
        return 0;
    }
    cout << maxOverall << " | " << lastLeft << "  " << lastRight << endl;
    int sizeOfRange = lastRight - lastLeft;
    int nonZeroes = sizeOfRange - maxOverall;
    int ones = maxOverall - nonZeroes;
    int originalOnes = nam - totalZeroes;
    cout << originalOnes + ones << endl; */
}