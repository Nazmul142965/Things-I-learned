#include<stdio.h>

int main(){
    int n;

    printf("Enter the number of subjects:");
    scanf("%d", &n);

    int marks[n], i;

    printf("Enter the marks of students:");

    for(i=0; i<n; i++){
        scanf("%d",&marks[i]);
    }
    int sum = 0;
    for(i=0; i<n; i++){
        sum = sum+ marks[i];
    }
    printf("Value of sum: %d\n",sum);

    int average;
    average= sum / n;
    printf("show the average number: %d\n", average);

    int count=0;
    for(i=0; i<n; i++){
        if(marks[i]>average){
            count++;
        }
    }
     printf("Above average number:%d\n", count);
    return 0;

}
