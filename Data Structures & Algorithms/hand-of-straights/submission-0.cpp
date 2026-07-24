class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize!=0) return false;

        map<int,int>mp;//we will be having number in ordered format

        for(auto it:hand){
            mp[it]++;
        }

        while(!mp.empty()){
            int currNo=mp.begin()->first;

            //now search for consecutive number in map according to group size
            for(int i=0;i<groupSize;i++){
                if(mp.find(currNo+i)==mp.end())return false;//cannot arrange

                mp[currNo+i]--;

                if(mp[currNo+i]<1){//delete the number if freq<0
                    mp.erase(currNo+i); 
                }
            }
        }
        return true;
    }
};