//Write the program which accept twon number from user and display position of common ON bits from that two number.

//Input: 10     15    (1010    1111)
//Output: 2   4
#include<stdio.h>

typedef unsigned int UINT;

void CommonBits(UINT iNo1, UINT iNo2)
{
    UINT iMask = 0X00000001;
    UINT ipos = 1;
    UINT Result1 = 0;
    UINT Result2 = 0;
    printf("Common ON Bits are : ");
    while(ipos < 32)
    {
        ipos++;
        iMask = 0X00000001;
        iMask = iMask << (ipos -1);
        Result1 = iNo1 & iMask;
        Result2 = iNo2 & iMask;
        
        if((Result1 == iMask) && (Result2 == iMask))
        {
            printf("%d\t",ipos);
        }
    }

}

int main()
{
    UINT iValue1 = 0, iValue2 = 0;
    int iRet = 0;
    printf("Enter the First Number to check ON bits\n");
    scanf("%d",&iValue1);

    printf("Enter the Second Number to check ON bits\n");
    scanf("%d",&iValue2);

    CommonBits(iValue1,iValue2);
    //printf("\nNumber of ON bits are : %d\t ", iRet);

    return 0;
}