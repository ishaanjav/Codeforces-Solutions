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
#define fi first
#define se second
#define all(v) v.begin(), v.end()

#include <string>
#include <vector>
typedef vector<int> vi;
//#include <algorithm>
//#include <set>
//#include <map>
#include <unordered_set>
//#include <unordered_map>
//#include <cmath>
//#include <cstring>
//#include <sstream>
//#include <stack>
//#include <queue>

int parent[101];
int sizes[101];

int findParent(int i) {
    if (parent[i] != parent[parent[i]]) parent[i] = findParent(parent[i]);
    return parent[i];
}

void unionNodes(int a, int b) {
    int A = findParent(a), B = findParent(b);
    if (A == B) return;
    if (sizes[B] > sizes[A]) swap(B, A);

    sizes[A] += sizes[B];
    parent[A] = parent[B];
}

vector<pair<int, int> > ar;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    ar.resize(n);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        ar[i] = mp(a, b);
        parent[i] = i;
    }

    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ar[i].first == ar[j].first || ar[i].second == ar[j].second) {
                // cout << "Unioining " << i << "and " << j << endl;
                unionNodes(i, j);
            }
        }
    }
    unordered_set<int> difs;

    // for (int i = 0; i < n; i++) cout << findParent(i) << endl;
    for (int i = 0; i < n; i++) difs.insert(findParent(i));

    cout << difs.size() - 1 << endl;
}
