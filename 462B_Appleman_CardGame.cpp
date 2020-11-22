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

#include <string>
#include <vector>
typedef vector<int> vi;
#include <algorithm>
//#include <set>
// #include <map>
// #include <unordered_set>
#include <unordered_map>
//#include <cmath>
//#include <cstring>
//#include <sstream>
//#include <stack>
//#include <queue>
bool comp(pair<char, int> a, pair<char, int> b) {
    return a.second > b.second;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    unordered_map<char, ll> map;
    for (char c : s) {
        map[c]++;
    }
    vector<pair<char, ll> > v;
    for (auto& it : map) {
        v.push_back(it);
    }
    sort(v.begin(), v.end(), comp);
    ll ans = 0;
    auto it = v.begin();
    while (k > 0) {
        ll val = min(k, (*it).second);
        ans += (ll)(val * val);
        k -= (*it).second;
        it++;
    }
    cout << ans << endl;
}
