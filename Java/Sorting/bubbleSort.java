import java.io.IOException;
import java.util.Scanner;

public class bubbleSort {
   
    static void BubbleSort(int arr[], int n)
    {
        for(int i=1;i<n;i++){
            for(int j=0;j<n-i;j++){
                if(isGreater(arr[j], arr[j+1]))
                    swap(arr, j, j+1);
            }
        }
    }
    static boolean isGreater(int i, int j){
        return (i>j);
    }
    static void swap(int arr[], int i, int j){
        arr[i]=arr[i]^arr[j];
        arr[j]=arr[i]^arr[j];
        arr[i]=arr[i]^arr[j];
    }
    static void printArray(int arr[])
    {
        int n = arr.length;
        for (int i=0; i<n; ++i)
            System.out.print(arr[i] + " ");
        System.out.println();
    }
	public static void main(String args[])throws IOException
	{
	    //taking input using Scanner class
		Scanner sc = new Scanner(System.in);

        //taking total elements
        int n = sc.nextInt();
        
        //creating a new array of length n
        int arr[] = new int[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
        {
            arr[i] = sc.nextInt(); 
        }
        sc.close();
        BubbleSort(arr,n);
        printArray(arr);
	}
}
