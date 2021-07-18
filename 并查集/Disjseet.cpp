#include<vector>
using namespace std;

class Disjset {

private:
	vector<int> parent;
	//count 表示并查集中联通的分量
    int count;
public:
	Disjset(int max_size) :parent(vector<int>(max_size)),count(max_size) {
		for (int i = 0; i < max_size; ++i) {
			parent[i] = i;
		}
	}
	int find(int x) {
		//return parent[x] == x ? x : find(parent[x]);
		while(x!= parent[x]){
			parent[x] =parent[parent[x]];
			x = parent[x];
		}
		return x;
	}
	bool is_same(int e1,int e2) {
		return find(e1) == find(e2);
	}
    int getcount(){
        return count;
    }
	void to_union(int x1, int x2) {
        int root1 = find(x1);
        int root2 = find(x2);
        if(root1==root2) return;
		parent[root1] = root2;
        count--;
	}
};