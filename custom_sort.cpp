class Solution {
    public:
        int numEquivDominoPairs(vector<vector<int>>& dominoes) {
            for(auto& pair : dominoes){
                if(pair[0] > pair[1]) {
                    int temp=pair[0];
                    pair[0]=pair[1];
                    pair[1]=temp;
                }
            }
            std::sort(dominoes.begin(), dominoes.end(), customCompare);
            return 0;
        }
    
        bool customCompare(const std::vector<int>& a, const std::vector<int>& b) {
            // First compare by first element
            if (a[0] != b[0]) {
                return a[0] < b[0];
            }
            // If first elements are equal, compare by second element
            return a[1] < b[1];
        }
    };
