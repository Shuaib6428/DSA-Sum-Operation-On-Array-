#include <stdio.h> //Header File.

void Traverse_Array(int arr[], int size);                                    //Declaration of Display all element in the Array function.
int Insert_array(int arr[], int size, int index, int capacity, int element); //Declaration of Insert new element in the existing Array function.
int Delete_array(int arr[], int size, int index);                            //Declaration of Delete the given index Array function.
int Linear_search(int arr[], int size, int element);                         //Declaration of One by one search element in the Array function.
int Binary_search(int arr[], int size, int element);                         //Declaration of search element in the mid point function.

int main()
{
    int arr[20] = {2, 15, 3, 7, 43, 6};
    int size = 6; //sizeof(arr) / sizeof(int);
    int element = 3, index = 1, capacity = 20;

    printf("Array element is : \n");
    Traverse_Array(arr, size);

    Insert_array(arr, size, index, capacity, element);
    size += 1;
    printf("\nAfter insert element in the array \n");
    Traverse_Array(arr,size);

    Delete_array(arr, size, index);
    size -= 1;
    printf("\nAfter Deletion of element\n");
    Traverse_Array(arr, size);


    //int item=Linear_search(arr,size,element);

    int item = Binary_search(arr, size, element);
    printf("the element %d was found at index %d", element, item);

    return 0;
}

//<---------Binary Search function  search a particular element in the mid point . Wc complexity(O(log n))-------->
int Binary_search(int arr[], int size, int element)
{
    int low, mid, high;
    low = 0;
    high = size - 1;

    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == element)
        {
            return mid;
        }
        if (arr[mid] < element)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
        return -1;
    }
}

//<------Linear search function search a particular element one by one in the Array----------->
int Linear_search(int arr[], int size, int element)
{
    for (int i = 0; i <= size - 1; i++)
    {
        if (arr[i] == element)
        {
            return i;
        }
    }
    return -1;
}

//<----------Delete_Array function delete a given index element.------------>
int Delete_array(int arr[], int size, int index)
{
    for (int i = index; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    return 1;
}

//<----------Insert_array function insert a new element in the Array------------->
int Insert_array(int arr[], int size, int index, int capacity, int element)
{
    if (size >= capacity)
    {
        return -1;
    }
    for (int i = size - 1; i >= index; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[index] = element;
    return 1;
}

//<--------------Traverse_array function Display the all element in the array------------>
void Traverse_Array(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}
