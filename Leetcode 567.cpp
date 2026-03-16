// class Solution {
// public:
//     bool checkInclusion(string s1, string s2) {
//         int n1 = s1.size();
//         int n2 = s2.size();
//         int l = 0;
//         int sum = 0;
//         bool a = false;
//         unordered_map<char, int>re;
//         for(int i=0;i<n1;i++)
//             re[s1[i]] +=1;
        
//         for(int r=0;r<n2;r++){
//             // if(re[s2[r]] >= 0){
//                 re[s2[r]] -=1;
//                 sum += 1;
//             // }
//             while((r-l+1) >= n1){
//                 int count = 0;
//                 for(int i=0;i<n1;i++){
//                     if(re[s1[i]] == 0)
//                         count += 1; 
//                 }
//                 if(count == n1){
//                     a = true;
//                     break; 
//                 } 
//                 re[s2[l]] +=1;
//                 l++;
//             }
            
//         }
//         return (a)?true:false;
//     }
// };
//Àu¤Æ«á
class Solution {
public:
    bool SI(vector<int>&re){
        for(int i=0;i<26;i++){
            if(re[i] != 0)
                return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        int l = 0;
        vector<int>re(26);
        
        for(int i=0;i<n1;i++)
            re[s1[i] - 'a'] += 1;
        
        for(int r=0;r<n2;r++){  
            re[s2[r] - 'a'] -= 1;

            while((r-l+1) == n1){
                if(SI(re))
                    return true;
                re[s2[l] - 'a'] += 1;
                l++;
            }
        }
        return false;
    }
};
