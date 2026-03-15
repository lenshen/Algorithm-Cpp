class Solution {
public:
    // だ猭 (穦TLE)
    // int QS(int l, int r, int t, vector<int>&nums){
    //     if(l == r) return nums[l];

    //     int p = l;
    //     int pivot = nums[r];
    //     for(int i = l;i<r;i++){
    //         if(nums[i] <= pivot){
    //             swap(nums[i], nums[p]);
    //             p++;
    //         } 
    //     }
    //     swap(nums[r] , nums[p]);

    //     if(p == t) 
    //         return nums[p];
    //     else if(p < t)
    //         return QS(p+1, r, t, nums); 
    //     else 
    //         return QS(l, p-1, t, nums);
        
    // }
    // int findKthLargest(vector<int>& nums, int k) {
    //     int n = nums.size();
    //     int t = n-k;
    //     return QS(0, n-1,t,nums);
    // }

    //だΘ > = < 场だΤ矪瞶秖计磷TLE
    int QS(int l, int r, int t, vector<int> &nums){
        if(r == l) return nums[l];  
        int p_l = l;
        int p_r = r;
        int i = l;
        int pivot = nums[l + rand() % (r - l + 1)]; //繦诀
        
        while(i<=p_r){
            if(nums[i] > pivot){
                //┕传┮璶穝浪琩Ω传筁ㄓ计┮ iぃノ笆
                swap(nums[i], nums[p_r]);
                p_r--;
            }
            else if(nums[i] < pivot){
                swap(nums[i], nums[p_l]);
                p_l++;
                i++;
            }
            // = 场だ 
            else i++;
        }
        if(t <= p_r && t >= p_l)
            return pivot;
        else if(t >p_r)
            return QS(p_r+1, r, t, nums);
        else
            return QS(l, p_l-1, t, nums);
    }

    int findKthLargest(std::vector<int>& nums, int k){
        int n = nums.size();
        int t = n-k;
        return QS(0, n-1, t, nums);
    }
};
