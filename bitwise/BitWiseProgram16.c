//Write the program which accept one number from user  and count number of ON(1) bits in it without using % and / operator.
//Input: 11
//Output: 3
#include<stdio.h>

typedef unsigned int UINT;

int Count(UINT iNo)
{
    UINT iMask = 0X00000001;
    int ipos = 1;
    UINT iResult = 0;
    int iOnBit = 0;
    while(ipos <= 32)
    {
        ipos++;
        iMask = 0X00000001;
        iMask = iMask << (ipos -1); 
        iResult = iNo & iMask;
        if(iResult == iMask)
        {
            iOnBit++;
        }
    }
    return iOnBit;
}

int main()
{
    UINT iValue = 0;
    int iRet = 0;
    printf("Enter the Number to check ON bits\n");
    scanf("%d",&iValue);

    iRet = Count(iValue);
    printf("\nNumber of ON bits are : %d\t ", iRet);

    return 0;
}