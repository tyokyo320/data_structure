#include <iostream>
#include <stdio.h>

void swap(int *x, int *y);
void printArray(int arr[], int size);
void insertSort(int arr[], int n);
void shellSort(int arr[], int n);
void selectionSort(int arr[], int n);
void bubbleSort(int arr[], int n);
void heapify(int arr[], int n, int i);
void heapSort(int arr[], int n);

int main(int argc, char const *argv[])
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int length = sizeof(arr) / sizeof(arr[0]);

    // insertSort(arr, length);
    // shellSort(arr, length);
    // selectionSort(arr, length);
    // bubbleSort(arr, length);
    heapSort(arr, length);

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

// 构建最大堆
void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // 找出两个子节点中的最大值
    // 当左节点存在且比根节点大
    if (left < n && arr[largest] < arr[left])
        largest = left;

    // 当右节点存在且比根节点大
    if (right < n && arr[largest] < arr[right])
        largest = right;

    // 当找出的最大值不是当前父节点对应的值, 那么将父节点和最大值所对应的下标交换
    // If largest is not root
    if (largest != i)
    {
        swap(&arr[largest], &arr[i]);
        heapify(arr, n, largest);
    }
}

// 堆排序
void heapSort(int arr[], int n)
{
    // 构建最大堆
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }

    // 一对一的将元素从堆中删除
    for (int i = n - 1; i >= 0; i--)
    {
        // 交换现在的根节点到最后
        swap(&arr[0], &arr[i]);
        // 重新创建最大堆，确保array[0]是[0, i]中的最大值
        // 注意这里一定要将顶堆限制在[0, i]的范围内，否则刚抽取出的最大值又被放到最大堆的起始了！
        heapify(arr, i, 0);
    }
}