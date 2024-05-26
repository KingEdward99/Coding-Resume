/*
    Binary Search
    Given a collection of 5 students (their ID, name, and  GPA), this 
    program will search for a student by ID using binary search.
*/
#include <iostream>
using namespace std;

class Student {
    int id;
    string name;
    double gpa;

    void StudentSearch ();
    void studentCreation(); 
};

int main () {

}
/*
int BinarySearch (int list[], int target, int size) {
    int start = 1;
    int end = size;

    while (start <= end)
    {
        int middle = (start + end) / 2;
        select (Compare(list[middle], target) from )
            case -1: start = middle + 1;
            case 0: return middle;
            case 1: end = middle - 1;
        end select;
    }

    return 0; 
}

int compare(int x,int y) {
    if (x < y) {
        return -1;
    } else if (x == y) {
        return 0;
    } else {
        return 1;
    }
}
*/