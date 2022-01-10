#include <stdio.h>
#include <stdlib.h>

int linearSearch(int *arr,int key, int n, int i)
{  
    if(i==n)
        return 0;
    if(arr[i]==key)
        return 1;
    return linearSearch(arr, key, n, ++i);
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
    int temp=linearSearch(arr, key, n, 0);
    if(temp==1)
        printf("Element is present in array");
    else        
        printf("Element is not present in array");

    return 0;
}