#include<iostream>
#include<string>
#include<vector>
#include<list>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<cctype>
#include<algorithm>
#include<functional>
using namespace std;

//动态规划法
class Solution1 {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n,vector<bool>(n));
        int start = 0;
        int maxlen =1;
        for(int i = n-1;i>=0;i--){
            for(int j =i;j<n;j++){
                int len = j-i+1;
                dp[i][j] = (s[i]==s[j])&&(len<=2||dp[i+1][j-1]);
                if(dp[i][j]&&len > maxlen){
                    start = i;
                    maxlen = len;
                    
                }
            }
        }
        return s.substr(start,maxlen);

    }
};

//动态规划 二维数组

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> dp(2,vector<bool>(n));
        int start = 0;
        int maxlen =1;
        for(int i = n-1;i>=0;i--){
            for(int j =i;j<n;j++){
                int len = j-i+1;
                int cur = i&1;
                int pre = (i+1)&1;
                dp[cur][j] = (s[i]==s[j])&&(len<=2||dp[pre][j-1]);
                if(dp[cur][j]&&len > maxlen){
                    start = i;
                    maxlen = len;
                    
                }
            }
        }
        return s.substr(start,maxlen);

    }
};

// 中心扩展法
class Solution3 {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int start = 0;
        int maxlen =1;
        int i = 0;
        while(i<n){

            //l 表示左边不等于 i的点
            int l = i-1;

            // r 表示右边第一个不等于i 的点
            int r = i;
            while( ++r<n && s[r]==s[i] );

            // 便是下一次i从 r位置开始扩展
            i = r;

            // 从l  r 开始向两边扩展
            while(l>=0 && r<n &&s[r]==s[l]){
                l--;
                r++;
            }
            int len = r-++l;
            if(len>maxlen){
                start = l;
                maxlen = len;
            }
        }
        return s.substr(start,maxlen);

    }
};
