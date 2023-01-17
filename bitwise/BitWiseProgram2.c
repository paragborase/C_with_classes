//Write the program which check whether 5th and 18th bit is or or OFF
#include<stdio.h>
#include<stdbool.h>
typedef int BOOL;
typedef unsigned int UINT;

#define TRUE 1
#define FALSE 0

//0000    0000    0000    0010    0000    0000    0001     0000
// 0        0      0        2       0       0       1        0 
//0X00020010
bool ChkBit(UINT iNo)
{
    UINT iMask = 0X00020010;
    UINT Result = 0;

    Result = iNo & iMask;

    if(Result == iMask)
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
    UINT Value = 0;
    bool bRet = false;
    
    printf("Please Enter the Number : ");
    scanf("%d",&Value);

    bRet = ChkBit(Value);

    if(bRet == true)
    {
        printf("15th and 18th bit is on\n");
    }
    else
    {
        printf("15th and 18th bit is off\n");
    }
    return 0;
}