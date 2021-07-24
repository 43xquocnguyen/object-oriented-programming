#include "vector.h"
#include "matrix.h"
#include <vector>

void Input(vector<Vector *> &listVector, vector<Matrix *> &listMatrix) {
    while (true)
    {
        system("cls");
        cout << "1. NHAP VECTOR\n";
        cout << "2. NHAP MATRIX\n";
        cout << "0. THOAT\n";
        cout << "\nLUA CHON: ";
        char lc;
        cin >> lc;
        cin.ignore();
        system("cls");

        if (lc == '0')
            break;
        else if (lc == '1') {
            Vector *temp = new Vector;
            cin >> *temp;
            listVector.push_back(temp);
            break;
        }
        else if (lc == '2') {
            Matrix *temp = new Matrix;
            cin >> *temp;
            listMatrix.push_back(temp);
            break;
        }
        else {
            cout << "LUA CHON KHONG HOP LE!\n";
        }
        system("pause");
    }
}
void Output(vector<Vector *> listVector, vector<Matrix *> listMatrix) {
    while (true)
    {
        system("cls");
        cout << "1. LIST VECTOR\n";
        cout << "2. LIST MATRIX\n";
        cout << "0. THOAT\n";
        cout << "\nLUA CHON: ";
        char lc;
        cin >> lc;
        cin.ignore();
        system("cls");

        if (lc == '0')
            break;
        else if (lc == '1') {
            int size = listVector.size();
            if (size >= 1) {
                cout << "\t\t\tLIST VECTOR\n";
                for (int i = 0; i < size; i++)
                {
                    cout << (char)(65 + i) << *listVector[i] << endl;
                }
            }
            else {
                cout << "KHONG CO DU LIEU\n";
            }
            break;
        }
        else if (lc == '2') {
            int size = listMatrix.size();
            if (size >= 1) {
                cout << "\t\t\tLIST MATRIX\n\n";
                for (int i = 0; i < size; i++)
                {
                    cout << "\t\tMA TRAN " << i + 1 << endl << endl;
                    cout << *listMatrix[i] << endl;
                }
            }
            else {
                cout << "KHONG CO DU LIEU\n";
            }
            break;
        }
        else {
            cout << "LUA CHON KHONG HOP LE!\n";
        }
        system("pause");
    }
}
void CalVector(vector<Vector *> listVector) {
    if (listVector.size() >= 2) {
        int a, b;
        do
        {
            cout << "NHAP VI TRI PHAN TU 1 (INDEX): ";
            cin >> a;
            cout << "NHAP VI TRI PHAN TU 2 (INDEX): ";
            cin >> b;
        } while (a < 0 || a >= listVector.size() || b < 0 || b >= listVector.size());

        while (true)
        {
            system("cls");
            cout << "1. CONG (+)\n";
            cout << "2. TRU (-)\n";
            cout << "3. TICH VO HUONG\n";
            cout << "4. TICH CO HUONG\n";
            cout << "5. NHAN k\n";
            cout << "0. THOAT\n";
            cout << "\nLUA CHON: ";
            char lc;
            cin >> lc;
            cin.ignore();
            system("cls");

            if (lc == '0')
                break;
            else if (lc == '1') {
                cout << "KET QUA TONG: " << *listVector[a] + *listVector[b] << endl;
            }
            else if (lc == '2') {
                cout << "KET QUA HIEU: " << *listVector[a] - *listVector[b] << endl;
            }
            else if (lc == '3') {
                cout << "KET QUA TICH VO HUONG: " << listVector[a]->DotProduct(*listVector[b]) << endl;
            }
            else if (lc == '4') {
                cout << "KET QUA TICH CO HUONG: " << *listVector[a] * *listVector[b] << endl;
            }
            else if (lc == '5') {
                int k;
                cout << "NHAP k: ";
                cin >> k;
                cout << "KET QUA a NHAN k: " << *listVector[a] * k << endl;
                cout << "KET QUA b NHAN k: " << *listVector[b] * k << endl;
            }
            else {
                cout << "LUA CHON KHONG HOP LE!\n";
            }
            system("pause");
        }
    }
    else {
        cout << "KHONG DU DU LIEU\n";
    }
}
void CalMatrix(vector<Matrix *> listMatrix) {
    if (listMatrix.size() >= 2) {
        int a, b;
        do
        {
            cout << "NHAP VI TRI PHAN TU 1 (INDEX): ";
            cin >> a;
            cout << "NHAP VI TRI PHAN TU 2 (INDEX): ";
            cin >> b;
        } while (a < 0 || a >= listMatrix.size() || b < 0 || b >= listMatrix.size());

        while (true)
        {
            system("cls");
            cout << "1. CONG (+)\n";
            cout << "2. TRU (-)\n";
            cout << "3. NHAN (*)\n";
            cout << "4. NHAN k\n";
            cout << "0. THOAT\n";
            cout << "\nLUA CHON: ";
            char lc;
            cin >> lc;
            cin.ignore();
            system("cls");

            if (lc == '0')
                break;
            else if (lc == '1') {
                cout << "KET QUA TONG: \n" << *listMatrix[a] + *listMatrix[b] << endl;
            }
            else if (lc == '2') {
                cout << "KET QUA HIEU: \n" << *listMatrix[a] - *listMatrix[b] << endl;
            }
            else if (lc == '3') {
                cout << "KET QUA TICH: \n" << *listMatrix[a] * *listMatrix[b] << endl;
            }
            else if (lc == '4') {
                int k;
                cout << "NHAP k: ";
                cin >> k;
                cout << "KET QUA 2 MT NHAN k: \n";
                cout << "a NHAN k\n" << *listMatrix[a] * k << endl;
                cout << "b NHAN k\n" << *listMatrix[b] * k << endl;
            }
            else {
                cout << "LUA CHON KHONG HOP LE!\n";
            }
            system("pause");
        }
    }
    else {
        cout << "KHONG DU DU LIEU\n";
    }
}
void VectorXMatrix(vector<Vector *> listVector, vector<Matrix *> listMatrix) {
    int a, b;
    do
    {
        cout << "NHAP VI TRI PHAN TU CUA VECTOR (INDEX): ";
        cin >> a;
        cout << "NHAP VI TRI PHAN TU CUA MATRIX (INDEX): ";
        cin >> b;
    } while (a < 0 || a >= listVector.size() || b < 0 || b >= listMatrix.size());

    cout << "KET QUA: " << Multiply(*listMatrix[b], *listVector[a]) << endl;
}
void CompareVector(vector<Vector *> listVector) {
    if (listVector.size() >= 2) {
        int a, b;
        do
        {
            cout << "NHAP VI TRI PHAN TU 1 (INDEX): ";
            cin >> a;
            cout << "NHAP VI TRI PHAN TU 2 (INDEX): ";
            cin >> b;
        } while (a < 0 || a >= listVector.size() || b < 0 || b >= listVector.size());

        if (*listVector[a] == *listVector[b]) {
            cout << "VECTOR " << *listVector[a] << " BANG VECTOR " << *listVector[b] << endl;
        } 
        else {
            cout << "VECTOR " << *listVector[a] << " KHAC VECTOR " << *listVector[b] << endl;
        } 
    }
    else {
        cout << "KHONG DU DU LIEU\n";
    }
}
void CompareMatrix(vector<Matrix *> listMatrix) {
    if (listMatrix.size() >= 2) {
        int a, b;
        do
        {
            cout << "NHAP VI TRI PHAN TU 1 (INDEX): ";
            cin >> a;
            cout << "NHAP VI TRI PHAN TU 2 (INDEX): ";
            cin >> b;
        } while (a < 0 || a >= listMatrix.size() || b < 0 || b >= listMatrix.size());

        cout << "\nMA TRAN A:\n";
        cout << *listMatrix[a] << endl;
        cout << "\nMA TRAN B:\n";
        cout << *listMatrix[b] << endl;

        if (*listMatrix[a] == *listMatrix[b]) {
            cout << "HAI MA TRAN NAY BANG NHAU" << endl;
        } 
        else {
            cout << "HAI MA TRAN NAY KHAC NHAU" << endl;
        } 
    }
    else {
        cout << "KHONG DU DU LIEU\n";
    }
}
void Option3(vector<Vector *> listVector, vector<Matrix *> listMatrix) {
    while (true)
    {
        system("cls");
        cout << "1. VECTOR VA VECTOR\n";
        cout << "2. MATRIX VA MATRIX\n";
        cout << "3. VECTOR NHAN MATRIX\n";
        cout << "0. THOAT\n";
        cout << "\nLUA CHON: ";
        char lc;
        cin >> lc;
        cin.ignore();
        system("cls");

        if (lc == '0')
            break;
        else if (lc == '1') {
            int size = listVector.size();
            if (size >= 2) {
                CalVector(listVector);
            }
            else {
                cout << "KHONG CO DU DU LIEU\n";
            }
            break;
        }
        else if (lc == '2') {
            int size = listMatrix.size();
            if (size >= 1) {
                CalMatrix(listMatrix);
            }
            else {
                cout << "KHONG CO DU LIEU\n";
            }
            break;
        }
        else if (lc == '3') {
            int size1 = listVector.size();
            int size2 = listMatrix.size();
            if (size1 >= 1 && size2 >= 1) {
                VectorXMatrix(listVector, listMatrix);
            }
            else {
                cout << "KHONG CO DU LIEU\n";
            }
            break;
        }
        else {
            cout << "LUA CHON KHONG HOP LE!\n";
        }
        system("pause");
    }
}
void Option4(vector<Vector *> listVector, vector<Matrix *> listMatrix) {
    while (true)
    {
        system("cls");
        cout << "1. VECTOR VA VECTOR\n";
        cout << "2. MATRIX VA MATRIX\n";
        cout << "0. THOAT\n";
        cout << "\nLUA CHON: ";
        char lc;
        cin >> lc;
        cin.ignore();
        system("cls");
        
        if (lc == '0')
            break;
        else if (lc == '1') {
            CompareVector(listVector);
        }
        else if (lc == '2') {
            CompareMatrix(listMatrix);
        }
        else {
            cout << "LUA CHON KHONG HOP LE!\n";
        }
        system("pause");
    }
}

void Menu(vector<Vector *> listVector, vector<Matrix *> listMatrix)
{
    while (1)
    {
        system("cls");
        cout << "1. NHAP VECTOR HOAC MATRIX\n";
        cout << "2. XUAT DS VECTOR HOAC MATRIX\n";
        cout << "3. TINH TOAN VECTOR HOAC MATRIX\n";
        cout << "4. SO SANH VECTOR HOAC MATRIX\n";
        cout << "0. THOAT\n";
        cout << "\nLUA CHON: ";
        char lc;
        cin >> lc;
        cin.ignore();
        system("cls");

        if (lc == '0')
            break;
        else if (lc == '1')
        {
            Input(listVector, listMatrix);
        }
        else if (lc == '2')
        {
            Output(listVector, listMatrix);
        }
        else if (lc == '3')
        {
            Option3(listVector, listMatrix);
        }
        else if (lc == '4')
        {
            Option4(listVector, listMatrix);
        }
        else
        {
            cout << "LUA CHON KHONG HOP LE\n";
        }
        system("pause");
    }
}

int main()
{
    vector<Vector *> listVector;
    vector<Matrix *> listMatrix;
    Menu(listVector, listMatrix);
    return 0;
}