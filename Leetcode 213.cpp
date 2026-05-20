class Solution {
public:
    int dfs(int i, int n, vector<int>& nums, vector<int>& mem){
        if(i < n) return 0;
        if(mem[i] != -1) return mem[i];

        int res = max(dfs(i-1, n, nums, mem), dfs(i-2, n, nums, mem) + nums[i]);
        mem[i] = res;

        return mem[i];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];
        // 怕污染
        std::vector<int> mem1(n, -1);
        std::vector<int> mem2(n, -1);
        // 偷最後
        int r = dfs(n-1, 1, nums, mem1);
        // 偷第一家
        int l = dfs(n-2, 0, nums, mem2);
        return (r>l)?r:l;
    }
};
