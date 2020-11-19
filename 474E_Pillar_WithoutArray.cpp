#include <iostream>

#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;

#include <string>
#include <vector>
typedef vector<int> vi;
//#include <algorithm>
#include <set>
//#include <map>
//#include <unordered_set>
#include <unordered_map>
//#include <cmath>
//#include <cstring>
//#include <sstream>
//#include <stack>
//#include <queue>
ll n, power;
vector<pair<ll, int> > tree;
vector<ll> lazy, start, endA;
unordered_map<ll, int> u;
int binSearch(ll target, vector<ll> sorted, int i) {
    int lo = 0, hi = sorted.size();
    int best = 1000000;
    // cout << "T h:" << target << " at " << i << "\n";
    while (lo <= hi && lo < sorted.size()) {
        int mid = (lo + hi) / 2;
        if (sorted[mid] < target || u[sorted[mid]] <= i) {
            lo = mid + 1;
        } else {
            // cout << " ||| " << sorted[mid] << " id " << u[sorted[mid]] << "\n";
            // best = min(best, u[sorted[mid]]);
            best = mid;
            hi = mid - 1;
        }
    }
    if (best == 1000000) return -1;
    return best;
}
int minSearch(ll target, vector<ll> sorted, int i) {
    int lo = 0, hi = sorted.size();
    int best = 1000000;
    // cout << "T l:" << target << " at " << i << "\n";
    while (lo <= hi && lo < sorted.size()) {
        int mid = (lo + hi) / 2;
        if (sorted[mid] > target || u[sorted[mid]] <= i) {
            // cout << "     " << sorted[mid] << " bad at  " << u[sorted[mid]] << endl;
            hi = mid - 1;
        } else {
            // cout << " ||| " << sorted[mid] << " id " << u[sorted[mid]] << "\n";
            // best = min(best, u[sorted[mid]]);
            best = mid;
            lo = mid + 1;
        }
    }
    if (best == 1000000) return -1;
    return best;
}
void build() {
    for (int i = 0; i < power; i++) {
        start[i + power] = i + 1;
        endA[i + power] = i + 1;
        tree[i + power] = mp(0, i);
    }
    for (int i = power - 1; i >= 1; i--) {
        start[i] = start[i * 2];
        endA[i] = endA[i * 2 + 1];
        tree[i] = mp(0, i);
    }
}
void push(int i);
void update(int s, int e, ll val, int index = 1) {
    // cout << "  updating  " << s << " - " << e << " at index " << index << "\n";
    if (s <= start[index] && endA[index] <= e) {
        lazy[index] += val;
        if (val > tree[index].first) {
            tree[index].first = val;
            // cout << "  " << index << " became => " << tree[index].first << endl;
        }
    } else if (s > endA[index] || e < start[index]) {
    } else {
        push(index);
        update(s, e, val, index * 2);
        update(s, e, val, index * 2 + 1);

        if (tree[index * 2].first > tree[index * 2 + 1].first) {
            tree[index] = tree[index * 2];
            // cout << " index is now " << tree[index].first << "\n";
        } else {
            tree[index] = tree[index * 2 + 1];
            // cout << " index is now " << tree[index].first << "\n";
        }
    }
}
void push(int index) {
    if (lazy[index] == 0) return;
    update(start[index], endA[index], lazy[index], index * 2);
    update(start[index], endA[index], lazy[index], index * 2 + 1);
    lazy[index] = 0;
}
ll query(int s, int e, int index = 1) {
    // cout << "querying  " << s << " - " << e << " at index " << index << "\n";
    if (index == 1) cout << "2 is " << tree[2].first << endl;
    if (s <= start[index] && endA[index] <= e) {
        // cout << "  returning " << tree[index].first << " from " << index << "\n";
        // if (index == 2) cout << "\n--------RETURNING " << tree[index].first << "\n";
        return tree[index].first;
    } else if (s > endA[index] || e < start[index]) {
        return 0;
    } else {
        push(index);
        ll q1 = query(s, e, index * 2);
        ll q2 = query(s, e, index * 2 + 1);
        // cout << " returning max of " << q1 << " & " << q2 << " from " << index << "  == " << max(q1, q2) << "\n";
        // if (index == 2) cout << "\n--------RETURNING " << max(q1, q2) << "\n";
        return max(q1, q2);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll d;
    cin >> n >> d;
    power = 1;
    ll nums[n];
    set<ll> unique;
    ll biggest = -1, smallest = 1e16;
    vector<ll> sorted(n);
    for (int tr = 0; tr < n; tr++) {
        cin >> nums[tr];
        sorted[tr] = nums[tr];
        u[nums[tr]] = tr;
        unique.insert(nums[tr]);
        if (nums[tr] > biggest) biggest = nums[tr];
        if (nums[tr] < smallest) smallest = nums[tr];
    }
    sort(sorted.begin(), sorted.end());
    vector<ll> mappings(unique.size());
    int c = 0;
    ll compressed[n];
    unordered_map<ll, int> makeCompressed;
    int lowBar = 1, upBar = unique.size();
    for (ll i : unique) {
        mappings[c++] = i;
        makeCompressed[i] = c;
        cout << i << " = " << c << "\n";
    }
    while (power < unique.size()) power *= 2;

    for (int i = 0; i < n; i++) {
        compressed[i] = distance(unique.begin(), unique.find(nums[i])) + 1;
    }
    tree.resize(power * 2);
    lazy.resize(power * 2);
    endA.resize(power * 2);
    start.resize(power * 2);
    build();

    int bestPos = n - 1;
    ll best = 1;
    int goToNext[n + 1];  //dp that stores the position of the pillar that gives us the best option.
    for (int i = n - 1; i >= 0; i--) {
        ll com = compressed[i];
        ll num = nums[i];
        cout << nums[i] << " is " << com << "\n";
        ll upper = num + d;
        ll lower = num - d;
        ll greatest = 1;
        int next = -1;
        if (i == n - 1) {
            goToNext[i] = -1;
        } else {
            if (lower >= smallest) {
                /*  // if (i == n - 2) cout << "L: " << lower << endl;
            auto lo = lower_bound(sorted.begin(), sorted.end(), lower);
            int pos = lo - sorted.begin();
            if (lo != sorted.end()) {
                while (nums[pos] > lower && pos < n) pos++;
            }
            if (pos < n) {
                // cout << "vector: " << *lo << " | ";
                // cout << pos << " , " << nums[pos] << " |  ";
            } */
                int pos = minSearch(lower, sorted, i);
                // Position in the sorted array where we found the #
                if (pos == -1) {
                    // cout << " not possible";
                    next = -1;
                } else {
                    int mapped = makeCompressed[sorted[pos]];
                    // TODO
                    // - Take mapped, and get its original position. Store it in goToNext[i]
                    // cout << "  Low: " << lowBar << " , " << mapped << "\n";
                    ll q = query(lowBar, mapped);
                    // cout << "   Low query (" << lowBar << "," << mapped << ") --> " << q << "\n";
                    greatest = max(greatest, q + 1);
                    if (greatest > 1) next = u[sorted[pos]];
                    cout << "  " << mapped << " " << mappings[mapped - 1] << endl;
                    // cout << " lPos: " << pos << " " << sorted[pos] << "  |  Compressed : " << mapped << " " << mappings[mapped - 1];
                }
            }
            //mapped is the compressed number
            if (upper <= biggest) {
                int pos = binSearch(upper, sorted, i);
                if (pos == -1) {
                    // cout << " not possible";
                } else {
                    int mapped = makeCompressed[sorted[pos]];
                    // cout << "  Hi: " << mapped << " , " << upBar << "\n";
                    ll q = query(mapped, upBar);
                    // cout << "   High query (" << mapped << "," << upBar << ") --> " << q << "\n";
                    if (q + 1 > greatest) next = u[sorted[pos]];
                    greatest = max(greatest, q + 1);
                    cout << "  " << mapped << " " << mappings[mapped - 1] << endl;
                    // cout << "     hPos: " << pos << " " << sorted[pos] << "  |  Compressed : " << mapped << " " << nums[mapped];
                }
                /* auto hi = lower_bound(sorted.begin(), sorted.end(), upper);
            if (hi != sorted.end()) {
                int pos = hi - sorted.begin();
                int mapped = u[sorted[pos]];

                cout << " Pos: " << pos << " " << sorted[pos] << " " << *hi << "  |  Original location : " << mapped << " " << nums[mapped];
            } */
            }
        }
        // cout << nums[i] << " :  " << greatest;
        update(com, com, greatest);
        // cout << "_Updated " << com << " to " << greatest << "\n";
        cout << endl;
        cout << endl;
        goToNext[i] = next;
        // cout << "--------------\n  ";
        if (greatest > best) {
            best = greatest;
            bestPos = i;
        }
    }
    cout << "BEST is : " << best << " , " << bestPos << "\n";
    for (int i = 0; i < n; i++) cout << goToNext[i] << " ";
}