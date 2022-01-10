#include <stdio.h>
#include <stdlib.h>

int binearSearch(int *arr,int key, int start, int end)
{  
    int mid=0;
    while(end>=start)
    {
        mid=(start+end)/2;
        if(arr[mid]==key)
            return 1;
        else if(key<arr[mid])
            end=mid-1;        
        else if(key>arr[mid])
            start=mid+1;     
    }
    return 0;
}
int main()
{
    int n,key;
    printf("Enter size of Array: ");
    scanf("%d",&n);
    int *arr=(int*)calloc(n,sizeof(int));
    for(int i=0;i<n;i++)
    {
        printf("Enter %d element: ",i+1);
        scanf("%d",&arr[i]);
    }
    printf("Enter element to be searched: ");
    scanf("%d",&key);
    int temp=binearSearch(arr, key, 0, n);
    if(temp==1)
        printf("Element is present in array");
    else        
        printf("Element is not present in array");

    return 0;
}