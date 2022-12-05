
#include <stdlib.h>
#include <stdio.h>

void mergesort(int arr[], int start, int end)
{
    int mid;
    if (start < end)
    {
        mid = (start + end) / 2;
        mergesort(arr, start, mid);
        mergesort(arr, mid + 1, end);
        merge(arr, start, mid, mid + 1, end);
    }
}

void merge(int arr[], int Start_Arr_1, int End_Arr_1, int Start_Arr_2, int End_Arr_2)
{
    int temp[10];
    int i, j, k;
    i = Start_Arr_1;
    j = Start_Arr_2;
    k = 0;
    while (i <= End_Arr_1 && j <= End_Arr_2)
    {
        if (arr[i] < arr[j])
        {
            temp[k] = arr[i];
            i++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
        }
        k++;

    }
    while (i <= End_Arr_1)
    {
        temp[k++] = arr[i++];
    }
    while (j <= End_Arr_2)
    {
        temp[k++] = arr[j++];
    }
    for (i = Start_Arr_1, j = 0; i <= End_Arr_2; i++, j++)
        arr[i] = temp[j];
}

int main()
{
    int arr[8] = {5, 2, 7, 9, 3, 77, 21, 3};
    int ArrSize = sizeof(arr) / sizeof(arr[0]);
    printf("The Array before sorted ::\n");
    for (int i = 0; i < ArrSize; i++)
        printf("%d ", arr[i]);
    mergesort(arr, 0, ArrSize - 1);
    printf("\nThe Array After sorted ::\n");
    for (int i = 0; i < ArrSize; i++)
        printf("%d ", arr[i]);
    return 0;
}
