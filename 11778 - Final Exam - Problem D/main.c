#include <stdio.h>

#define MIN -1

typedef struct
{
    char name[55];
    int score;
} Student;

void InsertionSort(Student* arr[], int size);
void MergeSort(Student* arr[], int front, int end);

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("test", "r", stdin);
#endif

    int numStudent;
    scanf("%d", &numStudent);

    Student list[1000];
    Student* book[1000];

    int i;
    for(i = 0; i < numStudent; i++) {
        scanf("%s %d", list[i].name, &list[i].score);
        book[i] = &list[i];
    }

    // InsertionSort(book, numStudent);
    MergeSort(book, 0, numStudent - 1);

    for(i = 0; i < numStudent; i++) {
        printf("%s\n", book[i]->name);
    }

    return 0;
}

void InsertionSort(Student* arr[], int size)
{
    int i, j;

    for(i = 1; i < size; i++) {
        Student *key = arr[i];
        j = i - 1;
        while(j >= 0 && arr[j]->score < key->score) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }

}

void Merge(Student* arr[], int front, int mid, int end)
{
    int leftSize = mid - front + 2;
    int rightSize = end - mid + 1;

    Student* leftArr[leftSize];
    Student* rightArr[rightSize];

    Student minStudent = {"min", MIN};

    int i, j, k;

    for(i = 0; i < leftSize - 1; i++)
        leftArr[i] = arr[front + i];
    leftArr[leftSize - 1] = &minStudent;

    for(i = 0; i < rightSize - 1; i++)
        rightArr[i] = arr[mid + 1 + i];
    rightArr[rightSize - 1] = &minStudent;

    i = j = 0;
    for(k = front; k <= end; k++) {
        if(leftArr[i]->score >= rightArr[j]->score) {
            arr[k] = leftArr[i];
            i++;
        }
        else {
            arr[k] = rightArr[j];
            j++;
        }
    }
}

void MergeSort(Student* arr[], int front, int end)
{
    if(front < end) {
        int mid = (front + end) / 2;
        MergeSort(arr, front, mid);
        MergeSort(arr, mid + 1, end);
        Merge(arr, front, mid, end);
    }
}
