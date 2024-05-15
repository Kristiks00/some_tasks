/*
Опишите абстрактный класс Figure, который будет корнем полиморфной иерархии классов, описывающих двухмерные фигуры.

Класс должен определять метод equals для перекрытия в производных классах. Метод будет принимать указатель на фигуру и возвращать true, если фигуры равны.

Напишите классы Rectangle с конструктором от двух целых (int) аргументов и Triangle с конструктором от трех целых (int) аргументов. Для этих классов определите методы equals. Равенство фигур понимается как равенство соответствующих сторон, то есть прямоугольник (10, 5) не равен прямоугольнику (5, 10).

Иерархия должна быть расширяемой, то есть добавление нового класса-наследника Figure должно не ломать существующий код и не требовать его модификации.
*/
struct Figure
{
    virtual bool equals(const Figure *) const = 0;
    virtual ~Figure() {};
};

class Rectangle: public Figure
{
    int a_, b_;
public:
    Rectangle(int a, int b)
    {
        a_ = a;
        b_ = b;
    }
    int get_a() const
    {
        return a_;
    }
    int get_b() const
    {
        return b_;
    }
    bool equals(const Figure *o) const override
    {
        const Rectangle *p = dynamic_cast<const Rectangle *>(o);
        if (!p) {
            return false;
        }
        return p->get_a() == a_ && p->get_b() == b_;
    }
};

class Triangle: public Figure
{
    int a_, b_, c_;
public:
    Triangle(int a, int b, int c)
    {
        a_ = a;
        b_ = b;
        c_ = c;
    }
    int get_a() const
    {
        return a_;
    }
    int get_b() const
    {
        return b_;
    }
    int get_c() const
    {
        return c_;
    }
    bool equals(const Figure *o) const override
    {
        const Triangle *p = dynamic_cast<const Triangle *>(o);
        if (!p) {
            return false;
        }
        return p->get_a() == a_ && p->get_b() == b_ && p->get_c() == c_;
    }
};

