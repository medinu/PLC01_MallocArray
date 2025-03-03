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

int convertCharToLetterGrade(void* grade){
    int a;
    switch (*(char*)grade){
    case 'A': case 'a':
        a = 4;
        break;
    case 'B': case 'b':
        a = 3;
        break;
    case 'C': case 'c':
        a = 2;
        break;
    case 'D': case 'd':
        a = 1;
        break;
    case 'F': case 'f':
        a = 0;
        break;
    default:
        printf("Warning... Invalid Character... Recording an F.\n");
        a = 0;
        break;
    }
    return a;
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
    printf("Please enter your last name: ");
    scanf(" %s", &str_lastName);
    printf("You entered: %s \n", str_lastName);    

    int32_t numPrevCourses;
    printf("Enter number of previous courses: ");
    scanf(" %d", &numPrevCourses);
    printf("You entered: %d\n", numPrevCourses);  

    int32_t *prevGrades = (int32_t*) malloc(sizeof(int)*(numPrevCourses+1));

    for (int32_t courseIx = 0; courseIx < numPrevCourses; ++courseIx){
        void* letterGrade;
        printf("Enter letter grade for course # %d: ", (courseIx+1));
        scanf(" %c" , &letterGrade);

        int numGrade = convertCharToLetterGrade(&letterGrade);
        prevGrades[courseIx] = numGrade;
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
    }

    char fullName[40]; 
    strcpy(fullName, str_firstName);
    strcat(fullName, " ");
    strcat(fullName, str_lastName);

    const auto const_fullName = fullName;

    printf("\nGrade Report for %s \n", const_fullName);
    const auto examAverage = getArrayAverage(examGrades, numExams);
    printf("Your exam average is: %.2f \n",  examAverage);
    

    // get GPA with newest course added:
    const auto newLetterGrade = getLetterGradeFromAverage(examAverage);
    prevGrades[numPrevCourses] = newLetterGrade;

    const auto gpa = getArrayAverage(prevGrades, (numPrevCourses+1));
    printf("Your latest GPA is: %.2f \n", gpa);

    return 0;
}