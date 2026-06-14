#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

/* 创建新结点 */
TreeNode* CreateNode(int value)
{
    TreeNode *node = (TreeNode*)malloc(sizeof(TreeNode));

    node->data = value;
    node->left = NULL;
    node->right = NULL;

    return node;
}

/* 
   根据顺序存储数组建立二叉链表
   数组中用 -1 表示空结点
   下标从 1 开始，结点 i 的左孩子为 2*i，右孩子为 2*i+1
*/
TreeNode* CreateTree(int arr[], int index, int n)
{
    if (index > n || arr[index] == -1)
    {
        return NULL;
    }

    TreeNode *root = CreateNode(arr[index]);

    root->left = CreateTree(arr, index * 2, n);
    root->right = CreateTree(arr, index * 2 + 1, n);

    return root;
}

/* 先序遍历：根 左 右 */
void PreOrder(TreeNode *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        PreOrder(root->left);
        PreOrder(root->right);
    }
}

/* 中序遍历：左 根 右 */
void InOrder(TreeNode *root)
{
    if (root != NULL)
    {
        InOrder(root->left);
        printf("%d ", root->data);
        InOrder(root->right);
    }
}

/* 后序遍历：左 右 根 */
void PostOrder(TreeNode *root)
{
    if (root != NULL)
    {
        PostOrder(root->left);
        PostOrder(root->right);
        printf("%d ", root->data);
    }
}

/* 求二叉树最大结点值 */
int MaxValue(TreeNode *root)
{
    int leftMax, rightMax, max;

    if (root == NULL)
    {
        return -999999;
    }

    leftMax = MaxValue(root->left);
    rightMax = MaxValue(root->right);

    max = root->data;

    if (leftMax > max)
    {
        max = leftMax;
    }

    if (rightMax > max)
    {
        max = rightMax;
    }

    return max;
}

/* 求叶子结点数 */
int CountLeaf(TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }

    if (root->left == NULL && root->right == NULL)
    {
        return 1;
    }

    return CountLeaf(root->left) + CountLeaf(root->right);
}

int main()
{
    int arr[MAX_SIZE];
    int n;
    TreeNode *root;

    printf("请输入顺序存储二叉树的结点个数：");
    scanf("%d", &n);

    printf("请输入顺序存储二叉树中的结点值，空结点用 -1 表示：\n");

    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &arr[i]);
    }

    root = CreateTree(arr, 1, n);

    printf("\n先序遍历序列为：");
    PreOrder(root);

    printf("\n中序遍历序列为：");
    InOrder(root);

    printf("\n后序遍历序列为：");
    PostOrder(root);

    printf("\n");

    printf("\n二叉树中的最大结点值为：%d\n", MaxValue(root));

    printf("二叉树中的叶子结点数为：%d\n", CountLeaf(root));

    return 0;
}