#include <stdio.h>
void quickSort( int * , int , int);
int partition(int *, int , int);
static int count=0;
int main(){
    int n;
    printf("Enter number of players: \n");
    scanf("%d",&n);
    int arr[n];
    int low=0,high = n-1;
    printf("Enter the player's ratings:\n");
    for(int i = 0;i < n; i++){
        scanf("%d",&arr[i]);
    }
    quickSort(arr, low, high);
    printf("The sorted array is:\n");
    for(int i = 0;i < n; i++){

        printf("%d\t",arr[i]);
    }
    printf("\nTeam 1: \n");
    for (int i=0; i<n/2; i++){
        printf("%d \t", arr[i]);
    }
    printf("\nTeam 2: \n");
    for (int j=n/2; j<n; j++){
        printf("%d \t",arr[j]);
    }
    printf("\nSwaps: %d",count) ;
}
void quickSort( int a[], int low, int high)
{
    int ele;
    if(low < high){
      ele = partition(a, low, high);
      quickSort(a, low, ele-1);
      quickSort(a, ele+1, high);
    }
}
int partition(int a[], int low, int high)
{
   int pivot, i, j, temp;
   pivot = a[low];
   i = low + 1;
   j = high;
  do {
   while( a[i] <= pivot && i <= high){
    i++;
   }
   while( a[j] >pivot && j >= low){
    j--;
   }
   if( i < j && a[i] > a[j]){
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
        
   }
   else{
      temp = a[j];
      a[j] = a[low];
      a[low] = temp;
      count++;
      break;
   }
   
   }while(i<j);
   
    

   return j;
}


