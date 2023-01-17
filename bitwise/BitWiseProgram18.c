//Write the program which accept twon number from user and check whether 9th and 12th bits is on or off
//Input: 2304
//Output: ON

#include<stdio.h>
#include<stdbool.h>
// 0000     0000    0000    0000    0000    0001    0000    0000
//  0        0       0        0       0       1       0       0    9th Pos
// 0000     0000    0000    0000    0000    1000    0000    0000
//  0        0       0        0       0       8       0       0    12th Pos

//  0X00000040
typedef unsigned int UINT;

bool ChkBit(UINT No)
{
    UINT iMask1 = 0X00000100;   //9th Bit ON
    UINT iMask2 = 0X00000800;   //12th Bit ON

    UINT Result1 = No  &  iMask1;
    UINT Result2 = No  &  iMask2;

    if((Result1 == iMask1) &&(Result2 == iMask2) )
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    UINT iValue = 0, Position1 = 0, Position2 = 0;
    bool bRet = 0;
    printf("Enter the Number : \n");
    scanf("%d",&iValue);

    bRet = ChkBit(iValue);
    if(bRet == true)
    {
       printf("Bit at the position 9th and 12th is ON\n");
    }
    else
    {
        printf("Bit at the position 9th and 12th is OFF\n");
    }

    return 0;
}