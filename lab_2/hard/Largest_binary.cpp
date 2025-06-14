#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

// Helper to find the largest rectangle in a histogram
int largestRectangleArea(vector<int>& heights) {
    stack<int> s;
    int maxArea = 0;
    heights.push_back(0); // Sentinel

    for (int i = 0; i < heights.size(); ++i) {
        while (!s.empty() && heights[i] < heights[s.top()]) {
            int height = heights[s.top()];
            s.pop();
            int width = s.empty() ? i : i - s.top() - 1;
            maxArea = max(maxArea, height * width);
        }
        s.push(i);
    }

    heights.pop_back(); // Remove sentinel
    return maxArea;
}

// Main function to find max rectangle of 1s
int maximalRectangle(vector<vector<int>>& mat) {
    if (mat.empty() || mat[0].empty()) return 0;

    int rows = mat.size(), cols = mat[0].size();
    vector<int> heights(cols, 0);
    int maxRect = 0;

    for (int i = 0; i < rows; ++i) {
        // Build up heights histogram
        for (int j = 0; j < cols; ++j) {
            heights[j] = (mat[i][j] == 0) ? 0 : heights[j] + 1;
        }
        // Compute max area from histogram
        maxRect = max(maxRect, largestRectangleArea(heights));
    }

    return maxRect;
}

int main() {
    int rows, cols;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    vector<vector<int>> mat(rows, vector<int>(cols));
    cout << "Enter the binary matrix (only 0s and 1s):\n";
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            cin >> mat[i][j];

    int result = maximalRectangle(mat);
    cout << "Maximum rectangle area with all 1's is: " << result << endl;

    return 0;
}
