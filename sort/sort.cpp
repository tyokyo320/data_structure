#include <iostream>
#include <stdio.h>

void swap(int *x, int *y);
void printArray(int arr[], int size);
void insertSort(int arr[], int n);
void shellSort(int arr[], int n);
void selectionSort(int arr[], int n);
void bubbleSort(int arr[], int n);

int main(int argc, char const *argv[])
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int length = sizeof(arr) / sizeof(arr[0]);

    // insertSort(arr, length);
    // shellSort(arr, length);
    // selectionSort(arr, length);
    bubbleSort(arr, length);

    printf("Sorted array: \n");
    printArray(arr, length);

    return 0;
}

// 交换
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

// 打印
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// 插入排序
void insertSort(int arr[], int n)
{
    int key, j;
    for (int i = 1; i < n; i++)
    {
        // 1.选择未排序的第一个元素key
        key = arr[i];
        j = i - 1;

        // 2.从key前一个元素开始比较，找到比key大的元素就继续向前找
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j -= 1;
        }
        // 3.找到合适的位置插入key
        arr[j + 1] = key;
    }
}

// 希尔排序
void shellSort(int arr[], int n)
{
    for (int gap = n / 2; gap >= 1; gap /= 2)
    {
        for (int i = gap; i < n; i++)
        {
            for (int j = i; j >= gap && arr[j - gap] > arr[j]; j -= gap)
            {
                // swap
                int temp = arr[j - gap];
                arr[j - gap] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// 选择排序
void selectionSort(int arr[], int n)
{
    // 最后一轮不需要遍历，已经是有顺序了
    for (int i = 0; i < n - 1; i++)
    {
        int min_index = i;
        // 循环查找最小值
        for (int j = i + 1; j < n; j++)
        {
            if (arr[min_index] > arr[j])
                min_index = j;
        }
        swap(&arr[min_index], &arr[i]);
    }
}

// 冒泡排序
void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        // 以后每次循环的次数为arr.length-1-i
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
        }
    }
}