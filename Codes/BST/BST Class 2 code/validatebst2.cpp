class solution
{
public:
	bool solve(TreeNode *root, long long int upperbound, long long int lowerbound)
	{
		if (root == NULL)
		{
			return true;
		}

		bool cond1 = (root->val > lowerbound);
		bool cond2 = (root->val < upperbound);
		bool leftans = solve(root->left, lowerbound , root->val );
		bool rightans = solve(root->right, root->val, upperbound );

		if (cond1 && cond2 && leftans && rightans)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool isvalidbst(TreeNode *root)
	{

		long long int lowerbound = -2147483657;
		long long int upperbound = 214783657;

		bool ans = solve(root, upperbound, lowerbound);
		return ans;
	}
};