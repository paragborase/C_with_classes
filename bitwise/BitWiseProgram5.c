//Write the program which check whether first and last bit is on or OFF
//First bit means bit number 1 and last bit is means bit number 32
#include<stdio.h>
#include<stdbool.h>
typedef int BOOL;
typedef unsigned int UINT;

#define TRUE 1
#define FALSE 0

//0000   0000    0000    0000    0000    0000    0000     0000
// 8       0      0        0       0      0       0         1 
//0X80000001 
bool ChkBit(UINT iNo)
{
    UINT iMask = 0X80000001;
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
        printf("1 and last bit is on\n");
    }
    else
    {
        printf("1 and last bit is off\n");
    }
    return 0;
}