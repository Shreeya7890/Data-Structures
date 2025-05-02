//Header file for Round Robin 
#include <iostream>
#include <cstdlib>
using namespace std;

class RoundRobinScheduler {
private:
    struct process {
        int time;
        process* next;
    };
    process* head;
    process* tail;
    int timeSlice;

public:
    RoundRobinScheduler(int timeSlice);
    void insertProcess(int time);
    void execute();
    void display();
};


