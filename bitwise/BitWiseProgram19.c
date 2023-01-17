//Write the program which accept twon number from user and two position from user and check whether bit at First aor bit at seocnd position is ON or OFF
//Input: 257     Position 1 and Position 9
//Output: TRUE

#include<stdio.h>
#include<stdbool.h>

typedef unsigned int UINT;

bool ChkBit(UINT No, UINT Pos1, UINT Pos2)
{
    UINT iMask1 = 0X00000001;    //UINT iMask = 1
    UINT iMask2 = 0X00000001;    //UINT iMask = 1

    UINT iMask = 0;

    UINT Result = 0;

    if((Pos1 < 1) || (Pos1 > 32) || (Pos2 < 1) || (Pos2 > 32))
    {
        printf("Invalid position, it should between 1 to 32\n");
        return false;
    }

    iMask1 = iMask1 << (Pos1 -1);  // Dynamic Mask Formation
    iMask2 = iMask2 << (Pos2 -1);  // Dynamic Mask Formation

    iMask = iMask1 | iMask2;

    Result = No & iMask;

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
    UINT iValue = 0, Position1 = 0, Position2 = 0;
    bool bRet = 0;
    printf("Enter the Number : \n");
    scanf("%d",&iValue);

    printf("Enter the Position1: \n");
    scanf("%d",&Position1);

    printf("Enter the Position2: \n");
    scanf("%d",&Position2);

    bRet = ChkBit(iValue,Position1,Position2);
    if(bRet == true)
    {
       printf("Bit at the position %d & %d is ON\n",Position1, Position2);
    }
    else
    {
        printf("Bit at the position %d & %d is OFF\n",Position1, Position2);
    }

    return 0;
}