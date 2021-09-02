#include <stdio.h>

void sort(int arr[])
{
    for (int i = 0; i < sizeof(arr)/4-1; i++)
    {
        for (int j = 0; j < sizeof(arr)/4-i-1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void unique (int arr[])
{
    //sort(arr);
    for (int i = 0; i < sizeof(arr)/4; i++)
    {
        printf("%d ", arr[i]);
    }
}

int main()
{
    int len;
    printf("To find unique elements of an array: ");
    printf("Enter the length of the array: ");
    scanf("%d", &len);
    int arr[len];

    for (int i = 0; i < len; i++)
    {
        printf("Enter element %d: ", i);
        scanf("%d", &arr[i]);
    }

    unique(arr);
    return 0;
}