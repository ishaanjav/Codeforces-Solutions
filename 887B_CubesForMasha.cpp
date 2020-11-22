/*
 * Created by ishaanjav
 * github.com/ishaanjav
 * Codeforces Solutions: https://github.com/ishaanjav/Codeforces-Solutions
 */

#include <iostream>
using namespace std;

#define ll long long
#define pb push_back
#define ins insert
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
//#include <algorithm>
//#include <set>
//#include <map>
//#include <unordered_set>
//#include <unordered_map>
//#include <cmath>
#include <cstring>
//#include <sstream>
//#include <stack>
//#include <queue>

int f[10];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 6; j++) {
            int a;
            cin >> a;
            f[a]++;
        }
    }
    int ans = 0;
    for (int i = 1; i <= 99; i++) {
        bool canDo = true;
        int num = i;
        int ar[10];
        memcpy(ar, f, sizeof(ar));
       /*  while (num != 0) {
            ar[num % 10]--;
            if (ar[num % 10] < 0) {
                canDo = false;
                break;
            }
            num /= 10;
        } */
        if()

        if (!canDo) break;
        ans = i;
    }
    cout << ans;
}
