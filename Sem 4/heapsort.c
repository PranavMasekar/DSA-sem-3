#include <stdio.h>
int heap[10];
int size = 0;
void heapUp(int i){
    int parent = (i-1)/2;
    if(heap[i]>heap[parent] && i > 0){
        int temp = heap[parent];
        heap[parent] = heap[i];
        heap[i] = temp;
        heapUp(parent);
    }
}

void create(int n){
    for(int i=0;i<n;i++){
        int num;
        scanf("%d",&num);
        heap[i] = num;
        size++;
        heapUp(i);
    }
}
void display(int n){
    for(int i=0;i<n;i++){
        printf("%d ",heap[i]);
    }
    printf("\n");
}
void heapDown(int i, int last){
    int l = ( 2 * i ) + 1;
    int r = ( 2 * i ) + 2;
    int largest = i;
    if(l< last && heap[l]>heap[i]){
        largest = l;
    }
    if(r< last && heap[r]>heap[i] && heap[r]>heap[l]){
        largest = r;
    }
    if(largest!=i) {
        int temp = heap[i];
        heap[i] = heap[largest];
        heap[largest] = temp;
        heapDown(largest,last);
    }
}

void delete(int s){
    int temp = heap[0];
    heap[0] = heap[s-1];
    heap[s-1] = temp;
    s--;
    heapDown(0,s);
}

int main() {
    int n;
    printf("Enter the number elements: ");
    scanf("%d",&n);
    create(n);
    printf("Max Heap :\n");
    display(n);
    int temp = n;
    for(int i=0;i<n;i++){
        delete(temp);
        temp--;
    }
    printf("Sorted array :\n");
    display(n);
    return 0;
}
