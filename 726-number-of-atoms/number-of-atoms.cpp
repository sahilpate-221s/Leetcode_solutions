class Solution {
public:
    string countOfAtoms(string formula) {
        int n = formula.length();
        stack<unordered_map<string, int>>
            st; // stack create kiya unordered map ka
        st.push(
            unordered_map<string, int>()); // empty map insert kiya isi ke andar
                                           // value dalna start karenge

        int i = 0;
        while (i < n) {
            if (formula[i] == '(') {
                st.push(unordered_map<string, int>());
                i++;
            } else if (formula[i] == ')') {
                unordered_map<string, int> curr = st.top();
                st.pop();

                i++; // ikso age badha ke check karenge kitne digits hai
                     // multiply karne ke liye

                string mult;
                while ((i < n) && isdigit(formula[i])) {
                    mult += formula[i];
                    i++;
                }
                // check karenge ki kitne digits hai
               
                if(!mult.empty())
                {
                    int multiInteger = stoi(mult);
                    for(auto &it: curr)
                    {
                        string ele = it.first;
                        int count = it.second;
                        curr[ele]=count*multiInteger;
                    }
                }

                // merging this to stack ka top
                for (auto& it : curr) {
                    string element = it.first;
                    int count = it.second;

                    st.top()[element] += count;
                }

            } else {
                string currElement;
                currElement.push_back(formula[i]);
                i++;
                while (i < n && isalpha(formula[i]) && islower(formula[i])) {
                    currElement.push_back(formula[i]);
                    i++;
                }

                string currCount;
                while (i < n && isdigit(formula[i])) {
                    currCount.push_back(formula[i]);
                    i++;
                }

                int currCountInteger = currCount.empty() ? 1 : stoi(currCount);
                st.top()[currElement] += currCountInteger;
            }
        }
        // st will have only unordered
        map<string, int> sortedMap(st.top().begin(), st.top().end());
        string result;

        for (auto &it : sortedMap) {
            string element = it.first;
            int count = it.second;
            result += element;
            if (count > 1) {
                result += to_string(count);
            }
        }

        return result;
    }
};