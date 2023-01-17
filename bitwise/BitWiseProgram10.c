//Write the program which accept one number from user and ON its first 4 bits of that number. Return modified number
//Input: 73
//Output: 79
#include<stdio.h>

typedef unsigned int UINT;
// 0000     0000    0000    0000    0000    0000    0000    1111
//  0        0       0        0       0       0       0       F  
//  0X0000000F
UINT OnBit(UINT iNo)
{
    UINT iMask = 0X0000000F;
    
    UINT Result = 0;

    Result = iNo | iMask;

    return Result;
}

int main()
{
    UINT Value = 0, iRet = 0;

    printf("Please Enter the number : \n");
    scanf("%d", &Value);

    iRet = OnBit(Value);

    printf("After on its 4 bits number is %d", iRet);

    return 0;
}
