class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        if(n < 2*k+1){return vector<int>(n, -1);}
        else if(k == 0){return nums;}
        
        vector<int> cop(n, -1);
        long long sum = 0;
        for(int i=0;i<2*k+1;i++){
            sum += nums[i];
        }
        cop[k] = sum / (2*k+1);
        for(int i=2*k+1, j=1;i<n;i++,j++){
            sum = sum - nums[i-(2*k+1)] + nums[i];
            cop[k+j] = sum / (2*k+1);
        }
        return cop;
    }
};
