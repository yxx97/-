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
#include<algorithm>
#include<functional>

using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int start = 0;
        int maxlen = 1;
        int i = 0;
        while(i<n){
            int r= i;
            int l = i-1;
            while(++r<n&&s[r]==s[i]);
            i = r;

            while(l>=0&&r<n&&s[l]==s[r]){
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
class Solution2 {
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

