#include <iostream>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pil pair<int, ll>
#define pib pair<int, bool>
#define SET(a, c) memset(a, c, sizeof a)
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
#include <unordered_set>
//#include <unordered_map>
#include <cmath>
#include <cstring>
//#include <sstream>
//#include <stack>
//#include <queue>
ll rollingHash(char first, char toAdd, ll origHash, ll length, ll base) {
    ll removed = origHash - (((first - 'a') + 1) * (pow(base, length - 1)));
    ll added = (removed * base) + ((toAdd - 'a') + 1);
    cout << "\t\t\t" << origHash << " - " << (first - 'a' + 1) << " * " << (pow(base, length - 1)) << "    "
         << " to " << added << " rem " << removed << endl;
    return added % 1000000007;
}

ll hashAdd(char toAdd, ll origHash, ll base) {
    return ((origHash * base) + (toAdd - 'a' + 1)) % 1000000007;
}

/* 
ababab
01000000000000000000000000
1
 */
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    bool c[26];
    string t;
    cin >> t;
    for (int i = 0; i < 26; i++) {
        c[i] = t[i] - '0';
        // cout << c[i];
    }
    // cout << endl;
    int k;
    cin >> k;
    unordered_set<ll> u;
    ll base = 27;
    for (int size = 1; size <= s.size(); size++) {
        ll hash1 = 0;
        int badCounter = 0;
        for (int i = 0; i < size; i++) {
            hash1 = hashAdd(s[i], hash1, base);
            badCounter += 1 - c[s[i] - 'a'];
            // cout << "     " << s[i] << " = " << (1 - c[s[i] - 'a']) << endl;
        }
        if (badCounter <= k) {
            // cout << "Inserting   0 to " << size - 1 << endl;
            // cout << "  Bad Counter  " << badCounter << endl;
            cout << "Inserting   " << s.substr(0, size) << "  |  " << hash1 << endl;
            u.insert(hash1);
        }
        for (int i = size; i < s.size(); i++) {
            //Do rolling hash here.
            hash1 = rollingHash(s[i - size], s[i], hash1, size, base);
            badCounter -= 1 - c[s[i - size] - 'a'];
            badCounter += 1 - c[s[i] - 'a'];
            // cout << "     " << s[i] << " =  -" << (1 - c[s[i - size] - 'a']) << " +" << (1 - c[s[i] - 'a']) << endl;
            // cout << "  Bad Counter  " << badCounter << endl;
            if (badCounter <= k) {
                u.insert(hash1);
                cout << "Inserting   " << s.substr(i - size, size) << "  |  " << hash1 << endl;
            }
        }
    }
    cout << u.size() << endl;
    for (ll l : u) cout << l << " ";
}