import java.util.*;


class insertionSort
{
  static void InsertionSort(int arr[], int n)
  {
      for(int i=1;i<n;i++)
      {
            for(int j=i-1;j>=0;j--)
            {
                if(isGreater(arr[j], arr[j+1]))
                    swap(arr, j, j+1);
                else
                    break;
            }
      }
  }
  static void swap(int arr[], int i, int j){
      arr[i]=arr[i]^arr[j];
      arr[j]=arr[i]^arr[j];
      arr[i]=arr[i]^arr[j];
  }
  static boolean isGreater(int a, int b){
      return (a>b);
  }
	static void printArray(int arr[],int size)
	{
		int i;
		for(i=0;i<size;i++)
		System.out.print(arr[i]+" ");
	    System.out.println();
	}
	
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		
        int n = sc.nextInt();
        int a[] = new int[n];
    
        for(int i=0;i<n;i++)
            a[i]= sc.nextInt();
        
        InsertionSort(a,n);
        printArray(a,n);		
		sc.close();
	}
}
