class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int> umap;
        //update the map and frequency
        for(string& ch: words)
        {
            umap[ch]++;
        }

        //flag for 1 wale frequency
        bool centerUsed = false;
        int result = 0;

        for(string &word : words) {
            string rev = word;
            reverse(begin(rev), end(rev));
            
            if(rev != word) { //"ab" "ba"    ->.  {ab      ba}
                if(umap[word] > 0 && umap[rev] > 0) {
                    umap[word]--;
                    umap[rev]--;
                    result += 4;
                }
            } else { //"abcc      ccba"
                if(umap[word] >= 2) {
                    umap[word] -= 2;
                    result += 4;
                } else if(umap[word] == 1 && centerUsed == false) {
                    umap[word]--;
                    result += 2;
                    centerUsed = true; //ab use hogaya hai center wala
                }
            }
        }
        
        return result;
    }
};