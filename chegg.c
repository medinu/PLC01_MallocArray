#include <stdio.h>

int convertCharToLetterGrade(char grade)
{
    switch (grade)
    {
    case 'A': case 'a':{return(4);}
    case 'B': case 'b':{ return(3);}
    case 'C': case 'c':{return(2);}
    case 'D': case 'd':{return(1);}
    case 'F': case 'f':{return(0);}
    default:{printf("Warning... Invalid Character... Recording an F.\n");return(0);} 
    }
}

int exavg(int *curGrade)
{
    int arraysize=sizeof(curGrade)/sizeof(int);
    int i,total=0;
    for(int i=0; i<arraysize; i++)
    {
    total=curGrade[i]+total;
    }
    return(total/arraysize);
}


char getLetterGradeFromAverage(int avg)
{
if(avg >= 90)
    return 'A';
else if(avg >= 80)
    return 'B';
else if(avg >= 70)
    return 'C';
else if(avg >= 60)
    return 'D';
else
    return 'F';
}

void main()
{
    char firstname[50];
    char lastname[50];
    int numPrevCourses;
    int courseIx = 0;
    int *preGrade=NULL;
    char courseGrade;
    int examCurSem;
    int examIx;
    int *curGrade=NULL;
    int Grade=0;
    int gpa=0, curEaxmAvg;
  
  
    printf("Please enter your first name: \n");
    scanf("%s",firstname);
    printf("Please enter your last name: \n");
    scanf("%s",lastname);
    
    printf("Enter number of previous courses: \n");
    scanf("%d",&numPrevCourses);
  

/* Allocate dynamic memory for storing the grade */
    preGrade = (int *) malloc(sizeof(int)*numPrevCourses+1);
  
    for(courseIx = 0; courseIx < numPrevCourses; ++courseIx){
        printf("Enter letter grade for course \n");
        scanf(" %c",&courseGrade);
        preGrade[courseIx]=convertCharToLetterGrade(courseGrade);
    }

    printf("Enter number of exams this semester: \n");
    scanf("%d",&examCurSem);
    

    /* Allocating dynamic memory to store the current semester grade */
    curGrade = (int *)malloc(sizeof(int)*examCurSem);
    for(examIx = 0; examIx < examCurSem; ++examIx){
        printf("Enter grade for exam as an integer: \n");
        scanf("%d",&curGrade[examIx]);
    }

    printf("Grade Report For %s %s\n",firstname, lastname);

    curEaxmAvg=exavg(curGrade);
    printf("Your exam average is: %d\n", curEaxmAvg);

    Grade=getLetterGradeFromAverage(curEaxmAvg);

    preGrade[numPrevCourses]=convertCharToLetterGrade(Grade);


    gpa = exavg(preGrade);
    printf("Your latest GPA is: %d\n",gpa);
}