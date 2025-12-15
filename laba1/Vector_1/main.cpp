#include <iostream>
#include "Vector3D/Vector3D.h"

namespace
{
    void PrintMenu()
    {
        std::cout << "1. Ввести два вектора\n"
                  << "2. Сложение\n"
                  << "3. Вычитание\n"
                  << "4. Скалярное произведение\n"
                  << "5. Векторное произведение\n"
                  << "6. Косинус угла\n"
                  << "0. Выход\n";
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    Vector3D vectorA;
    Vector3D vectorB;
    bool isRunning = true;

    while (isRunning)
    {
        PrintMenu();

        int command = 0;
        std::cout << "Введите команду: ";
        if (!(std::cin >> command))
        {
            std::cerr << "Некорректный ввод. Завершение.\n";
            return 1;
        }

        switch (command)
        {
            case 1:
                std::cout << "Введите 6 координат для первого вектора "
                             "(x1 y1 z1 x2 y2 z2): ";
                std::cin >> vectorA;

                std::cout << "Введите 6 координат для второго вектора "
                             "(x1 y1 z1 x2 y2 z2): ";
                std::cin >> vectorB;
                break;

            case 2:
                std::cout << "A + B = " << (vectorA + vectorB) << '\n';
                break;

            case 3:
                std::cout << "A - B = " << (vectorA - vectorB) << '\n';
                break;

            case 4:
                std::cout << "A * B (dot) = " << (vectorA * vectorB) << '\n';
                break;

            case 5:
            {
                Vector3D crossProduct = vectorA.Cross(vectorB);
                std::cout << "A x B = " << crossProduct << '\n';
                break;
            }

            case 6:
                try
                {
                    std::cout << "cos(A, B) = " << (vectorA ^ vectorB) << '\n';
                }
                catch (const std::exception& exception)
                {
                    std::cerr << "Ошибка: " << exception.what() << '\n';
                }
                break;

            case 0:
                isRunning = false;
                break;

            default:
                std::cout << "Неизвестная команда\n";
                break;
        }
    }

    return 0;
}
