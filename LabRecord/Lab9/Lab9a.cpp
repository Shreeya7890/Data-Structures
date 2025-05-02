//Nene's game. 
//Keep eleiminating players till the no. of players left is just less than the smallest index being deleted
#include <iostream>
using namespace std;

int main() {
    int testcases;
    cin >> testcases;

    while (testcases--) {
        int no_pos, grps;
        cin >> no_pos >> grps;

        int pos[no_pos];
        int group[grps];

        for (int i = 0; i < no_pos; i++) {
            cin >> pos[i];
        }

        for (int i = 0; i < grps; i++) {
            cin >> group[i];
        }
        
        players(pos, group, no_pos, grps);
    }

    return 0;
}

//Function to find the minimum value
int Min(int arr[], int size) {
    int min_index = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < min_index) {
            min_index = arr[i];
        }
    }
    return min_index;
}

//Function to find number of remaining players.
void players(int pos[], int group[], int no_pos, int grps) {
    int smallest = Min(pos, no_pos);

    for (int i = 0; i < grps; i++) {
        int remaining = group[i];
        if (group[i] >= smallest) {
            remaining = smallest - 1;
        }
        cout << remaining << " ";
    }
    cout << endl;
}
