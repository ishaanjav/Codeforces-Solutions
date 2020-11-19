#include <iostream>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second

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

int track[8];
int dup[8];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int ar[n];
    bool possible = true;
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
        if (ar[i] == 5 || ar[i] == 7) possible = false;
        track[ar[i]]++;
        dup[ar[i]]++;
    }
    if (!possible)
        cout << "-1\n";
    else {
        track[6] -= track[3];
        track[1] -= track[3];
        track[3] = 0;
        bool possible = true;
        if (track[2] > 0) {
            if (track[1] == track[2] && track[2] == track[4] + track[6]) {
            } else
                possible = false;
        }
        track[1] -= track[2];
        int two = track[2];
        if (track[6] > 0) {
            if (track[6] > two) possible = false;
            two -= track[6];
            //   cout << track[6] << endl;
            track[6] = 0;
        }
        track[4] -= two;
        track[2] = 0;
        for (int i : track) {
            if (i != 0) {
                possible = false;
            }
        }
        if (!possible)
            cout << "-1\n";
        else {
            for (int i = 0; i < dup[3]; i++) {
                cout << "1 3 6\n";
            }
            dup[6] -= dup[3];
            dup[1] -= dup[3];
            for (int i = 0; i < dup[6]; i++)
                cout << "1 2 6\n";
            for (int i = 0; i < dup[4]; i++)
                cout << "1 2 4\n";
        }
    }
}