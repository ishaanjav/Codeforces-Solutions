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

pair<int, int> tree[262500];
int lazy[262500], start[262500], endA[262500];

void build() {
    for (int i = 0; i < 131072; i++) {
        start[i + 131072] = i + 1;
        endA[i + 131072] = i + 1;
        tree[i] = mp(0, i + 1);
    }
    for (int i = 131072 - 1; i > 0; i--) {
        start[i] = start[i * 2];
        endA[i] = endA[2 * i + 1];
        tree[i] = mp(0, 1);
    }
}
void push(int i);
void update(int s, int e, int val, int index = 1) {
    //cout << "UPDATING: " << index << "   " << start[index] << " , " << endA[index] << "\n";

    if (s <= start[index] && endA[index] <= e) {
        lazy[index] += val;
        //This interval will be itself + value we are updating interval with * size of interval.
        tree[index] = mp(tree[index].fi + val, s);
        //cout << "   updated " << index << " to " << tree[index].first << " at pos " << tree[index].se << "\n";
        //  val * (endA[index] - start[index] + 1);
    } else if (s > endA[index] || e < start[index]) {
    } else {
        push(index);
        int LEFT = index * 2, RIGHT = index * 2 + 1;
        update(s, e, val, LEFT);
        update(s, e, val, RIGHT);
        if (tree[LEFT].first >= tree[RIGHT].first)
            tree[index] = tree[LEFT];
        else
            tree[index] = tree[RIGHT];
    }
}
// Helper method to push lazy values down
int counter = 0;
void push(int index) {
    if (lazy[index] == 0) return;  // Nothing to push
    int LEFT = index * 2, RIGHT = index * 2 + 1;
    counter++;
    // Move changes into children
    update(start[index], endA[index], lazy[index], LEFT);
    update(start[index], endA[index], lazy[index], RIGHT);
    lazy[index] = 0;  // Nothing left to push
}

pair<int, int> query(int s, int e, int index = 1) {
    // //cout << "QUERYING: " << index << "   " << start[index] << " , " << endA[index] << "\n";
    if (s <= start[index] && e >= endA[index]) {  // Case 1
        // Bucket contained by query
        // //cout << "    returning " << tree[index].first << " from " << tree[index].se << "\n";
        return tree[index];
    } else if (s > endA[index] || e < start[index]) {  // Case 2
        // Bucket is disjoint from query
        return mp(-1000000000, 0);  // There were no problems
    } else {                        // Case 3
        // Some but not complete overlap
        int LEFT = index * 2, RIGHT = index * 2 + 1;
        push(index);
        pair<int, int> left = query(s, e, LEFT), right = query(s, e, RIGHT);
        if (right.first > left.first)
            return right;
        else if (right.first == left.first)
            return (right.second > left.second ? right : left);
        else
            return left;
        // return aggregate(query(s, e, LEFT), query(s, e, RIGHT));
    }
}
int main() {
    int n;
    cin >> n;
    int ar[n];
    build();
    vector<pair<pair<int, int>, int> > v(n);
    int dp[n];
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v[i] = mp(mp(a, a + b), i);
    }
    sort(v.begin(), v.end());
    vector<pair<int, int> > ans;
    for (int i = n - 1; i >= 0; i--) {
        int canReach = v[i].first.second;
        int lo = i + 1;
        int hi = n - 1;
        // //cout << i << " -------\n";
        int highest = i;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (canReach > v[mid].first.first) {
                // //cout << "   Mid: " << mid << "  " << dp[mid] << "\n";
                // //cout << lo << " " << mid << " " << hi << "\n";
                // dp[i] = max(mid - i + 1, dp[i]);
                // dp[i] = max(dp[i], dp[mid]);
                highest = mid;
                // //cout << i << ", " << mid << "\n";
                lo = mid + 1;
            } else {
                if (hi == mid) mid--;
                hi = mid;
            }
        }
        // if (highest == i) highest++;
        dp[i] = highest - i + 1;
        pair<int, int> best = query(i + 1, highest + 1);
        //cout << "Highest: " << highest << "   dp[i] " << dp[i] << "\n";
        //cout << "   Best: " << best.first << " " << best.second << "\n";
        dp[i] = max(dp[i], best.first + best.second - i - 1);
        // for (int j = i + 1; j <= highest; j++) dp[i] = max(dp[i], dp[j] + j - i);
        if (n == i + 1) dp[i] = 1;
        update(i + 1, i + 1, dp[i]);
        //cout << "looked for " << query(2, 32).first << endl;
        ans.pb(mp(v[i].second, dp[i]));
    }
    sort(ans.begin(), ans.end());
    for (int i = 0; i < n; i++)
        cout << ans[i].second << " ";
}