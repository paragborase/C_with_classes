//Write the program which accept one number from user and off 7th bit of that number if it is on. Return modified number
//Input: 79
//Output: 15
#include<stdio.h>

typedef unsigned int UINT;
// 1111     1111    1111    1111    1111    1111    1011    1111
//  F        F       F        F       F        F      B      F  
//  0XFFFFFFBF
UINT OffBit(UINT iNo)
{
    UINT iMask = 0XFFFFFFBF;
    
    UINT Result = 0;

    Result = iNo & iMask;

    return Result;
}

int main()
{
    UINT Value = 0, iRet = 0;

    printf("Please Enter the number : \n");
    scanf("%d", &Value);

    iRet = OffBit(Value);

    printf("After off 7th bit number is %d", iRet);

    return 0;
}
