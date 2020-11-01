using namespace std;
#include <cstring>
#include <iostream>
#include <queue>
#include <stack>

long long parent[101];
long long size[101];

long long findParent(long long i) {
    if (parent[i] != parent[parent[i]]) parent[i] = findParent(parent[i]);
    return parent[i];
}

vector<pair<long long, long long> > intervals;

void unionNodes(int p1, int p2) {
    int parentA = findParent(p1), parentB = findParent(p2);
    if (parentA == parentB) return;
    int a = intervals[p1].first, b = intervals[p1].second, c = intervals[p2].first, d = intervals[p2].second;

    if (size[parentB] > size[parentA]) swap(parentA, parentB);

    parent[parentB] = parentA;
    size[parentA] += size[parentB];
}

vector<vector<int> > adj;

int main() {
    int n;
    cin >> n;

    while (n--) {
        int co, x, y;
        cin >> co >> x >> y;

        if (co == 1) {
            intervals.push_back(make_pair(x, y));
            parent[intervals.size()] = intervals.size();
            vector<int> t;
            adj.push_back(t);
            for (int i = 0; i < intervals.size() - 1; i++) {
                // cout << " AT" << i << endl;
                int a = intervals[i].first, b = intervals[i].second, c = intervals[intervals.size() - 1].first, d = intervals[intervals.size() - 1].second;
                if ((c < a && a < d) || (c < b && b < d)) adj[i].push_back(intervals.size() - 1);
                swap(a, c);
                swap(b, d);
                if ((c < a && a < d) || (c < b && b < d)) adj[intervals.size() - 1].push_back(i);
            }
            // cout << "\nHI\n";

            /* for (int i = 1; i < intervals.size() - 1; i++) unionNodes(i, intervals.size());
            for (int i = 1; i <= intervals.size(); i++) cout << findParent(i) << " "; */
            // cout << endl;
        } else {
            bool reachable = false;
            stack<int> s;
            s.push(x - 1);
            bool visited[intervals.size() + 1];
            // cout << "SIZE: " << intervals.size() << endl;
            memset(visited, false, sizeof(visited));
            while (!s.empty() && !reachable) {
                int u = s.top();
                s.pop();
                // cout << "visiting " << u << " | " << adj[u].size() << "\n";
                if (u == y - 1) {
                    reachable = true;
                    break;
                }
                if (visited[u]) continue;
                visited[u] = 1;
                // cout << "i " << u << endl;

                for (int i : adj[u]) {
                    if (!visited[i]) {
                        // cout << "i " << i << endl;
                        s.push(i);
                    }
                }
            }
            cout << (reachable ? "YES\n" : "NO\n");
        }
    }
}