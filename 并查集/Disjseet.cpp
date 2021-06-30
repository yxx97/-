#include<vector>
using namespace std;

class Disjset {

private:
	vector<int> parent;
public:
	Disjset(int max_size) :parent(vector<int>(max_size)) {
		for (int i = 0; i < max_size; ++i) {
			parent[i] = i;
		}
	}
	int find(int x) {
		return parent[x] == x ? x : find(parent[x]);
	}
	bool is_same(int e1,int e2) {
		return find(e1) == find(e2);
	}
	void to_union(int x1, int x2) {
		parent[find(x1)] = find(x2);
	}
};