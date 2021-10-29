#include <iostream>
#include <stdlib.h>
using namespace std;

//Node
struct Node {
public:
    int data; //skaicius

    struct Node* next;
};

//menu
void Menu_content()
{
    system("cls");
    cout << "-------------------------------------" << endl;
    cout << "Choose the wanted function:" << endl;
    cout << "-------------------------------------" << endl;
    cout << "[1] - View list" << endl;
    cout << "[2] - Add new number (front)" << endl;
    cout << "[3] - Delete last added" << endl;
    cout << "[4] - Cout list, then delete list" << endl;
    cout << "[5] - Sort list (descending)" << endl;
    cout << "[6] - Sort list (ascending)" << endl;
    cout << "[7] - Search for X number" << endl;
    cout << "[8] - Display list size" << endl;
    cout << "" << endl;
    cout << "[0] To close the program select this option" << endl; \
    cout << "-------------------------------------" << endl;
    cout << "Your choise: ";
}
void Menu(int* pas)
{
    char lpas;
    Menu_content();

    do
    {
        lpas = getchar();
        if ((isdigit(lpas) == false) && (lpas != '\n'))
        {
            cout << "You must enter the number (1, 2, 3...)" << endl;
            cout << "Please try again:" << endl;
            Menu_content();
        }

    } while (isdigit((unsigned char)lpas) == false);
    *pas = (int)lpas - '0';
}
void leave() {
    cout << endl;
    cout << endl;
    system("pause");
}

//functions
int cinInt() {
    int a = 0;
    cin >> a;
    return a;
}
int calcSize(struct Node* node) {
    int size = 0;
    while (node != NULL)
    {
        size++;
        node = node->next;
    }
    return size;
}
struct Node* swap(struct Node* ptr1, struct Node* ptr2)
{
    struct Node* tmp = ptr2->next;
    ptr2->next = ptr1;
    ptr1->next = tmp;
    return ptr2;
}
void addToFirst(struct Node** head, int node_data) {

    struct Node* newNode = new Node;
    newNode->data = node_data;
    newNode->next = (*head);
    (*head) = newNode;
}
void deleteFirst(struct Node** head) {

    if ((*head) == NULL) {
        cout << "theres no list" << endl;
        return;
    }

    struct Node* del = *head;
    struct Node* last = *head;

    del = last;
    (*head) = last->next; //  ->head
    delete del;

}
void displayList(struct Node* node) {

    if (node == NULL) {
        cout << "null";
        return;
    }
    while (node != NULL)
    {
        cout << node->data;
        cout << " ";
        node = node->next;
    }

    if (node == NULL)
        cout << "null" << endl;
}
void coutAndDelList(struct Node** head) {

    struct Node* del = *head; //pazymejimas kas bus trinama
    struct Node* last = *head; //dabar esama vieta


    while (last != NULL)
    {
        cout << last->data << "-->";
        del = last;
        last = last->next;
        delete del;
    }

    if (last == NULL)
        (*head) = last;
    cout << "null";
    cout << "" << endl;
    cout << "list deleted" << endl;
}
void sortAscending(struct Node** head, int count)
{
    struct Node** h;
    int i, j, swapped;

    for (i = 0; i <= count; i++)
    {

        h = head;
        swapped = 0;

        for (j = 0; j < count - i - 1; j++)
        {

            struct Node* p1 = *h;
            struct Node* p2 = p1->next;

            if (p1->data > p2->data)
            {

                /* update the link after swapping */
                *h = swap(p1, p2);
                swapped = 1;
            }

            h = &(*h)->next;
        }

        /* break if the loop ended without any swap */
        if (swapped == 0)
            break;
    }
}
void sortDescending(struct Node** head, int count) {
    struct Node** h;
    int i, j, swapped;

    for (i = 0; i <= count; i++)
    {

        h = head;
        swapped = 0;

        for (j = 0; j < count - i - 1; j++)
        {

            struct Node* p1 = *h;
            struct Node* p2 = p1->next;

            if (p1->data < p2->data)
            {

                /* update the link after swapping */
                *h = swap(p1, p2);
                swapped = 1;
            }

            h = &(*h)->next;
        }

        /* break if the loop ended without any swap */
        if (swapped == 0)
            break;
    }

}
void searchFor(struct Node* node, int a) {
    if (node == NULL) {
        cout << "List is empty";
        return;
    }
    while (node != NULL)
    {
        if (a == node->data) {
            cout << a << " is in the list!";
            break;
        }

        node = node->next;
    }

    if (node == NULL)
        cout << a << " is not in list." << endl;
}

//start
void startProgram() {
    int i, pas, data = 0;
    string sname;
    struct Node* head = NULL;

    int arr[6] = { 78, 20, 10, 32, 1, 5 };
    for (i = 0; i < 6; i++)
        addToFirst(&head, arr[i]);

    do
    {
        Menu(&pas);
        switch (pas)
        {
        case 1:
            system("cls");

            cout << "List:" << endl;
            displayList(head);

            leave();
            break;
        case 2:
            system("cls");

            cout << "Number: ";
            cin >> data;
            addToFirst(&head, data);

            leave();
            break;
        case 3:
            system("cls");

            deleteFirst(&head);
            cout << "Deleted last added number" << endl;

            leave();
            break;
        case 4:
            system("cls");

            cout << "List & deletion of list" << endl;
            coutAndDelList(&head);

            leave();
            break;
        case 5: //[5] - Sort list (descending)" << endl;
            system("cls");

            cout << "List sorted (descending)" << endl;
            sortDescending(&head, calcSize(head));

            leave();
            break;
        case 6: //[6] - Sort list (ascending)" << endl;
            system("cls");
            cout << "List sorted (ascending)" << endl;
            sortAscending(&head, calcSize(head));

            leave();
            break;
        case 7: //[7] - Search for X" << endl;
            system("cls");

            cout << "Search for: ";
            searchFor(head, cinInt());

            leave();
            break;
        case 8:
            system("cls");

            cout << "Size of the list: " << calcSize(head);
            leave();
            break;
        case 0:
            system("cls");
            cout << "Selected the fifth option, bye bye" << endl;
            cout << endl;
            break;
        default:
            system("cls");
            cout << "Selected option is not valid please select again" << endl;
            leave();

            break;
        }
    } while (pas != 0);
}

int main()
{
    /*
    By default numbers in list:
    5 1 32 10 20 78
    */

    startProgram();
}