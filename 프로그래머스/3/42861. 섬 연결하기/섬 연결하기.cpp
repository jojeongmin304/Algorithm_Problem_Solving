#include <string>
#include <vector>
#include <algorithm>

using namespace std;
//상호배타적집합
class DisjointSet {
    private:
    vector<int> parent, rank;
    
    public:
    DisjointSet(int size) : parent(size, -1), rank(size, 0) {} //생성자
    
    int find(int node) {
        if(parent[node] == -1)
            return node;
        
        //매우중요: 경로압축 + 루트노드재귀탐색
        return parent[node] = find(parent[node]);
    }
    
    void merge(int node1, int node2) {
        int root1 = find(node1);
        int root2 = find(node2);
        
        if(root1 != root2) {
            //더 긴 랭크가 루트노드가 된다.
            
            if(rank[root1] > rank[root2]) {
                parent[root2] = root1;
            }
            else if (rank[root1] < rank[root2]) {
                parent[root1] = root2;
            }
            else {
                parent[root2] = root1;
                rank[root1]++;
            }
        }
    }
    
    bool isCycle(int node1, int node2) {return find(node1) == find(node2);}
};

int solution(int n, vector<vector<int>> costs) {
    sort(costs.begin(), costs.end(), [](const vector<int> & a, const vector<int>& b) {return a[2] < b[2]; });
    
    DisjointSet disjointSet(n);
    int totalCost = 0;
    
    for (const auto& edge : costs) {
        int cost = edge[2];
        int node1 = edge[0];
        int node2 = edge[1];
        
        if(!disjointSet.isCycle(node1, node2)) {
            disjointSet.merge(node1, node2);
            totalCost += cost;
        }
    }
    
    return totalCost;
}