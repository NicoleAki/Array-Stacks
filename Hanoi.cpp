#include <iostream>

using namespace std;


class Stack {
    
    int* arr;
    int top;
    int capacity;

    public:
    
        Stack(int size) { 
            arr = new int[size];
            capacity = size;
            top = -1;
        }

        ~Stack() {
            delete[] arr;
        }

        // Function to add an element to the stack
        void push(int x) {
            //Write your code here
            if (top == capacity -1){
                cout << "Overflow\n";
                
            }
            else{
                top++;
                arr[top] = x;
                
            }
        }

        // Function to pop the top element
        int pop() {
            //Write your code here
            if (top == -1){
                cout <<"Underflow\n";
                return -1;
            }
            else{
                int element = arr[top];
                top--;
                return element;
            }


        }

        // Function to display the elements of the stack
        void display() const {
            if (isEmpty()) {
                cout << "Empty";
            } else {
                for (int i = 0; i <= top; i++) {
                    cout << arr[i] << " ";
                }
            }
            cout << endl;
        }

    private:
    
        // Function to check if the stack is full
        bool isFull() const {
            //Write your code here
            return top == capacity -1;
        }

        // Function to check if the stack is empty
        bool isEmpty() const {
            //Write your code here
            return top == -1;
        }

};

// Stacks have been defined globally for the towers A, B, and C for printing the towers at each step
Stack* A;
Stack* B;
Stack* C;

// Function to display the contents of the towers
void displayTowers() {
    cout << "Tower A: ";
    A->display();
    cout << "Tower B: ";
    B->display();
    cout << "Tower C: ";
    C->display();
    cout << "\n";
}

void rearrangeDisks(int n, Stack& A, Stack& B, Stack& C, char from, char to, char aux) {
    //Write your code here
    // Base Case: n=1
    //Move n from A to C
    if (n == 1){
        int x = A.pop();
        C.push(x);
        cout << "Move disk " << x << " from " << from << " to " << to << endl;
        displayTowers(); 
    }
    else{
        //Move n-1 disks from A to B through C
        rearrangeDisks(n-1, A, C, B,from,aux,to);
        //Move the nth disk from A to C
        int x = A.pop();
        C.push(x);
        cout << "Move disk " << x << " from " << from << " to " << to << endl;
        displayTowers();   
         //Move n-1 disks from B to C through A
         rearrangeDisks(n-1, B, A, C,aux,to,from);
    }
}

int main() { 
    int n;
    cin >> n;
    if (n <= 0) {
        cout << "Invalid Input" << endl;
        return 0;
    }

    A = new Stack(n);
    B = new Stack(n);
    C = new Stack(n);

    for (int i = n; i >= 1; i--) {
        A->push(i);
    }

    displayTowers();

    rearrangeDisks(n, *A, *B, *C, 'A', 'C', 'B');

    delete A;
    delete B;
    delete C;

    return 0;
}
