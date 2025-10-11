class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;

        while (start <= end) {
            int mid = start + (end - start) / 2; // Safer mid calculation

            // Case 1: Target found
            if (target == nums[mid]) {
                return true;
            }

            // Case 2: Handle duplicates where nums[start] == nums[mid] == nums[end]
            // This situation makes it impossible to determine which half is sorted.
            // So, we shrink the search space by moving both pointers.
            if (nums[start] == nums[mid] && nums[mid] == nums[end]) {
                start++;
                end--;
                continue; // Restart loop with new bounds
            }

            // Case 3: Left half is sorted (nums[start] <= nums[mid])
            if (nums[start] <= nums[mid]) {
                // Check if target is within the left sorted range [nums[start], nums[mid])
                if (target >= nums[start] && target < nums[mid]) {
                    end = mid - 1; // Target is in the left sorted part
                } else {
                    start = mid + 1; // Target is in the right (potentially unsorted) part
                }
            }
            // Case 4: Right half is sorted (nums[mid] < nums[start])
            else {
                // Check if target is within the right sorted range (nums[mid], nums[end]]
                if (target > nums[mid] && target <= nums[end]) { // CORRECTED CONDITION
                    start = mid + 1; // Target is in the right sorted part
                } else {
                    end = mid - 1; // CORRECTED UPDATE: Target is in the left (potentially unsorted) part
                }
            }
        }
        return false; // Target not found
    }
};