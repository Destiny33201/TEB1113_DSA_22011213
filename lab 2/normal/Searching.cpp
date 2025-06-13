#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Function to find any peak element's coordinates
pair<int, int> findPeak(const vector<vector<int>>& mat) {
    int rows = mat.size();
    int cols = mat[0].size();

    // Loop through all elements
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int curr = mat[i][j];

            // Neighbors (use INT_MIN for missing edges)
            int top    = (i > 0)      ? mat[i - 1][j] : INT_MIN;
            int bottom = (i < rows-1) ? mat[i + 1][j] : INT_MIN;
            int left   = (j > 0)      ? mat[i][j - 1] : INT_MIN;
            int right  = (j < cols-1) ? mat[i][j + 1] : INT_MIN;

            if (curr >= top && curr >= bottom && curr >= left && curr >= right) {
                return {i, j}; // Return first peak found
            }
        }
    }

    return {-1, -1}; // Should never happen per problem statement
}

int main() {
    int rows, cols;
    int count = 1;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    vector<vector<int>> mat(rows, vector<int>(cols));

    cout << "Enter matrix values row by row:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
        	cout << "Enter your " << count << "# number: ";
            cin >> mat[i][j];
            count++;
        }
    }

    pair<int, int> peak = findPeak(mat);
    cout << "Peak found at: " << peak.first << ", " << peak.second << " with value " << mat[peak.first][peak.second] << endl;

    return 0;
}
