
class TreeNode{
	 public:
	    int data;
	    TreeNode *left;
	    TreeNode *right;
	
	    TreeNode(int data) {
	        this->data = data;
	        left = NULL;
	        right = NULL;
	    }
};
TreeNode*findLCA(TreeNode *root, int node1, int node2)
{
    if (root == NULL)
    {
        return root;
    }
    if (root->val == node1 || root->val == node2)
    {
        return root;
    }
    TreeNode *left = findLCA(root->left, node1, node2);
    TreeNode *right = findLCA(root->right, node1, node2);
    if (left != NULL && right != NULL)
    {
        return root;
    }
    if (left != NULL)
    {
        return left;
    }
    return right;
}


int findLevel(TreeNode *root, int lca_is, int level)
{
    if (root == NULL)      
        return -1;

    if (root->val == lca_is)
        return level;
    .
    int left_tree = findLevel(root->left, lca_is, level + 1);

    if (left_tree == -1)
    {
        return findLevel(root->right, lca_is, level + 1);
    }

    return left_tree;
}

int findDistanceBetweenNodes(TreeNode *root, int node1, int node2)
{

    TreeNode *lca = findLCA(root, node1, node2);
    if (lca == NULL)
    {
        return -1;
    }
    int level1 = findLevel(lca, node1, 0);
    int level2 = findLevel(lca, node2, 0);

    return level1+level2;
}
