//Write the program which accept one number from user and toggle 7th and 10th bit of that number. Return modified number
//Input: 137
//Output: 713
#include<stdio.h>

typedef unsigned int UINT;
// 0000     0000    0000    0000    0000    0010    0100    0000
//  0        0       0        0       0       2       4       0  
//  0X00000240
UINT ToggleBit(UINT iNo)
{
    UINT iMask = 0X00000240;
    
    UINT Result = 0;

    Result = iNo ^ iMask;

    return Result;
}

int main()
{
    UINT Value = 0, iRet = 0;

    printf("Please Enter the number : \n");
    scanf("%d", &Value);

    iRet = ToggleBit(Value);

    printf("After toggle 7th and 10th bit number is %d", iRet);

    return 0;
}
