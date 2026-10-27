#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binarySearch(vector<int>& arr, int x) {

    sort(arr.begin(), arr.end());

    int low = 0;
    int high = arr.size() - 1;

    while (low <= high) {

        int mid = low + (high - low) / 2;

        if (arr[mid] == x) {
            return mid;
        }

        if (arr[mid] < x) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return -1;
}

int main() {

    vector<int> list = {9, 3, 4, 5, 2, 10};

    int userInput;

    cout << "Enter a number to find in the list: ";
    cin >> userInput;

    int result = binarySearch(list, userInput);

    if (result == -1) {
        cout << "Element is not present in array" << endl;
    }
    else {
        cout << "Element is present at index: " << result << endl;
    }

    return 0;
}