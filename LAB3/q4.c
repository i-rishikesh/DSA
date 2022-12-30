/*Q4. Create a structure named student that has name, roll and mark as members.
Assume appropriate types and size of member. Write a program using structure
to read and display the data entered by the user by passing structure to a function.
*/
#include <stdio.h>

struct Student {
    char name[100];
    int roll, totalMarks;
};

void input( struct Student *A ){
    // Input details
    printf("Enter name: ");
    scanf("%[^\n]s", A->name);

    printf("Enter roll: ");
    scanf("%d", &A->roll);

    printf("Enter marks: ");
    scanf("%d", &A->totalMarks);
}

void display( struct Student A ){
    printf("Student details are: ");
    printf("\n\tName: %s\n\tRoll: %d\n\tTotal marks: %d\n", A.name, A.roll, A.totalMarks);
}

int main(){
    // declare a student
    struct Student A;
    // Input details
    input(&A);
    // Display
    display(A);

    // End
    return 0;
}