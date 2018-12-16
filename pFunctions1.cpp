/*
 Taylor Cella
 Practical Final
 September 26, 2018
 Compiled using g++ version 9.1.0
 */

#include <iostream>
#include "pFunctions.h"
using namespace std;

int functionClass::addNumbers(int num)
{
    int sum;
    int finalnum = abs(num);
    // While the num entered is positive, adds up all numbers and modulates by 10, then divides by 10 to get non decimal answer
    while (finalnum > 0){
        sum += finalnum % 10;
        finalnum /= 10;
    }
    cout << "The sum of all the digits in your number is " << sum << endl;
    return 0;
}

void functionClass::arraySort(int array1[])
{
    int size = 50; //sizeof(array1)/sizeof(array1[0]);
    srand(time(NULL));
    // Adds random numbers into the given array
    for(int i = 0; i < size; ++i){
        array1[i] = rand();
    }
    cout << "Before Sorting: " << endl;
    // Prints out the values within the array before sorting
    for(int i = 0; i < size; ++i){
        cout << array1[i] << endl;
    }
    cout << endl;
    cout << "After Sorting: " << endl;
    // Uses the sort function, starting from the array's beginning to its end
    sort(array1, array1 + size);
    // Prints out the values within the array after sorting
    for(int i = 0; i < size; ++i){
        cout << array1[i] << endl;
    }
}

int functionClass::max(int maxnum, int num2, int num3, int num4, int num5)
{
    // Compares all numbers to the first given to find the max
    if(num2 > maxnum){
        maxnum = num2;
    }
    if (num3 > maxnum){
        maxnum = num3;
    }
    if (num4 > maxnum){
        maxnum = num4;
    }
    if (num5 > maxnum) {
        maxnum = num5;
    }
    cout << "The maximum number is " << maxnum << endl;
    return 0;
}

//This function is unfinished.
void gradeBook(int studentgrades[][10])
{
    for(int i = 0; i < 10; ++i){
        cout << studentgrades[i] << endl;
    }
}

