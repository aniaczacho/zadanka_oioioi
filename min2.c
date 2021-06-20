#include<stdio.h>
#include<math.h>

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

/* This function takes last element as pivot, places
the pivot element at its correct position in sorted
array, and places all smaller (smaller than pivot)
to left of pivot and all greater elements to right
of pivot */
int partition (int arr[], int low, int high)
{
    int pivot = arr[high]; // pivot
    int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far

    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than the pivot
        if (arr[j] < pivot)
        {
            i++; // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low --> Starting index,
high --> Ending index */
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
        at right place */
        int pi = partition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int max_i(int tab[], int n) {
    int max_ = 0;
    for (int i = 1; i < n; i++) {
        if (tab[i] > tab[max_]) max_ = i;
    }
    return max_;
}

int min_sum(int tab[], int n, int k) {
    for (int i = 0; i < k; i++) {
        int m = max_i(tab, n);
        tab[m] = floor(tab[m]/2);
    }
    int sum = 0;
    for (int i = 0; i < n; i++) sum += tab[i];
    return sum;
}

int main() {

    int n, k;
    scanf("%d%d", &n, &k);

    int tab[n];
    for (int i = 0; i < n; i++) scanf("%d", &tab[i]);

    printf("%d", min_sum(tab, n, k));

    return 0;
}

