class Solution {
public:
    static bool comp(string &a,string &b){
        return a+b>b+a;
    }
    string largestNumber(vector<int>& nums) {
        vector<string>arr;

        for(auto it:nums){
            arr.push_back(to_string(it));
        }

        sort(begin(arr),end(arr),comp);

        if(arr[0]=="0") return "0";

        string ans="";

        for(auto it:arr){
            ans+=it;
        }
        return ans;
    }
};