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
bool solve(int need[], int parent = 0, int vertex = 1, bool bad = false) {
    // need[vertex] = need[parent];
    preorder[vertex] = counter++;
    // cout << parent << " ---> " << vertex << "  |  " << bad << endl;
    if (adj[vertex].size() == 1 && vertex != 1) {
        if (bad) {
            check[parent] = false;
        }
        check[vertex] = bad;
        // cout << " " << vertex << " returning " << bad << endl;
        return bad;
    }
    bool badAlongPath = false;
    for (auto e : adj[vertex]) {
        // cout << "  ";
        // e.toString();
        if (e.first == parent) continue;
        badAlongPath |= solve(need, vertex, e.first, e.second);
        // need[vertex] =
    }
    /*  cout << " Setp " << parent << " to false\n";
    cout << " Set " << vertex << " to " << !badAlongPath << endl;
    */
    check[parent] = false;
    if (badAlongPath)
        check[vertex] = false;
    return badAlongPath;
}

int main() {
    ios_base::sync_with_stdio(false);
    ifstream cin("in.txt");
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
        }
    }

    need[n] = n;
    need[0] = 1; /* 
    cout << "BEFORE: ";
    for (int i = 1; i <= n; i++)
        cout << check[i] << " "; */
    // cout << "\n";
    solve(need);
    int num = 0;
    string s = "";
    for (int i = 1; i <= n; i++) {
        num += check[i];
        if (check[i]) s += to_string(i) + " ";
        // cout << check[i] << " ";
    }
    cout << num << "\n" + s;
}
