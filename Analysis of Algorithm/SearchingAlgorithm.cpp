/*
    This program brings up Student names based on their IDs using Sequential Search Algorithm
*/

#include <iostream>
#include <vector> 
using namespace std;

//function to search for student ID
int sequentialSearch(int arr[], int n, int x) {
    int studentID;
    cin >> studentID; //input student ID
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i;
        }
    }
    return -1;
}

int main() {
    //matrix that has student names and their IDs
    vector<vector<pair<string, int>>> matrix = {
        {{"Eddy", 0624}, {"Jada", 1010}, {"Dasean", 0201}, {"Jeremy", 0504}, {"Jasmine", 0701}}
    };
}