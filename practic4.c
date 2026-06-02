#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
//1.按奇偶排序数组
// 给定一个非负整数数组 nums。nums 中一半整数是奇数 ，一半整数是偶数
// 对数组进行排序，以便当 nums[i] 为奇数时，i也是奇数
// 当 nums[i] 为偶数时， i 也是 偶数
// 交换数组两个位置的值
void swap(int nums[], int i, int j)
{
    int tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp;
}
int* SortArrayByParity(int arr[], int size)
{
    int even = 0;//偶数
    int odd = 1;//奇数
    while (even < size && odd < size )
    {
        if (arr[size - 1] % 2 != 0)//最后一个位置是奇数
        {
            swap(arr,odd, size-1);
            odd += 2;
        }
        else
        {
            swap(arr, even, size-1);
            even += 2;
        }
    }
    return arr;
}