#include <stdio.h>
#include <string.h>
struct Student{
    int age;
    char name[50]="Sonu paswan";
    float marks;
};
int main()
{
    struct Student S1;
    S1.age=16;
    // S1.name="sonu Paswan";
    S1.marks=90;
    printf("student name %s",S1.name);
    return 0;
}