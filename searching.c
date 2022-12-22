#include <stdio.h>

void inputarr(int arr[],int n){
    int i;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    printf("Input elements of the array: ");
    for(i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
}

void linearSearch(int arr[], int n){
    int i, num;
    printf("Enter the element you want to search: ");
    scanf("%d", &num);
    for(i=0; i<n; i++){
        if(arr[i]== num){
            printf("The element %d is presesnt at position %d\n", num, i+1);
            return;
        }
    }
    printf("The element is not present in the array\n");
}

int binarySearch(int arr[], int n){
    int beg = 0, end = n-1, mid, num, found = 0;
    printf("Enter the element you want to search: ");
        scanf("%d", &num);
    while(beg<=end){
        mid = (beg + end)/ 2;
        if(arr[mid] == num){
            printf("Element %d is found at position %d\n", num, mid + 1);
            found = 1;
            break;
        }
        else if(arr[mid] > num)
            end = mid - 1;
        else
            beg = mid + 1;
    }
    if((beg>end) || (found == 0))
        printf("Element is not present in the array!\n");
    return 0;
}

int interpolationSearch(int arr[], int n){
    int beg = 0, end = n-1, mid, num, found = 0;
    printf("Enter the element you want to search: ");
        scanf("%d", &num);
    while(beg<=end){
        mid = end + (beg - end)* ((num-arr[beg])/(arr[end] - arr[beg]));
        if(arr[mid] == num){
            printf("Element %d is found at position %d\n", num, mid + 1);
            found = 1;
            break;
        }
        else if(arr[mid] > num)
            end = mid - 1;
        else
            beg = mid + 1;
    }
    if((beg>end) || (found == 0))
        printf("Element is not present in the array!\n");
    return 0;
}



int main(){
    int arr[50], n;
    inputarr(arr, n);
    // linearSearch(arr, n);
    binarySearch(arr, n);
    return 0;
}