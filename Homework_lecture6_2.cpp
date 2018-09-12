//Alexander Zhigunov
//Programming language: C++

/*
2. ���������� ���������, ����������� �������� ������ ������.
�) �������� � ���� ����� ������ ���������� ���������;
�) ����������� ����� � �������� ������ ������;
�) *�������� � ��������� ��������� ��������� ������ � ������� ������� ����� ���������
�� ������ ����� ��������� ������, ����� ������� �������� ������.
*/

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>



typedef int T;
typedef struct Node {
 T data;
 struct Node *left;
 struct Node *right;
 struct Node *parent;
} Node;
// ���������� ��������� ������ � ���� ��������� ������
void printTree(Node *root) {
 if (root)
 {
 printf("%d",root->data);
 if (root->left || root->right)
 {
 printf("(");



 if (root->left)
 printTree(root->left);
 else
 printf("NULL");
 printf(",");



 if (root->right)
 printTree(root->right);
 else
 printf("NULL");
  printf(")");
 }
 }
}



// �������� ������ ����
Node* getFreeNode(T value, Node *parent) {
 Node* tmp = (Node*) malloc(sizeof(Node));
 tmp->left = tmp->right = NULL;
 tmp->data = value;
 tmp->parent = parent;
 return tmp;
}



// ������� ����
void insert(Node **head, int value) {
 Node *tmp = NULL;
 if (*head == NULL)
 {
 *head = getFreeNode(value, NULL);
 return;
 }



 tmp = *head;
 while (tmp)
 {
 if (value> tmp->data)
 {
 if (tmp->right)
 {
 tmp = tmp->right;
 continue;
 }
 else
 {
 tmp->right = getFreeNode(value, tmp);
 return;
 }
 }
 else if (value< tmp->data)
 {
 if (tmp->left)
 {
 tmp = tmp->left;
 continue;
 }
 else
 {
 tmp->left = getFreeNode(value, tmp);
 return;
 }
 }
 else
 {
 exit(2); // ������ ��������� �����������
 }
 }
}

void preOrderTravers(Node* root) {
 if (root) {
 printf("%d ", root->data);
 preOrderTravers(root->left);
 preOrderTravers(root->right);
 }
}

//��� � �������������������
void preOrderTravers1(Node* root) {
 if (root) {
 preOrderTravers(root->left);
 printf("%d ", root->data);
 preOrderTravers(root->right);
 }
}

//��� � �������������������
void preOrderTravers2(Node* root) {
 if (root) {
 preOrderTravers(root->left);
 preOrderTravers(root->right);
 printf("%d ", root->data);
 }
}

//����� � �������� ������
Node* findval(Node* root, T value) {
 if (root == NULL || value == root->data)
     return root;
 if (value < root->data)
     return findval(root->left, value);
 else
     return findval(root->right, value);
}

int main()
{
 Node *Tree = NULL;
 char s[100];
 printf("Please, enter file name: ");
 scanf("%s", s);
 FILE* file = fopen(s, "r");
 if (file == NULL)
 {
 puts("Can't open file!");
 exit(1);
 }
 int count;
 fscanf(file, "%d", &count); // ��������� ���������� �������
 int i;
 for(i = 0; i < count; i++)
 {
 int value;
 fscanf(file, "%d", &value);
 insert(&Tree, value);
 }
 fclose(file);
 printTree(Tree);
 unsigned int m=0;
 printf("please, enter method (1-2-3):");
 scanf("%i", m);
 switch (m)
        {
            case 1:
                printf("\nPreOrderTravers:");
                preOrderTravers(Tree);
                break;
            case 2:
                printf("\nPreOrderTravers1:");
                preOrderTravers1(Tree);
                break;
            case 3:
                printf("\nPreOrderTravers2:");
                preOrderTravers2(Tree);
                break;
            default:
                printf ( "Wrong selected\n" );
        }





 return 0;
}
