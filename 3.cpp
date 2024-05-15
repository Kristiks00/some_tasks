/*
 Дано корректное математическое выражение, состоящее из переменных, обозначаемых строчными латинскими буквами (только одна буква), инфиксных бинарных операций и круглых скобок для группировки подвыражений.

Все операции имеют ассоциативность слева направо и приоритеты, указанные в таблице:
Приоритет	   Операции
1 (наибольший)	*, /
2	            +, -
3	            &
4	            ^
5 (наименьший)	|

Требуется удалить из выражения все лишние пары скобок, не влияющие на порядок операций в нём (операции трактовать абстрактно, без какого-либо математического смысла, опираясь только на формальный порядок операций).

Приоритет определяет, в каком порядке выполняются операции в цепочке, а ассоциативность определяет направление вычислений в цепочке операций одного приоритета. 
*/
#include <iostream>
#include <string>
#include <map>

static std::map<char, int> m = {{'*', 1}, {'/', 1}, {'+', 2}, {'-', 2}, {'&', 3}, {'^', 4}, {'|', 5}};
int expr(auto &it, auto &end)
{
    int new_op{}, cur_op{}, left_op{};
    while (it != end && *it != ')') {
        if (*it == '(') {
            auto sit = it;
            new_op = expr(++it, end);
            int right_op{};
            if (it + 1 != end && *(it + 1) != ')') {
                right_op = m[*(it + 1)];
            }
            if ((!left_op && !right_op) || (!left_op && right_op >= new_op) || (!right_op && left_op > new_op) ||
                    (right_op >= new_op && left_op > new_op)) {
                *sit = '#';
                *it = '#';
            }
            cur_op = (cur_op > right_op) ? cur_op : right_op;
            cur_op = (!cur_op) ? new_op : cur_op;
            if (it != end) {
                ++it;
            }
        } else if ('a' <= *it && *it <= 'z') {
            ++it;
        } else {
            left_op = m[*it];
            cur_op = (cur_op  < left_op) ? left_op : cur_op;
            ++it;
        }
    }
    return cur_op;
}

int main(void)
{
    std::string s{};
    std::cin >> s;
    auto beg = s.begin(), end = s.end();
    expr(beg, end);
    for (char &i : s) {
        if (i != '#') {
            std::cout.put(i);
        }
    }
    std::cout.put('\n');
    return 0;
}
