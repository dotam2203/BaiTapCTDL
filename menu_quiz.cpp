#include <cstdlib>
#include <iostream>
using namespace std;

//========================= Struct =====================
struct node {
    int data;
    node *pLeft;
    node *pRight;
};
typedef struct node NODE;
typedef NODE *TREE;
//======================================================
int getNumberMax(int a, int b, int c);
void menuStack();
void menuQueue();
void menuTree();
void inArrTree(int x, int a[100]);
void outArrTree(int x, int a[100]);
void inputArray(int n, int a[]);
void outputArray(int n, int a[]);
void initTree(TREE &t);
void addNodeTree(TREE &t, int x);
void traversalNLR(TREE t);
void traversalLNR(TREE t);
void traversalLRN(TREE t);
NODE *searchTrees(TREE t, int x);
//=======================================================

void inArrTree(int x, int a[100]) {
    for (int i = 0; i < 100; i++) {
        a[i] = x;
    }
}

void outArrTree(int a[100]) {
    cout << "Danh sach phan tu nhap vao: ";
    for (int i = 0; i < 100; i++) {
        cout << a[i] << "  ";
    }
}
void menuQueue() {
    int choice;
    do {
        // hien thi menu stack
        system("cls");
        cout << "\t\tMenu Queue:\n";
        cout << "Moi ban chon phep toan voi DS LKD:\n";
        cout << "1. Kiem tra Queue rong\n";
        cout << "2. Them phan tu vao Queue\n";
        cout << "3. Xoa phan tu trong Queue\n";
        cout << "4. Xuat Queue\n";
        cout << "0. Quay lai menu chinh.\n";
        cout << "===========================\n";
        cout << "Ban chon: ";
        cin >> choice;
        cout << "===========================\n";
        switch (choice) {
            case 1: {
                break;
            }
            case 2: {
                break;
            }
            case 3: {
                break;
            }
            case 4: {
                break;
            }
            case 0: {  // thoat chuong trinh
                break;
            }
            default: {
                cout << "Chuc nang khong hop le. Vui long chon lai!\n";
                system("pause");
                break;
            }
        }
        if (choice > 0) {
            cout << endl;
            system("pause");
        }
    } while (choice != 0);
}
void menuTree(TREE &t) {
    int choice;
    int n = 100, arr[n];
    do {
        // hien thi menu tree
        system("cls");
        cout << "\t\tMenu TREE:\n";
        cout << "1. Nhap du lieu cay:\n";
        cout << "2. Duyet cay: NLR.\n";
        cout << "3. Duyet cay: LNR.\n";
        cout << "4. Duyet cay: LRN.\n";
        cout << "5. Tim kiem cay nhi phan.\n";
        cout << "6. Xoa phan tu bat ki trong cay.\n";
        cout << "0. Quay lai menu chinh.\n";
        cout << "===========================\n";
        cout << "Ban chon: ";
        cin >> choice;
        cout << "===========================\n";
        switch (choice) {
            case 1: {
                int x;
                cout << "Nhap so nguyen x = ";
                cin >> x;
                // inArrTree(x, arr);
                addNodeTree(t, x);
                break;
            }
            case 2: {
                // outArrTree(arr);
                cout << "\nDuyet N-L-R: ";
                traversalNLR(t);
                break;
            }
            case 3: {
                // outArrTree(arr);
                cout << "\nDuyet L-N-R: ";
                traversalLNR(t);
                break;
            }
            case 4: {
                // outArrTree(arr);
                cout << "\nDuyet L-R-N: ";
                traversalLRN(t);
                break;
            }
            case 5: {
                int x;
                cout << "Nhap so nguyen can tim kiem: ";
                cin >> x;
                NODE *p = searchTree(t, x);
                if (p == NULL)
                    cout << "\n" << x << " khong ton tai!";
                else
                    cout << "\n" << x << " co ton tai!";
                break;
            }
            case 0: {  // thoat chuong trinh
                break;
            }
            default: {
                cout << "Chuc nang khong hop le. Vui long chon lai!\n";
                system("pause");
                break;
            }
        }
        if (choice > 1) {
            cout << endl;
            system("pause");
        }
    } while (choice != 0);
}
void setNumberMax(int a, int b, int c) {
    cout << "Input numbers\nNumber a, b, c = ";
    cin >> a >> b >> c;
    cout << "Max = " << getNumberMax(a, b, c) << endl;
}
int getNumberMax(int a, int b, int c) {
    int max = a;
    if (max < b) max = b;
    if (max < c) max = c;
    return max;
}

void inputArray(int n, int a[]) {
    for (int i = 0; i < n; i++) {
        cout << "Nhap phan tu thu " << i + 1 << ": ";
        cin >> a[i];
    }
}

void outputArray(int n, int a[]) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            count++;
        }
    }
    cout << "So phan tu chan trong mang: " << count << endl;
    cout << "So phan tu le trong mang: " << n - count << endl << endl;
}
void initTree(TREE &t) { t = NULL; }
void addNodeTree(TREE &t, int x) {
    NODE *p = new NODE;
    if (t == NULL) {
        p->data = x;
        p->pLeft = NULL;
        p->pRight = NULL;
        t = p;
    } else {
        if (t->data > x)
            addNodeTree(t->pLeft, x);
        else if (t->data < x)
            addNodeTree(t->pRight, x);
    }
}
void traversalNLR(TREE t) {
    if (t != NULL) {
        cout << t->data << "  ";
        traversalNLR(t->pLeft);
        traversalNLR(t->pRight);
    }
}
void traversalLNR(TREE t) {
    if (t != NULL) {
        traversalLNR(t->pLeft);
        cout << t->data << "  ";
        traversalLNR(t->pRight);
    }
}
void traversalLRN(TREE t) {
    if (t != NULL) {
        traversalLRN(t->pLeft);
        traversalLRN(t->pRight);
        cout << t->data << "  ";
    }
}
NODE *searchTree(TREE t, int x) {
    if (t == NULL)
        return NULL;
    else {
        if (t->data > x)
            searchTree(t->pLeft, x);
        else if (t->data < x)
            searchTree(t->pRight, x);
        else
            return t;
    }
}

int main() {
    int choice;
    TREE t;
    do {
        //   hien thi menu
        system("cls");
        cout << "\n\n\n\t\t\tMENU:\n";
        cout << "1. Tim so lon nhat trong 3 so.\n";
        cout << "2. Dem so chan/le trong mang 10 so nguyen.\n";
        cout << "3. Kiem tra x co ton tai trong mang n phan tu hay khong?\n";
        cout << "4. Sap xep mang su dung Selection Sort.\n";
        cout << "5. Sap xep mang su dung Insertion Sort.\n";
        cout << "6. Sap xep mang su dung Bubble Sort.\n";
        cout << "\n\t\tBT DANH SACH LIEN KET\n";
        cout << "7. Tao 2 DSLK (khong pha huy DSKL goc) chua so chan/le "
                "cua ds da cho.\n";
        cout << "8. Them - Sua - Xoa nut K trong DSLK.\n";
        cout << "9. Stack.\n";
        cout << "10. Queue.\n";
        cout << "11.\t\tBT CAY NHI PHAN\n";
        cout << "0. Thoat chuong trinh\n";
        cout << "===========================\n";
        cout << "Chon chuc nang (1-11): ";
        cin >> choice;
        cout << "===========================\n";

        // xu ly lua chon
        switch (choice) {
            case 1: {
                int a, b, c;
                setNumberMax(a, b, c);
                cout << endl;
                break;
            }
            case 2: {
                int n = 10, arr[n];
                inputArray(n, arr);
                outputArray(n, arr);
                break;
            }
            case 3: {
                break;
            }
            case 4: {
                break;
            }
            case 5: {
                break;
            }
            case 6: {
                break;
            }
            case 7: {
                break;
            }
            case 8: {
                break;
            }
            case 9: {
                break;
            }
            case 10: {
                menuQueue();
                system("cls");
                break;
            }
            case 11: {
                initTree(t);
                menuTree(t);
                system("cls");
                break;
            }
            case 0: {  // thoat chuong trinh
                break;
            }
            default: {
                cout << "Chuc nang khong hop le. Vui long chon lai!\n";
                system("pause");
                break;
            }
        }
        if (choice >= 1 && choice <= 9) {
            cout << endl;
            system("pause");
        }
    } while (choice != 0);
    return 0;
}
