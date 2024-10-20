class Solution {
public:
    vector<int>parent;
    vector<int> rank;

    int find(int x)
    {
        if(parent[x]==x)
        {
            return x;
        }

        return parent[x] = find(parent[x]);
    }

    //union using rank compression
    void Union(int x, int y)
    {
        int x_parent = find(x);
        int y_parent = find(y);

        if(rank[x_parent] > rank[y_parent])
        {
            parent[y_parent] = x_parent;
        }
        else if(rank[x_parent] < rank[y_parent])
        {
            parent[x_parent] = y_parent;
        }
        else
        {
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }



    bool equationsPossible(vector<string>& equations) {
        parent.resize(26);
        rank.resize(26,0);
        for(int i=0;i<26;i++)
        {
            parent[i]=i;
        }
        //frist do  the union of equals
        for(string &s: equations)
        {
            if(s[1]=='=') //a==b
            {
                Union(s[0]-'a' , s[3]-'a');
            }
        }

        //find not equal wale cases and check validity
        for(string &s: equations)
        {
            if(s[1]=='!') //a==b
            {
                char first = s[0];//a
                char second = s[3]; //b

                int first_parent = find(first-'a');
                int second_parent = find(second-'a');

                if(first_parent == second_parent)
                {
                    return false;
                }
                
            }
        }

        return true;
        
    }
};