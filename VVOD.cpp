#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    // Входные данные
    double t_nasos, t_rabotniki, S, Hg, d;
    const double v = 1.0; // скорость воды (м/с)
    const double viscosity = 1e-6; // кинематическая вязкость воды (м^2/с)
    const double Hc = 5.0; // свободный напор (условно постоянный)
    double L; // длина трубы

    // Ввод данных
    cout << "Введите время работы насоса (в часах): ";
    cin >> t_nasos;

    cout << "Введите время отработки работников (в часах): ";
    cin >> t_rabotniki;

    cout << "Введите площадь участка (в квадратных метрах): ";
    cin >> S;

    cout << "Введите геодезический напор Hg (в метрах): ";
    cin >> Hg;

    cout << "Введите диаметр трубы (в метрах): ";
    cin >> d;

    // Оценка длины трубы (можно изменить при необходимости)
    L = sqrt(S); // Упрощённо считаем длину по площади участка

    // Расчёт числа Рейнольдса
    double Re = (d * v) / viscosity;
    double lambda;

    cout << fixed << setprecision(2);
    cout << "\nЧисло Рейнольдса: " << Re << endl;

    // Определение типа потока через if-else
    if (Re < 2300) {
        cout << "Поток: Ламинарный" << endl;
        lambda = 64 / Re;
    }
    else {
        cout << "Поток: Турбулентный" << endl;
        lambda = pow((0.3 / Re), 0.25); // Корень 4 степени
    }

    // Расчёт потери напора
    double h = (lambda * L / d) + (pow(v, 2) / 19.6);

    // Расчёт общего напора
    double H = Hg + h + Hc;

    // Вывод результатов
    cout << "\n--- Результаты расчёта ---\n";
    cout << "Время работы насоса: " << t_nasos << " ч\n";
    cout << "Время отработки работников: " << t_rabotniki << " ч\n";
    cout << "Коэффициент трения (λ): " << lambda << endl;
    cout << "Потеря напора (h): " << h << " м" << endl;
    cout << "Общий напор насоса (H): " << H << " м" << endl;

    return 0;
}
