#include<stdio.h>

void swap(int arr, int n){
   
}

void insertion(int arr, int n){

}

int main(){
    int arr[] ={10,7,6,4,1,3,5,8};
    int n = sizeof(arr)/sizeof(arr[0]);
    return 0;
}
//By arnav
#include<stdio.h>

int main() {
    int n;
    int i, j, key;
    
    printf("Enter the number of elements: ");
    scanf("%d", &n);
 
    int arr[n];
    printf("Enter your array: ");
    for(i=0; i<=n-1; i++) {
        scanf("%d", &arr[i]);
    }

    for(i=0; i<n-1; i++) {
        for(j=i+1; j<n; j++) {
            if(arr[i]>arr[j]) {
                key = arr[i];
                arr[i] = arr[j];
                arr[j] = key;
            }
        }
    }

    printf("Sorted Array: ");
    for(i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
}