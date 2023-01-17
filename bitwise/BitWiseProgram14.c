//Write the program which accept one number and position from user and 
//toggle that bit
//Return Modified number
//Input: 10  3
//Output: 14
#include<stdio.h>
#include<stdbool.h>
typedef unsigned int UINT;
// 0000     0000    0000    0000    0000    0000    0000    0000
//  0        0       0        0       0       0       0      1  
//  0X00000001
UINT toggleBit(UINT iNo, UINT iPos)
{
    UINT iMask = 0X00000001;

    UINT Result = 0;
    
    iMask = iMask << (iPos-1);     
    
    Result = iNo ^ iMask;

    return Result;
}

int main()
{
    UINT Value = 0,  ipos = 0;
    int iRet = 0;

    printf("Please Enter the number : \n");
    scanf("%d", &Value);

    printf("Please Enter the number : \n");
    scanf("%d", &ipos);

    iRet = toggleBit(Value,ipos);

    printf("After toggle bit of position  %d number is %d",ipos,iRet);
    
    return 0;
}
