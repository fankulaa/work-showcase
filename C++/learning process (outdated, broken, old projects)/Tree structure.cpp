#include <iostream>
using namespace std;

/*
Test:
37 24 42 7 32 40 42 2 35 120
*/

//------------------MENU------------------

void Menu_content()
{
    cout << endl;
    cout << endl;
    cout << "System name: Binary tree" << endl;
    cout << "-------------------------------------" << endl;
    cout << "Choose the wanted function:" << endl;
    cout << "-------------------------------------" << endl;
    cout << "[1] - Print tree" << endl;
    cout << "[2] - Add tree branch" << endl;
    cout << "[3] - Search number in tree" << endl;
    cout << "[4] - Delete tree" << endl;
    cout << "[5] - Tree element count" << endl;
    cout << "[6] - Check if tree structure is correct" << endl;
    cout << "[8] - Run test version of a tree (coppy from main)" << endl;
    cout << "[9] - To close the program select this option" << endl;
    cout << "Input: ";
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

//------------------PROJECT------------------

//Structure
struct Tree {
    int data;
    struct Tree* left;
    struct Tree* right;

    Tree(int value)
    {
        data = value;

        left = NULL;
        right = NULL;
    }
};

//Put into tree - HOW THE FUCK DO I DO THIS?? - ...WOAH IT ACTUALLY WORKS!...
void putIntoTree(struct Tree* root, int a) {

    struct Tree* temp = root;
    while(temp != NULL){
        if (temp->data == a) { //QUIT ON DETECTING SAME DATA
            return;
        }
        if (temp->data > a){
            if (temp->left == NULL) {
                temp->left = new Tree(a);
                return;
            }
            else {
                temp = temp->left;
            }
        }
        else {
            if (temp ->right == NULL) {
                temp->right = new Tree(a);
                return;
            }
            else {
                temp = temp->right;
            }
        }
    }

}

//root input - WORKS
void firstNumberCin(struct Tree* root, int x) {
    cout << "(Duplicates will be merged)" << endl;
    cout << "Input number 1-" << x << ":" << endl;
    int a;
loop:
    cin >> a;

    if (a < 1 || a>x) {
        cout << "Wrong number, try again;" << endl;
        goto loop;
    }

    root->data = a;
    //cout <<"Root number: "<< root->data << endl;
}

//imputing numbers - WORKS
void numberCin(struct Tree* root,int x) {
    cout << "(Duplicates will be merged)" << endl;
    cout << "Input number 1-" << x << ":" << endl;
    int a;
loop:
    cin >> a;

    if (a < 1 || a>x) {
        cout << "Wrong number, try again;" << endl;
        goto loop;
    }
    putIntoTree(root, a);
}

//displays list (vidinis) - WORKS = Reference Used: https://www.youtube.com/watch?v=z0FDBGbf42Q&ab_channel=PaulProgramming
void printInOrder(Tree* Ptr) {

    if (Ptr != NULL && Ptr->data != 0) { // If list is not empty
        if (Ptr->left != NULL) {
            printInOrder(Ptr->left);
        }
        cout << Ptr->data << " ";
        if (Ptr->right != NULL) {
            printInOrder(Ptr->right);
        }
    }
    else {
        cout << "Tree is empty" << endl;
    }
}

//displays list in preorder (tiesioginis) - WORKS
void printPreOrder(Tree* Ptr) {

    if (Ptr != NULL && Ptr->data != 0) { // If list is not empty
        cout << Ptr->data << " ";
        if (Ptr->left != NULL) {
            printInOrder(Ptr->left);
        }
        if (Ptr->right != NULL) {
            printInOrder(Ptr->right);
        }
    }
    else {
        cout << "Tree is empty" << endl;
    }
}

//displays list in postorder (atvirkstinis) - WORKS
void printPostOrder(Tree* Ptr) {

    if (Ptr != NULL && Ptr->data != 0) { // If list is not empty
        if (Ptr->left != NULL) {
            printInOrder(Ptr->left);
        }
        if (Ptr->right != NULL) {
            printInOrder(Ptr->right);
        }
        cout << Ptr->data << " ";
    }
    else {
        cout << "Tree is empty" << endl;
    }
}

//searchForNumber sub function = searches for specific number and says if its not in list - WORKS, even tho works abusing bug
bool searchForNoNumber(Tree* Ptr, int a) {
    if (Ptr != NULL && Ptr->data != 0) { // If list is not empty
        if (Ptr->data == a) {
            return false;
        }
        if (Ptr->left != NULL) {
            searchForNoNumber(Ptr->left, a);
        }
        if (Ptr->right != NULL) {
            searchForNoNumber(Ptr->right, a);
        }
    }
}

//search for specific number and say if its in a list - WORKS
void searchForNumber(Tree* Ptr,int a) {

    bool a1 = 0;
    a1 = searchForNoNumber(Ptr, a);

    if ( a1 == 0) {
        cout << a << " is in list" << endl;
    }
    else {
        cout << a << " is not list" << endl;
    }
}

//deleteTree sub function = sets root to 0 - WORKS
void resetRoot(Tree* Ptr) {
    Ptr->data = 0;
}

//deletes whole tree - WORKS
void deleteTree(Tree* Ptr, Tree* Ptr2) {

    if (Ptr != NULL && Ptr->data != 0) { // If list is not empty
        if (Ptr->left != NULL) {
            deleteTree(Ptr->left, Ptr2);
        }
        if (Ptr->right != NULL) {
            deleteTree(Ptr->right, Ptr2);
        }
        if (Ptr == Ptr2) {
            Ptr->left = null;
            Ptr->right = null;
            resetRoot(Ptr);
            return;
        }
        delete Ptr;
    }
}

//counts tree elements - WORKS
int coutTreeElements(Tree* Ptr, int size) {
    if (Ptr != NULL && Ptr->data != 0) { // If list is not empty
        if (Ptr->left != NULL) {
            size = coutTreeElements(Ptr->left, size);
        }
        size++;
        if (Ptr->right != NULL) {
            size = coutTreeElements(Ptr->right, size);
        }
        return size;
    }
    else {
        cout << "Tree is empty" << endl;
    }
}

//Check if tree structure is correct- WORKS
//code - https://www.geeksforgeeks.org/a-program-to-check-if-a-binary-tree-is-bst-or-not/
int checkTreeScructure(Tree * node, int min, int max)
    {
        /* an empty tree is BST */
        if (node == NULL)
            return 1;

        /* false if this node violates
        the min/max constraint */
        if (node->data < min || node->data > max)
            return 0;

        /* otherwise check the subtrees recursively,
        tightening the min or max constraint */
        return
            checkTreeScructure(node->left, min, node->data - 1) && // Allow only distinct values
            checkTreeScructure(node->right, node->data + 1, max); // Allow only distinct values
    }

int main()
{
    /*
    Test:
    37 24 42 7 32 40 42 2 35 120
    */
    
    int x = 1000; //max input number
    int n = 9; //tree size for test tree (+1 because root already created)
    int print = 0; //Print options
    int check_if_first = 0; //keeping in check if root is created
    int pas; //Number that indicates what option you pick
    struct Tree* root = new Tree(0); //root created

    do
    {
        Menu(&pas);
        switch (pas)
        {
        case 1: //Print tree
            cout << endl;
            printing:
            cout << "1 - print in order, 2 - print post order, 3 - print pre order" << endl;
            cout << "Input: ";
            cin >> print;
            if (print == 1) {
                cout << "Tree print in order: ";
                printInOrder(root);
            }
            else if(print == 2) {
                cout << "Tree print post order: ";
                printPostOrder(root);
            }
            else if (print == 3) {
                cout << "Tree print pre order: ";
                printPreOrder(root);

            }
            else {
                cout << "Wrong number, try again:" << endl;
            goto printing;
            }
            break;
        case 2: //Add tree branch

            if (check_if_first == 0) {
                firstNumberCin(root, x);
                check_if_first++;
            }
            else if (check_if_first >0){
                numberCin(root, x);
            }
            break;
        case 3: //Search number in tree
            cout << endl;
            for (int i = 0; i < 1; i++){
                cout << "Input number 1-" << x << ":" << endl;
                int a;
            loop:
                cin >> a;

                if (a < 1 || a>x) {
                    cout << "Wrong number, try again;" << endl;
                    goto loop;
                }
                searchForNumber(root, a);
            }
            break;
        case 4: //Delete tree
             deleteTree(root, root);
             check_if_first = 0;
             cout << "Tree has been deleted" << endl;
            break;
        case 5: //Tree element count
            cout << "Tree element count: " << coutTreeElements(root, 0) << endl;
            break;
        case 6: //Check if tree structure is correct
            if (checkTreeScructure(root, 0, 0) == 0) {
                cout << "Structure is correct" << endl;
            }
            else {
                cout << "Structure is incorrect" << endl;
            }
            break;
        case 8: //Run test version of a tree (coppy from main)
            //root number cin
            firstNumberCin(root, x);
            //branches number cin
            for (int i = 0; i < n; i++) {
                numberCin(root, x);
            }
            cout << endl;
            //Tree print in order
            cout << "Tree print in order: ";
            printInOrder(root);
            cout << endl;
            //search for number
            searchForNumber(root,402);
            //Tree element count
            cout << "Tree element count: " << coutTreeElements(root, 0) << endl;
            //Check tree structure
            if (checkTreeScructure(root, 0, 0) == 0) {
                cout << "Structure is correct" << endl;
            }
            else {
                cout << "Structure is incorrect" << endl;
            }
            //deletion of tree
            deleteTree(root, root);
            check_if_first = 0;
            //end
            break;
        case 9: //To close the program select this option
            cout << "Selected the ninth option, bye bye" << endl;
            break;
        default:
            cout << "Selected option is not valid please select again" << endl;
            break;
        }
    } while (pas != 9);

    return 0;
}

