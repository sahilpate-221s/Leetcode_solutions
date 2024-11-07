class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        int minScore = INT_MAX;
        int i=0,j=n-1;
        sort(begin(people),end(people));

        int count = 0;
        if(people[n-1] > limit)return -1;

        while(i<j)
        {
            if(people[i]+people[j]<= limit)
            {
                count++;
                i++,j--;
            }
            else if(people[i]+people[j] > limit)
            {
                count++;
                j--;
            }
        }
        if(i==j)count++;
        return count;
        
    }
};