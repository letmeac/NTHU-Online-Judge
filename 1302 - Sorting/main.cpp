#include <iostream>
#include <cstdio>
/*
#include <algorithm>
//sort(arr, arr+n);
//stable_sort(arr, arr+n);
*/

using namespace std;

void swap(int* x, int* y);
/*
void Bubble_sort(int arr[], int n);
void Selection_sort(int arr[], int n);
void Insertion_sort(int arr[], int n);
*/
void Quick_sort(int arr[], int n);
void Quick_sort_recursive(int arr[], int left, int right);
/*
void Merge_sort(int arr[], int n);
void Merge_recursive(int arr[], int temp[], int left, int right);
void Merge_sorting(int arr[], int temp[], int left, int mid, int right);

void Heap_sort(int arr[], int n);
void Heapify(int arr[], int start, int end);

void Radix_sort(int arr[], int n, int r);
int Radix_sort_maxdigit(int arr[], int n, int r);
int Radix_digit(int num, int n_th, int r);
*/
int main()
{   //freopen("test.in", "r", stdin);

    int T;
    cin >> T;

    int n;
    while(cin >> n) {
        int arr[n];
        for(int i = 0; i < n; i++) cin >> arr[i];

        //Bubble_sort(arr, n);
        //Selection_sort(arr, n);
        //Insertion_sort(arr, n);
        Quick_sort(arr, n);
        //Merge_sort(arr, n);
        //Heap_sort(arr, n);
        //Radix_sort(arr, n, 10);  //10 = radix / non-neg!!!

        for(int i = 0; i < n; i++) {
            cout << arr[i];
            if(i < n-1) cout << " ";
        }
        cout << endl;
    }

    return 0;
}


void swap(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

/*
void Bubble_sort(int arr[], int n)
{
    for(int i = n-1; i >= 1; i--) {
        for(int j = 0; j <= i-1; j++) {
            if(arr[j] > arr[j+1])
                swap(arr[j+1], arr[j]);
        }
    }
}


void Selection_sort(int arr[], int n)
{
    int min;

    for(int i = 0; i <= n-2; i++) {
        min = i;
        for(int j = i+1; j <= n-1; j++) {
            if(arr[j] < arr[min])
                min = j;
        }
        swap(arr[i], arr[min]);
    }
}


void Insertion_sort(int arr[], int n)
{
    int key;

    for(int i = 1; i <= n-1; i++) {
        key = arr[i];
        int j = i-1;
        while((j >= 0) && (arr[j] > key)) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}
*/

void Quick_sort(int arr[], int n)
{
    Quick_sort_recursive(arr, 0, n-1);
}

void Quick_sort_recursive(int arr[], int left, int right)
{
    if(left >= right) return;

    int i = left;
    int j = right+1;
    int key = arr[left];

    do {
        do i++; while(arr[i] < key);
        do j--; while(arr[j] > key);
        if(i < j) swap(arr[i], arr[j]);
    } while(i < j);

    swap(arr[left], arr[j]);

    Quick_sort_recursive(arr, left, j-1);
    Quick_sort_recursive(arr, j+1, right);
}

/*
void Merge_sort(int arr[], int n)
{
    int temp[n];
    Merge_recursive(arr, temp, 0, n-1);
}

void Merge_recursive(int arr[], int temp[], int left, int right)
{
    if(left >= right) return;

    int mid = (left + right) / 2;

    Merge_recursive(arr, temp, left, mid);
    Merge_recursive(arr, temp, mid+1, right);
    Merge_sorting(arr, temp, left, mid+1, right);
}

void Merge_sorting(int arr[], int temp[], int left, int mid, int right)
{
    int i = left;
    int j = mid;

    int k = left;

    while((i <= mid-1) && (j <= right)) {
        if(arr[i] > arr[j]) {
            temp[k++] = arr[j++];
        } else {
            temp[k++] = arr[i++];
        }
    }

    while(i <= mid-1) temp[k++] = arr[i++];
    while(j <= right) temp[k++] = arr[j++];

    for(i = left; i <= right; i++) arr[i] = temp[i];
}


void Heap_sort(int arr[], int n)
{
    for(int i = n/2-1; i >= 0; i--)
        Heapify(arr, i, n-1);

    for(int i = n-1; i >= 1; i--) {
        swap(arr[0], arr[i]);
        Heapify(arr, 0, i-1);
    }
}

void Heapify(int arr[], int start, int end)
{
    int parent = start;
    int child = parent*2+1;
    while(child <= end) {
        if((child+1 <= end) && (arr[child] < arr[child+1]))
            child++;

        if(arr[parent] >= arr[child]) return;
        else {
            swap(arr[parent], arr[child]);
            parent = child;
            child = parent*2+1;
        }
    }
}

//non-neg!!!
void Radix_sort(int arr[], int n, int r)
{
    int i, j;

    int d = Radix_sort_maxdigit(arr, n, r);

    int link[n], temp[n];
    for(i = 0; i <= n-1; i++) link[i] = i + 1;

    int f[r], e[r];
    int first = 0, last = n-1;

    for(i = 1; i <= d; i++) {
        for(j = 0; j < r; j++) f[j] = -1;

        for(int current = first; current != n; current = link[current]) {
            int k = Radix_digit(arr[current], i, r);

            if(f[k] == -1) f[k] = current;
            else link[e[k]] = current;
            e[k] = current;
        }

        for(j = 0; f[j] == -1; j++);
        first = f[j];
        last = e[j];

        for(int k = j+1; k < r; k++) {
            if(f[k] != -1) {
                link[last] = f[k];
                last = e[k];
            }
        }
        link[last] = n;
    }

    for(i = 0, j = first; i < n; i++) {
        temp[i] = arr[j];
        j = link[j];
    }
    for(i = 0; i < n; i++) arr[i] = temp[i];
}

int Radix_sort_maxdigit(int arr[], int n, int r)
{
    int maxnum = arr[0];

    for(int i = 1; i < n; i++) {
        if(maxnum < arr[i])
            maxnum = arr[i];
    }

    int d = 1;
    while(maxnum >= r) {
        maxnum /= r;
        d++;
    }
    return d;
}

int Radix_digit(int num, int n_th, int r)
{
    if(n_th == 1) return num % r;
    else return Radix_digit(num/r, n_th-1, r);
}
*/
