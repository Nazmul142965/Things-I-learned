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

    int count=0, A=0,B=0,C=0,D=0, F=0;
    for(i=0; i<n; i++){
        if(marks[i]>average){
            count++;
        }
            if(marks[i]>=90 &&marks[i]<=100){
                A++;
            }
            if(marks[i]>=80 &&marks[i]<=89){
                B++;
            }
            if(marks[i]>=70 &&marks[i]<=79){
                C++;
            }
            if(marks[i]>=60 &&marks[i]<=69){
                D++;
            }
            if(marks[i]<=60 ){
                F++;
            }
    }
     printf("Above average number:%d\n", count);
     printf("Students get A:%d\n", A);
     printf("Students get B:%d\n", B);
     printf("Students get C:%d\n", C);
     printf("Students get D:%d\n", D);
     printf("Students get F:%d\n", F);

    return 0;

}
