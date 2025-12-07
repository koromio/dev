#include <stdio.h>

void bubble_sort(int arr[], int len);

int main()
{
    int arr[5] = {5, 4, 3, 2, 1};
    bubble_sort(arr, 5);
    for (int i = 0; i < 5; i++)
        printf("%d", arr[i]);
}

void bubble_sort(int arr[], int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 0; j < len - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}