#include<stdio.h>
#include<stdlib.h>
int singleNumber(int* nums, int numsSize)
{
    while (--numsSize)
    {
        nums[numsSize - 1] ^= nums[numsSize];
    }
    return nums[0];
}

// ====================测试代码====================
void Test(char* testName, int* nums, int numsSize,int* targ)
{
    if (testName != nullptr)
        printf("%s begins: ", testName);
    int result = singleNumber(nums, numsSize);
    if (result == targ[0])
    {
        printf("Passed.\n");
        return;
    }
    else
    {
        printf("Failed.\n");
        return;
    }
}

void Test1()
{
    int nums[] = { 1,2,1 };
    int targ[] = { 2 };
    Test((char*)"Test1", nums, sizeof(nums) / sizeof(nums[0]),targ);
}

void Test2()
{
    int nums[] = { 4,5,5,3,2,3,4 };
    int targ[] = { 2 };
    Test((char*)"Test2", nums, sizeof(nums) / sizeof(nums[0]), targ);
}

void Test3()
{
    int nums[] = { 8,1,1 };
    int targ[] = { 1 };
    Test((char*)"Test2", nums, sizeof(nums) / sizeof(nums[0]), targ);
}

int main()
{
    Test1();
    Test2();
    Test3();
    system("pause");
}
//int main()
//{
//    int nums[] = {1,2,1 };
//    int numsSize = sizeof(nums) / sizeof(nums[0]);
//    singleNumber(nums, numsSize);
//    printf("%d", nums[0]);
//    return 0;
//}