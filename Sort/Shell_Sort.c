#include <stdio.h>

void inshelltion_sort(int arr[], int gap, int start, int size)
{
    for (int i = start + gap; i < size; i += gap)
    {
        int j, key = arr[i];
        for (j = i - gap; j >= start && arr[j] > key; j -= gap)
        {
            arr[j + gap] = arr[j];
        }
        arr[j + gap] = key;
    }

}

void Shell_sort(int arr[], int size)
{
    int max_index = size - 1;
    for (int gap = max_index / 2; gap > 0; gap /= 2)
    {
        if (gap % 2 == 0) gap++;

        for (int i = 0; i < gap; i++)
        {
            inshelltion_sort(arr, gap, i, size);
        }
    }
}

int main()
{
    int arr[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    Shell_sort(arr, 10);
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }
}
