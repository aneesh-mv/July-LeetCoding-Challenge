/*
Given a binary tree, write a function to get the maximum width of the given tree. The width of a tree is the maximum width among all levels. The binary tree has the same structure as a full binary tree, but some nodes are null.

The width of one level is defined as the length between the end-nodes (the leftmost and right most non-null nodes in the level, where the null nodes between the end-nodes are also counted into the length calculation.

Example 1:

Input: 

           1
         /   \
        3     2
       / \     \  
      5   3     9 

Output: 4
Explanation: The maximum width existing in the third level with the length 4 (5,3,null,9).
*/
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if( !root ) return 0;
        queue<pair<TreeNode*, int> > q;
        q.push({root, 1 });
        int ans = 0;
        while(!q.empty() ){
            int size = q.size();
            if (size == 1){
                q.push({q.front().first,1});
                q.pop();
            }
            ans = max( q.back().second - q.front().second + 1, ans);
        
            while( size--){
                auto node = q.front().first;
                auto idx = q.front().second;
                q.pop();
                if( node->left )
                    q.push({node->left, idx*2});
                if( node->right )
                    q.push({node->right, idx*2+1});
            }
            
        }
        return ans;
    }
};
