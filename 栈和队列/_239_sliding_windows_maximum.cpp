/*
  给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的
  最右侧。你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。
  返回滑动窗口中的最大值。
*/
#include<vector>
#include<deque>
using namespace std;
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        if(k==1) return nums;
        //双端队列始终保持单调递减
        deque<int> dq;
        vector<int> res(n-k+1);
        for(int i = 0 ;i<n;i++){
            //如果不满足单调递减 就将队列的后端进行pop
            while(!dq.empty()&&nums[i]>=nums[dq.back()]){
                dq.pop_back();
            }
            //注意存放的是索引
            dq.push_back(i);
            
            int t = i-k+1;
            if(t<0) continue;
            
            // 如果队列开头的索引下于t 说明失效就进行删除
            if(dq.front()<t){
                dq.pop_front();
            }
            res[t] = nums[dq.front()];
        }
        return res;


    }
};