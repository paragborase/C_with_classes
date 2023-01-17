//Write the program which accept one number and position from user and 
//toggle contents of first and last nibble of that number.
//return Modified number.

#include<stdio.h>
#include<stdbool.h>
typedef unsigned int UINT;
// 1111     0000    0000    0000    0000    0000    0000    1111
//  F        0       0        0       0       0       0      F  
//  0XF000000F
UINT ToggleBit(UINT iNo)
{
    UINT iMask = 0XF000000F;

    UINT Result = 0;
    
    Result = iNo ^ iMask;

    return Result;
}

int main()
{
    UINT Value = 0;
    int iRet = 0;

    printf("Please Enter the number : \n");
    scanf("%d", &Value);

    iRet = ToggleBit(Value);

    printf("Updated number is %d",iRet);
    
    return 0;
}


//      1   1   0   0      0   0   1   0        0   0   1   1
// ^    1   1   1   1      0   0   0   0        1   1   1   1
//===================================================================
//      0   0   1   1      0   0   1   0        1   1   0   0
//      Toggle             0   0   1   0        Toggle
