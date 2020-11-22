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
#include <cmath>
//#include <cstring>
//#include <sstream>
//#include <stack>
//#include <queue>

double gcf(int a, int b) {
    if (a == 0) return b;
    if (a > b)
        return (a % b, b);
    return (b % a, a);
}
bool debug = false;
double nCr(double a, double b) {
    /* double ans = 1;
    double o = a - b;
    for (ll i = a; i > b; i--) {
        ans *= i;
        double g = gcf((int)i, (int)o);
        ans /= g;
        o /= g;
         if(debug)
        cout << "\t" << ans << " " << o << "   g: " << g << endl;
    }
    return ans; */
    double res = 1;

    for (int i = 0; i < b; ++i) {
        res *= (a - i);
        res /= (i + 1);
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s1, s2;
    cin >> s1 >> s2;
    int target = 0, net = 0;
    int u = 0;
    int p1 = 0, n1 = 0;
    int p2 = 0, n2 = 0;
    for (char c : s1) {
        if (c == '+') {
            target++;
            p1++;
        } else {
            target--;
            n1++;
        }
    }
    for (char c : s2) {
        if (c == '+') {
            net++;
            p2++;
        } else if (c == '?')
            u++;
        else {
            n2++;
            net--;
        }
    }
    cout.precision(15);
    if (abs(target - net) > u && u > 0) {
        cout << "0.000000000000\n";
    } else if (u == 0) {
        if (target == net)
            cout << "1.000000000000\n";
        else
            cout << "0.000000000000\n";
    } else {
        double a, b;
        if (debug)
            cout << target << " " << net << endl;
        double dif = target - net;

        if (dif == 0) {
            p1 -= p2;
            n1 -= n2;
            if (debug)
                cout << u << " " << p1 << " " << n1 << endl;
            if (debug)
                cout << "nCR: " << nCr(u, max(p1, n1)) << endl;
            a = nCr(u, max(p1, n1)) / pow(2, u);
        } else if (dif > 0) {
            int posi = u / 2;
            int negi = u / 2;
            if (u % 2 == 1) posi++;
            while (posi - negi != dif) {
                posi++;
                negi--;
            }
            if (debug)
                cout << posi << " " << negi << endl;
            if (posi == u) {
                a = 1.0 / pow(2, u);
            } else {
                a = nCr(u, max(posi, negi)) / pow(2, u);
            }
        } else {
            int posi = u / 2;
            int negi = u / 2;
            if (u % 2 == 1) negi++;
            while (posi - negi != dif) {
                posi--;
                negi++;
            }
            if (debug)
                cout << posi << " " << negi << endl;
            if (negi == u) {
                a = 1.0 / pow(2, u);
            } else {
                a = nCr(u, max(posi, negi)) / pow(2, u);
            }
        }
        cout << a << endl;
    }
}
