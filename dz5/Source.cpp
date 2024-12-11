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
        {"яблочный", 100},
        {"апельсиновый", 120},
        {"абрикосовый", 130},
        {"грушевый", 110},
        {"томатный", 90},
        {"луковый", 80},
        {"огуречный", 70},
        {"чесночный", 160},
        {"петрушевый", 150}
    };

    double total = 0;
    int limit = 1000; 
    int herbalTeaLiters = 0; 
    int onionJuiceLiters = 0; 

    while (true) {
        cout << "\nВыберите напиток (введите название или 'стоп' для завершения):\n";
        cout << "Фруктовые: яблочный, апельсиновый, абрикосовый, грушевый\n";
        cout << "Овощные: томатный, луковый, огуречный\n";
        cout << "Чаи: чесночный, петрушевый\n";

        string choice;
        cin >> choice;

        if (choice == "стоп") {
            break;
        }

        if (prices.find(choice) == prices.end()) {
            cout << "Неверный выбор. Пожалуйста, выберите другой напиток.\n";
            continue;
        }

        int liters;
        cout << "Введите количество литров: ";
        cin >> liters;

        total += prices[choice] * liters;

        if (choice == "петрушевый") {
            herbalTeaLiters += liters;
        }

        if (choice == "луковый") {
            onionJuiceLiters += liters;
        }
    }

    double discount = calculateDiscount(total, herbalTeaLiters, limit);

    if (onionJuiceLiters > 0) {
        int freeLiters = onionJuiceLiters / 4;
        total -= freeLiters * prices["луковый"];
    }

    total -= discount;

    cout << fixed << setprecision(2);
    cout << "Итоговая сумма: " << total << " рублей\n";
    if (discount > 0) {
        cout << "Скидка: " << discount << " рублей\n";
    }

    return 0;
}