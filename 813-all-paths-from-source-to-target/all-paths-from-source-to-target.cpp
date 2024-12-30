class Solution {
public:
    void dfs(vector<vector<int>>& graph,int u, int target, vector<vector<int>>& result, vector<int> & temp)
    {
        temp.push_back(u);
        if(u==target)
        {
            result.push_back(temp);
        }
        else
        {
            for(auto &v: graph[u])
            {
                dfs(graph,v,target,result,temp);
            }
        }

        temp.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int target = graph.size()-1;

        vector<vector<int>> result;
        vector<int> temp;
        dfs(graph,0,target,result,temp);

        return result;
        
    }
};