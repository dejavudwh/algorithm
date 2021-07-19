class Solution {
public:
    // 贪心问题：每次修改都保证是最优，即越小越好
    // nums[i] = nums[i+1]
    // nums[i+1] = nums[i]
    bool checkPossibility(vector<int>& nums) {
        if(nums.size() <= 2) {
            return true;
        }

        bool flag = true;
        for (int i = 0; i < nums.size()-1; i++) {
            if(nums[i] > nums[i+1]) {
                if(flag) {
                    if(i == 0) {
                        nums[i] = nums[i+1];
                    } else if(i > 0 && nums[i+1] >= nums[i-1]) {
                        nums[i] = nums[i+1];   
                    } else {
                        nums[i+1] = nums[i];  
                    }
                    flag = !flag;              
                } else{
                    return false;
                }
            }
        }
        return true;
    }
};