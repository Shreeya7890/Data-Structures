//Remove Duplicates from Array (Keep Unique Elements)
#include <iostream>
using namespace std;

// Main program
int main() {
    int test;
    cout << "Enter number of testcases: ";
    cin >> test;
    while (test--) {
        int n;
        cout << "Enter number of inputs for the case: ";
        cin >> n;
        int arr[n];
        cout << "Inputs:\n";
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cout << "Output: " << solve(arr, n) << endl;
    }
    return 0;
}

// Function to find the duplicates and return position to remove repetitions
int solve(int arr[], int n) {
    int index = n - 1;
    while (index >= 0) {
        for (int i = index - 1; i >= 0; i--) {
            if (arr[i] == arr[index]) {
                return i + 1;
            }
        }
        index--;
    }
    return 0;
}
