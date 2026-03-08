class Solution {
public:
    void Merge(vector<int>&nums,int f,int m,int e){
        vector<int> l_sub(nums.begin()+f, nums.begin()+m+1);
        vector<int> r_sub(nums.begin()+m+1, nums.begin()+e+1);

        int j = 0, h = 0;
        int i = f;
        while(j < r_sub.size() && h < l_sub.size()){
            if(l_sub[h] >= r_sub[j]){
                nums[i] = r_sub[j];
                j++;
            }
            else{
                nums[i] = l_sub[h];
                h++;
            }
            i++;
        }
        while(j < r_sub.size()){
            nums[i] = r_sub[j];
            j++;
            i++;
        }

        while(h < l_sub.size()){
            nums[i] = l_sub[h];
            h++;
            i++;
        }
    }

    void Divide(vector<int> &nums, int f, int e){
        
        if(f<e){
            int mid = (f+e)/2;
            Divide(nums, f, mid);
            Divide(nums, mid+1, e);
            Merge(nums, f, mid, e);
        }
        
    }
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return nums;
        Divide(nums, 0, n-1);
        return nums;
    }
};
