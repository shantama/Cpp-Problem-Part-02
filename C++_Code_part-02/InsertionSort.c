#include<stdio.h>
int main()
{
    int n,key;
    printf("Enter the size of array : ");
    scanf("%d",&n);
    int array[n];
    printf("Enter the array : ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&array[i]);
    }
    for(int i=1;i<n;i++)
    {
        key=array[i];
        int j=i-1;
    while(j>=0 && key<array[j])
    {
        array[j+1]=array[j];
        j--;
    }
    array[j+1]=key;
    }
    printf("Sorted array(Insertion sort Algorithm):\n");
    for(int i=0;i<n;i++)
    {
        printf("%d ,",array[i]);
    }
    printf("\n");
}
