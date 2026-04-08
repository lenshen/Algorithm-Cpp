class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.begin()+n);
        int ans = nums[n-1] - nums[0];
        if(n == 1) return 0;
       // if(n == 2) return abs(nums[1]- nums[0] -2*k);
        int mi = INT_MAX;
        int ma = 0;
        for(int i=0;i<n-1;i++){
            ma = max(nums[i]+k, nums[n-1]-k);
            mi = min(nums[0]+k, nums[i+1]-k);
            int a = ma-mi;
            ans = min(ans,a);
        }
        return ans;
    }
};
