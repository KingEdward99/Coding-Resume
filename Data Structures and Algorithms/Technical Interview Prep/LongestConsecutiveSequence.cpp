
/*
    Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

    You must write an algorithm that runs in O(n) time.

    

    Example 1:

    Input: nums = [100,4,200,1,3,2]
    Output: 4
    Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
    Example 2:

    Input: nums = [0,3,7,2,5,8,4,6,0,1]
    Output: 9
    

    Constraints:

    0 <= nums.length <= 105
    -109 <= nums[i] <= 109
*/
#include <vector>
#include <unordered_set>
class Solution {
    public:
        int longestConsecutive(vector<int>& nums) {
            std::unordered_set<int> numSet(nums.begin(), nums.end()); // Insert all elements into a set
            int longestStreak = 0;
            
            for (int num : nums) {
                // Check if this number is the start of a sequence
                if (numSet.find(num - 1) == numSet.end()) {
                int currentNum = num;
                int currentStreak = 1;
                
                // Count the length of the sequence
                    while (numSet.find(currentNum + 1) != numSet.end()) {
                    currentNum += 1;
                    currentStreak += 1;
                    }

                // Update the maximum length found
                longestStreak = std::max(longestStreak, currentStreak);
            }
        }
        return longestStreak;
}
};