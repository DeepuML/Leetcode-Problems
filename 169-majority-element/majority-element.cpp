class Solution {
public:
    int majorityElement(vector<int>& arr) {
        int c=0,el;
	for(int i=0;i<arr.size();i++){
	    if(c==0){
	        c=1;
	        el=arr[i];
	    }else if(el==arr[i]){
	        c++;
	    }else{
	        c--;
	    }
	}
	return el;
    }
};