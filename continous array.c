#include <stdio.h>

int findmax(int *arr,int n)
{
    int max,maax;
    max=maax=0;
    for(int i=0;i<n;i++)
    {
        maax+=arr[i];
        if(maax > max)
        {
            max=maax;
        }
        if(maax < 0)
        {
            maax=0;
        }
    }
    return max;
}

int main()
{
    int arr[]={1,2,3,-5,10};
    int n=sizeof(arr)/sizeof(arr[0]);
    int max=findmax(arr,n);
    printf("The max value is: ");
    printf("%d",max);
}
