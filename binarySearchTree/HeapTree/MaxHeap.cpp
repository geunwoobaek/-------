#include<bits/stdc++.h>
using namespace std;

struct Maxheap
{
    int *data;
    int size;
    int capacity;
    int Parent(int now){
        if(now&1) return now>>1;
        else return (now>>1)-1;
    }
    int right(int p){return (p<<1)+2;}
    int left(int p){return (p<<1)+1;}
    int next(int l,int R){return data[l]>data[R]?l:R;}
    Maxheap(int size)
    {
        this->size = size;
        capacity=-1;
        data = new int[size + 1];
    }
    void insert(int target) //밑에서부터 위로올라가는방식
    {  
        if(capacity==size) return; //꽉찼을시
        if(++capacity==0) data[0]=target; 
        else{
            int index=capacity;
            data[index]=target;
            int p=Parent(index);
            while(data[p]<data[index]){
                    swap(data[p],data[index]);
                    index=p;
                    p=Parent(p);
                }              
            }    
    }
    int extractMaxheap(){
        int answer=data[0];
        remove();
        return answer;
    }
    void remove(){
        int index=0;
        data[index]=data[capacity--];
        if(capacity==0) return;
        int leftChild=left(index);
        int rightChild=right(index);
        int nextChild= next(leftChild,rightChild);
        while(data[index]<data[nextChild]){
            swap(data[index],data[nextChild]);
            index=nextChild;
            nextChild=next(left(nextChild),right(nextChild));
        }
    }
};

int main()
{
    Maxheap h(10);
    h.insert(3); 
    h.insert(2); 
    cout<<h.extractMaxheap()<<","; 
    h.insert(15); 
    h.insert(5); 
    h.insert(4); 
    h.insert(45); 
    cout<<h.extractMaxheap(); 
    return 0; 
}