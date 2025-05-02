//Processing string with stack
#define MAX_SIZE 100 

class Stack {
    private:
        char arr[MAX_SIZE];
        int top;

    public:
        Stack() {
            top = -1;
        }
        bool isEmpty();
        bool isFull();
        void push(char ch);
        char pop();
};

void processString(char input[], char output[]);

// Check if stack is empty
bool Stack::isEmpty() {
    return top == -1;
}

// Check if stack is full
bool Stack::isFull() {
    return top == MAX_SIZE - 1;
}

// Push an element onto the stack
void Stack::push(char ch) {
    if (!isFull()) {
        arr[++top] = ch;
    }
}

// Pop an element from the stack
char Stack::pop() {
    if (!isEmpty()) {
        return arr[top--];
    }
    return '\0'; 
}

// Function to process the string
void processString(char input[], char output[]) {
    Stack st;
    int i = 0, j = 0;

    while (input[i] != '\0') {
        if (input[i] == '+') {
            if (!st.isEmpty()) {
                st.pop(); 
            }
        } else {
            st.push(input[i]); 
        }
        i++;
    }

    // Construct output from stack
    while (!st.isEmpty()) {
        output[j++] = st.pop();
    }

    // Reverse the output string
    for (int k = 0; k < j / 2; k++) {
        char temp = output[k];
        output[k] = output[j - k - 1];
        output[j - k - 1] = temp;
    }

    output[j] = '\0'; 
}

