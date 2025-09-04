#include<stdio.h>
int main(){
int j;
printf("ENTER THE SIZE OF A ARRAY:\n");
scanf("%d", &j);
int array[j];
printf("Enter the value of array:\n");
for(int i= 0; i<=j; i++){
scanf("%d", &array[i]);
}
printf("Value of the array:\n");
for(int i= 0; i<=j; i++){
printf("%d ", array[i]);
}
printf("\n");
int k, item;
printf("Enter the value of Position:\n");
scanf("%d", &k);
printf("Enter the value of a Insert number:\n");
scanf("%d", &item);

for(int n = j ; n>= k; n--){
array[n+1] = array [n];
}
array[k] = item;
j = j+1;
printf("New array:\n");
for(int i= 0; i<j+1; i++){
printf("%d ", array[i]);
}
return 0;
}