class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int pre = 0;
        int cur = 0;
        int n = nums.size();
        if(n < 2) return n;
        int count = 0;
        for(int i=0;i<n-1;i++){
            cur = nums[i+1] - nums[i];
            if((pre <= 0 && cur > 0)||(pre >= 0 && cur < 0)){
                pre = cur;
                count++;
            }
        }
        return count+1;
    }
};
