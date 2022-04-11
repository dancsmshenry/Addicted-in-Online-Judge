class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        auto cmp =[](const string& s1, const string& s2) -> bool{
            if (s1.size() > s2.size()) {
                return true;
            } else if (s1.size() < s2.size()) {
                return false;
            }
            return s1 > s2;
        };

        int n = nums.size();
        int left = 0, right = n - 1;
        while (true) {
            string mid = nums[left];
            swap(nums[left], nums[rand() % (right - left + 1) + left]);
            int index = left;
            for (int i = left + 1; i < right + 1; ++ i) {
                if (cmp(nums[i], nums[left])) {
                    index ++ ;
                    swap(nums[i], nums[index]);
                }
            }
            swap(nums[left], nums[index]);
            if (index == k - 1) {
                return nums[index];
            } else if (index > k - 1) {
                right = index - 1;
            } else {
                left = index + 1;
            }
        }
    }
};

class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        auto cmp =[](const string& s1, const string& s2) -> bool{
            if (s1.size() > s2.size()) {
                return true;
            } else if (s1.size() < s2.size()) {
                return false;
            }
            return s1 > s2;
        };

        sort(nums.begin(), nums.end(), cmp);
        return nums[k-1];
    }
};