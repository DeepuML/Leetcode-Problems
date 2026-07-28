class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {

        if(!root)
            return 0;

        queue<pair<TreeNode*, long long>> q;
        int ans = 0;
        q.push({root,0});

        while(!q.empty()){
            int size = q.size();
            long long mini = q.front().second;
            long long first;
            long long last;

            for(int i=0;i<size;i++){
                long long curr_i = q.front().second - mini;
                TreeNode* temp = q.front().first;
                q.pop();
                if(i==0)
                    first = curr_i;
                if(i==size-1)
                    last = curr_i;
                    
                if(temp->left){
                    q.push({temp->left, curr_i*2+1});
                }

                if(temp->right){
                    q.push({temp->right, curr_i*2+2});
                }
            }

            ans = max(ans, (int)(last-first+1));
        }

        return ans;
    }
};