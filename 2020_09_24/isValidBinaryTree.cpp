/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

struct Valid {
    bool isValid{false};
    bool isNull{false};
    int min{0};
    int max{0};
};

bool isValidBST(TreeNode* root) {
    Valid * const v = (Valid * const) malloc(sizeof(Valid));
    v->isValid = true;
    v->isNull = (root == nullptr);
    v->min = 0;
    v->max = 0;
    
    isValidBST_full(root,v);
    return v->isValid;
}
    
void isValidBST_full(TreeNode * root, Valid * const v) {
    if (!root) {
        v->isValid = true;
        v->isNull = true;
        return;
    }

    int min;
    int max;

    isValidBST_full(root->left,v);

    if (!v->isValid) return;
    else if (!v->isNull) {
        if (v->max >= root->val) {
            v->isValid = false;
            return;
        }
        min = v->min;
    } else min = root->val;

    isValidBST_full(root->right,v);

    if (!v->isValid) return;
    else if (!v->isNull) {
        if (root->val >= v->min) {
            v->isValid = false;
            return;
        }
        max = v->max;
    } else max = root->val;

    v->isValid = true;
    v->isNull = false;
    v->min = min;
    v->max = max;
    return;
}