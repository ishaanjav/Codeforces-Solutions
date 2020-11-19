#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    if (n % 2 == 0) {
        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= n / 2; j++) {
                int x = j + (n / 2) * i;
                cout << x << " " << (n - x) << " ";
            }
            cout << endl;
        }
    } else {
        for (int i = 0; i < n; i++) {
        }
    }
}