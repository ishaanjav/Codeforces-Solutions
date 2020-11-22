/*
 * Created by ishaanjav
 * github.com/ishaanjav
 * Codeforces Solutions: https://github.com/ishaanjav/Codeforces-Solutions
 */

#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int q;
    cin >> q;
    while (q--) {
        int rows, cols;
        cin >> rows >> cols;
        // Grid is the grid we read from input
        string grid[rows];
        for (int i = 0; i < rows; i++) cin >> grid[i];

        // Except for the Input, Output, and min function, the rest of the code is exactly the same as Java

        // In the worst case our answer is rows + cols - 1. We do -1 because we don't want to count the center square twice.
        int ans = rows + cols - 1;

        // EXPLANATION OF SOLUTION
        // To solve this problem, we have to go through every single position in our grid
        //   and count the number of X's required to make a cross. This is pretty much the only way to do it.
        //   we do this by treating each position as the center of our cross and counting the # of X's missing in its row and column
        // But, if we do this trivially, we'd have an O(n^3) time complexity which wouldn't pass
        //    It is O(n^3) because there are n^2 elements to go through and it takes linear time to go through that element's row and column.
        // ----
        // The idea is to do precomputations to bring it down to O(n^2)
        // The way that this works is:
        //    for position (0,0) we need to know the # of crosses in row 0 and column 0.
        //    for position (0,1) we need to know the # of crosses in row 0 and column 1.
        //    for position (0,2) we need to know the # of crosses in row 0 and column 2.
        // ......
        //  Do you see that for all those positions we need to know the # of crosses in row 0?
        //  Rather than repeatedly counting this, beforehand we go through the grid array and count the # of xs in each row
        //   We repeat the same thing with columns.
        //  And we store these values in arrays.
        //  Now, all we have to do is for each element in our grid.
        //   The number of x's required to make a cross is
        //   rows + cols - # of X's in row - # of X's in column
        //   To get the # of X's in the rows and columns, we can use the arrays we created from precomputation
        //   there is one special case: if the current element is a . not an X, then we have to make that an X as well so we add 1 to the number above
        //  And our answer is the minimum out of that equation for every element
        // See the code below!

        // rowFilled[row] = # of X's in row
        // colFilled[column] = # of X's in column
        int rowFilled[rows], colFilled[cols];
        for (int i = 0; i < rows; i++) {
            int counter = 0;
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] != '.') {
                    counter++;
                }
            }
            rowFilled[i] = counter;
        }
        for (int j = 0; j < cols; j++) {
            int counter = 0;
            for (int i = 0; i < rows; i++) {
                if (grid[i][j] != '.') {
                    counter++;
                }
            }
            colFilled[j] = counter;
        }
        // After doing precomputations, for each position calculate the minimum # of X's we need to add to make a cross
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == '.') {
                    ans = min(ans, rows + cols - (rowFilled[i] + colFilled[j] + 1));
                } else {
                    ans = min(ans, rows + cols - (rowFilled[i] + colFilled[j]));
                }
                // 0 is the lowest we can go so break.
                if (ans == 0) break;
            }
            if (ans == 0) break;
        }
        //Print answer
        cout << ans << endl;
    }
}
