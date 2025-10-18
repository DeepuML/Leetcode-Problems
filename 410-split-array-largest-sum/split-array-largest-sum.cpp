
class Solution {
public:
    int countStudents(vector<int>& arr, int mid) {
        int students = 1;
        int pages = 0;

        for (int i = 0; i < arr.size(); i++) {
            if (pages + arr[i] <= mid) {
                pages += arr[i];
            } else {
                students++;
                pages = arr[i];
            }
        }
        return students;
    }

    int allocation(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int students = countStudents(nums, mid);

            if (students <= k) {
                ans = mid;
                high = mid - 1; // try smaller max pages
            } else {
                low = mid + 1;  // need more pages per student
            }
        }
        return ans;
    }

    int splitArray(vector<int>& nums, int k) {
        return allocation(nums, k);
    }
};