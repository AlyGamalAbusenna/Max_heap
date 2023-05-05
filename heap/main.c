#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int n;
    int array[100];
}Heap;


Heap* newHeap()
{
    Heap *h=malloc(sizeof(Heap));
    h->n=0;
    return h;
}


void swap(int*x,int*y)       // Swap function
{
    int temp=*x;
    *x=*y;
    *y=temp;
}



void siftUp(int*arr,int i)          //Sifting the node up keeping in consideration to keep it a heap
{
    int parent=(i-1)/2;
    if(i&&arr[parent]<arr[i])
    {
        swap(&arr[parent],&arr[i]);
        siftUp(arr,parent);
    }
}
void siftDown(int*arr,int n,int i)     //Sifting the node down keeping in consideration to keep it a heap
{
    int largest=i;
    int l=(2*i)+1;
    int r=(2*i)+2;
    if (l<n && arr[l]>arr[largest])
        largest=l;
    if (r<n && arr[r]>arr[largest])
        largest=r;
    if (largest!=i)
    {
        swap(&arr[i],&arr[largest]);
        siftDown(arr,n,largest);
    }
}



void insert(Heap*h,int val)        // Inserting new node to the heap in the right place
{
    h->array[h->n]=val;
    siftUp(h->array,h->n);
    h->n++;
}




void pop(Heap*h)                  // Remove the parent node if exist
{
    if (!h->n) return;
    h->array[0]=h->array[--h->n];
    siftDown(h->array,h->n,0);
}




void display(Heap*h)             // Printing the Heap level by level
{
    for (int i=0;i<(h->n);i++)
    {
        printf("(%d)",h->array[i]);
    }
}




void buildHeap (int arr[],int n)    // Building a Heap from array by calling shiftDown function
{
    int start=(n/2)-1;
    for (int i=start;i>=0;i--)
        siftDown(arr,n,i);
}




void HeapSort(int arr[],int n)   // Sorting the Heap
{
    for (int i=n/2-1;i>=0;i--)
        siftDown(arr,n,i);
    for (int i=n-1;i>=0;i--)
    {
        swap(&arr[0],&arr[i]);
        siftDown(arr,n,i);
    }
}



           // Example for trial

int main()
{
    Heap*h=newHeap();
    insert(h,9);
    insert(h,4);
    insert(h,3);
    insert(h,7);
    insert(h,5);
    insert(h,12);
    display(h);
    pop(h);
    printf("\n");
    display(h);
    return 0;
}
