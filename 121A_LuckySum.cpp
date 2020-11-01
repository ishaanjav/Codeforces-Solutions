#include <iostream>
using namespace std;

#define ll long long
#define pb push_back
#define ins insert
#define mp make_pair
#define pii pair<int, int>
#define pil pair<int, ll>
#define pib pair<int, bool>
#define SET(a, c) memset(a, c, sizeof(a))
#define MOD 1000000007
#define enld endl
#define endl "\n"
#define fi first
#define se second
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define found(u, val) u.find(val) != u.end()

#include <string>
#include <vector>
typedef vector<int> vi;
typedef vector<ll> vl;
#include <algorithm>

vl gen;
void generate(int length = 0, string s = "") {
    if (length == 10) return;
    gen.pb(stoll(s + "4"));
    gen.pb(stoll(s + "7"));
    generate(length + 1, s + "4");
    generate(length + 1, s + "7");
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll l, r;
    cin >> l >> r;
    generate();
    sort(all(gen));
    ll sum = 0;
    int pos;
    for (int i = 0; i < gen.size(); i++) {
        if (gen[i] >= l) {
            pos = i;
            break;
        }
    }
    int pos2 = 0;
    for (int i = 0; i < gen.size(); i++) {
        if (gen[i] >= r) {
            pos2 = i;
            break;
        }
    }
    cout << pos << " " << pos2 << endl;
    if (pos == pos2) {
        sum = (r - l + 1) * gen[pos];
    } else {
        sum = (gen[pos] - l + 1) * gen[pos];
        for (int i = pos + 1; i <= pos2 - 1; i++)
            sum += (gen[i] - gen[i - 1]) * gen[i];
        sum += gen[pos2] * (r - gen[pos2 - 1]);
    }
    cout << sum;
}