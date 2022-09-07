#include <vector>
#include <iostream>

using namespace std;

// 给定一个长为n的数组，和一个数字x，按照顺序访问数组
// 如果此时的number超过范围[数字-x，数字+x]，那就要调整
// 给出的解就是，从头开始遍历，如果当前维护最大值与最小值，
// 当最大值与最小值的差大于2*x，伪装次数加1，最大最小值变为当前遍历值
// 这里的按顺序访问很重要...
void test3()
{
    int n, x;
    cin >> n >> x;
    vector<int> arr;
    while (n--)
    {
        int a;
        cin >> a;
        arr.push_back(a);
    }
    int res = 0;
    int maxarr = arr[0];
    int minarr = arr[0];
    for (int i = 0; i < arr.size(); i++)
    {
        maxarr = max(maxarr, arr[i]);
        minarr = min(minarr, arr[i]);
        if (maxarr - minarr > 2 * x)
        {
            res++;
            maxarr = arr[i];
            minarr = arr[i];
        }
    }

    cout << res << endl;
}