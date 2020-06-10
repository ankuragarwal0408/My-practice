void sortColors(vector<int>& nums) {
    int l{}, mid{}, h{nums.size() - 1};
    while (mid <= h)
        if (nums[mid] == 0)
            swap(nums[mid++], nums[l++]);
        else if (nums[mid] == 1)
            mid++;
        else 
            swap(nums[mid], nums[h--]);
}
