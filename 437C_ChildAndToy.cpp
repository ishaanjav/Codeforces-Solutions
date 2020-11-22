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
//#include <algorithm>
//#include <set>
//#include <map>
//#include <unordered_set>
//#include <unordered_map>
//#include <cmath>
//#include <cstring>
//#include <sstream>
//#include <stack>
#include <queue>
int vertices, edges;
vector<int> adj[1001];
int removed[1001];
int inside[1001];
//https://www.quora.com/How-would-I-solve-the-child-and-toy-problem-on-codeforces
//My answer is wrong. It's really smart and nice, but wrong.
// Apparently answer is just choose node with highest weight, remove it, then next highest weight, remove....
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> vertices >> edges;

    int per[vertices + 1];
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
    int ar[vertices + 1];
    for (int i = 1; i <= vertices; i++) {
        int weight;
        cin >> weight;
        ar[i] = weight;
        per[i] = 0;
        //  q.push(make_pair(weight, i));
    }

    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        per[u] += ar[v];
        per[v] += ar[u];
        cout << "U: " << u << " V : " << v << " ar[u] " << ar[u] << "  ar[v] " << ar[v] << "       " << per[u] << " | " << per[v] << endl;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int min = 1e7;
    int pos = 0;
    for (int i = 1; i <= vertices; i++) {
        if (per[i] < min) {
            min = per[i];
            pos = i;
        }
        q.push(make_pair(per[i], i));
        inside[i]++;
        removed[i] = per[i];
        cout << i << " " << per[i] << endl;
    }
    // q.push(make_pair(min, pos));
    ll cost = 0;
    while (!q.empty()) {
        pair<int, int> p = q.top();  //weight, vertex
        q.pop();
        if (removed[p.second] == 0 || inside[p.second] > 1) {
            if (inside[p.second] > 0) inside[p.second]--;
            continue;
        }
        int u = p.second;
        cout << "At: " << u << endl;
        bool allRemoved = true;
        for (int v : adj[u]) {
            cout << "\tNeighbor: " << v << " " << removed[v];
            if (removed[v] != 0) {
                allRemoved = false;
                cout << "   + " << per[u];
                removed[v] -= ar[u];  //Weight of neighbors for v decreases since u no longer exists
                per[v] -= ar[u];
                //per[u] -= ar[v];   //
                removed[u] = 0;  //Completely removed.
                if (per[v] != 0) {
                    q.push(make_pair(per[v], v));
                    inside[v]++;
                }
                cout << "    per[v]: " << per[v] << "  per[u]: " << per[u];
            }
            cout << endl;
        }
        if (!allRemoved)
            cost += per[u];  //Increase cost. We are removing vertex u.
        cout << "\tFinal Cost: " << cost << endl;
    }
    cout << cost << endl;
}
/* 

4 3
10 20 30 40
1 4
1 2
2 3

 */
