/*
 * Created by ishaanjav
 * github.com/ishaanjav
 * Codeforces Solutions: https://github.com/ishaanjav/Codeforces-Solutions
 */

#include <iostream>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pil pair<int, ll>
#define pib pair<int, bool>
#define SET(a, c) memset(a, c, sizeof(a))
#define MOD 1000000007
#define enld endl
#define endl "\n"
#define fi first
#define se second
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

#include <string>
#include <vector>
typedef vector<int> vi;
typedef vector<ll> vl;
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

    int length, sum;
    cin >> length >> sum;


    if (sum == 0 || length * 9 < sum) {
        if (length == 1 && sum == 0)
            cout << "0 0";
        else
            cout << "-1 -1";
        return 0;
    }

    int ar[length];
    int avg = sum / length;
    int remaining = sum - 1;
    ar[0] = 1;
    int stop = length;
    for (int i = length - 1; i > -1; i--) {
        if (remaining == 0) break;
        stop--;
        int take = min(remaining, 9);
        ar[i] = take;
        remaining -= take;
        if (i == 0) ar[0]++;
    }
    for (int i = stop - 1; i > 0; i--) ar[i] = 0;
    ar[0] = min(ar[0], 9);
    /* for (int i = 0; i < length; i++) {
        ar[i] = avg;
        if (i == length - 1) {
            if (avg == 0)
                ar[i] += sum % ;
            else
        }
    } */
    int p1 = 0, p2 = length - 1;
    /* while (p1 < p2) {
        int a = ar[p1], b = ar[p2];
        if (b == 9) {
            p2--;
            continue;
        }
        if (a == 0) {
            p1++;
            continue;
        }
        int toGive = min(a, 9 - b);
        ar[p1] -= toGive;
        ar[p2] += toGive;
        if (ar[p1] == 0)
            p1++;
        if (ar[p2] == 9) p2--;
    } */
    int biggest[length];
    remaining = sum;
    for (int i = 0; i < length; i++) {
        if (remaining == 0) {
            biggest[i] = 0;
        };
        int take = min(remaining, 9);
        biggest[i] = take;
        remaining -= take;
    }

    for (int i : ar) cout << i;
    cout << " ";

    for (int i : biggest) cout << i;
}
