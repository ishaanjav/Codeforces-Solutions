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
//#include <algorithm>
//#include <set>
//#include <map>
//#include <unordered_set>
//#include <unordered_map>
//#include <cmath>
//#include <cstring>
//#include <sstream>
//#include <stack>
//#include <queue>

// 8/4/20
// FIRST GO LETS GO!!!!
int peeps, dances;

int colors[100001];
vector<int> adj[100001];
bool visited[100001];
void traverse(int pos, int color = 1) {
    if (visited[pos]) return;
    int alreadyUsed[4];
    for (int i = 0; i < 4; i++) alreadyUsed[i] = 0;
    visited[pos] = true;
    for (int v : adj[pos]) {
        // traverse(v);
        alreadyUsed[colors[v]]++;
    }
    int i;
    for (i = 1; i <= 3; i++) {
        if (alreadyUsed[i] == 0) {
            colors[pos] = i;
            break;
        }
    }
    if (i == 4) {
        cout << "ERROR " << pos << " does not have a color!\n";
    }
    for (int v : adj[pos]) {
        traverse(v);
        // alreadyUsed[colors[v]]++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> peeps >> dances;
    for (int i = 0; i < dances; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].pb(b);
        adj[a].pb(c);
        adj[b].pb(a);
        adj[b].pb(c);
        adj[c].pb(a);
        adj[c].pb(b);
    }
    for (int i = 1; i <= peeps; i++) {
        if (visited[i]) continue;
        traverse(i);
    }
    for (int i = 1; i <= peeps; i++) cout << colors[i] << " ";
}