class Solution {
public:
    int mergeSort(vector<int>& nums, vector<int>& tmp, int l, int r) {
        /*
        这里的思路很巧妙：
        因为当把数列分为两份以后，即使对两个数列分别各自进行排序，只要我计算了这个小数列里面的逆序数，再拿两个数列进行比较求得逆序数，就不会改变整体的逆序数的
        所以，基于这个思想就使用了归并排序


        对于两个数列A和B来说，设置两个指针a1和b1（数列B是在数列A的后面）
        这里对逆序数的计算分为了两个部分：

        第一步：用两个指针操作，把元素都放入到tmp临时数组里面
        哪个元素小，就把那个元素放入tmp数组中，
        但你想一想，后面的元素比前面的元素大，是正常的事情，如果都这样，就不会有逆序数了
        但是，如果出现了前面的元素大于后面的元素的情况，怎么说？（注意这里的两个数列都是排好序了的）
        此时，后面数列的元素就会放到tmp中，那么，此时这个元素，就会被A数列后续所有的数给大于
        那么，对于后面的数列来说，之前进去的数，相对于当前前面数列指针指到的数来说，它们既比前面指针指到的数要小，又是在前面的数的后面，就构成了逆序数
        同时我们又知道，前面的数是按序排列的，即这个指针后买你的数都会大于后面数列已经进去的数
        ok，理解了这个之后，分析一下现在的情况
        对于B数列来说，B数列指针指向的数 是大于 A数列指针指向的数 大于 B数列前面的数字
        所以，每当A数列走一个数字，逆序数就要加上B数列指针前面的数列的长度（因为走的这个数虽然比B数列指针指向的数要小，但还是比B数列前面已走的数要大）

        理解了第一步，第二步无非就是把后续的元素一一填满到数组里面
        当填入A数列的数字的时候，就把B数列已经放入tmp数组的数字的数量给加一遍

        总结：事实上，这里利用的就是归并排序的特性，利用了大于的转接性的特性
        */
        if (l >= r){
            return 0;
        }
        int mid = (l + r) / 2;
        int inv_count = mergeSort(nums, tmp, l, mid) + mergeSort(nums, tmp, mid + 1, r);
        int i = l, j = mid + 1, pos = l;
        while (i <= mid && j <= r){
            if (nums[i] <= nums[j]) {
                tmp[pos] = nums[i];
                i ++ ;
                inv_count += (j - (mid + 1));
            }else{
                tmp[pos] = nums[j];
                j ++ ;
            }
            pos ++ ;
        }
        for (int k = i; k <= mid; k ++ ){
            tmp[pos ++ ] = nums[k];
            inv_count += (r + 1 - (mid + 1));//这里的r+1改为j也是可以的，本质不变
        }
        for (int k = j; k <= r; k ++ ){
            tmp[pos ++ ] = nums[k];
        }
        copy(tmp.begin() + l, tmp.begin() + r + 1, nums.begin() + l);
        return inv_count;
    }

    int reversePairs(vector<int>& nums) {
        /*一看数据，50000，n^2一定会超时，这道题没啥思路啊.....*/
        int n = nums.size();
        //用来存储临时的数据
        vector<int> tmp(n);
        return mergeSort(nums, tmp, 0, n - 1);
    }
};