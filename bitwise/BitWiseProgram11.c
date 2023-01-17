//Write the program which accept one number and position from user and check whether
//bit as that position is on or off. If bits is one return True otherwise retrun false
//Input: 10  2
//Output: TRUE
#include<stdio.h>
#include<stdbool.h>
typedef unsigned int UINT;
// 0000     0000    0000    0000    0000    0000    0000    0000
//  0        0       0        0       0       0       0      1  
//  0X00000001
bool CheckBit(UINT iNo, UINT iPos)
{
    UINT iMask = 0X00000001;
    UINT Result = 0;
    
    iMask = iMask << (iPos-1);
    
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
    UINT Value = 0,  ipos = 0;
    bool bRet = false;

    printf("Please Enter the number : \n");
    scanf("%d", &Value);

    printf("Please Enter the number : \n");
    scanf("%d", &ipos);

    bRet = CheckBit(Value,ipos);

    if(bRet == true)
    {
        printf("%d position of bit in number %d is ON",ipos,Value);
    }
    else
    {
        printf("%d position of bit in number %d is OFF",ipos,Value);
    }
    return 0;
}
