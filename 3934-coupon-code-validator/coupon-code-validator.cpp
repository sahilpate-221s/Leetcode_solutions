class Solution {
public:
    set<string> validBusinesses = {"electronics", "grocery", "pharmacy", "restaurant"};
    map<string, int> businessOrder = {
        {"electronics", 0},
        {"grocery", 1},
        {"pharmacy", 2},
        {"restaurant", 3}
    };

    bool isValidBusiness(const string& word) {
        return validBusinesses.count(word) > 0;
    }

    bool validWord(const string& word) {
        if (word.empty()) return false;
        for (char ch : word) {
            if (!((ch >= 'a' && ch <= 'z') ||
                  (ch >= 'A' && ch <= 'Z') ||
                  (ch >= '0' && ch <= '9') || ch == '_')) {
                return false;
            }
        }
        return true;
    }

    vector<string> validateCoupons(vector<string>& code,
                                   vector<string>& businessLine,
                                   vector<bool>& isActive) {

        vector<pair<string, string>> validCoupons; // {businessLine, code}

        for (int i = 0; i < code.size(); i++) {
            if (validWord(code[i]) && isValidBusiness(businessLine[i]) && isActive[i]) {
                validCoupons.push_back({businessLine[i], code[i]});
            }
        }

        sort(validCoupons.begin(), validCoupons.end(), [&](const pair<string, string>& a, const pair<string, string>& b) {
            if (businessOrder[a.first] != businessOrder[b.first])
                return businessOrder[a.first] < businessOrder[b.first];
            return a.second < b.second;
        });

        vector<string> result;
        for (const auto& pair : validCoupons) {
            result.push_back(pair.second);
        }

        return result;
    }
};