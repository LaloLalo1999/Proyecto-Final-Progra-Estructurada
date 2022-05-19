#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXSTUDENTS 100

//Estructura que guarda las calificaciones de todos los semestres cursados
typedef struct grades
{
  int semesters[10];
  float grade[10];
  float avg;
} grades;

//Estructura que guarda todos los datos de cada estudiante
typedef struct student 
{
  char name[60];
  int age, semester;
  grades current_grades;
  int id;
} student;

//Prototipos
struct student fillinfo();
float avg_grade(student s1, float avg, int n);
void printstudent(student s1);
void printall(student s[]);
int countstudents(student s[]);
void sortbyname(student s[]);
void sortbyage(student s[]);
void sortbygrade(student s[]);

int main ()
{
  //Declarar el array de estudiantes y llenar la edad de todos con 0
  student students[MAXSTUDENTS];
  for (int n=0; n < MAXSTUDENTS; n++){
    students[n].age = 0;
  } 
  //Example Students
  int ansex = 10;
  while (ansex > 1 || ansex < 0){
    printf("Do you want to add the example students?\n");
    printf("1 YES    0 NO\n");
    int sc1 = 0;
    while (sc1 != 1){
      sc1 = scanf("%d", &ansex);
      getchar();
    }
  }
  if (ansex == 1){
    strcpy(students[0].name, "Eduardo Garcia");
    students[0].age = 23;
    students[0].semester = 2;
    for (int z = 1; z <= students[0].semester; z++){
      students[0].current_grades.semesters[z-1] = z;
    }
    students[0].current_grades.grade[0] = 10;
    students[0].current_grades.grade[1] = 9;
    students[0].current_grades.avg = avg_grade(students[0], 0, 1);
    students[0].id = 741766;
  
    strcpy(students[1].name, "Lucy Serrano");
    students[1].age = 19;
    students[1].semester = 4;
    for (int z = 1; z <= students[1].semester; z++){
      students[1].current_grades.semesters[z-1] = z;
    }
    students[1].current_grades.grade[0] = 10;
    students[1].current_grades.grade[1] = 9;
    students[1].current_grades.grade[2] = 8;
    students[1].current_grades.grade[3] = 10;
    students[1].current_grades.avg = avg_grade(students[1], 0, 1);
    students[1].id = 578324;

    strcpy(students[2].name, "Andres Gomez");
    students[2].age = 25;
    students[2].semester = 3;
    for (int z = 1; z <= students[2].semester; z++){
      students[2].current_grades.semesters[z-1] = z;
    }
    students[2].current_grades.grade[0] = 7;
    students[2].current_grades.grade[1] = 6;
    students[2].current_grades.grade[2] = 8;
    students[2].current_grades.avg = avg_grade(students[1], 0, 1);
    students[2].id = 895145;
  }

  int c = 1;
  while (c == 1){
    int pick = 0;
    while (pick <= 0 || pick > 5){
      printf("\nPick an option on the menu\n");
      printf("1 - Show student list\n");
      printf("2 - Add a student to the list\n");
      printf("3 - Sort students by alphabetical order\n");
      printf("4 - Sort students by age (young to old)\n");
      printf("5 - Sort students by grade (low to high)\n");
      int sc2 = 0;
      while (sc2 != 1){
        sc2 = scanf("%d", &pick);
        getchar();
      }
      printf("\n");
    }
  
    switch(pick){
      case 1:
        {
          printall(students);
          break;
        }
      case 2:
        {
          student st1 = fillinfo();
          int counter = countstudents(students);
          students[counter] = st1;
          break;
        }
      case 3:
        {
          sortbyname(students);
          break;
        }
      case 4:
        {
          sortbyage(students);
          break;
        }
      case 5:
        {
          sortbygrade(students);
          break;
        }
    }
    printf("\nDo you want to continue?\n");
    printf("1 YES     0 NO\n");
    int sc3 = 0;
    while (sc3 != 1){
      sc3 = scanf("%d", &c);
      getchar();
    }
  }
  
  return 0;
}

//Funcion para agregar un estudiante y llenar su informacion
struct student fillinfo()
{
  struct student s1;

  printf("Enter the name of the student: "); //Pregunta el nombre del estudiante
  int sc4 = 0;
  while (sc4 != 1){
    sc4 = scanf ("%[^\n]%*c", s1.name);
    getchar();
  }
  printf("What is the student's age? "); //Pregunta la edad del estudiante
  int sc5 = 0;
  while (sc5 != 1){
    sc5 = scanf("%d", &s1.age);
    getchar();
  }
  

  printf("What is the student's semester? "); //Pregunta en que semestre va el estudiante
  int sc6 = 0;
  while (sc6 != 1){
    sc6 = scanf("%d", &s1.semester);
    getchar();
  }
//Capturar calificacion de cada semestre
  for (int x = 1; x <= s1.semester; x++){
    s1.current_grades.semesters[x-1] = x;
    printf("Grade on semester %d: ", s1.current_grades.semesters[x-1]); //Preguntar calificacion de semestre x
    int sc7 = 0;
    while (sc7 != 1){
      sc7 = scanf("%f", &s1.current_grades.grade[x-1]);
      getchar();
    }
  }
  s1.current_grades.avg = avg_grade(s1, 0, 1);
  printf("What is the student's ID? "); //Preguntar ID de estudiante
  int sc8 = 0;
  while (sc8 != 1){
    sc8 = scanf("%d", &s1.id);
    getchar();
  }
  return s1;
}

//Funcion para calculara el promedio total de un estudiante
float avg_grade(struct student s1, float avg, int n)
{
  if (n <= s1.semester){
    avg += s1.current_grades.grade[n-1];
    avg_grade(s1, avg, n+1);
  } else{
    avg = avg/(n-1);
    return avg;
  }
}

//Funcion para imprimir toda la informacion de un estudiante
void printstudent(struct student s1)
{
  printf("\nName: ");
  printf("%s\n", s1.name);
  printf("Age: ");
  printf("%d\n", s1.age);
  printf("ID: ");
  printf("%d\n", s1.id);
  printf("Semester: ");
  printf("%d\n", s1.semester);
  printf("\tGrades: \n");
  for (int i = 0; i < s1.semester; i++){
    printf("Semester %d: %.1f\n", s1.current_grades.semesters[i], s1.current_grades.grade[i]);
  }
  printf("Total Average: ");
  printf("%.1f\n", s1.current_grades.avg);
}

//Funcion para contar cuantos estudiantes estan registrados
int countstudents(student s[])
{
  int count = 0;
  for (int n = 0; n < MAXSTUDENTS; n++){
    if (s[n].age > 0){
      count++;
    }
  }
  return count;
}

//Funcion para imprimir la lista completa de alumnos
void printall(student s[])
{
  int count = countstudents(s);
  printf("\n########################################");
  for (int n = 0; n < count; n++){
    printstudent(s[n]);
    printf("########################################");
  }
  printf("\n");
}

//Funcion para ordenar por nombre
void sortbyname(student s[])
{
  int i, j;
  student temp;
  int count = countstudents(s);
  for (i=0;i<count;i++){
    for (j=i+1;j<count;j++){
      if (strcmp(s[i].name,s[j].name)>0){
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        }
      }
    }
  printall(s);
}

//Funcion para ordenar por edad
void sortbyage(student s[])
{
  int x, y;
  student temp;
  int counter = countstudents(s);
  
  for(x = 0; x < counter - 1; x++){       
    for(y = 0; y < counter - x - 1; y++){          
      if(s[y].age > s[y + 1].age){               
        temp = s[y];
        s[y] = s[y + 1];
        s[y + 1] = temp;
      }
    }
  }
  printall(s);
}

//Funcion para ordenar por calificacion
void sortbygrade(student s[])
{
  int x, y;
  student temp;
  int counter = countstudents(s);
  
  for(x = 0; x < counter - 1; x++){       
    for(y = 0; y < counter - x - 1; y++){          
      if(s[y].current_grades.avg > s[y + 1].current_grades.avg){               
        temp = s[y];
        s[y] = s[y + 1];
        s[y + 1] = temp;
      }
    }
  }
  printall(s);
}