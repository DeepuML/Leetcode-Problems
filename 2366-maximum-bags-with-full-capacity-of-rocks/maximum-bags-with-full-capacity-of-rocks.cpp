class Solution { 
public: 
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) { 
        vector<int> req;
        for(int i = 0; i < capacity.size(); i++) { 
            int curr = rocks[i]; 
            int cap_rock = capacity[i]; 
            int req_roc = cap_rock - curr; 
            req.push_back(req_roc); 
        } 
        
        sort(begin(req), end(req)); 
        int count = 0; 
         for(int i = 0; i < capacity.size(); i++) { 
              if(req[i] == 0) { 
                count++; 
            } 
            else { 
                if(additionalRocks >= req[i]) { 
                    additionalRocks = additionalRocks - req[i]; 
                    count++; 
                } 
                else { 
                    break; 
                } 
            } 
        } 
        
        return count; 
    } 
};