#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

void swap(int *x, int *y);
void printArray(int arr[], int size);

// Time Complexity: O(n*2)
void insertSort(int arr[], int n);
void selectionSort(int arr[], int n);
void bubbleSort(int arr[], int n);

void shellSort(int arr[], int n);

void heapify(int arr[], int n, int i);
void heapSort(int arr[], int n);

int partition(int arr[], int low, int high);
void quickSort(int arr[], int low, int high);

void merge(int arr[], int l, int m, int r);
void mergeSort(int arr[], int l, int r);

void bucketSort(float arr[], int n);

int getMax(int arr[], int n);
void countSort(int arr[], int n, int exp);
void radixSort(int arr[], int n);

int main(int argc, char const *argv[])
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int length = sizeof(arr) / sizeof(arr[0]);

    // insertSort(arr, length);
    // shellSort(arr, length);
    // selectionSort(arr, length);
    // bubbleSort(arr, length);
    // heapSort(arr, length);
    // quickSort(arr, 0, length - 1);
    // mergeSort(arr, 0, length);

    // float arr[] = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};
    // bucketSort(arr, length);
    // cout << "Sorted array is \n";
    // for (int i = 0; i < length; i++)
    //     cout << arr[i] << " ";
    radixSort(arr, length);

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

// 划分函数
int partition(int arr[], int low, int high)
{
    int i = low;
    int j = high - 1;
    // 枢纽元素，这里初始选为最后一个
    int pivot = arr[high];

    // j指向比枢纽小的元素，i指向比枢纽大的元素
    while (1)
    {
        // j遇到比枢纽元素小的元素就停下来，i遇到比枢纽元素大的元素停下来
        while (arr[i] < pivot)
            i += 1;
        while (arr[j] > pivot)
            j -= 1;

        if (i < j)
            swap(&arr[i], &arr[j]);
        else
            break;
    }
    // 把枢纽元素放到正确的位置
    swap(&arr[i], &arr[high]);
    // 返回枢纽的位置
    return i;
}

// 快速排序
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int mid = partition(arr, low, high);
        quickSort(arr, low, mid - 1);
        quickSort(arr, mid + 1, high);
    }
}

// 合并
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    // 申请两个辅助数组L，R
    int L[n1], R[n2];

    // 复制数据至辅助数组L，R中
    for (i = 0; i < n1; i++)
    {
        L[i] = arr[l + i];
    }
    for (j = 0; j < n2; j++)
    {
        R[j] = arr[m + 1 + j];
    }

    i = 0;
    j = 0;
    k = l;

    // 合并
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i += 1;
        }
        else
        {
            arr[k] = R[j];
            j += 1;
        }
        k += 1;
    }

    // 若辅助数组L中有剩余
    while (i < n1)
    {
        arr[k] = L[i];
        i += 1;
        k += 1;
    }

    // 若辅助数组R中有剩余
    while (j < n2)
    {
        arr[k] = R[j];
        j += 1;
        k += 1;
    }
}

// 归并排序
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        // (l+r)/2与一样，这里是为了防止溢出
        int mid = l + (r - l) / 2;

        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
}

// 桶排序
void bucketSort(float arr[], int n)
{

    // 1) Create n empty buckets
    vector<float> b[n];

    // 2) Put array elements
    // in different buckets
    for (int i = 0; i < n; i++)
    {
        int bi = n * arr[i]; // Index in bucket
        b[bi].push_back(arr[i]);
    }

    // 3) Sort individual buckets
    for (int i = 0; i < n; i++)
        sort(b[i].begin(), b[i].end());

    // 4) Concatenate all buckets into arr[]
    int index = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < b[i].size(); j++)
            arr[index++] = b[i][j];
}

// A utility function to get maximum value in arr[]
int getMax(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

// A function to do counting sort of arr[] according to
// the digit represented by exp.
void countSort(int arr[], int n, int exp)
{
    int output[n]; // output array
    int count[10] = {0};

    // Store count of occurrences in count[]
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    // Change count[i] so that count[i] now contains actual
    // position of this digit in output[]
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build the output array
    for (int i = n - 1; i >= 0; i--)
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copy the output array to arr[], so that arr[] now
    // contains sorted numbers according to current digit
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

// The main function to that sorts arr[] of size n using
// Radix Sort
void radixSort(int arr[], int n)
{
    // Find the maximum number to know number of digits
    int m = getMax(arr, n);

    // Do counting sort for every digit. Note that instead
    // of passing digit number, exp is passed. exp is 10^i
    // where i is current digit number
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}