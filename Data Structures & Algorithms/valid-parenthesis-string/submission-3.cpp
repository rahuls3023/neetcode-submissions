class Solution {
public://constant space
    bool checkValidString(string s) {
        int open=0;
        int close=0;

        //left to right
        for(int i=0;i<s.size();i++){
            if(s[i]=='(' || s[i]=='*') open++;
            else open--;

            if(open<0){
                //iska mtlb ki close bracket ka count bht jyada hogya,
                //humne star * ko bhi open bracket mana aur open bracket to the hi , un dono ke total se bhi jyada close bracket milgye
                return false;
            }
        }

        //right to left-> take * as close bracket
        for(int i=s.length()-1;i>=0;i--){
            if(s[i]==')' || s[i]=='*'){
                close++;
            }
            else close--;

            if(close<0){
                  //iska mtlb ki open bracket ka count bht jyada hogya,
                //humne star * ko bhi close bracket mana aur close bracket to the hi , un dono ke total se bhi jyada open bracket milgye
                return false;
            }
        }
        return true;
    }
};