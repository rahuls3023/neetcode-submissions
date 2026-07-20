class Solution {
public: // Binary Search

    bool canKokoEat(int speed, vector<int>& piles, int hours) {

        long long totalHours = 0;

        for (int i = 0; i < piles.size(); i++) {

            // Current speed par is pile ko finish karne me
            // minimum kitne hours lagenge
            totalHours += (int)ceil((double)piles[i] / speed);
        }

        // Agar Koko given hours ke andar saari piles finish kar sakti hai
        if (totalHours <= hours) {
            return true;
        }

        return false;
    }

    int minEatingSpeed(vector<int>& piles, int h) {

        // Minimum possible eating speed 1 banana per hour hogi
        int low = 1;

        // Maximum useful eating speed largest pile ke equal hogi,
        // kyuki isse zyada speed rakhne ka koi fayda nahi.
        // Koko ek hour me sirf ek pile se hi kha sakti hai.
        // Isliye ye binary search ka upper bound hoga.
        int high = *max_element(piles.begin(), piles.end());

        int ans = 0;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (canKokoEat(mid, piles, h)) {

                // Current speed valid hai, isliye ise answer store karo.
                // Ab aur chhoti valid speed search karenge.
                ans = mid;
                high = mid - 1;
            }
            else {

                // Current speed slow hai, isliye speed badhani padegi.
                low = mid + 1;
            }
        }

        return ans;
    }
};