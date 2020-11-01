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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for (int tr = 0; tr < n; tr++) {
        string s;
        cin >> s;
        int frequency[10];
        for (int i = 0; i < 10; i++) frequency[i] = 0;
        int biggest = 0;
        int nums = 0;
        int already = -1;
        bool alternating = true;
        char prev = 'a';
        for (char c : s) {
            frequency[c - '0']++;
            if (already == -1)
                nums = 1;
            else if (already != c - '0')
                nums++;
            already = c - '0';
            biggest = max(frequency[c - '0'], (int)biggest);
            if(prev == c) alternating = false;
            prev = c;
        }
        /*        if (s.length() % 2 == 1) {
            if (nums == 1)
                cout << s.length() - biggest << endl;
                else{

                }
        } else { */
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (frequency[i] == 0 && frequency[j] == 0) continue;
                int prev = -1;
                int erasors = 0;
                for (char c : s) {
                    int t = c - '0';
                    if (t != i && t != j) {
                        erasors++;
                    } else if (t == i) {
                        if (prev == t) erasors++;
                        prev = t;
                    } else if (t == j) {
                        if (prev == t) erasors++;
                        prev = t;
                    }
                }
                // cout << i << " " << j << "   | " << erasors << endl;
                biggest = min(biggest, erasors);
            }
        }
        if(alternating && nums == 2) biggest =0;
        cout << biggest << endl;
        //  }
    }
}
/* 
1
95831

 */