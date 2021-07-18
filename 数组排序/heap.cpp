#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>

using namespace std;

void adjust(vector<int>& v,int len,int index){
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int maxindex = index;
    if(left<len&&v[left]>v[maxindex])
        maxindex = left;
    if(right<len&&v[right]>v[maxindex])
        maxindex = right;
    if(maxindex!= index){
        swap(v[index], v[maxindex]);
        adjust(v, len, maxindex);
    }
}
void heapsort(vector<int>& v){
    int n = v.size();
    for (int i = n / 2 - 1; i >= 0;--i){
        adjust(v, n, i);
    }
    for (int i = n - 1; i >= 1;i--){
        swap(v[0], v[i]);
        adjust(v, i, 0);
    }
}



int main(){

    vector<int> arr = {8, 1, 14, 3, 21, 5, 7, 10};
    heapsort(arr);
    for(auto i:arr){
        cout << i << endl;
    }
    return 0;



}