#include <iostream>
#include <iomanip>
#include <string>
#include <map>

using namespace std;

double calculateDiscount(double total, int herbalTeaLiters, double limit) {
    double discount = 0;

    if (herbalTeaLiters >= 3) {
        discount += (0.05 * herbalTeaLiters * 150);
    }

    if (total > limit) {
        discount += 0.13 * total;
    }

    return discount;
}

int main() {
    setlocale(LC_ALL, "ru");

    map<string, double> prices = {
        {"��������", 100},
        {"������������", 120},
        {"�����������", 130},
        {"��������", 110},
        {"��������", 90},
        {"�������", 80},
        {"���������", 70},
        {"���������", 160},
        {"����������", 150}
    };

    double total = 0;
    int limit = 1000; 
    int herbalTeaLiters = 0; 
    int onionJuiceLiters = 0; 

    while (true) {
        cout << "\n�������� ������� (������� �������� ��� '����' ��� ����������):\n";
        cout << "���������: ��������, ������������, �����������, ��������\n";
        cout << "�������: ��������, �������, ���������\n";
        cout << "���: ���������, ����������\n";

        string choice;
        cin >> choice;

        if (choice == "����") {
            break;
        }

        if (prices.find(choice) == prices.end()) {
            cout << "�������� �����. ����������, �������� ������ �������.\n";
            continue;
        }

        int liters;
        cout << "������� ���������� ������: ";
        cin >> liters;

        total += prices[choice] * liters;

        if (choice == "����������") {
            herbalTeaLiters += liters;
        }

        if (choice == "�������") {
            onionJuiceLiters += liters;
        }
    }

    double discount = calculateDiscount(total, herbalTeaLiters, limit);

    if (onionJuiceLiters > 0) {
        int freeLiters = onionJuiceLiters / 4;
        total -= freeLiters * prices["�������"];
    }

    total -= discount;

    cout << fixed << setprecision(2);
    cout << "�������� �����: " << total << " ������\n";
    if (discount > 0) {
        cout << "������: " << discount << " ������\n";
    }

    return 0;
}