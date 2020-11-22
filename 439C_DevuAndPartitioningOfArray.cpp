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
#define pii pair<int, int>
#define pil pair<int, ll>
#define SET(a, c) memset(a, c, sizeof a)
#define MOD 1000000007
#define enld endl
#define endl "\n"
#define fi first
#define se second
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

#include <string>
#include <vector>
typedef vector<int> vi;
#include <algorithm>
#define fore(i, l, r) for (int i = int(l); i < int(r); ++i)
#define forn(i, n) fore(i, 0, n)
#define fori(i, l, r) fore(i, l, (r) + 1)
#define forit(i, a) for (typeof((a).begin()) i = (a).begin(); i != (a).end(); ++i)
#define sz(v) int((v).size())
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define mp make_pair
#define X first
#define Y second

template <typename T>
inline T abs(T a) { return ((a < 0) ? -a : a); }
template <typename T>
inline T sqr(T a) { return a * a; }

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

const int N = (int)1e5 + 100;
int a[N];

void print(vector<int> v) {
    //assert(sz(v) >= 1);
    cout << sz(v) << " ";
    forn(i, sz(v)) {
        if (i) cout << " ";
        cout << v[i];
    }
    cout << endl;
}

int main() {
    int n, k, p;
    cin >> n >> k >> p;
    forn(i, n) cin >> a[i];

    vector<vector<int> > answer;
    vector<int> even, odd;

    forn(i, n) {
        if (a[i] % 2)
            odd.pb(a[i]);
        else
            even.pb(a[i]);
    }

    int oddNeed = k - p;
    int evenNeed = p;
    int ok = true;

    if (sz(odd) < oddNeed || sz(odd) % 2 != oddNeed % 2) {
        ok = false;
    } else {
        if (sz(even) + (sz(odd) - oddNeed) / 2 < evenNeed) {
            ok = false;
        } else {
            forn(i, oddNeed) {
                vector<int> v;
                v.pb(odd[odd.size() - 1]);
                odd.pop_back();
                answer.pb(v);
            }

            //assert(sz(odd) % 2 == 0);

            while (odd.size() >= 2) {
                vector<int> v;
                v.pb(odd[odd.size() - 1]);
                odd.pop_back();
                v.pb(odd[odd.size() - 1]);
                odd.pop_back();
                answer.pb(v);
                evenNeed--;
            }

            forn(i, sz(even)) {
                vector<int> v;
                v.pb(even[i]);
                answer.pb(v);
            }
        }
    }

    if (!ok) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;

        //cout << sz(answer) << endl;

        vector<int> last;
        //assert(answer.size() >= k);
        for (int i = k - 1; i < answer.size(); i++) {
            forn(j, answer[i].size()) {
                last.pb(answer[i][j]);
            }
        }

        forn(i, k - 1) {
            print(answer[i]);
        }

        //cout << sz(last) << endl;

        print(last);
    }

    return 0;
}
