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
vector<vi> adj;
int n, start, k;
vector<pair<int, int> > distances;
vector<pair<int, int> > orig;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    adj.resize(n);
    distances.resize(n);
    orig.resize(n);
    int zeroes = 0;
    for (int tr = 0; tr < n; tr++) {
        int a;
        cin >> a;
        if (a == 0) {
            zeroes++;
            start = tr;
        }
        distances[tr] = mp(a, tr);
        orig[tr] = mp(a, tr);
    }
    // cout << "START: " << start << endl;
    if (zeroes > 1)
        cout << -1;
    else {
        sort(distances.begin(), distances.end());
        int previousDist = 0;
        bool good = true;
        int children[n + 1];
        children[0] = 0;
        for (int i = 1; i < n; i++) {
            // cout << distances[i].second << " " << distances[i].first << " | " << previousDist << endl;
            children[i] = 0;
            if (distances[i].first == previousDist)
                continue;
            else if (distances[i].first == previousDist + 1)
                previousDist++;
            else {
                good = false;
                break;
            }
        }
        if (!good)
            cout << -1;
        else {
            int prevVertex = start;
            int prevDistance = 0;
            int pos = 0;
            good = true;
            // cout << endl;
            for (int i = 1; i < n; i++) {
                int distance = distances[i].first;
                int v = distances[i].second;
                // cout << v << " and " << distance << endl;
                if (distance == prevDistance + 1) {
                    if (children[prevVertex] == k) {
                        pos++;
                        if (pos == n) {
                            good = false;
                            break;
                        }
                        prevVertex = distances[pos].second;
                        if (prevVertex == n || distances[pos].first != distance - 1) {
                            good = false;
                            break;
                        }
                    }
                    // cout << "  " << prevVertex << " ---> " << v << "\n";
                    adj[prevVertex].pb(v);
                    children[prevVertex]++;
                } else {
                    prevDistance++;
                    while (distances[pos].first != prevDistance) {
                        pos++;
                        if (pos == n) {
                            good = false;
                            break;
                        }
                    }
                    if (!good) break;
                    prevVertex = distances[pos].second;
                    if (children[prevVertex] == k) {
                        pos++;
                        if (pos == n) {
                            good = false;
                            break;
                        }
                        prevVertex = distances[pos].second;
                        if (prevVertex == n || distances[pos].first != distance - 1) {
                            good = false;
                            break;
                        }
                    }
                    // cout << "  " << prevVertex << " ---> " << v << "\n";
                    adj[prevVertex].pb(v);
                    children[prevVertex]++;
                }
            }
            if (!good)
                cout << -1;
            else {
                // cout << "FINE\n";
                cout << n - 1 << endl;
                for (int i = 0; i < n; i++) {
                    for (int v : adj[i]) {
                        cout << i + 1 << " " << v + 1 << "\n";
                    }
                }
            }
        }
    }
}