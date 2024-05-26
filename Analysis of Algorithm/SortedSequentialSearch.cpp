/*
 An algorithm that will run more quickly because it stops as soon as the key smaller than the current list 
 value. It uses the Compare(x.y) function to compare the key with the current list value which is defined as 
 Compare (x,y) =   {-1 if x < y
                    0 if x = y
                    1 if x > y}
 The Compare function should be counted as one comparison and can best be used in a switch
*/
#include <iostream>
using namespace std;

int compare(int x,int y) {
    if (x < y) {
        return -1;
    } else if (x == y) {
        return 0;
    } else {
        return 1;
    }
}


int main () {
    int list [] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; //list of numbers
}