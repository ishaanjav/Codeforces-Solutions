/*
 * Created by ishaanjav
 * github.com/ishaanjav
 * Codeforces Solutions: https://github.com/ishaanjav/Codeforces-Solutions
 */

#include <iostream>
using namespace std;

#define ll long long
#define pb push_back
#define ins insert
#define mp make_pair
#define pii pair<int, int>
#define pil pair<int, ll>
#define pll pair<ll, ll>
#define pib pair<int, bool>
#define SET(a,c) memset(a,c,sizeof(a))
#define MOD 1000000007
#define Endl endl
#define endl "\n"
#define fi first
#define se second
#define rs resize
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define FOUND(u, val) u.find(val) != u.end()
#define max_self(a, b) a = max(a, b);
#define min_self(a, b) a = min(a, b);

#include <string>
#include <vector>
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<ll> vl;
typedef vector<bool> vb;
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

ll move(string from, string to){
	ll c = 0;
	while(from != to){
		from = from.substr(1) + from[0]; c++;
		if(c > from.length()) return -1;
	}
	return c;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
	cin >> n;

	string ar[n];
	for(string &x: ar) cin >> x;

	ll best = (n-1) * ar[0].length();
    for(int i = 0; i < n; i++){
		string str = ar[i];
		ll cur = 0;

		for(int j = 0; j < n; j++){
			if(i == j) continue;

			ll temp = move(ar[j], str);
			if(temp == -1){
				cout << -1;
				return 0;
			}

			cur += temp;
		}

		min_self(best, cur);
	}	
	cout << best;
}
