// Create a program to ask the user for n elements and a target number, then count how many times the target appears in the array.

 #include <stdio.h>

 int main(void){
    int n; printf("Input length of array: ");scanf("%d", &n);
    int arr[n]; printf("Input numbers into the array: \n");
    for (int i = 0; i < n; i++){
        printf("Element [%d]: ", i);
        scanf("%d", &arr[i]);
    }
    int target; printf("Input target number: ");
    scanf("%d", &target);

    int counter = 0;
    for (int i = 0; i < n; i++){
        if (arr[i] == target){
            counter++;
        }
    }

    printf("%d appears %d times\n", target, counter);
 }