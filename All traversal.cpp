vector<vector<int>> getTreeTraversal(TreeNode *root)
{
   stack<pair<TreeNode* , int>>st;
   vector<int> pre,ino,post;
   if(root==nullptr)
   {
      return {ino,pre,post};
   }
   st.push({root,1});
   while(!st.empty())
   {
       auto it = st.top();
       st.pop();
       
       if(it.second == 1)
       {
           pre.push_back(it.first->data);
           it.second++;
           st.push(it);

           if(it.first ->left != nullptr)
           {
             st.push({it.first->left, 1});
           }
       }

       else if (it.second == 2) 
       {
           ino.push_back(it.first->data);
           it.second++;
           st.push(it);

           if(it.first ->right != nullptr)
           {
               st.push({it.first->right,1});
           }
       } 
       else 
       {
           post.push_back(it.first->data);
       }
   }
   return {ino,pre,post};
}