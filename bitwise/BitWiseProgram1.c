//Write the program which check whether 15th bit is or or OFF
#include<stdio.h>
#include<stdbool.h>
typedef int BOOL;
typedef unsigned int UINT;

#define TRUE 1
#define FALSE 0

//0000    0000    0000    0000    0100    0000    0000     0000
// 0        0      0        0        4      0      0        0 
//0X00004000
bool ChkBit(UINT iNo)
{
    UINT iMask = 0X00004000;
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
        printf("15th bit is on\n");
    }
    else
    {
        printf("15th bit is off\n");
    }
    return 0;
}