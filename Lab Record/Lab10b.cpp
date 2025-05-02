//Word Game Between 3 Players
#include <iostream>
#include <unordered_map>
#include <vector>
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
        calculate(n);
    }
    return 0;
}

// Function to read input, compare words, calculate points, and print results
void calculate(int n) {
    unordered_map<string, int> wordcount;
    vector<vector<string>> words(3, vector<string>(n));

    cout << "Enter input:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n; j++) {
            cin >> words[i][j];
            wordcount[words[i][j]]++;
        }
    }

    vector<int> points(3, 0);
    for (int i = 0; i < 3; i++) {
        for (const string& word : words[i]) {
            if (wordcount[word] == 1) {
                points[i] += 3;
            } else if (wordcount[word] == 2) {
                points[i] += 1;
            }
        }
    }
    cout << "Results: " << points[0] << " " << points[1] << " " << points[2] << endl;
}

