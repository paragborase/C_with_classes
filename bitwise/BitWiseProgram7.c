//Write the program which accept one number from user and off 7th bit and 10th bit of that number if it is on. Return modified number
//Input: 577
//Output: 1
#include<stdio.h>

typedef unsigned int UINT;
// 1111     1111    1111    1111    1111    1101    1011    1111
//  F        F       F        F       F        D      B      F  
//  0XFFFFFDBF
UINT OffBit(UINT iNo)
{
    UINT iMask = 0XFFFFFDBF;
    
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

    printf("After off 7th bit and 10th bit number is %d", iRet);

    return 0;
}
