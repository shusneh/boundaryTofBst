class Solution {
public:
    bool islf(Node* root){
        if(root==NULL||root->left==NULL||root->right==NULL)return true;
        return false;
    }
    void left(Node* root,vector<int> &left){
        Node* tmp=root;
        tmp=tmp->left;
        while(tmp){
            if(!islf(tmp))left.push_back(tmp->data);
            if(tmp->left)tmp=tmp->left;
            else tmp=tmp->right;
        }
    }
    void right(Node* root,vector<int> &right){
        Node* tmp=root;
        tmp=tmp->right;
        vector<int> temp;
        while(tmp){
            if(!islf(tmp))temp.push_back(tmp->data);
            if(tmp->right)tmp=tmp->right;
            else tmp=tmp->left;
        }
        
        for(int i=0;i<temp.size();i++){
            right.push_back(temp[temp.size()-1-i]);
        }
    }
    void leaft(Node* root, vector<int> &leaf){
        if(islf(root)){
            leaf.push_back(root->data);
            return ;
        }
        if(root->left) leaft(root->left,leaf);
        if(root->right)leaft(root->right,leaf);
    }
    vector <int> boundary(Node *root)
    {
        //Your code here
        vector<int> ans;
        if(!root)return ans;
        if(!islf(root))ans.push_back(root->data);
        left(root,ans);
        leaft(root,ans);
        right(root,ans);
        return ans;
        
    }
};
