/*
    This program finds the union (called merger for error purposes), intersection, and 
    complement of two sets with the size of n given by the user.
*/
// The merger function will merge the two sets


using namespace std;
#include <iostream>

class Set {
    public:
        int set1size, set2size = 0; 
        int set1[100], set2[100];
        void merger();
        void intersection();
        void complement();
        void setCreator(); 
};

int main() {
    Set set;
    set.setCreator();
    set.merger();
    return 0;
}

void Set::setCreator() {
    // The setCreator function will create the two sets with the size of n given by the user

   cout << "Enter the size of first set : " << endl;
   cin >> set1size;

   cout << "Enter the size of the second set : " << endl;
   cin >> set2size;

   cout << "Enter a maximum number of " << set1size << " elements for the first set : " << endl;
   for(int i = 0; i < set1size; i++){
       cin >> set1[i];
   }

   cout << "The numbers you entered for set 1 is : ";
   for(int i = 0; i < set1size; i++) {
       cout << set1[i] << " ";
   }

   cout << endl << "Enter a maximum number of " <<  set2size << " elements for the second set : " << endl;
   for(int i = 0; i < set2size; i++){
       cin >> set2[i];
   }

   cout << "The numbers you entered for set 2 is : ";
   for(int i = 0; i < set2size; i++) {
       cout << set2[i] << " ";
   }
}

void Set::merger() {
    // Create a new set to store the merged set
    int mergedSet[set1size + set2size];
    int mergedSize = 0; 

    // Merging the two sets
    for (int i = 0; i < set1size; i++) {
        mergedSet[mergedSize++] = set1[i];
    }

    for (int i = 0; i < set2size; i++) {
        bool found = false; 
        for(int j = 0; j < set1size; j++) {
            if(set2[i] == set1[j]) {
                found = true;
                break;
            }
        }
        if(!found) {
            mergedSet[mergedSize++] = set2[i];
        }
    }

    // Outputting the merged set
    cout << "The union of the two sets is: " << endl;
    for (int i = 0; i < mergedSize; i++) {
        cout << mergedSet[i] << " ";
    }
}

void Set::intersection() {
    // Create a new set to store the intersection set
    int intersectionSet[set1size + set2size];
    int intersectionSize = 0; 

    // Finding the intersection of the two sets
    for (int i = 0; i < set1size; i++) {
        for (int j = 0; j < set2size; j++) {
            if(set1[i] == set2[j]) {
                intersectionSet[intersectionSize++] = set1[i];
            }
        }
    }

    // Outputting the intersection set
    cout << "The intersection of the two sets is: " << endl;
    for (int i = 0; i < intersectionSize; i++) {
        cout << intersectionSet[i] << " ";
    }
}