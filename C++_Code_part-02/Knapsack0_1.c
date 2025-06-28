#include<stdio.h>
int max(int a,int b)
{
    return a>b?a:b;
}
int knapsack(int iteam,int capacity,int weights[],int profits[])
{
    int dataTable[iteam+1][capacity+1];
    for(int i=0;i<=iteam;i++)
    {
        for(int w=0;w<=capacity;w++)
        {
            if(i==0 ||w==0)
            {
                dataTable[i][w]=0;
            }
            else if(weights[i-1]<=w)
            {
                dataTable[i][w]=max(dataTable[i-1][w],dataTable[i-1][w-weights[i-1]]+profits[i-1]);
            }
            else
            {
                dataTable[i][w]=dataTable[i-1][w];
            }
        }
    }
    return dataTable[iteam][capacity];
}
int main()
{
    int iteam,capacity;
    printf("Enter the number of iteam :");
    scanf("%d",&iteam);
    int weights[iteam],profits[iteam];
    printf("Enter weights of %d iteam respectively : ",iteam);
    for(int i=0;i<iteam;i++)
    {
        scanf("%d",&weights[i]);
    }
    printf("Enter profits of %d iteam respectively : ",iteam);
    for(int i=0;i<iteam;i++)
    {
        scanf("%d",&profits[i]);
    }
     printf("Enter the maximum weight : ");
    scanf("%d",&capacity);
    int max=knapsack(iteam,capacity,weights,profits);
    printf("Maximum profits : %d",max);
}
