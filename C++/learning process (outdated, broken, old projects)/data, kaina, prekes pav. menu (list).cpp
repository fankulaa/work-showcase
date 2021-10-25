#include <iostream>
#include <stdlib.h>

using namespace std;


struct Node {
public:
    int data; //galiojimo pasibaigimas
    double data2; //prekes kaina
    string data3; //pavadinimas

    struct Node* next;
};

//done
void addToFirst(struct Node** head, int node_data, double node_data2, string node_data3) {

    struct Node* newNode = new Node;
    newNode->data = node_data;
    newNode->data2 = node_data2;
    newNode->data3 = node_data3;
    newNode->next = (*head);
    (*head) = newNode;
}

//unused
void addAfterSelectedNode(struct Node* prev_node, int node_data) {

    if (prev_node == NULL) {
        cout << "the given previous node is required,cannot be NULL";
    }
    struct Node* newNode = new Node;
    newNode->data = node_data;
    newNode->next = prev_node->next;
    prev_node->next = newNode;

}

//unsused
void addToLast(struct Node** head, int node_data) {

    struct Node* newNode = new Node;
    struct Node* last = *head;

    newNode->data = node_data;
    newNode->next = NULL;

    if (*head == NULL) {

        *head = newNode;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = newNode;

}

//done
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

//done
void displayList(struct Node* node) {

    if (node == NULL) {
        cout << "null";
        return;
    }
    while (node != NULL)
    {
        cout << node->data << " ";
        cout << node->data2 << " ";
        cout << node->data3;
        cout << "-->";
        node = node->next;

        /*
        if (node->null) {
            cout << node->data << " ";
            cout << node->data2 << " ";
            cout << node->data3;
            cout << "-->";

            return 0;
        }
        */
    }

    if (node == NULL)
        cout << "null" << endl;
}

//unused
void searchFor(struct Node** head, string node_data) {

    struct Node* newNode = new Node;
    struct Node* last = *head;

    newNode->data3 = node_data;
    //cout<<"newnode data: "<<newNode->data<<endl;


    //jaigu pirmam nieko nera, baigti funkcija
    if (*head == NULL) {
        cout << "empty list" << endl;
        return;
    }

    if (last->data3 == newNode->data3) {
        cout << "Preke " << last->data3 << " yra duomenu strukturoje" << endl;
        return;
    }

    while (last->data3 != newNode->data3) {

        last = last->next;

        if (last->data3 == newNode->data3) {
            cout << "Preke " << last->data3 << " yra duomenu strukturoje" << endl;
            return;
        }
        if (last->next == NULL) {
            cout << "Preke " << newNode->data3 << " nera duomenu strukturoje" << endl;
            return;
        }
    }


}

//needs change
void coutAndDelList(struct Node** head) {

    struct Node* del = *head; //pazymejimas kas bus trinama
    struct Node* last = *head; //dabar esama vieta


    while (last != NULL)
    {
        cout << last->data<<" " <<last->data2<<" "<<last->data3<< "-->";
        del = last;
        last = last->next;
        delete del;
    }

    if (last == NULL)
        (*head)=last;
        cout << "null";
    cout << "" << endl;
    cout << "list deleted" << endl;
}

void Menu(int* pas);
void Menu_content();

int main()
{
    int pas, data = 0;
    double data2 = 0;
    string data3, sname;
    struct Node* head = NULL;

    /*
        addToFirst(&head, 1);
        addToFirst(&head, 7);
        addToFirst(&head, 9);
        addToLast(&head, 4);
        //addAfterSelectedNode(head->next->next, 9);

        cout<<"pre del: "<<endl;
        searchFor(&head, 9);
        displayList(head);
        cout<<""<<endl;

        //coutAndDelList(&head);
        coutAndDelList(&head);

        cout<<""<<endl;cout<<""<<endl;
        cout<<"Final  : "<<endl;
        //searchFor(&head, 9);
        //displayList(head);
        cout<<""<<endl;
    */
    do
    {
        Menu(&pas);
        switch (pas)
        {
        case 0:
            cout << "" << endl;
            cout << "List:" << endl;
            displayList(head);
            cout <<""<< endl;
            break;
        case 1:
            cout << "" << endl;
            cout << "Write new product and add it to list" << endl;
            cout << "Prekes pavadinimas: ";
            cin >> data3;
            cout << "Prekes kaina: ";
            cin >> data2;
            cout << "Galiojimo data (betarpo): ";
            cin >> data;


            addToFirst(&head, data, data2, data3);
            cout << endl;
            break;
        case 2:
            cout << "" << endl;
            deleteFirst(&head);
            cout << "Deleted last added" << endl;
            cout << endl;
            break;
        case 3:
            cout << "List & deletion of list" << endl;
            coutAndDelList(&head);
            cout << endl;
            break;
        case 4:
            cout << "Input product name you want to find: ";
            cin >> sname;
            searchFor(&head, sname);
            cout << endl;
            break;
        case 5:
            cout << "Selected the fifth option, bye bye" << endl;
            cout << endl;
            break;
        default:
            cout << "Selected option is not valid please select again" << endl;
            cout << endl;
            break;
        }
        //system("CLS"); Clear control panel
    } while (pas != 5);

    return 0;
}


//menu functions






void Menu_content()
{
    cout << "System name: Node" << endl;
    cout << "-------------------------------------" << endl;
    cout << "Choose the wanted function:" << endl;
    cout << "-------------------------------------" << endl;
    cout << "[0] - View product list" << endl;
    cout << "[1] - Add new product" << endl;
    cout << "[2] - Delete last added product" << endl;
    cout << "[3] - Cout product list, then delete list" << endl;
    cout << "[4] - Search for product (name)" << endl;
    cout << "[5] To close the program select this option" << endl; \
    cout << "" << endl;
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

/*
void deleteAllRequestedNodeValues(struct Node**head, int node_data){

    struct Node *newNode = new Node;
    struct Node *last =*head;
    struct Node *prev =*head;
    struct Node *del =*head;
    newNode->data=node_data;
    newNode->next = NULL;

    //jaigu pirmam nieko nera, baigti funkcija
    if(last == NULL){
        cout<<"empty list"<<endl;
        return;
    }



    while (last->next->data == newNode->data){

        del= last->next;

        last->next=last->next->next;

        delete last->next;
    }

    if(last->data == newNode->data){
        cout<<"\n say yes"<<endl;

        del = last;
        (*head)=last->next;
        delete del;
    }

    last=last->next;

    //Rodo i kita (praleidzia kita, delto reikia virsuj esancio kodo)
    while (last->next != NULL){

        last=last->next;
        prev=prev->next;

        cout<<"test"<<endl;
        if(last->data==newNode->data){

                del=last;

                last=last->next;
                prev->next=last;

                delete del;
            return;
        }


    }
    delete newNode;

}
*/
