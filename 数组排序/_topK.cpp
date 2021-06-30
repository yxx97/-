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


#include<ctime>
using namespace std;

class Solution {
public:
    vector<int> smallestK(vector<int>& arr, int k) {
        int l =0,r = arr.size()-1;
        if(k==0) return vector<int>();
        qsortk(arr,0,r,k);
        return vector<int>(arr.begin(),arr.begin()+k);

    }
    void qsortk(vector<int> & v,int left ,int right,int k){
        if(left<right){
            int i = rand()%(right-left+1)+left;
            swap(v[left],v[i]);
            int pivot = v[left];
            int lo = left,hi = right;
            while(lo<hi){
                while(lo<hi){
                    if(v[hi]>pivot){
                        hi--;
                    }else{
                        v[lo++] = v[hi];
                        break;
                    }
                }
                while(lo<hi){
                    if(v[lo]<pivot){
                        lo++;
                    }else{
                        v[hi--] = v[lo];
                        break;
                    }
                }  
            }
            v[lo] = pivot;
            if(lo-left+1==k) return ;
            else if(lo-left+1<k){
                qsortk(v,lo+1,right,k-lo+left-1);

            }else{
                qsortk(v,left,lo-1,k);
            }
        }
    }
};


int main(){
    srand((unsigned)time(NULL));
}