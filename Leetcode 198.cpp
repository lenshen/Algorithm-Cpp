class Solution {
public:
    int dfs(int i, vector<int>& nums,vector<int>& mem){
        if (i < 0) return 0;
        if (mem[i] != -1) return mem[i];

        int res = max(dfs(i-1, nums, mem),dfs(i-2, nums, mem)+nums[i]);
        mem[i] = res;
        return res; 
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        vector<int> mem(n,-1);
        return dfs(n-1, nums,mem);
    }
};
