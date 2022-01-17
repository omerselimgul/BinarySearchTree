#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;

} nd;

struct node *root = NULL;

nd *createnode(int data)
{

    nd *temp = (struct node *)(malloc(sizeof(nd)));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
void InserttheTree(nd *head, nd *node)
{
    if (root == NULL)
    {
        root = node;
    }
    else
    {
        if (node->data < head->data)
        {
            if (head->left == NULL)
            {
                head->left = node;
            }
            else
            {
                InserttheTree(head->left, node);
            }
        }
        else
        {
            if (head->right == NULL)
            {
                head->right = node;
            }
            else
            {
                InserttheTree(head->right, node);
            }
        }
    }
}
void display(nd *head)
{
    if (head != NULL)
    {
        display(head->left);
        printf("%d -> ", head->data);
        display(head->right);
    }
}
nd *searchTheData(nd *head, int data)
{
    while ((head->data != data) && (head != NULL))
    {
        if (data > head->data)
        {
            printf("%d ", head->data);
            head = head->right;
        }
        else
        {
            printf("%d ", head->data);
            head = head->left;
        }
    }
    return head;
}

struct node *deleteElement(struct node *tree, int val)
{
    struct node *cur, *parent, *suc, *psuc, *ptr;
    if (tree-> left == NULL)
    {
        printf("\n The tree is empty ");
        return (tree);
    }
    parent = tree;
    cur = tree-> left;
    while (cur != NULL && val != cur-> data)
    {
        parent = cur;
        cur = (val<cur-> data) ? cur-> left : cur-> right;
    }
    if (cur == NULL)
    {
        printf("\n The value to be deleted is not present in the tree");
        return (tree);
    }
    if (cur-> left == NULL)
        ptr = cur-> right;
    else if (cur-> right == NULL)
       // 310 Data Structures Using C
            ptr =cur-> left;
    else
    {
        // Find the in–order successor and its parent
        psuc = cur;
        suc = cur-> left;
        while (suc-> right != NULL)
        {
            psuc = suc;
            suc = suc-> right;
        }
        if (cur == psuc)
        {
            // Situation 1
            suc-> right = cur-> right;
        }
        else
        {
            // Situation 2
            suc-> left = cur-> left;
            psuc-> right = suc-> left;
            suc-> right = cur-> right;
        }
        ptr = suc;
    }
    // Attach ptr to the parent node
    if (parent-> left == cur)
        parent-> left = ptr;
    else
        parent-> right = ptr;
    free(cur);
    return tree;
}
int countNodes(nd *treeRoot, int sum)
{
    if (treeRoot == NULL)
        return sum;
    sum++;
    sum = countNodes(treeRoot->left, sum);
    sum = countNodes(treeRoot->right, sum);
    return sum;
}
int main()
{
    int data;
    int answer;
    while (1)
    {
        printf("-----------Menu---------\n");
        printf("Insert :  1\nSearch : 2 \nDisplay : 3\nDelete :  4 \nCount : 5 \nExit :  6 \t");

        scanf("%d", &answer);

        switch (answer)
        {
        case 1:
            printf("Data giriniz :  ");
            scanf("%d", &data);
            nd *newnode = createnode(data);
            InserttheTree(root, newnode);
            break;
        case 2:
            printf("Data giriniz :  ");
            scanf("%d", &data);
            nd *node;
            node = searchTheData(root, data);
            if (node->data == data)
            {
                printf(" %d  \n  Data Bulundu \n ", node->data);
            }
            else
            {
                printf("Data Bulanamadi");
            }
            break;
        case 3:
            display(root);
            break;
        case 4:
            printf("Data giriniz :  ");
            scanf("%d", &data);
            nd *temp = deleteElement (root, data);
            break;
        case 5:
            data = countNodes(root, 0);
            printf("%d  : ", data);
            break;
        case 6:
            exit(0);
            break;
        default:
            break;
        }
    }

    return 0;
}