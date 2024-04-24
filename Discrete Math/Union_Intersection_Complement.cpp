/*
    This program finds the union (called merger for error purposes), intersection, and 
    complement of two sets with the size of n given by the user.
*/

using namespace std;
#include <iostream>

class Set {
    public:
        int merger(int[], int[]);
        int intersection(int[], int[]);
        int complement(int[], int[]);
        void setCreator(); 
};

int main() {
    cout << "Testing" << endl; 
    Set set;


    set.setCreator();
    set.merger(0, 0);
    return 0;
}
// The setCreator function will create the two sets with the size of n given by the user
void Set::setCreator() {
   int set1size, set2size = 0; 
   int set1[set1size], set2[set2size];

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

// The merger function will merge the two sets
int  Set::merger(int set1[], int set2[]) {
    int set1size, set2size = 0;
    int mergeSet[set1size + set2size];

    for(int i = 0; i < set1size; i++) {
        mergeSet[i] = set1[i];
    }
    /*
    for(int i = set1size; i < (set1size + set2size); i++) {
        mergeSet[set1size + i] = set2[i];
    }
    */

    cout << "The merged set is : ";
    for(int i = 0; i < (set1size + set2size); i++) {
        cout << mergeSet[i] << " ";
    }
}