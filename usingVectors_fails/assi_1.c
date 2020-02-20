#include <stdio.h>
#include <stdint.h>

#include <stdlib.h>

#include <string.h>

/* hw part*/ 
enum LetterGrade {
    A = 4,
    B = 3,
    C = 2,
    D = 1, 
    F = 0
};

//error prone
double getArrayAverage(int32_t *a, int n){
    double sum = 0;
    for (int i = 0; i < n; i++){
        sum = a[i] + sum;
    }
    sum = sum / n;
    return sum; 
};

void convertCharToLetterGrade(char* grade){
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

    int32_t *prevGrades = (int32_t*) malloc(sizeof(int)*numPrevCourses);

    for (int32_t courseIx = 0; courseIx < numPrevCourses; ++courseIx){
        char letterGrade;
        printf("\nEnter letter grade for course # %d: ", (courseIx+1));
        scanf(" %c" , &letterGrade);

        convertCharToLetterGrade(&letterGrade);
        prevGrades[courseIx] = letterGrade;
    }
    
    int32_t numExams;
    printf("Enter number of exams this semester: ");
    scanf("%d", &numExams);

    int32_t *examGrades = (int32_t*)malloc(sizeof(int32_t)*numExams);

    for (int32_t examIx = 0; examIx < numExams; examIx++){
        int32_t gradeToEnter;
        printf("Enter grade for exam # %d as an integer: ", (examIx+1));
        scanf(" %d", &gradeToEnter);

        examGrades[examIx] = gradeToEnter; 
        printf("You entered: %d\n", examGrades[examIx]);
    }

    char fullName[40]; 
    strcpy(fullName, str_firstName);
    strcat(fullName, " ");
    strcat(fullName, str_lastName);

    const auto const_fullName = fullName;

    printf("\nGrade Report for %s \n", const_fullName);

    const auto examAverage = getArrayAverage(examGrades, numExams);

    printf("Your latest GPA is: %.2f \n", examAverage);

    return 0;
}