#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        int n = nums.size();
        if(n<3) return res;
        for(int i = 0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int l = i+1;
            int r = n-1;
            int target = -nums[i];
            while(l<r){
               int sum = nums[l]+nums[r];
               if(sum==target){
                   res.push_back(vector<int>{nums[i],nums[l],nums[r]});
                   while(l<r&&nums[l]==nums[l+1]) l++;
                   while(l<r&&nums[r]==nums[r-1]) r--;
                   l++;
                   r--;
               }else if(sum>target){
                   r--;

               }else{
                   l++;
               }
            }

        }
        return res;
        
    }
};