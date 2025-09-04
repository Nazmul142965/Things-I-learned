#include<stdio.h>
int main() {
int j;
printf("ENTER THE SIZE OF A ARRAY:\n");
scanf("%d", &j);
int array[j];
printf("Enter the value of array:\n");
for(int i = 0; i < j; i++) {
scanf("%d", &array[i]);
}
printf("Value of the array:\n");
for(int i = 0; i < j; i++) {
printf("%d ", array[i]);
}
printf("\n");
int k;
printf("Enter the position to delete: ");
scanf("%d", &k);

for(int i = k; i < j - 1; i++) {
array[i] = array[i + 1];
}

j = j - 1;
printf("New array:\n");
for(int i = 0; i < j; i++) {
printf("%d ", array[i]);
}
printf("\n");
return 0;
}