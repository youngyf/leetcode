// array[32]
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int cnt[32] = {};
        int ans = 0;
        int N = 2;  // 其余数字出现2次
        
        for(int i = 0;i < 32;i++)
        {
            for(int j = 0;j < nums.size();j++)
            {
                cnt[i] += (nums[j]>>i) & 1;
            }
            
            ans |= (cnt[i] % N) << i;
        }
        
        return ans;
    }
};

// xor
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int len = nums.size();
        for(int i = 1;i < len;i++)
            nums[0] ^= nums[i];
        return nums[0];
    }
};