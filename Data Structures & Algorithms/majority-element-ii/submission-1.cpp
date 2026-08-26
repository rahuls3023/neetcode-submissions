class Solution {
public://Boyer-Moore Voting Algorithm-> somewhat same approach as N/2 question
    vector<int> majorityElement(vector<int>& nums) {
    int elem1=INT_MIN;// 0 mt lena yaha pe vrna input->> [0,0,0] ye wala case ft jayega
	int elem2=INT_MIN;
	int cnt1=0;
	int cnt2=0;
	for(int i=0;i<nums.size();i++){

		if(cnt1==0 && nums[i]!=elem2){//remember this check condition, taaki dusre ko assign element firse na assign hojaye
			cnt1=1;
			elem1=nums[i];
		}
		 else if(cnt2==0 && nums[i]!=elem1){//remember this check condition, taaki dusre ko assign element firse na assign hojaye
			cnt2=1;
			elem2=nums[i];
		}

		else if(elem1==nums[i]){
			cnt1++;
		}
		else if(elem2==nums[i]){
			cnt2++;
		}
		else{
			cnt1--;
			cnt2--;
		}
	}

	//now check for elem1 and elem2
	vector<int>ans;
	int newcnt1=0;
	int newcnt2=0;

	for(int i=0;i<nums.size();i++){//ab agar element ka count greater ajaye to answer h vo ek
		if(nums[i]==elem1) newcnt1++;
		if(nums[i]==elem2) newcnt2++;
	}
	int mini=(int)(nums.size()/3)+1;

	if(newcnt1>=mini) ans.push_back(elem1);
	if(newcnt2>=mini) ans.push_back(elem2);

	sort(ans.begin(),ans.end());
	return ans;
    }
};