#ifndef SPACE_DEFS_H
#define SPACE_DEFS_H

class Janitor;

class Space
{
    friend class Janitor;

private:
    double space_area;
    bool is_sanitized;
    bool cleaned;  // ← ДОБАВИТЬ ЭТО ПОЛЕ!

public:
    Space(const double space_area);
    Space(const double space_area, const bool is_sanitized);

    bool check_sanitized_status() const;
    bool is_cleaned() const;  // ← ДОБАВИТЬ ГЕТТЕР!
    void set_cleaned(bool status);  // ← ДОБАВИТЬ СЕТТЕР!
};

#endif // SPACE_DEFS_H
