//queue menggunakan array
#include <iostream>

using namespace std;

const int MAX_SIZE = 100;

class queue {
    private:
        int arr[MAX_SIZE];
        int front, rear;
    public:
        queue(){
            front = -1;
            rear = -1;
        }
        bool isempty(){
            return front == -1 && rear == -1;
        }
        bool isfull(){
            return (rear + 1) % MAX_SIZE == front;
        }
        void enqueue(int x){
            if(isfull()){
                cout << "Queue is full" << endl;
                return;
            }
            if(isempty()){
                front = rear = 0;
            } else {
                rear = (rear + 1) % MAX_SIZE;
            }
            arr[rear] = x;
        }
        void dequeue(){
            if(isempty()){
                cout << "Queue is empty" << endl;
                return;
            } else if(front == rear){
                front = rear = -1;
            } else {
                front = (front + 1) % MAX_SIZE;
            }
        }
    int peek() {
        if (isempty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[front];
    }

    void display() {
        if (isempty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        int count = (rear + MAX_SIZE - front) % MAX_SIZE + 1;
        cout << "Queue elements: ";
        for (int i = 0; i < count; i++) {
            int index = (front + i) % MAX_SIZE;
            cout << arr[index] << " ";
        }
        cout << endl;
    }
};

int main() {
    queue q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    q.display();

    cout << "Front element is: " << q.peek() << endl;

    q.dequeue();
    q.display();

    cout << "Front element is: " << q.peek() << endl;

    return 0;
}
