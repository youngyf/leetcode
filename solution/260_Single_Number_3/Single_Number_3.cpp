class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> re;
        int len = nums.size();
        
        int diff = 0;
        for(int i = 0;i < len;i++)
            diff ^= nums[i];
        
        // find one bit that can distinguish the two numbers
        for(int i = 0;i < 32;i++)
        {
            if(diff & (1 << i))
            {
                diff &= (1 << i);
                break;
            }
        }
        
        // devide into two group, one & diff == true, another & diff == false
        int ans1 = 0;
        int ans2 = 0;
        for(int i = 0;i < len;i++)
        {
            if(nums[i] & diff)
            {
                ans1 ^= nums[i];
            }
            else
            {
                ans2 ^= nums[i];
            }
        }
        re.push_back(ans1);
        re.push_back(ans2);
        
        return re;
    }
};