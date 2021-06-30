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
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n,vector<bool>(n));
        int num = 0;
        for(int i = n-1;i>=0;i--){
            for(int j =i;j<n;j++){
                int len = j-i+1;
                dp[i][j] = (s[i]==s[j])&&(len<=2||dp[i+1][j-1]);
                if(dp[i][j]) num++;
            }
        }
        return num;

    }
};