class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        // 这道题的意思应该是数字在两个数组中出现了几次，如果次数相同就打印一定的次数，如果不同就打印小一点的次数
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        vector<int> f;
        int point1 = 0, point2 = 0;
        int n1 = nums1.size(), n2 = nums2.size();

        while(point1 < n1 && point2 < n2){
            if (nums1[point1] < nums2[point2]){
                point1 ++;
            }
            else if (nums1[point1] > nums2[point2]){
                point2 ++ ;
            }
            else {
                f.push_back(nums1[point1 ++ ]);
                point2 ++ ;
            }
        }

        return f;
    }
};