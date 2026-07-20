class Solution {
public://brute force.
    int minEatingSpeed(vector<int>& piles, int h) {
    // Koko ki maximum useful eating speed maximum pile ke equal hogi,
    // kyuki isse zyada speed rakhne ka koi fayda nahi.
    // Ek hour me wo sirf ek pile se hi kha sakti hai.
          int maxPile = *max_element(piles.begin(), piles.end());


          //try every speed
          for(int speed=1;speed<=maxPile;speed++){
                long long totalHours=0;

                // Calculate total hours required at current speed
                for(int bananas:piles){

                    //itna totalhour lagega usko is pile ko khtm krne me at current speed
                    totalHours += (int)ceil((double)bananas / speed);
                }
                    //if coco can finish all within k hours,
                    //ye speed sbse minimum h.
                    if(totalHours<=h){
                        return speed;
                    }
          }
          return -1;
    }
};