class Solution {
public:
    vector<int> majorityElement(vector<int>& arr) {
        vector<int>ar;
        int c1=0,el1=INT_MIN,c2=0,el2=INT_MIN;
	for(int i=0;i<arr.size();i++){
	    if(c1==0&&arr[i]!=el2){
	        c1=1;
	        el1=arr[i];
	    }else if(c2==0&&el1!=arr[i]){
	        c2=1;
            el2=arr[i];
	    }else if(arr[i]==el1){
	        c1++;
	    }else if(arr[i]==el2){
            c2++;
        }else{
            c1--;c2--;
        }
	}
	int co1=0,co2=0;
    for(int i=0;i<arr.size();i++){
        if(arr[i]==el1)co1++;
        if(arr[i]==el2)co2++;
    }
    if(co1>(arr.size()/3)) ar.push_back(el1);
    if(co2>(arr.size()/3)) ar.push_back(el2);
	
	return ar;
    }
};