#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

//一维数组 手写 输入 输出
int main(){
	
    int V;
	vector<int> val;
	vector<int> weight;
    cin>>V;
	int temp;
	while(cin >> temp)
	{
		weight.push_back(temp);
		while(cin.peek() == ' ')        
		    cin.get();               
		
		if(cin.peek() == '\n')      
			break;
	}
	while(cin>>temp){
		val.push_back(temp);
		if(cin.peek()==' ')
			cin.get();
		if(cin.peek() =='\n')
			break;
		
	}
	int N = val.size();
	
    vector<int> dp(V+1);
    for(int i = 1;i<=N;i++){
        int w = weight[i-1];
        int v = val[i-1];
        for(int j = V;j>=w;j--){
                dp[j] = max(dp[j],dp[j-w]+v);
        }
    }
    cout<<dp[V]<<endl;
    return 0;
}