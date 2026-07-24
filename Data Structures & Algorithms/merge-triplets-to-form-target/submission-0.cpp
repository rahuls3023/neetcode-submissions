class Solution {
public://optimal
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int i=0;

        int n=triplets.size();
        
        bool zeroIndexTarget=false;//ye btayega ki pure triplets me hume 0th index wala target mila ya nhi 
        bool oneIndexTarget=false;
        bool twoIndexTarget=false;

        while(i<n){

            //we can ignore the triplet if any element in triplet is greater  than the corresponding value in target
            if(triplets[i][0]>target[0] || triplets[i][1]>target[1] || triplets[i][2]>target[2]){
                //ye triplet ko ignore kro as iski value jyada h target se to isko compare nhi krege
                i++; 
                continue;
            }
            
            if(triplets[i][0]==target[0]){
                zeroIndexTarget=true;
            }
            if(triplets[i][1]==target[1]){
                oneIndexTarget=true;
            }
            if(triplets[i][2]==target[2]){
                twoIndexTarget=true;
            }
            i++;
        }

        if(zeroIndexTarget==true && oneIndexTarget==true && twoIndexTarget==true){
            return true;
        }
        else return false;
    }
};
