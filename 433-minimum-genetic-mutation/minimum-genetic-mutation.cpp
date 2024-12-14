class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> bankset(begin(bank), end(bank));
        unordered_set<string> visited;
        int level = 0;

        queue<string> que;
        que.push(startGene);
        visited.insert(startGene);

        while (!que.empty()) {
            int n = que.size();

            while (n--) {
                string curr = que.front();
                que.pop();

                if(curr == endGene)return level;

                for (auto ch : "ACGT") {
                    for(int i=0;i<curr.length();i++)
                    {
                        string neighbour = curr;
                        neighbour[i]=ch;

                        if(visited.find(neighbour) == visited.end() &&
                        bankset.find(neighbour) != bankset.end())
                        {
                            visited.insert(neighbour);
                            que.push(neighbour);
                        }
                    }
                }
            }
            level++;
        }
        return -1;
    }
};