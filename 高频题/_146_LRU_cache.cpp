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

class node{
public:
    node* pre = nullptr;
    node* next = nullptr;
    int key;
    int val;
    node(int key,int val){
        this->key =key;
        this->val = val;
    }
};
class LRUCache {
public:

    LRUCache(int capacity) {
        head = new node(0,0);
        tail = new node(0,0);
        this->capacity = capacity;
        head->next = tail;
        tail->pre = head;
    }
    
    int get(int key) {
        if(!map.count(key)){
            return -1;
        }
        node * temp = map[key];
       
        remove(temp);
        addfirst(temp);
        return temp->val;


    }
    
    void put(int key, int value) {
        node * temp = new node(key,value);
        if(map.count(key)){
            remove(map[key]);
            map[key] = temp;
            addfirst(temp);
        }else {
            if(map.size()==capacity){
                //删除最后一个 最后一个节点的key
                int lastkey =tail->pre->key; 
                remove(tail->pre);
                map.erase(lastkey);
            }
            map[key] = temp;
            addfirst(temp);
        }

        
    }
    void remove(node * temp){
        temp->pre->next = temp->next;
        temp->next->pre = temp->pre;

    }
    void addfirst(node *temp){
        //先和head后面的连接起来；
        temp->next=head->next;
        head->next->pre = temp;
        //再和head链接起来
        head->next = temp;
        temp->pre = head;
    }

private:
    node* head;
    node* tail;
    unordered_map<int,node*> map;
    int capacity;
};



int main(){
    cout << "heh" << endl;
}

