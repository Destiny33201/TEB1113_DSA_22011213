#include <iostream>
#include <vector>
using namespace std;

int main(){
	// declare variable of matrix and counter
	int count = 1;
	int Matrix[3][3];
	
	// user input matrix
	for (int i = 0;i<3;i++){
		for (int j=0;j<3;j++){
			cout << "Enter your " << count << "# number: ";
			cin >> Matrix[i][j];
			count++;
		}
	}
	// displaying matrix
	cout << "\nMatrix:\n";
	for (int i = 0;i<3;i++){
		for (int j=0;j<3;j++){
			cout << Matrix[i][j] << " ";
		}
		cout << '\n';
	}

// Step 1: Extract outer layer into a vector (in order)
    vector<int> outer;

    // Top row (left to right)
    for (int j = 0; j < 3; j++) outer.push_back(Matrix[0][j]);

    // Right column (top to bottom, skip first)
    for (int i = 1; i < 3; i++) outer.push_back(Matrix[i][2]);

    // Bottom row (right to left, skip last)
    for (int j = 1; j >= 0; j--) outer.push_back(Matrix[2][j]);

    // Left column (bottom to top, skip first & last)
    for (int i = 1; i > 0; i--) outer.push_back(Matrix[i][0]);

    // Step 2: Rotate outer layer by 1 (clockwise)
    int last = outer.back();
    outer.pop_back();
    outer.insert(outer.begin(), last);

    // Step 3: Put rotated values back into matrix

    int idx = 0;

    // Top row
    for (int j = 0; j < 3; j++) Matrix[0][j] = outer[idx++];

    // Right column
    for (int i = 1; i < 3; i++) Matrix[i][2] = outer[idx++];

    // Bottom row
    for (int j = 1; j >= 0; j--) Matrix[2][j] = outer[idx++];

    // Left column
    for (int i = 1; i > 0; i--) Matrix[i][0] = outer[idx++];

    // Show rotated matrix
    cout << "\nMatrix after 1-step clockwise rotation of outer layer:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << Matrix[i][j] << " ";
        }
        cout << '\n';
    }
	
	
	return 0;
}