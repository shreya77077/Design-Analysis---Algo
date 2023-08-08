#include<stdio.h>

void insertion(int arr[],int n){
    int i,key,j;
    for(i=0;i <n; i++){
    key = arr[i];
    j = i-1;
    while(j >0 && arr[j]> key){
        arr[j+1]== arr[j];
        j=j-1;
    }
    arr[j+1]= key;
    }
}

void printoutput(int arr[],int n){
    int i;
    for (i=0; i<n;i++){
        printf("%d",arr[i]);
        print("\n");
    }
}
int main(){
    int arr[] = {7,8,10,2,4,3,1,5};
    int i,n;
    //n is no.of elements
    n = sizeof(arr)/sizeof(arr[0]);
    insertion(arr,n);
    printoutput(arr,n);

    return 0;

}
//it should be assesnding order to get best case
