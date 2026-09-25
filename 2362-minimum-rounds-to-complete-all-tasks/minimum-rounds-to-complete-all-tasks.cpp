class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int rnd = 0;
        unordered_map<int, int> mp;
        for(int &task: tasks){
            mp[task]++;
        }
        for(auto &it: mp){
            int count=it.second;

            if(count ==1){
                return -1;
            }

            if(count % 3==0){
                //  3k form 
                rnd = rnd + count / 3;
            }
            else{
                //  3k+1 , 3k+2
                rnd = rnd + count/3 + 1;
            }
        }
        return rnd;

    }
};