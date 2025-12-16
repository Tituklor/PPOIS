/// @file Vector3D.h
/// @brief Класс трехмерного вектора
/// @date 2025
/// @version 1.0

#pragma once

#include <iosfwd>

/**
 * @class Vector3D
 * @brief Класс трехмерного вектора, заданного координатами концов
 * 
 * @note Для сравнения векторов используется их длина с учетом погрешности kEpsilon
 * 
 * @example
 * @code
 * Vector3D v1(0, 0, 0, 1, 0, 0);  // Вектор вдоль оси X
 * Vector3D v2(0, 0, 0, 0, 1, 0);  // Вектор вдоль оси Y
 * Vector3D sum = v1 + v2;          // Сложение векторов
 * double dot = v1 * v2;            // Скалярное произведение
 * @endcode
 */
class Vector3D
{
public:
    /// @brief Константа для сравнения с плавающей точкой
    static constexpr double kEpsilon = 1e-9;

    /**
     * @brief Конструктор по умолчанию
     * @details Создает нулевой вектор с началом и концом в точке (0,0,0)
     */
    Vector3D();

    /**
     * @brief Параметризованный конструктор
     * @param startX X-координата начала
     * @param startY Y-координата начала
     * @param startZ Z-координата начала
     * @param endX X-координата конца
     * @param endY Y-координата конца
     * @param endZ Z-координата конца
     */
    Vector3D(double startX, double startY, double startZ,
             double endX, double endY, double endZ);

    /// @brief Конструктор копирования (по умолчанию)
    Vector3D(const Vector3D& other) = default;

    /// @brief Оператор присваивания (по умолчанию)
    Vector3D& operator=(const Vector3D& other) = default;

    /// @brief Деструктор (по умолчанию)
    ~Vector3D() = default;

    // === Геттеры ===

    /// @brief Получить X-координату начала
    double GetStartX() const;

    /// @brief Получить Y-координату начала
    double GetStartY() const;

    /// @brief Получить Z-координату начала
    double GetStartZ() const;

    /// @brief Получить X-координату конца
    double GetEndX() const;

    /// @brief Получить Y-координату конца
    double GetEndY() const;

    /// @brief Получить Z-координату конца
    double GetEndZ() const;

    /**
     * @brief Установить координаты начала
     * @param x X-координата
     * @param y Y-координата
     * @param z Z-координата
     */
    void SetStart(double x, double y, double z);

    /**
     * @brief Установить координаты конца
     * @param x X-координата
     * @param y Y-координата
     * @param z Z-координата
     */
    void SetEnd(double x, double y, double z);


    /**
     * @brief Вычислить длину вектора
     * @return Длина вектора
     * @note Использует формулу: sqrt(dx² + dy² + dz²)
     */
    double GetLength() const;

    /**
     * @brief Сложение векторов
     * @param rhs Второй вектор
     * @return Новый вектор - сумма
     */
    Vector3D operator+(const Vector3D& rhs) const;

    /**
     * @brief Сложение с присваиванием
     * @param rhs Второй вектор
     * @return Ссылка на измененный вектор
     */
    Vector3D& operator+=(const Vector3D& rhs);

    /**
     * @brief Вычитание векторов
     * @param rhs Второй вектор
     * @return Новый вектор - разность
     */
    Vector3D operator-(const Vector3D& rhs) const;

    /**
     * @brief Вычитание с присваиванием
     * @param rhs Второй вектор
     * @return Ссылка на измененный вектор
     */
    Vector3D& operator-=(const Vector3D& rhs);

    /**
     * @brief Скалярное произведение
     * @param rhs Второй вектор
     * @return Скалярное произведение
     * @note Использует формулу: dx1*dx2 + dy1*dy2 + dz1*dz2
     */
    double operator*(const Vector3D& rhs) const;

    /**
     * @brief Векторное произведение
     * @param rhs Второй вектор
     * @return Новый вектор - векторное произведение
     * @note Результат имеет начало в точке (0,0,0)
     */
    Vector3D Cross(const Vector3D& rhs) const;

    /**
     * @brief Умножение на скаляр
     * @param scalar Скаляр
     * @return Новый вектор
     */
    Vector3D operator*(double scalar) const;

    /**
     * @brief Умножение на скаляр с присваиванием
     * @param scalar Скаляр
     * @return Ссылка на измененный вектор
     */
    Vector3D& operator*=(double scalar);

    /**
     * @brief Деление на скаляр
     * @param scalar Скаляр (не должен быть нулевым)
     * @return Новый вектор
     * @throws std::invalid_argument если scalar близок к нулю
     */
    Vector3D operator/(double scalar) const;

    /**
     * @brief Деление на скаляр с присваиванием
     * @param scalar Скаляр (не должен быть нулевым)
     * @return Ссылка на измененный вектор
     * @throws std::invalid_argument если scalar близок к нулю
     */
    Vector3D& operator/=(double scalar);

    /**
     * @brief Косинус угла между векторами
     * @param rhs Второй вектор
     * @return Косинус угла
     * @throws std::invalid_argument если один из векторов нулевой
     * @note Использует оператор ^
     */
    double operator^(const Vector3D& rhs) const;

   

    /**
     * @brief Проверка равенства длин векторов
     * @param rhs Второй вектор
     * @return true если длины равны с учетом kEpsilon
     */
    bool operator==(const Vector3D& rhs) const;

    /**
     * @brief Проверка неравенства длин векторов
     * @param rhs Второй вектор
     * @return true если длины не равны
     */
    bool operator!=(const Vector3D& rhs) const;

    /**
     * @brief Сравнение "больше"
     * @param rhs Второй вектор
     * @return true если длина текущего вектора больше
     */
    bool operator>(const Vector3D& rhs) const;

    /**
     * @brief Сравнение "больше или равно"
     * @param rhs Второй вектор
     * @return true если длина текущего вектора больше или равна
     */
    bool operator>=(const Vector3D& rhs) const;

    /**
     * @brief Сравнение "меньше"
     * @param rhs Второй вектор
     * @return true если длина текущего вектора меньше
     */
    bool operator<(const Vector3D& rhs) const;

    /**
     * @brief Сравнение "меньше или равно"
     * @param rhs Второй вектор
     * @return true если длина текущего вектора меньше или равна
     */
    bool operator<=(const Vector3D& rhs) const;

private:
    double startX_;  ///< X-координата начала
    double startY_;  ///< Y-координата начала
    double startZ_;  ///< Z-координата начала
    double endX_;    ///< X-координата конца
    double endY_;    ///< Y-координата конца
    double endZ_;    ///< Z-координата конца

    /// @brief Получить X-компоненту направляющего вектора
    double GetDirectionX() const;

    /// @brief Получить Y-компоненту направляющего вектора
    double GetDirectionY() const;

    /// @brief Получить Z-компоненту направляющего вектора
    double GetDirectionZ() const;
};

/**
 * @brief Оператор вывода вектора в поток
 * @param out Выходной поток
 * @param vector Вектор для вывода
 * @return Ссылка на поток
 * @example
 * @code
 * Vector3D v(1, 2, 3, 4, 5, 6);
 * std::cout << v; // Вывод: Start(1, 2, 3) End(4, 5, 6)
 * @endcode
 */
std::ostream& operator<<(std::ostream& out, const Vector3D& vector);

/**
 * @brief Оператор ввода вектора из потока
 * @param in Входной поток
 * @param vector Вектор для заполнения
 * @return Ссылка на поток
 * @note Ожидает 6 чисел: x1 y1 z1 x2 y2 z2
 */
std::istream& operator>>(std::istream& in, Vector3D& vector);
