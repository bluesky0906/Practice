#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int key;
    Node *next;
    Node *prev;

    Node()
    {
        this->prev = this;
        this->next = this;
    }
    Node(int key, Node *prev, Node *next)
    {
        this->key = key;
        this->prev = prev;
        this->next = next;
    }
};

class DoublyLinkedList
{
public:
    class Node *nil;

    DoublyLinkedList()
    {
        nil = new Node();
    }

    void print_list()
    {
        Node *cur = nil->next;
        while (cur != nil)
        {
            cout << cur->key;
            cur = cur->next;
            if (cur != nil)
                cout << " ";
        }
        cout << endl;
    }

    void insert(int x)
    {
        Node *node = new Node(x, nil, nil->next);
        nil->next->prev = node;
        nil->next = node;
    }

    void delete_node(Node *node)
    {
        if (node == nil)
            return;
        node->next->prev = node->prev;
        node->prev->next = node->next;
        delete (node);
    }

    Node *search(int x)
    {
        Node *cur = nil->next;
        while (cur != nil && cur->key != x)
        {
            cur = cur->next;
        }
        return cur;
    }

    void delete_key(int x)
    {
        delete_node(search(x));
    }

    void delete_first()
    {
        delete_node(nil->next);
    }

    void delete_last()
    {
        delete_node(nil->prev);
    }
};

int main()
{
    DoublyLinkedList *list = new DoublyLinkedList();

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        char order[10];
        int num;
        scanf("%s", order);

        if (order[0] == 'i')
        {
            scanf("%d", &num);
            list->insert(num);
        }
        else if (order[0] == 'd')
        {
            if (strlen(order) > 6)
            {
                if (order[6] == 'F')
                {
                    list->delete_first();
                }
                else if (order[6] == 'L')
                {
                    list->delete_last();
                }
            }
            else
            {
                cin >> num;
                list->delete_key(num);
            }
        }
    }
    list->print_list();
}

// #include <cstdio>
// #include <cstdlib>
// #include <cstring>

// struct node
// {
//     unsigned int key;
//     struct node *next;
//     struct node *prev;
// };

// typedef struct node *NodePointer;

// NodePointer nil;

// NodePointer listSearch(int key)
// {
//     NodePointer cur = nil->next;
//     while (cur != nil && cur->key != key)
//     {
//         cur = cur->next;
//     }
//     return cur;
// }

// void init()
// {
//     nil = (node *)malloc(sizeof(struct node));
//     nil->next = nil;
//     nil->prev = nil;
// }

// void printList()
// {
//     NodePointer cur = nil->next;
//     int isf = 1;
//     while (1)
//     {
//         if (cur == nil)
//             break;
//         if (isf == 0)
//             printf(" ");
//         printf("%d", cur->key);
//         cur = cur->next;
//         isf = 0;
//     }
//     printf("\n");
// }

// void deleteNode(NodePointer t)
// {
//     if (t == nil)
//         return;
//     t->prev->next = t->next;
//     t->next->prev = t->prev;
//     free(t);
// }

// void deleteFirst()
// {
//     NodePointer t = nil->next;
//     if (t == nil)
//         return;
//     deleteNode(t);
// }

// void deleteLast()
// {
//     deleteNode(nil->prev);
// }

// void deleteKey(int key)
// {
//     deleteNode(listSearch(key));
// }

// void insert(int key)
// {
//     NodePointer x;
//     x = (node *)malloc(sizeof(struct node));
//     x->key = key;
//     x->prev = nil;
//     x->next = nil->next;
//     nil->next->prev = x;
//     nil->next = x;
// }

// int main()
// {
//     int key, n, i;
//     int size = 0;
//     char com[20];
//     int np = 0, nd = 0;
//     scanf("%d", &n);
//     init();
//     for (i = 0; i < n; i++)
//     {
//         scanf("%s%d", com, &key);
//         if (com[0] == 'i')
//         {
//             insert(key);
//             np++;
//             size++;
//         }
//         else if (com[0] == 'd')
//         {
//             if (strlen(com) > 6)
//             {
//                 if (com[6] == 'F')
//                     deleteFirst();
//                 else if (com[6] == 'L')
//                     deleteLast();
//             }
//             else
//             {
//                 deleteKey(key);
//                 nd++;
//             }
//             size--;
//         }
//     }

//     printList();
//     return 0;
// }