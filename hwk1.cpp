// DOCUMENTATION GOES HERE
/*
Author: Aseel Shaheen
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <iomanip>
#include "student.h"
#include "bubble.h"

using namespace std;

struct classStats{
  float mean, min, max, median;
  char *name;
};

int main(){
  
  struct classStats stat;
  student* studentArr[19];
  float sum=0.0;
  stat.mean = 0.0;
  char coursename[50];

  cin.getline(coursename, 50);
  stat.name = coursename;


  for (int i = 0; i<19; i++){

    //allocating malloc space
    studentArr[i] = (student*)malloc(sizeof(student));
    studentArr[i]->first = (char*)malloc(99 * sizeof(char));
    studentArr[i]->last = (char*)malloc(99 * sizeof(char));

    //inputting name and grades
    cin >> studentArr[i]->first >> studentArr[i]->last>> studentArr[i]->exam1 >> studentArr[i]->exam2 >> studentArr[i]->exam3;
    //calculating student mean
    studentArr[i]->mean = (studentArr[i]->exam1 + studentArr[i]->exam2 + studentArr[i]->exam3)/3.0;

    //sum of mean to calculate class mean
    sum += studentArr[i]->mean;
  }

    //sorting using bubble sort
    bubble(studentArr, 19);

    //storing min and max
    stat.min = studentArr[0]->mean;
    stat.max = studentArr[18]->mean;

    //class mean
    stat.mean = sum/19.0;
    stat.median = studentArr[9]->mean;


    //output
    cout << fixed << setprecision(2);
    //output
    cout << setw(7) << left << stat.name << " MEAN " << setw(5) << stat.mean << " MIN: " << setw(5) << stat.min << " MAX: " << setw(5) << stat.max << " MEDIAN: " << setw(5) << stat.median << endl;

    // Output student averages
    for (int i = 0; i < 19; i++) {
        cout << setw(10) << left << studentArr[i]->first << " " << setw(10) << left << studentArr[i]->last << " " <<  setw(10) << studentArr[i]->mean << endl;
    }


  //freeing malloc space
    for (int i = 0; i < 19; i++) {
        free(studentArr[i]->first);
        free(studentArr[i]->last);
        free(studentArr[i]);  
    }

  return 0;
}
