#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node;

node *new_node(int data)
{
    node *new_node = (node *)malloc(sizeof(node));
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->data = data;
    return new_node;
}

void inOrder(node *root)
{
    node *ptr = root;
    if (ptr == NULL)
    {
        return;
    }
    inOrder(ptr->left);
    printf("%d ", ptr->data);
    inOrder(ptr->right);
}

// int sum_tree(node* root){
//   node* ptr=root;
//   if(ptr->left==NULL||ptr->right==NULL){
//       return 1;
//   }
//   else{
//       int a=ptr->left->data;
//       int b=ptr->right->data;
//       if(ptr->data!=a+b){
//           return 0;
//       }
//   }
//   sum_tree(ptr->left);
//   sum_tree(ptr->right);
// }

int main()
{
    int n;
    printf("Enter the no. of level you want: ");
    scanf("%d", &n);
    node *root;
    node **nodes = (node **)malloc(sizeof(node *) * pow(2, n));
    for (int i = 0; i < n; i++)
    {
        node **nodes1 = (node **)malloc(sizeof(node *) * pow(2, n));
        int k = 0;
        int x = pow(2, i);
        int arr[x];
        printf("Enter the data for %d level: ", i);
        for (int j = 0; j < pow(2, i); j++)
        {
            scanf("%d", &arr[j]);
        }
        if (i == 0)
        {
            root = new_node(arr[i]);
            nodes[i] = root;
            continue;
        }
        else
        {
            int k = 0, t = 0;
            for (int j = 0; j < pow(2, i - 1); j++)
            {
                node *temp = new_node(arr[t]);
                nodes1[k] = temp;
                nodes[j]->left = temp;
                k++;
                t++;
                node *temp2 = new_node(arr[t]);
                nodes1[k] = temp2;
                nodes[j]->right = temp2;
                k++;
                t++;
            }
        }
        for (int p = 0; p < pow(2, i); p++)
        {
            nodes[p] = nodes1[p];
        }
        free(nodes1);
    }
    inOrder(root);
    // printf("\n%d",sum_tree(root));

    return 0;
}