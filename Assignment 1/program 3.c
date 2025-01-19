//program to manage student details
#include<stdio.h>
struct student
{
    char name[100];
    int roll;
    float marks;
};

int main()
{
    printf("enter the number of students you want details for: ");
    int n;
    scanf("%d",&n);
    struct student a[n];
    
    for (int i=0;i<n;i++)
    {   
        printf("\nenter the name of student %d: ",i+1);
        char t;
        scanf("%c",&t);
        fgets(a[i].name,100,stdin);
        printf("\nenter the roll number of student %d: ",i+1);
        scanf("%d",&a[i].roll);
        printf("\nenter the marks of student %d: ",i+1);
        scanf("%f",&a[i].marks);
    }
    
    for(int i=0;i<n;i++)
    {
        printf("\nname of student %d: %s",i+1,a[i].name);
        printf("\nroll number of student %d: %d",i+1,a[i].roll);
        printf("\nmarks of student %d: %f",i+1,a[i].marks);
        printf("\n");
    }    
}