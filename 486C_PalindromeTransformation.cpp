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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, pos;
    cin >> n >> pos;
    string s;
    cin >> s;

    int difs[s.length()];
    for (int i = 0; i < n; i++) difs[i] = 0;
    pos--;
    int counter = 0;
    for (int i = 0; i < s.length() / 2; i++) {
        char a = s[i], b = s[s.length() - 1 - i];
        if (s[i] != b) {
            difs[i] = min((a - b + 26) % 26, (b - a + 26) % 26);
            counter += difs[i];
            difs[s.length() - 1 - i] = min((a - b + 26) % 26, (b - a + 26) % 26);
        }
    }
    // for (int i = 0; i < s.length(); i++) cout << difs[i] << " ";
    // cout << endl;
    int mid = s.length() / 2;
    int dist = 0;
    if (pos >= mid) {
        reverse(difs, difs + n);
        pos = s.length() - pos - 1;
    }
    int minPos = pos;
    for (int i = pos - 1; i >= 0; i--) {
        if (difs[i] > 0) {
            minPos = i;
            // cout << "Min: " << minPos << endl;
        }
    }
    // dist += pos - minPos;
    int maxPos = pos;
    for (int i = pos; i < s.length() / 2; i++)
        if (difs[i] > 0) {
            maxPos = i;
            // cout << "Max: " << maxPos << endl;
        }
    // dist += maxPos - minPos;
    if (maxPos - pos < pos - minPos) {
        dist += maxPos - pos;
        if (maxPos != pos)
            dist += maxPos - minPos;
        else
            dist += pos - minPos;
    } else {
        dist += pos - minPos;
        if (maxPos != pos)
            dist += maxPos - minPos;
        else
            dist += pos - minPos;
    }
    // cout << "Dist: " << dist << " counter  " << counter << endl;
    cout << dist + counter << endl;
}