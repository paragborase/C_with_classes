//Write the program which accept one number from user and toggle 7th bit of that number. Return modified number
//Input: 137
//Output: 201
#include<stdio.h>

typedef unsigned int UINT;
// 0000     0000    0000    0000    0000    0000    0100    0000
//  0        0       0        0       0       0       4       0  
//  0X00000040
UINT ToggleBit(UINT iNo)
{
    UINT iMask = 0X00000040;
    
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

    printf("After toggle 7th bit  number is %d", iRet);

    return 0;
}
