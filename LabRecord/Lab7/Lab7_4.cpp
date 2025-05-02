#include <iostream>
#include "Lab7_4.h"

using namespace std;

int main() {
    char input[MAX_SIZE], output[MAX_SIZE];

    cout << "Enter the string: ";
    cin >> input;

    processString(input, output);
    cout << "Processed string: " << output << endl;

    return 0;
}
