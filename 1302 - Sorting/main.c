#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// #define LIBRARY_QSORT
// #define INSERTION_SORT
// #define MERGE_SORT
#define QUICK_SORT
// #define HEAP_SORT

#define Parent(index) (((index) - 1) / 2)
#define LeftChild(index) ((index) * 2 + 1)
#define RightChild(index) ((index) * 2 + 2)

void swap(int* a, int* b);

// Standard Library qsort (488ms)
int compare(const void *a, const void *b);
// Insertion Sort (TLE)
void InsertionSort(int arr[], int size);
// Merge Sort (460ms)
void MergeSort(int arr[], int front, int end);
void Merge(int arr[], int front, int mid, int end);
// Quick Sort (420ms)
void QuickSort(int arr[], int front, int end);
int Partition(int arr[], int front, int end);
// Heap Sort (464ms)
void HeapSort(int arr[], int size);
void BuildMaxHeap(int arr[], int size);
void MaxHeapify(int arr[], int size, int root);

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("test", "r", stdin);
#endif

    int cases;
    scanf("%d", &cases);

    while(cases-- > 0) {

        int size;
        scanf("%d", &size);

        int i;
        int arr[1000000];

        for(i = 0; i < size; i++)
            scanf("%d", &arr[i]);

#if defined(LIBRARY_QSORT)
        qsort(arr, size, sizeof(int), compare);
#elif defined(INSERTION_SORT)
        InsertionSort(arr, size);
#elif defined(MERGE_SORT)
        MergeSort(arr, 0, size - 1);
#elif defined(QUICK_SORT)
        QuickSort(arr, 0, size - 1);
#elif defined(HEAP_SORT)
        HeapSort(arr, size);
#endif

        for(i = 0; i < size - 1; i++) {
            printf("%d ", arr[i]);
        }
        printf("%d\n", arr[size - 1]);
    }

    return 0;
}

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int compare(const void *a, const void *b)
{
    return (*(int*)a > *(int*)b) - (*(int*)a < *(int*)b);
}

void InsertionSort(int arr[], int size)
{
    int i, j;
    for(i = 1; i < size; i++) {
        int key = arr[i];
        j = i - 1;
        while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void MergeSort(int arr[], int front, int end)
{
    if(front < end) {
        int mid = (front + end) / 2;
        MergeSort(arr, front, mid);
        MergeSort(arr, mid + 1, end);
        Merge(arr, front, mid, end);
    }
}

void Merge(int arr[], int front, int mid, int end)
{
    int leftSize = mid - front + 2;
    int rightSize = end - mid + 1;

    int leftArr[leftSize];
    int rightArr[rightSize];

    int i, j, k;

    for(i = 0; i < leftSize - 1; i++)
        leftArr[i] = arr[front + i];
    leftArr[leftSize - 1] = INT_MAX;

    for(i = 0; i < rightSize - 1; i++)
        rightArr[i] = arr[mid + 1 + i];
    rightArr[rightSize - 1] = INT_MAX;

    i = j = 0;
    for(k = front; k <= end; k++) {
        if(leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i++];
        }
        else {
            arr[k] = rightArr[j++];
        }
    }
}

void QuickSort(int arr[], int front, int end)
{
    if(front < end) {
        int pivot = Partition(arr, front, end);
        QuickSort(arr, front, pivot - 1);
        QuickSort(arr, pivot + 1, end);
    }
}

int Partition(int arr[], int front, int end)
{
    int pivot = arr[end];
    int i = front - 1;
    int j;
    for(j = front; j < end; j++) {
        if(arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    i++;
    swap(&arr[i], &arr[end]);
    return i;
}

void HeapSort(int arr[], int size)
{
    BuildMaxHeap(arr, size);

    int i;
    for(i = size - 1; i >= 1; i--) {
        swap(&arr[0], &arr[i]);
        size--;
        MaxHeapify(arr, size, 0);
    }
}

void BuildMaxHeap(int arr[], int size)
{
    int i;
    for(i = Parent(size - 1); i >= 0; i--) {
        MaxHeapify(arr, size, i);
    }
}

void MaxHeapify(int arr[], int size, int root)
{
    int left = LeftChild(root);
    int right = RightChild(root);
    int largest = root;

    if(left < size && arr[left] > arr[largest]) {
        largest = left;
    }
    if(right < size && arr[right] > arr[largest]) {
        largest = right;
    }

    if(largest != root) {
        swap(&arr[root], &arr[largest]);
        MaxHeapify(arr, size, largest);
    }
}
