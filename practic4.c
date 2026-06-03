#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<math.h>
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
//2.寻找重复数
int findDuplicate(int arr[], int size)
{
    if (arr == NULL || size < 2)
    {
        return -1;
    }
    //快慢指针，成环
    int slow = arr[0];
    int fast = arr[arr[0]];
    while (slow != fast)
    {
        slow = arr[slow];
        fast = arr[arr[fast]];
    }
    //第一次已经相遇
    fast = arr[0];
    while (slow != fast)
    {
        slow = arr[slow];
        fast = arr[fast];
    }
    //第二次相遇就是入环节点，也就是重复的数
    return slow;
}
//3.接雨水
// 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水
int trap(int arr[], int size)
{
    int l = 1;//左侧0位置肯定没雨水
    int r = size - 2;//右侧size-1位置肯定没雨水
    int lmax = arr[0];
    int rmax = arr[size-1];
    int ans = 0;
    while (l <= r)
    {
        if (lmax <= rmax)
        {
            ans += max(0, lmax - arr[l]);
            lmax = max(lmax, arr[l]);
            l++;
        }
        else
        {
            ans += max(0, rmax - arr[r]);
            rmax = max(rmax, arr[r]);
            r--;
        }
    }
    return ans;
}
//4.救生艇问题
// 给定数组 people
// people[i]表示第 i 个人的体重 ，船的数量不限，每艘船可以承载的最大重量为 limit
// 每艘船最多可同时载两人，但条件是这些人的重量之和最多为 limit
// 返回 承载所有人所需的最小船数
//冒泡排序
void BubbleSort(int* arr, int length)
{
    assert(arr);

    for (int i = 0; i < length - 1; i++)
    {
        for (int j = 0; j < length - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])//如果大，交换
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
int numRescueBoats(int* people, int peopleSize, int limit) {
    BubbleSort(people, peopleSize);
    int l = 0;
    int r = peopleSize - 1;
    int sum = 0;
    int ans = 0;
    while (l <= r)
    {
        sum = (l==r) ? sum = people[l] : people[l] + people[r];
        if (sum <= limit)
        {
            l++;
            r--;
            ans++;
        }
        else
        {
            r--;
            ans++;
        }
    }
    return ans;
}
//5.盛水最多的容器
// 给定一个长度为 n 的整数数组 height 。有 n 条垂线，第 i 条线的两个端点是 (i, 0) 和 (i, height[i]) 。
// 找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水
// 返回容器可以储存的最大水量
int maxArea(int arr[], int size)
{
    int l = 0;
    int r = size - 1;
    int ans = 0;
    while (l < r)
    {
        //原来的大于现在的
        ans = (ans > min(arr[l], arr[r]) * (r - l)) ? ans : min(arr[l], arr[r]) * (r - l);
        if (arr[l] < arr[r])
        {
            l++;
        }
        else
        {
            r--;
        }
    }
    return ans;
}