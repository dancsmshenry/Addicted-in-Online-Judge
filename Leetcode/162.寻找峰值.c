int findPeakElement(int* nums, int numsSize)
{
    if (numsSize == 1 || numsSize == 0) return 0;
    
    for (int i = 0; i < numsSize; i++)
    {
        if (i == 0)
        {
            if (nums[i] > nums[i + 1]) return i;
        }
        else if (i == numsSize - 1) return i;
        else if (nums[i] > nums[i + 1] && nums[i] > nums[i - 1]) return i;
    }

    return 0;
}
