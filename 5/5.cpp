#include <iostream>
#include <functional>
#include <stack>
#include <sstream>
#include <queue>
#include <map>
#include <vector>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool isSameTree(TreeNode* p, TreeNode* q) {
    if (!p && !q) return true;
    if (!p || !q) return false;
    return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

//

bool isSymmetric(TreeNode* root) {
    if (!root) return true;

    std::function<bool(TreeNode*, TreeNode*)> isMirror = [&](TreeNode* t1, TreeNode* t2) {
        if (!t1 && !t2) return true;
        if (!t1 || !t2) return false;
        return t1->val == t2->val && isMirror(t1->left, t2->right) && isMirror(t1->right, t2->left);
        };

    return isMirror(root, root);
}

//

TreeNode* invertTree(TreeNode* root) {
    if (!root) return nullptr;
    std::swap(root->left, root->right);
    invertTree(root->left);
    invertTree(root->right);
    return root;
}

//

int kthSmallest(TreeNode* root, int k) {
    std::stack<TreeNode*> stack;
    while (root || !stack.empty()) {
        while (root) {
            stack.push(root);
            root = root->left;
        }
        root = stack.top();
        stack.pop();
        if (--k == 0) return root->val;
        root = root->right;
    }
    return -1; 
}

//

class Codec {
public:
    std::string serialize(TreeNode* root) {
        if (!root) return "";
        std::ostringstream out;
        std::queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node) {
                out << node->val << ",";
                q.push(node->left);
                q.push(node->right);
            }
            else {
                out << "null,";
            }
        }
        return out.str();
    }

    TreeNode* deserialize(const std::string& data) {
        if (data.empty()) return nullptr;
        std::istringstream in(data);
        std::string val;
        std::getline(in, val, ',');
        TreeNode* root = new TreeNode(std::stoi(val));
        std::queue<TreeNode*> q;
        q.push(root);
        while (std::getline(in, val, ',')) {
            TreeNode* node = q.front();
            q.pop();
            if (val != "null") {
                node->left = new TreeNode(std::stoi(val));
                q.push(node->left);
            }
            if (std::getline(in, val, ',')) {
                if (val != "null") {
                    node->right = new TreeNode(std::stoi(val));
                    q.push(node->right);
                }
            }
        }
        return root;
    }
};

//

int maxPathSum(TreeNode* root) {
    int result = INT_MIN;

    std::function<int(TreeNode*)> helper = [&](TreeNode* node) {
        if (!node) return 0;
        int left = std::max(helper(node->left), 0);
        int right = std::max(helper(node->right), 0);
        result = std::max(result, left + right + node->val);
        return node->val + std::max(left, right);
        };

    helper(root);
    return result;
}

//

int minCameraCover(TreeNode* root) {
    enum State { NO_CAM, HAS_CAM, COVERED };
    std::function<int(TreeNode*, State&)> dfs = [&](TreeNode* node, State& state) -> int {
        if (!node) {
            state = COVERED;
            return 0;
        }

        State leftState, rightState;
        int left = dfs(node->left, leftState);
        int right = dfs(node->right, rightState);

        if (leftState == NO_CAM && rightState == NO_CAM) {
            state = HAS_CAM;
            return 1 + left + right;
        }

        if (leftState == HAS_CAM || rightState == HAS_CAM) {
            state = COVERED;
            return left + right;
        }

        state = NO_CAM;
        return left + right;
        };

    State state;
    int cameras = dfs(root, state);
    return cameras + (state == NO_CAM ? 1 : 0);
}

//

std::vector<std::vector<int>> verticalOrder(TreeNode* root) {
    std::map<int, std::vector<int>> columns;
    std::queue<std::pair<TreeNode*, int>> q;
    q.push({ root, 0 });

    while (!q.empty()) {
        auto [node, col] = q.front();
        q.pop();
        if (node) {
            columns[col].push_back(node->val);
            q.push({ node->left, col - 1 });
            q.push({ node->right, col + 1 });
        }
    }

    std::vector<std::vector<int>> result;
    for (auto& [col, nodes] : columns) {
        result.push_back(nodes);
    }
    return result;
}

//

TreeNode* recoverFromPreorder(const std::string& traversal) {
    std::stack<TreeNode*> stack;
    int i = 0;

    while (i < traversal.size()) {
        int level = 0;
        while (i < traversal.size() && traversal[i] == '-') {
            level++;
            i++;
        }

        int val = 0;
        while (i < traversal.size() && std::isdigit(traversal[i])) {
            val = val * 10 + (traversal[i] - '0');
            i++;
        }

        TreeNode* node = new TreeNode(val);
        while (stack.size() > level) stack.pop();

        if (!stack.empty()) {
            if (!stack.top()->left) stack.top()->left = node;
            else stack.top()->right = node;
        }

        stack.push(node);
    }

    return stack.top();
}


int main()
{
	return 0;
}