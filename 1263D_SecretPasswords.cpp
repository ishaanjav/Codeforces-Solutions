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
#include <unordered_map>
#include <unordered_set>
//#include <cmath>
//#include <cstring>
//#include <sstream>
//#include <stack>
//#include <queue>
vi parents, sizes;
int findParent(int num) {
    if (parents[num] != parents[parents[num]]) parents[num] = findParent(parents[num]);
    return parents[num];
}
void unionNodes(int a, int b) {
    int A, B;
    if (a == b || ((A = findParent(a)) == (B = findParent(b)))) {
        // cout << "skipping " << a << " " << b << endl;
        return;
    }
    if (sizes[B] > sizes[A]) swap(B, A);
    sizes[A] += sizes[B];
    parents[B] = A;
    // cout << "B: " << B << " parent is " << A << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int counter = 0;
    sizes.resize(n);
    parents.resize(n);
    vi ar[26];

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        parents[i] = i;
        sizes[i] = 1;
        for (char c : s) {
            ar[c - 'a'].pb(counter);
        }
        counter++;
    }
    for (int i = 0; i < 26; i++) {
        if (ar[i].size() <= 1) continue;
        int first = ar[i].front();
        for (int j = 1; j < ar[i].size(); j++) {
            // cout << "unioning " << first << " and " << ar[i][j] << endl;
            unionNodes(first, ar[i][j]);
        }
    }
    unordered_set<int> ans;
    for (int i = 0; i < n; i++) {
        // cout << findParent(i) << endl;
        ans.insert(findParent(i));
    }
    cout << ans.size();
}