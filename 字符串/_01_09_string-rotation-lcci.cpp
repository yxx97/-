#include<iostream>
#include<string>

using namespace std;
class Solution {
public:
    bool isFlipedString(string s1, string s2) {
        if(s2.size()!=s1.size()) return false;
        string s = s1+s1;
        return s.find(s2)!= string::npos;
    }
};
int main(){
    Solution s;
    cout << s.isFlipedString("waterbottle","erbottlewat") << endl;
    return 0;
}