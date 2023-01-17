//Write the program which accept one number and position from user and off that bit
//Return Modified number
//Input: 10  2
//Output: 8
#include<stdio.h>
#include<stdbool.h>
typedef unsigned int UINT;
// 0000     0000    0000    0000    0000    0000    0000    0000
//  0        0       0        0       0       0       0      1  
//  0X00000001
UINT OffBit(UINT iNo, UINT iPos)
{
    UINT iMask = 0X00000001;

    UINT Result = 0;
    
    iMask = iMask << (iPos-1);   

    iMask = ~iMask;    
    
    Result = iNo & iMask;

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

    iRet = OffBit(Value,ipos);

    printf("After of OFF bit of position %d number is %d",ipos,iRet);
    
    return 0;
}
