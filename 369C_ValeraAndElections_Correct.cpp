/*
 * Created by ishaanjav
 * github.com/ishaanjav
 * Codeforces Solutions: https://github.com/ishaanjav/Codeforces-Solutions
 */

#include <fstream>
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
//#include <unordered_set>
//#include <unordered_map>
//#include <cmath>
//#include <cstring>
//#include <sstream>
#include <stack>
//#include <queue>

struct Edge {
    int to, from;
    bool bad;
    void toString() {
        cout << to << " " << from << " == " << bad << endl;
    }
};
// As far as I am aware. It works. It missed one test case where it output 0 edges need to be fixed.
// vector<vector<Edge> > adj;
vector<vector<pair<int, bool> > > adj;
int n;
int counter = 0;
int preorder[200002];
vector<bool> check;
int colors[2000002];
int amount[2000002];
int solve(int parent = 0, int vertex = 1, bool bad = false) {
    int white = 0;

    for (pair<int, int> p : adj[vertex]) {
        if (p.first == parent) continue;
        if (p.second) white++;
        white += solve(vertex, p.first, p.second);
    }
    if (bad) white++;
    colors[vertex] = white;

    return white;
}

int main() {
    ios_base::sync_with_stdio(false);
    // ifstream cin("in.txt");
    cin.tie(0);

    cin >> n;
    adj.resize(n + 1);
    int need[n + 1];
    check.resize(n + 1);
    for (int tr = 0; tr < n - 1; tr++) {
        Edge e;
        int b;
        cin >> e.to >> e.from >> b;
        e.bad = b == 2;
        // adj[e.to].pb(e);
        adj[e.to].pb(mp(e.from, e.bad));
        adj[e.from].pb(mp(e.to, e.bad));
        Edge f = e;
        swap(f.to, f.from);
        // cout << " "; e.toString();
        // cout << " ";f.toString();
        // adj[f.to].pb(f);
        need[tr + 1] = tr + 1;
        if (e.bad) {
            check[e.to] = check[e.from] = true;
            colors[e.to] = colors[e.from] = 1;
        }
    }

    need[n] = n;
    need[0] = 1; /* 
    cout << "BEFORE: ";
    for (int i = 1; i <= n; i++)
        cout << check[i] << " "; */
    // cout << "\n";
    solve();
    int num = 0;
    string s = "";
    for (int i = 1; i <= n; i++) {
        if (colors[i] == 1)
            num += colors[i], s += to_string(i) + " ";
        // if (check[i]) ;
        // cout << colors[i] << " ";
        // cout << check[i] << " ";
    }
    // cout << "\n";
    cout << num << "\n" + s;
}
