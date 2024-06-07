//QUESTION 2;

#include <stdio.h>

void merge(int arr[], int low, int mid, int high)
{
    int n1 = mid - low + 1;
    int n2 = high - mid;
    int l[n1], r[n2];
    for (int i = 0; i < n1; i++)
    {
        l[i] = arr[low + i];
    }
    for (int i = 0; i < n2; i++)
    {
        r[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = low;

    while (i < n1 && j < n2)
    {
        if (l[i] <= r[j])
        {
            arr[k] = l[i];
            i++;
        }
        else
        {
            arr[k] = r[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = l[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = r[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int n;
    printf("enter no.of elements in array: ");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("enter arr[%d]: ", i);
        scanf("%d", &arr[i]);
        printf("\n");
    }
    printf("before sorting: ");
    printArray(arr, n);
    mergeSort(arr, 0, n - 1);
    printf("after sorting: ");
    printArray(arr, n);
}