#include "ReadWriter.h"
#include "MergeSort.h"

using namespace std;

//Описание методов на английском языке имеется в классе MergeSort, в файле MergeSort.h
void MergeSort::sort(int *arr, int length)
{
    //start dividing the original array
    divide_and_merge(arr, 0, length - 1);
}

void MergeSort::merge(int *arr, int first, int second, int end)
{
    //number of elements in the first subarray
    int n1 = second - first + 1;
    //number of elements in the second subarray
    int n2 = end - second;

    int leftArray[n1];
    int rightArray[n2];

    //copy needed elements from arr to the left subarray
    for (int i = 0; i < n1; i++)
        leftArray[i] = arr[first + i];

    //copy needed elements from arr to the right subarray
    for (int j = 0; j < n2; j++)
        rightArray[j] = arr[second + j + 1];

    int i = 0, j = 0, k = first;

    while (i < n1 && j < n2)
    {
        if (leftArray[i] <= rightArray[j])
            arr[k] = leftArray[i++];
        else
            arr[k] = rightArray[j++];
        k++;
    }

    //copy the first subarray elements with their new position into the original array
    while (i < n1)
        arr[k++] = leftArray[i++];

    //copy the second subarray elements with their new position into the original array
    while (j < n2)
        arr[k++] = rightArray[j++];

}

void MergeSort::divide_and_merge(int *arr, int left, int right)
{
    if (left < right)
    {
        //center of an array
        int m = left + (right - left) / 2;
        //sort the first half of array
        divide_and_merge(arr, left, m);
        //sort the second half of array
        divide_and_merge(arr, m + 1, right);

        merge(arr, left, m, right);
    }
}

int main()
{
    ReadWriter rw;

    int *brr = nullptr;
    int length;

    //Read data from file
    length = rw.readInt();

    brr = new int[length];
    rw.readArray(brr, length);

    //Start sorting
    MergeSort s;

    s.sort(brr, length);

    //Write answer to file
    rw.writeArray(brr, length);

    delete[] brr;

    return 0;
}