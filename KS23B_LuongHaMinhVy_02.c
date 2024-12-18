#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void insertHead(Node **head, int data)
{
    Node *newNode = createNode(data);
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    newNode->next = *head;
    (*head)->prev = newNode;
    *head = newNode;
}

void insertEnd(Node **head, int data)
{
    Node *newNode = createNode(data);
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    Node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void insertTo(Node **head, int data, int pos)
{
    if (pos < 0)
    {
        printf("Vi tri khong hop le.\n");
        return;
    }
    if (*head == NULL || pos == 0)
    {
        insertHead(head, data);
        return;
    }

    Node *temp = *head;
    for (int i = 0; i < pos - 1; i++)
    {
        if (temp->next == NULL)
        {
            break;
        }
        temp = temp->next;
    }

    Node *newNode = createNode(data);
    newNode->next = temp->next;
    if (temp->next != NULL)
    {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void deleteHead(Node **head)
{
    if (*head == NULL)
    {
        printf("Danh sach rong.\n");
        return;
    }
    Node *temp = *head;
    *head = (*head)->next;
    if (*head != NULL)
    {
        (*head)->prev = NULL;
    }
}

void deleteEnd(Node *head)
{
    if (head == NULL)
    {
        printf("Danh sach rong.\n");
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    if (temp->prev != NULL)
    {
        temp->prev->next = NULL;
    }
}

void displayForward(Node *head)
{
    if (head == NULL)
    {
        printf("Danh sach rong.\n");
        return;
    }
    Node *temp = head;
    printf("NULL ");
    while (temp != NULL)
    {
        printf("<-> %d ", temp->data);
        temp = temp->next;
    }
    printf("<-> NULL\n");
}

void deleteByValue(Node **head, int value)
{
    if (*head == NULL)
    {
        printf("Danh sach rong.\n");
        return;
    }
    Node *temp = *head;
    while (temp != NULL)
    {
        if (temp->data == value)
        {
            if (temp == *head)
            {
                *head = temp->next;
                if (*head != NULL)
                {
                    (*head)->prev = NULL;
                }
            }
            else
            {
                if (temp->prev != NULL)
                {
                    temp->prev->next = temp->next;
                }
                if (temp->next != NULL)
                {
                    temp->next->prev = temp->prev;
                }
            }
            printf("Da xoa phan tu co gia tri %d.\n", value);
            return;
        }
        temp = temp->next;
    }
    printf("Khong tim thay gia tri %d trong danh sach.\n", value);
}

void displayBackward(Node *head)
{
    if (head == NULL)
    {
        printf("Danh sach rong.\n");
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    printf("NULL ");
    while (temp != NULL)
    {
        printf("<-> %d ", temp->data);
        temp = temp->prev;
    }
    printf("<-> NULL\n");
}

int main()
{
    Node *head = NULL;
    int value, pos;
    do
    {
        printf("------------ Menu -----------\n");
        printf("1. Them phan tu vao dau danh sach\n");
        printf("2. Them phan tu vao cuoi danh sach\n");
        printf("3. Chen phan tu vao vi tri cu the\n");
        printf("4. Xoa phan tu vao dau danh sach\n");
        printf("5. Xoa phan tu vao cuoi danh sach\n");
        printf("6. Xoa phan tu theo gia tri\n");
        printf("7. Duyet danh sach tu dau den cuoi\n");
        printf("8. Duyet danh sach tu cuoi len dau\n");
        printf("9. Thoat\n");
        int choice;
        printf("Moi ban nhap: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Nhap gia tri them dau: ");
            scanf("%d", &value);
            insertHead(&head, value);
            break;
        case 2:
            printf("Nhap gia tri them cuoi: ");
            scanf("%d", &value);
            insertEnd(&head, value);
            break;
        case 3:
            printf("Nhap gia tri chen: ");
            scanf("%d", &value);
            printf("Nhap vi tri chen: ");
            scanf("%d", &pos);
            insertTo(&head, value, pos);
            break;
        case 4:
            deleteHead(&head);
            break;
        case 5:
            deleteEnd(head);
            break;
        case 6:
            printf("Nhap gia tri can xoa: ");
            scanf("%d", &value);
            deleteByValue(&head, value);
            break;
        case 7:
            printf("Danh sach lien ket: ");
            displayForward(head);
            break;
        case 8:
            printf("Danh sach lien ket: ");
            displayBackward(head);
            break;
        case 9:
            printf("Hen gap lai.\n");
            exit(0);
        default:
            printf("Vui long chon lai.\n");
            break;
        }
    } while (1);
    return 0;
}
