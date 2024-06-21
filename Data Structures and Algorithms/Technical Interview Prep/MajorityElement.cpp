/*
    Given an array nums of size n, return the majority element.

    The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

    Example 1:

    Input: nums = [3,2,3]
    Output: 3
    Example 2:

    Input: nums = [2,2,1,1,1,2,2]
    Output: 2
 

    Constraints:

    n == nums.length
    1 <= n <= 5 * 104
    -109 <= nums[i] <= 109
*/

#include <iostream>
#include <vector>

using namespace std;

int majorityElement(vector<int>& nums) {
    int candidate = 0;
    int count = 0;

    for (int num : nums) {
        if (count == 0) {
            candidate = num;
        }
        if (num == candidate) {
            count++;
        } else {
            count--;
        }
    }

    return candidate;
}

int main() {
    // Example 1
    vector<int> nums1 = {3, 2, 3};
    cout << "Majority Element in nums1: " << majorityElement(nums1) << endl;  // Output: 3

    // Example 2
    vector<int> nums2 = {2, 2, 1, 1, 1, 2, 2};
    cout << "Majority Element in nums2: " << majorityElement(nums2) << endl;  // Output: 2

    return 0;
}