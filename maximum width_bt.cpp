class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        int ans;
        queue<pair<TreeNode*,unsigned int>>q; //node,index
        if(root==nullptr)
        {
            return 0;
        }
        q.push({root,0});
        while(!q.empty())
        {
            int n = q.size();
            unsigned int minimum = q.front().second;
            int first;
            int last;
            for(int i =0;i<n;i++)
            {
               unsigned int curr_index = q.front().second - minimum;
                TreeNode* node = q.front().first;
                q.pop();
                if(i==0)
                {
                    first = curr_index;
                }
                if(i==n-1)
                {
                    last = curr_index;
                }
                if(node->left != nullptr)
                {
                    q.push({node->left,(curr_index)*2+1});
                }
                if(node->right != nullptr)
                {
                    q.push({node->right,(curr_index)*2+2});
                }
                ans = max(ans,last-first+1);
            }
        }
        return ans;
    }
};
