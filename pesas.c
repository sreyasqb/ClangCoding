#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student{
    int rollno;
    char name[100];
    char section;
    char dept[100];
    int fees;
    int result;
};

int main(){
    struct student s1,s2;
    scanf("%d",&s1.rollno);
    scanf("%s",&s1.name);
    getchar();
    scanf("%c",&s1.section);
    getchar();
    scanf("%s",&s1.dept);
    getchar();
    scanf("%d",&s1.fees);
    scanf("%d",&s1.result);
    scanf("%d",&s2.rollno);
    scanf("%s",&s2.name);
    getchar();
    scanf("%c",&s2.section);
    getchar();
    scanf("%s",&s2.dept);
    getchar();
    scanf("%d",&s2.fees);
    scanf("%d",&s2.result);
    printf("Student details who has scored the highest marks\n");
    if (s1.result>s2.result){
        printf("Roll number: %d\n",s1.rollno);
        printf("Name: %s\n",s1.name);
        printf("Section: %c\n",s1.section);
        printf("Department: %s\n",s1.dept);
        printf("fees: %d\n",s1.fees);
        printf("Results: %d\n",s1.result);
    }
    else{
        printf("Roll number: %d",s2.rollno);
        printf("Name: %s",s2.name);
        printf("Section: %c",s2.section);
        printf("Department: %s",s2.dept);
        printf("fees: %d",s2.fees);
        printf("Results: %d",s2.result);

    }
}