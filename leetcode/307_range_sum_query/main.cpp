class NumArray {
public:
    struct Node {
      struct Node* left;
      struct Node* right;
      int value;
      // represent the range of this node
      int rangeLeft;
      int rangeRight;
    };

    Node* root;


    // pass left and right so we don't need to duplicate vector which is O(n)
    Node* createTree(vector<int>& nums, int left, int right) {
      struct Node* root = new Node();

      // leaves
      if (right == left) {
        root->value = nums[left];
        root->rangeLeft = left;
        root->rangeRight = left;
        return root;
      }

      int leftNodeHigh = (left + right) / 2;
      int rightNodeLow = leftNodeHigh + 1;
      root->left = createTree(nums, left, leftNodeHigh);
      root->right = createTree(nums, rightNodeLow, right);

      root-> value = root->left->value + root->right->value;
      root->rangeLeft = root->left->rangeLeft;
      root->rangeRight = root->right->rangeRight;

      return root;
    }

    int querySum(Node* root, int left, int right) {
      if (root->rangeLeft == left && root->rangeRight == right) {
        return root->value;
      }
      // answer is only in left subtree
      if (right <= root->left->rangeRight) {
        return querySum(root->left, left, right);
      }
      // only in right subtree
      if (left >= root->right->rangeLeft) {
        return querySum(root->right, left, right);
      }

      // in both side
      return querySum(root->left, left, root->left->rangeRight) + querySum(root->right, root->right->rangeLeft, right);
    }

    int updateNode(Node* root, int index, int value) {
      int diff;

      if (index == root->rangeLeft && index == root->rangeRight) {
        diff = root->value - value;
        root->value = value;

        // return the diff so the parent can update
        return diff;
      }

      // in the left subtree
      if (index <= root->left->rangeRight) {
        diff = updateNode(root->left, index, value);
      } else {
        diff = updateNode(root->right, index, value);
      }
      root->value = root->value - diff;
      return diff;
    }

    NumArray(vector<int>& nums) {
        this->root = createTree(nums, 0, nums.size() - 1);
    }

    void update(int index, int val) {
        this->updateNode(this->root, index, val);
    }

    int sumRange(int left, int right) {
        return this->querySum(this->root, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
