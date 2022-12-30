/*6. Define a structure of student having data members: name, address, marks in C
language, and marks in information system. Take data for n students in an array
and find the total marks obtained by passing structure to a function.*/
#include <stdio.h>

struct student
{
    char name[10];
    char addres[20];
    int marks_C, marks_IS;
};
int get_total_marks(struct student s)
{
    return s.marks_C + s.marks_IS;
}
int main()
{
    int n;
    printf("Enter the number of students = ");
    scanf("%d", &n);
    struct student s[n];
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter student name : ");
        scanf("%s", s[i].name);
        printf("Enter student address : \n");
        scanf("%s", s[i].addres);
        printf("Enter marks in C language : ");
        scanf("%d", &s[i].marks_C);
        printf("Enter marks in Information Systems : ");
        scanf("%d", &s[i].marks_IS);
    }
    printf("LIST OF STUDENT DETAILS:\n");
    for (int i = 0; i < n; i++)
    {
        int total = get_total_marks(s[i]);
        printf("\nNAME : %s\nADDRES : %s\nMARKS IN C LANGUAGE : %d\nMARKS IN SYSTEMS INFORMATION : %d\nTOTAL MARKS: %d\n", s[i].name, s[i].addres, s[i].marks_C, s[i].marks_IS, total);
        total = 0;
    }

    return 0;
}