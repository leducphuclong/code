// Le Duc Phuc Long, 2024
// If you don't think twice, you code twice

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Forward declaration of the struct priority_queue based on max-heap tree
struct priority_queue;
typedef struct priority_queue priority_queue;

// Function pointer typedefs for the priority queue operations
typedef void (*insert_func) (priority_queue*, int);
typedef int (*maximum_func) (priority_queue*);
typedef int (*extract_func) (priority_queue*);
typedef void (*increase_func) (priority_queue*, int index, int key);
typedef void (*decrease_func) (priority_queue*, int index, int key);
typedef void (*change_func) (priority_queue *, int index, int key);
typedef int (*isFull_func) (priority_queue*);
typedef int (*isEmpty_func) (priority_queue*);

// Define the struct for the priority queue
struct priority_queue {
    int maxSize; // Maximum number of elements in the priority queue
    int heapSize; // Current number of elements in the priority queue
    int *heapTree; // Pointer to an array storing the elements of the priority queue

    // Function pointers for priority_queue operations
    insert_func insert;
    maximum_func maximum;
    extract_func extract;
    change_func change;
    isFull_func isFull;
    isEmpty_func isEmpty;

    // Function pointers for heap operations
    void (*maxHeapify)(struct priority_queue*, int);

    // Function pointer for viewing the heap
    void (*viewHeap)(int*, int);
};

// Function to swap two elements in the priority queue
void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

// Function to maintain the max heap property
void maxHeapify(priority_queue* pq, int index) {

    int largest = index;
    while (index < pq->heapSize/2) {
        int leftChild = index * 2 + 1;
        int rightChild = index * 2 + 2;
        if (leftChild < pq->heapSize && pq->heapTree[leftChild] > pq->heapTree[largest])
            largest = leftChild;
        if (rightChild < pq->heapSize && pq->heapTree[rightChild] > pq->heapTree[largest])
            largest = rightChild;

        if (largest != index) {
            swap(pq->heapTree + largest, pq->heapTree + index);
            index = largest;
        } else {
            break;
        }
    }
}

// Function to check if the priority queue is empty
int isEmpty(priority_queue *pq) {
    return pq->heapSize == 0;
}

// Function to check if the priority queue is full
int isFull(priority_queue *pq) {
    return pq->heapSize == pq->maxSize;
}

// Function to float up an element in the priority queue
void floatUp(priority_queue* pq, int index) {
    while (index > 0 && pq->heapTree[index] > pq->heapTree[(index - 1) / 2]) {
        swap(pq->heapTree + index, pq->heapTree + (index - 1) / 2);
        index = (index - 1) / 2;
    }
}

// Function to insert a new element into the priority queue
void insert(priority_queue* pq, int key) {
    if (isFull(pq)) {
        perror("Heap is full, cannot insert any more!");
        return;
    }

    pq->heapTree[pq->heapSize] = key;
    pq->heapSize++;

    int index = pq->heapSize - 1;
    floatUp(pq, index);
}

// Function to extract the maximum element from the priority queue
int extract(priority_queue* pq) {
    if (isEmpty(pq)) {
        printf("Priority queue is empty\n");
        return -1;
    }

    int maxElement = pq->heapTree[0];
    swap(pq->heapTree + 0, pq->heapTree + pq->heapSize - 1);
    pq->heapSize -= 1;
    maxHeapify(pq, 0);
    return maxElement;
}

// Function to decrease the key of an element in the priority queue
void decrease(priority_queue *pq, int index, int key) {
    pq->heapTree[index] = key;
    maxHeapify(pq, index);
}

// Function to increase the key of an element in the priority queue
void increase(priority_queue *pq, int index, int key) {
    pq->heapTree[index] = key;
    floatUp(pq, index);
}

// Function to change the key of an element in the priority queue
void change(priority_queue *pq, int index, int key) {
    if (key >= pq->heapTree[index])
        increase(pq, index, key);
    else
        decrease(pq, index, key);
}



// Function to view the elements of the heap
void viewHeap(int *heapTree, int n) {
    for (int i = 0; i < n; ++i)
        printf("%d ", heapTree[i]);
    printf("\n");
}

// Function to initialize a priority queue
priority_queue* initializePriorityQueue(int maxSize) {
    priority_queue* pq = (priority_queue*)malloc(sizeof(priority_queue));
    pq->maxSize = maxSize;
    pq->heapSize = 0;
    pq->heapTree = (int*)malloc(maxSize * sizeof(int));

    // Assign function pointers
    pq->insert = insert;
    pq->extract = extract;
    pq->isFull = isFull;
    pq->isEmpty = isEmpty;
    pq->maxHeapify = maxHeapify;
    pq->change = change;
    pq->viewHeap = viewHeap;

    return pq;
}

int main(int argc, char const *argv[]) {
    // Opening input file
    if (access("in", F_OK) != -1) {
        FILE *file = freopen("in", "r", stdin);
        if (file == NULL) {
            perror("Error opening file!");
            return 1;
        }
    }

    // Load the input data
    int n;
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        perror("Memory allocation failed!");
        return 1;
    }

    // Initialize priority queue
    priority_queue* pq = initializePriorityQueue(n);

    // Insert elements into the priority queue
    for (int i = 0; i < n; ++i) {
        scanf("%d", arr + i);
        pq->insert(pq, arr[i]);
    }

    // Swap first and last elements to test the change function
    int tmp = pq->heapTree[0];
    pq->change(pq, 0, pq->heapTree[pq->heapSize - 1]);
    pq->change(pq, pq->heapSize - 1, tmp);
    // Extract elements from the priority queue
    while (!pq->isEmpty(pq)) {
        arr[pq->heapSize - 1] = pq->extract(pq);
    }

    // View the result
    viewHeap(arr, n);

    // Free allocated memory
    free(arr);
    free(pq->heapTree);
    free(pq);

    return 0;
}
