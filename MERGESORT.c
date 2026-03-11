#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void mergesort(int a[], int low, int high);
void merge(int a[], int low, int mid, int high);

int main()
{
    clock_t start, end;
    int n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int a[n];

    srand(time(NULL));   // seed random numbers

    for(i = 0; i < n; i++)
        a[i] = rand() % 1000;

    start = clock();

    mergesort(a, 0, n - 1);

    end = clock();

    float d = (float)(end - start) / CLOCKS_PER_SEC;

    // Optional: print sorted array
    /*
    printf("Sorted array:\n");
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);
    */

    printf("\nTime taken: %f sec\n", d);

    return 0;
}

void mergesort(int a[], int low, int high)
{
    int mid;

    if(low < high)
    {
        mid = (low + high) / 2;

        mergesort(a, low, mid);
        mergesort(a, mid + 1, high);

        merge(a, low, mid, high);
    }
}

void merge(int a[], int low, int mid, int high)
{
    int i = low, j = mid + 1, k = low;

    int temp[high + 1];   // dynamic size

    while(i <= mid && j <= high)
    {
        if(a[i] <= a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }

    while(i <= mid)
        temp[k++] = a[i++];

    while(j <= high)
        temp[k++] = a[j++];

    for(i = low; i <= high; i++)
        a[i] = temp[i];
}
