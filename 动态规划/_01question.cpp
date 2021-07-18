#include<iostream>
#include<vector>
#include<string>
class Solution {
public:
    int trap(vector<int>& height) {
        const int n = height.size();
        int ans = 0;
        auto sit = height.begin();
        auto eit = height.end();
        for(int i=0;i<n;++i){
            int l =*max_element(sit,sit+i+1);
            int r = *max_element(sit+i,eit);
            ans+= min(l,r)-height[i];
        }
        return ans;

    }
};