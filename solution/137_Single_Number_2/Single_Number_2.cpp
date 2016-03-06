// array[32]
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int cnt[32] = {};
        int ans = 0;
        int N = 3; // 其余数字出现3次
        
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

// one, two
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int one = 0;
        int two = 0;
        int three = 0;

        for(int i = 0;i < n;i++)
        {
            two |= one & nums[i];
            one = one ^ nums[i];
            three = one & two;
            one &= ~three;
            two &= ~three;
        }
        
        return one;
    }
};