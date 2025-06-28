#include<stdio.h>
void HanoiOfTower(int n,char fromRod,char toRod,char auxRod)
{
    if(n==1)
    {
        printf("Move disk 1 from rod %c to rod %c.\n",fromRod,toRod);
        return;
    }
    HanoiOfTower(n-1,fromRod,auxRod,toRod);
    printf("Move disk %d from rod %c to rod %c.\n",n,fromRod,toRod);
    HanoiOfTower(n-1,auxRod,toRod,fromRod);
}
int main()
{
    int n;
    printf("Enter the disks number = ");
    scanf("%d",&n);
    HanoiOfTower(n,'A','C','B');
    return 0;
}
