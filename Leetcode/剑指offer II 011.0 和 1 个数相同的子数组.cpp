class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        //  һ��ʼ�뵽����dp����˫ѭ�����������ʱ�临�Ӷ�̫����
        //  ���濴�˿���ǩ��˲�������
        unordered_map<int, int> hashmap;
        int maxn = 0;
        int n = nums.size();

        for (int i = 0, record = 0; i < n; ++ i) {
            record += (nums[i] == 0) ? -1: 1;
            if (record == 0) {
                maxn = i + 1;
                continue;
            }
            if (hashmap.count(record)) {
                maxn = max(maxn, i - hashmap[record]);
            } else {
                hashmap[record] = i;
            }
        }

        return maxn;
    }
};

//  ���õ�����
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        int prev = 0;
        int total = accumulate(nums.begin(), nums.end(), 0);

        for (int i = 0; i < n; ++ i) {
            if (prev == total - (prev + nums[i])) {
                return i;
            }
            prev += nums[i];
        }

        return -1;
    }
};