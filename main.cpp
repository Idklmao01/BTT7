#include <iostream>

using namespace std;

int main() {
    int NamBD, NamKT;
    cout << "Năm bắt đầu khảo sát: ";
    cin >> NamBD;
    cout << "Năm kết thúc khảo sát: ";
    cin >> NamKT;
    int SoNam = NamKT - NamBD + 1;
    int N[SoNam]= {0};
    int year, so_sinh;
    cout << "Nhập số liệu về trẻ em sinh ra (nhập -1 để kết thúc, không nhập coi như bằng 0):" << endl;
    while (true) {
        cout << "Năm: ";
        cin >> year;
        if (year == -1) break;
        if (year >= NamBD && year <= NamKT) {
        cout << "Số trẻ em sinh ra: ";
        cin >> so_sinh;
            N[year - NamBD] = so_sinh;
        } else {
            cout << "Năm không hợp lệ. Vui lòng nhập năm trong khoảng khảo sát." << endl;
        }
    }
     int maxPopulation = N[0], minPopulation = N[0];
    for (int i = 1; i < SoNam; ++i) {
        if (N[i] > maxPopulation) {
            maxPopulation = N[i];
        }
        if (N[i] < minPopulation) {
            minPopulation = N[i];
        }
    }

    cout << "Nam co so nguoi sinh ra nhieu nhat: ";
    for (int i = 0; i < SoNam; ++i) {
        if (N[i] == maxPopulation) {
            cout << i + NamBD << " ";
        }
    }
    cout << "voi " << maxPopulation << " nguoi." << endl;

    cout << "Nam co so nguoi sinh ra it nhat: ";
    for (int i = 0; i < SoNam; ++i) {
        if (N[i] == minPopulation) {
            cout << i + NamBD << " ";
        }
    }
    cout << "voi " << minPopulation << " nguoi." << endl;
    cout << "So nam co cung so luong nguoi sinh ra:" << endl;
    for (int i = 0; i < SoNam; ++i) {
        int count = 0;
        for (int j = 0; j < SoNam; ++j) {
            if (N[i] == N[j]) {
                count++;
            }
        }
        bool printed = false;
        for (int j = 0; j < i; ++j) {
            if (N[i] == N[j]) {
                printed = true;
                break;
            }
        }
        if (!printed && count > 1) {
            cout << "So luong nguoi sinh ra: " << N[i] << ", Nam: ";
            for (int j = 0; j < SoNam; ++j) {
                if (N[j] == N[i]) {
                    cout << j + NamBD << " ";
                }
            }
            cout << endl;
        }
    }
    return 0;
}