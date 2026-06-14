#include <stdio.h>
#include <stdlib.h>

/* ===================== 折半查找部分 ===================== */

int BinarySearch(int a[], int n, int k)
{
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (a[mid] == k)
        {
            return mid;
        }
        else if (k < a[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return -1;
}

/* ===================== 二叉排序树部分 ===================== */

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node* CreateNode(int x)
{
    Node *p = (Node*)malloc(sizeof(Node));

    p->data = x;
    p->left = NULL;
    p->right = NULL;

    return p;
}

void InsertBST(Node **root, int x)
{
    if (*root == NULL)
    {
        *root = CreateNode(x);
    }
    else if (x < (*root)->data)
    {
        InsertBST(&((*root)->left), x);
    }
    else if (x > (*root)->data)
    {
        InsertBST(&((*root)->right), x);
    }
}

void InOrder(Node *root)
{
    if (root != NULL)
    {
        InOrder(root->left);
        printf("%d ", root->data);
        InOrder(root->right);
    }
}

int main()
{
    int n, k;
    int a[100];

    printf("请输入有序序列的元素个数：");
    scanf("%d", &n);

    printf("请输入有序序列中的元素：\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("请输入要查找的关键字 k：");
    scanf("%d", &k);

    int pos = BinarySearch(a, n, k);

    if (pos != -1)
    {
        printf("查找成功，关键字 %d 在序列中的位置为第 %d 个元素。\n", k, pos + 1);
    }
    else
    {
        printf("查找失败，序列中不存在关键字 %d。\n", k);
    }

    printf("\n");

    int b[] = {16, 5, 17, 29, 11, 3, 15, 20};
    int m = 8;

    Node *root = NULL;

    for (int i = 0; i < m; i++)
    {
        InsertBST(&root, b[i]);
    }

    printf("二叉排序树的中序遍历结果为：\n");
    InOrder(root);
    printf("\n");

    return 0;
}