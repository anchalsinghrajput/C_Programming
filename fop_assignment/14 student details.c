/*Define a structure, student, to store the following data about a student: rollno (integer), name (string) and marks(float) . 
Your program must contain the following functions: ( Use Array of Structures).
B7        A function to read the students data.
B7        A function to sort in descending order, the records of student based on marks
B7        A function print all students details
B7        A function to search student details by rollno
B7        A function to print the names of the students having the highest test score.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Students
{
  int roll;
  char name[100];
  float marks;
} student;

student *input (int *n)   //A function to read the students data.
{
  printf ("Enter the number of students : ");
  scanf ("%d", n);

  static student data[50];

  for (int i = 0; i < *n; i++)
    {
      printf ("\n\t............Data for Student %d.............\n", i + 1);     
      printf ("Enter student name: ");
      scanf ("%s", data[i].name);
      printf ("Enter student Roll Number: ");
      scanf ("%d", &data[i].roll);
      printf ("Enter student Marks: ");
      scanf ("%f", &data[i].marks);
    }
  return data;
}

void sort_roll (student * data, int n)  //A function to sort in descending order, the records of student based on marks
{
  for (int i = 0; i < n - 1; i++)
    {
      for (int j = 0; j < n - i - 1; j++)
	{
	  if (data[j].marks < data[j + 1].marks)
	    {
	      student temp = data[j + 1];
	      data[j + 1] = data[j];
	      data[j] = temp;
	    }
	}
    }
}

void display (student * data, int n)   //A function print all students details
{
  for (int i = 0; i < n; i++)
    {
      printf ("\t.............DETAILS OF STUDENT %d..............\n\n", i + 1);
      printf ("Student Name: %s\n", data[i].name);
      printf ("Student Roll Number: %d\n", data[i].roll);
      printf ("student Marks: %.2f\n", data[i].marks);
    }
}

int search_student (student * data, int n, int key)  //A function to search student details by rollno
{
  for (int i = 0; i < n; i++)
    {
      if (data[i].roll == key)
	{
	  printf ("\n\t.............Student Found.............\n");
	  printf ("Student Name: %s\n", data[i].name);
	  printf ("Student Roll Number: %d\n", data[i].roll);
	  printf ("Student Marks: %.2f\n", data[i].marks);
	  return 0;
	}
    }
  printf ("...............Student not Found.............\n");
  return -1;
}

void display_name (student * data)  // A function to print the names of the students having the highest test score.
{
    printf("%s",data->name);
}

int main ()
{
  int n;
  student *data;
  data = input (&n);

  printf ("\n\n\n");
  printf ("\t......... ALL STUDENTS DETAILS IN dESCENDING ORDER OF THEIR MARKS............. \n\n");
  sort_roll (data, n);
  display (data, n);
  
  printf ("\n\n");
  int key;
  printf ("\nEnter the roll number of student you want to search : ");
  scanf ("%d", &key);
  search_student(data, n, key);

  printf ("\n\n");
  printf ("\t\tNAME OF THE STUDENT WITH HIGHEST SCORE IS : ");
  display_name (data);
  return 0;
}


