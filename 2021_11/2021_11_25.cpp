// The Sequential Search Algorithm

#include <stdio.h>
#include <stdlib.h>

#define N 20     //The number of elements in the dataset

//Implement sequential search, arr[N] is the data set, value is the target element to find
int linear_search(int arr[N], int value)
{
    int i;
    //Start iterating from the first element
    for (i = 0; i < N; i++)
    {
        //If the match is successful, the position index of the element is returned
        if (arr[i] == value)
        {
            return i;
        }
    }
    //If the match fails, -1 is returned
    return -1;
}

int main()
{
    int arr[N] = { 10,14,19,26,27,31,33,35,64,42,44,78 };
    int add = linear_search(arr, 64);
    if (add != -1)
    {
        printf("Successfully! The element is the %d element in the sequence. \n\n", add + 1);
    }
    else
    {
        printf("Failure! \n\n");
    }
    system("pause");
    return 0;
}