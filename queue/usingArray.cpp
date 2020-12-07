#include<bits/stdc++.h> 
using namespace std;

struct Queue_
{
    int* arr;
    int front;
    int rear;
    int capacity;

    Queue_(int n)
    {
        capacity = n;
        front = rear = -1;
        arr = new int[n];
    }
    void push(int value);
    void pop();
    void clear();
    int enqueue();
    int go_next(int index);
    void display();
};
void Queue_::push(int value)
{
    if (front != -1)
    {
        int next = go_next(rear);
        if (next == front)
            cout << "full" << endl;
        else
        {
            rear = next;
            arr[rear] = value;
        }
    }
    else
    {
        front = rear = 0;
        arr[front] = value;
    }
    display();
}
void Queue_::pop()
{
    if ((front == -1) && (front == rear))
        cout << "empty";
    else
    {
        arr[front] = 0;
        front = go_next(front);
    }
}
int Queue_::enqueue()
{
    if (front == -1 && front == rear)
    {
        cout << "empty";
        return 0;
    }
    else
    {
        return arr[front];
    }
}
void Queue_::clear()
{
    memset(arr, 0, sizeof(arr));
    front = rear = -1;
}
int Queue_::go_next(int index)
{
    return (index + 1) % capacity;
}
void Queue_::display()
{
    if (front == -1) return;
    int index = front;
    cout << arr[front]<<" ";
    while (index != rear) {
        index = go_next(index);
        cout << arr[index]<<" ";
    }
    cout << endl;
}
int main()
{
    Queue_* que = new Queue_(5);
    que->push(1);
    que->push(2);
    que->pop();
    que->push(3);
    que->push(4);
    que->pop();
    que->push(5);
    que->push(6);
    que->pop();
    que->push(7);
    que->push(8);
    que->pop();
    que->push(9);
    que->push(10);
    return 0;
}