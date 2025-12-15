/**
 * @file Set.h
 * @brief Заголовочный файл класса Set - множества с поддержкой вложенных множеств
 * @author Ваше Имя
 * @date 2025
 * @version 1.0
 *
 * @mainpage Библиотека Set - Множества с вложенными элементами
 */

#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <set>
#include <sstream>

/**
 * @class Set
 * @brief Основной класс, представляющий множество
 *
 * Класс позволяет хранить элементы двух типов: строки и вложенные множества.
 * Поддерживает основные операции теории множеств: объединение, пересечение,
 * разность, построение булеана.
 *
 * @warning Рекурсивные вложения ограничены константой MAX_DEPTH
 *
 * @invariant Элементы в множестве уникальны (нет дубликатов)
 * @invariant Порядок элементов не гарантируется
 *
 * @code
 * Set s1("{a, b, c}");
 * Set s2("{b, c, d}");
 * Set unionSet = s1 + s2; // {a, b, c, d}
 * @endcode
 */
class Set {
public:
    /**
     * @struct Element
     * @brief Элемент множества
     * @var Element::isString
     * Флаг, указывающий тип элемента (true - строка, false - множество)
     *
     * @var Element::strValue
     * Строковое значение элемента (валидно только если isString == true)
     *
     * @var Element::setValue
     * Указатель на вложенное множество (валиден только если isString == false)
     */
    struct Element {
        bool isString;                ///< Тип элемента: true - строка, false - множество
        std::string strValue;         ///< Строковое значение
        std::shared_ptr<Set> setValue; ///< Указатель на вложенное множество

        /**
         * @brief Конструктор для строкового элемента
         * @param str Строковое значение элемента
         * @post isString == true
         * @post strValue == str
         * @post setValue == nullptr
         */
        Element(const std::string& str);

        /**
         * @brief Конструктор для множественного элемента
         * @param set Указатель на множество (будет сохранен через shared_ptr)
         * @post isString == false
         * @post strValue == ""
         * @post setValue == set
         */
        Element(std::shared_ptr<Set> set);

        /**
         * @brief Оператор сравнения элементов
         * @param other Другой элемент для сравнения
         * @return true если элементы равны по типу и значению
         *
         * Для строк сравниваются strValue, для множеств - содержимое setValue
         * @note Сравнение множеств выполняется рекурсивно
         */
        bool operator==(const Element& other) const;

        /**
         * @brief Оператор неравенства элементов
         * @param other Другой элемент для сравнения
         * @return true если элементы не равны
         * @see operator==
         */
        bool operator!=(const Element& other) const;
    };

    /**
     * @brief Конструктор по умолчанию
     * @post empty() == true
     * @post size() == 0
     */
    Set();

    /**
     * @brief Конструктор копирования (глубокое копирование)
     * @param other Множество для копирования
     * @post *this == other
     */
    Set(const Set& other);

    /**
     * @brief Оператор присваивания (глубокое копирование)
     * @param other Множество для копирования
     * @return Ссылка на этот объект
     * @post *this == other
     */
    Set& operator=(const Set& other);

    /// @brief Деструктор по умолчанию
    ~Set() = default;

    // Основные операции
    /**
     * @brief Проверка на пустоту множества
     * @return true если множество не содержит элементов
     */
    bool empty() const;

    /**
     * @brief Количество элементов в множестве
     * @return Число уникальных элементов
     */
    size_t size() const;

    /**
     * @brief Проверка наличия элемента в множестве
     * @param elem Элемент для поиска
     * @return true если элемент найден
     * @see hasElement
     */
    bool contains(const Element& elem) const;

    /**
     * @brief Добавление элемента в множество
     * @param elem Элемент для добавления
     * @return Ссылка на этот объект
     * @post contains(elem) == true
     * @post size() увеличится на 1, если элемент не был в множестве
     */
    Set& insert(const Element& elem);

    /**
     * @brief Удаление элемента из множества
     * @param elem Элемент для удаления
     * @return true если элемент был найден и удален
     * @post contains(elem) == false (если элемент был удален)
     */
    bool erase(const Element& elem);

    // Операции над множествами
    /**
     * @brief Объединение множеств
     * @param other Множество для объединения
     * @return Новое множество, содержащее все элементы из обоих множеств
     * @note Дубликаты исключаются
     */
    Set operator+(const Set& other) const;

    /**
     * @brief Оператор объединения с присваиванием
     * @param other Множество для объединения
     * @return Ссылка на этот объект
     * @post Содержит все элементы из исходного множества и other
     * @see operator+
     */
    Set& operator+=(const Set& other);

    /**
     * @brief Пересечение множеств
     * @param other Множество для пересечения
     * @return Новое множество, содержащее общие элементы
     */
    Set operator*(const Set& other) const;

    /**
     * @brief Оператор пересечения с присваиванием
     * @param other Множество для пересечения
     * @return Ссылка на этот объект
     * @post Содержит только элементы, присутствующие в обоих множествах
     */
    Set& operator*=(const Set& other);

    /**
     * @brief Разность множеств
     * @param other Множество для вычитания
     * @return Новое множество, содержащее элементы из первого, отсутствующие во втором
     */
    Set operator-(const Set& other) const;

    /**
     * @brief Оператор разности с присваиванием
     * @param other Множество для вычитания
     * @return Ссылка на этот объект
     * @post Содержит только элементы, отсутствующие в other
     */
    Set& operator-=(const Set& other);

    /**
     * @brief Построение булеана (множества всех подмножеств)
     * @return Множество, содержащее все подмножества исходного
     * @warning Для больших множеств (>10 элементов) вычисляется частичный булеан
     * @note Для пустого множества возвращает множество, содержащее пустое множество
     */
    Set powerSet() const;

    /**
     * @brief Конструктор из строкового представления
     * @param str Строка в формате "{элемент1, элемент2, {вложенное}, ...}"
     *
     * Формат строки:
     * - Начинается с '{' и заканчивается '}'
     * - Элементы разделены запятыми
     * - Строковые элементы могут быть без кавычек (только буквы и цифры)
     * - Вложенные множества в фигурных скобках
     *
     * @throws Нет явных исключений, но при ошибках парсинга может создаться частичное множество
     */
    explicit Set(const std::string& str);

    /**
     * @brief Сравнение множеств на равенство
     * @param other Множество для сравнения
     * @return true если множества содержат одинаковые элементы (порядок не важен)
     */
    bool operator==(const Set& other) const;

    /**
     * @brief Сравнение множеств на неравенство
     * @param other Множество для сравнения
     * @return true если множества различаются
     */
    bool operator!=(const Set& other) const;

    /**
     * @brief Оператор вывода в поток
     * @param os Выходной поток
     * @param set Множество для вывода
     * @return Ссылка на поток
     *
     * Формат вывода: "{элемент1, элемент2, {вложенное}, ...}"
     */
    friend std::ostream& operator<<(std::ostream& os, const Set& set);

    /**
     * @brief Оператор ввода из потока
     * @param is Входной поток
     * @param set Множество для заполнения
     * @return Ссылка на поток
     *
     * Читает до закрывающей фигурной скобки '}'
     */
    friend std::istream& operator>>(std::istream& is, Set& set);

private:
    /// @brief Максимальная глубина вложенности множеств
    static constexpr size_t MAX_DEPTH = 5;

    /// @brief Вектор элементов множества
    std::vector<Element> elements_;

    /**
     * @brief Рекурсивный парсинг строки
     * @param str Строка для парсинга
     * @param pos Текущая позиция в строке (изменяется в процессе)
     * @private
     */
    void parseString(const std::string& str, size_t& pos);

    /**
     * @brief Проверка наличия элемента (внутренняя реализация)
     * @param elem Элемент для поиска
     * @return true если элемент найден
     * @private
     * @see contains
     */
    bool hasElement(const Element& elem) const;

    /**
     * @brief Глубокое копирование множества
     * @return shared_ptr на новую копию
     * @private
     */
    std::shared_ptr<Set> deepCopy() const;
};

/**
 * @brief Фабричная функция для создания строкового элемента
 * @param str Строковое значение
 * @return Элемент типа строка
 */
Set::Element makeString(const std::string& str);

/**
 * @brief Фабричная функция для создания множественного элемента
 * @param set Указатель на множество
 * @return Элемент типа множество
 */
Set::Element makeSet(std::shared_ptr<Set> set);
