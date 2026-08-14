class Solution {
public:
    int recursion(int start,int end,vector<int>&piles){
        if(start>end) return 0;

        if(start==end) return piles[start];

        //agar shuru se le 
        int PickfromStart=piles[start]-recursion(start+1,end,piles);

        //end se le
        int PickFromEnd=piles[end]-recursion(start,end-1,piles);

        return max(PickfromStart,PickFromEnd);
    }
    bool stoneGame(vector<int>& piles) {
       int n=piles.size();
       int ans=recursion(0,n-1,piles);

       if(ans>=0) return true;
       else return false; 
    }
};