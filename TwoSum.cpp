class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> indices = {};
        int tmp = target;
        for (int i = 0; i < nums.size(); i++){
            tmp -= nums[i];
            indices.push_back(i);
            for (int j = i + 1; j < nums.size(); j++){
                tmp -= nums[j];
                if ( tmp == 0 ){
                    indices.push_back(j);
                    return indices;
                }
                else
                    tmp += nums[j];
            }
            tmp = target;
            indices.clear();
        }
        return indices;
    }
};
