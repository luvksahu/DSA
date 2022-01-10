#include <stdio.h>
#include <stdlib.h>

int linearSearch(int *arr,int key, int n)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i]==key)
            return 1;       
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
    int temp=linearSearch(arr, key, n);
    if(temp==1)
        printf("Element is present in array");
    else        
        printf("Element is not present in array");

    return 0;
}