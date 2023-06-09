#include<iostream>
#include<queue>
using namespace std;
/*
1] By default Priority queue build a Max-heap
2] Priority queue is used using stl
*/

int main(){
    //Building a Priority Queue
    priority_queue<int> maxheap;
    //inserting elements in queue
    maxheap.push(4);
    maxheap.push(3);
    maxheap.push(10);
    maxheap.push(1);

    cout<<"Element at the top of priority queue: "<<maxheap.top()<<endl;
    cout<<"Size of the priority queue: "<<maxheap.size()<<endl;

    //deleting elements from queue
    maxheap.pop();

    cout<<"Size of the priority queue after pop operation : "<<maxheap.size()<<endl;

    if(maxheap.empty())
    {
        cout<<"pq is empty"<<endl;
    }
    else
    {
        cout<<"pq is not empty"<<endl;
    }

    //Building Min-Heap
    priority_queue<int,vector<int>,greater<int>> minheap; //syntax to design Min-heap
    //inserting elements in Min-Heap
    minheap.push(4);
    minheap.push(-1);
    minheap.push(0);
    minheap.push(55);
    minheap.push(1000);
    minheap.push(75);
    minheap.push(60);

    cout<<"Element at the top: "<<minheap.top()<<endl;
    return 0;
}