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


class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        graph_ = vector<vector<int>>(numCourses);

        for(const auto& p:prerequisites){
            graph_[p[1]].push_back(p[0]);

        }
        //states 0 = unkonwn, 1==visiting 2 ==visite
        vector<int> v(numCourses,0);

        for(int i =0;i<numCourses;++i){
            if(dfs(i,v)) return false;
        }
        return true;



    }
private:
    vector<vector<int>> graph_;
    bool dfs(int cur,vector<int>& v){
        if(v[cur]==1) return true;;
        if(v[cur]==2) return false;

        v[cur] = 1;
        for(auto num:graph_[cur]){
            if(dfs(num,v)) return true;
        }
        
        v[cur] = 2;
        return false;
    }
};
class Solution2 {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<int> indegree(numCourses);
        vector<vector<int>> adjacency(numCourses);
        for(const auto& p:prerequisites){
            indegree[p[0]]++;
            adjacency[p[1]].push_back(p[0]);
        }
        queue<int> q;
        for(int i =0;i<numCourses;++i){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        int count=0;
        while(!q.empty()){
            int visited = q.front();
            count++;
            q.pop();

            for(auto&i:adjacency[visited]){
                indegree[i]--;
                if(indegree[i]==0){
                    q.push(i);
                }
            }
        }
        return count==numCourses;

    }
};