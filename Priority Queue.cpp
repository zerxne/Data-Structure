#include<iostream>
using namespace std;

struct element
{
    int priority;
    string thing;
};
element arr[1000000];

void MaxHeapify(int root, int length){

    int left = 2*root,right = 2*root + 1,largest=root;
    if (left <= length && arr[left].priority > arr[largest].priority)
        largest = left;
    if (right <= length && arr[right].priority > arr[largest].priority)
        largest = right;
    if (largest != root)
    {
        swap(arr[largest], arr[root]);
        MaxHeapify(largest, length);
    }
}

void HeapSort(int n)
{
    for(int i=n/2;i>=1;i--)
        MaxHeapify(i,n);
}

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>arr[i].thing>>arr[i].priority;
    HeapSort(n);
    cout<<"First three things to do:"<<endl;
    cout<<arr[1].thing<<endl;
    arr[1].priority=-1;
    HeapSort(n);
    cout<<arr[1].thing<<endl;
    arr[1].priority=-1;
    HeapSort(n);
    cout<<arr[1].thing<<endl;
    return 0;
}
