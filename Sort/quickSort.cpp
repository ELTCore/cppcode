#include <iostream>

using namespace std;

class QuickSort
{
public:
    void quickSort(int A[], int low, int high)
    {
        if (low < high)
        { // 递归跳出的条件
            // partition() 就是划分操作，将表A[low...high]划分为满足上述条件的两个子表
            int pivotPos = partition(A, low, high); //划分
            quickSort(A, low, pivotPos - 1);        // 依次对两个子表进行递归排序
            quickSort(A, pivotPos + 1, high);
        }
    }

    int partition(int A[], int low, int high)
    {
        int pivot = A[low]; // 将当前表中第一个元素设为枢轴，对表进行划分
        while (low < high)
        { // 循环跳出条件
            while (low < high && A[high] >= pivot)
                --high;
            A[low] = A[high]; // 将比枢轴小的元素移动到左端
            while (low < high && A[low] <= pivot)
                ++low;
            A[high] = A[low]; // 将比枢轴大的元素移动到右端
        }
        A[low] = pivot; // 枢轴元素存放到最终位置

        return low;
    }
};

int main(int argc, char const *argv[])
{

    return 0;
}
