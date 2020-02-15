#include <stdio.h>
#include <stdint.h>

#include <stdlib.h>

#include <string.h>
//#include "sandbox.h"

typedef struct vector_ {
    void** data;
    int size;
    int count;
} vector;


void vector_init(vector *v)
{
    v->data = NULL;
    v->size = 0;
    v->count = 0;
}

int vector_count(vector *v)
{
    return v->count;
}

void vector_add(vector *v, void *e)
{
    /* char *test = (char*)e;
    printf("\t <%c> is passed in to the function vector_add\n", *test); */

    void* a;
    if (v->count == 0) {
        v->size = 10;
        a = malloc((sizeof(void*)) * v->size);
        v->data = &a;
    }

    if (v->size == v->count) {
        v->size *= 2;
        a = realloc(&a, sizeof(void*) * v->size);
        v->data = &a;
    }

    v->data[v->count] = e;
    //printf("<%c> has been added", *(char*)v->data[v->count]);
    v->count++;
}

void vector_print(vector *v){
    if (v->count < 0){
        printf("vector is empty\n");
    }else{
        printf("%s is in index %d\n", v->data[0], 0);
        int i = 1;
        while(i < vector_count(v)){
            printf("%s is in index %d\n", v->data[i], i);
            i++;
        }
    }
}

void *vector_return(vector *v, int index){
    if (v->count <= 0){
        printf("vector is empty\n");
        return NULL;
    }
    else{ 
        return (v->data[index]);
    }
}

/* hw part*/ 
enum LetterGrade {
    A = 4,
    B = 3,
    C = 2,
    D = 1, 
    F = 0
};

//error prone
double getArrayAverage(vector *a){

    int exe = (int*)vector_return(a, 0);

    /* int sum = 0;
    
    for (int i = 0; i < a->count; i++){
        int tempVar = (int)vector_return(a, i);
        int temp = tempVar;
        // convert (int)vector_return(a, i); to int and compute average
        sum = sum + temp;
    }
    sum = sum / a->count;
    return sum; */
};

void convertCharToLetterGrade(char* grade){
    //printf("\t <%c> is passed in to the function\n", *grade);
    switch (*grade){
    case 'A': case 'a':
        *grade = '4';
        break;
    case 'B': case 'b':
        *grade = '3';
        break;
    case 'C': case 'c':
        *grade = '2';
        break;
    case 'D': case 'd':
        *grade = '1';
        break;
    case 'F': case 'f':
        *grade = '0';
        break;
    
    default:
        printf("Warning... Invalid Character... Recording an F.\n");
        break;
    }
};

enum LetterGrade getLetterGradeFromAverage(const double avg) {
    if (avg >= 90)
        return A;
    else if (avg >= 80)        
        return B;
    else if (avg >= 70)    
        return C;
    else if (avg >= 60)
        return D;
    else 
        return F;
}

int main()
{
    char str_firstName[20];
    printf("Please enter your first name: ");
    scanf(" %s", &str_firstName);
    printf("You entered: %s \n", str_firstName); 

    char str_lastName[20];
    printf("Please enter your lasst name: ");
    scanf(" %s", &str_lastName);
    printf("You entered: %s \n", str_lastName);    

    int32_t numPrevCourses;
    printf("Enter number of previous courses: ");
    scanf(" %d", &numPrevCourses);
    printf("You entered: %d", numPrevCourses);  

    vector prevGrades;
    vector_init(&prevGrades);

    for (int32_t courseIx = 0; courseIx < numPrevCourses; ++courseIx){
        char letterGrade;
        printf("\nEnter letter grade for course %d :", courseIx);
        scanf(" %c" , &letterGrade);

        convertCharToLetterGrade(&letterGrade);

        vector_add(&prevGrades, &letterGrade);
    }
    
    int32_t numExams;
    printf("\nEnter number of exams this semester: ");
    scanf("%d", &numExams);

    vector examGrades;
    vector_init(&examGrades);

    for (int32_t examIx = 0; examIx < numExams; ++examIx){
        int32_t gradeToEnter;
        printf("\nEnter grade for exam %d as an integer: ", examIx);
        scanf(" %d", &gradeToEnter);

        printf("You entered: %d", gradeToEnter);

        vector_add(&examGrades, &gradeToEnter);
    }

    char fullName[40]; 
    strcpy(fullName, str_firstName);
    strcat(fullName, " ");
    strcat(fullName, str_lastName);

    const auto const_fullName = fullName;

    printf("\nGrade Report for %s: ", const_fullName);

    const auto examAverage = getArrayAverage(&examGrades);

    printf("Your latest GPA is: %d \n", &examAverage);

    return 0;
}