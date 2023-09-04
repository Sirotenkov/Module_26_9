#include "sum_elems.h"
#include <iostream>
#include <chrono>
#include <thread>

int main()
{
    setlocale(LC_ALL, "Ru");

    const int array_size = 10000000;
    const int quantity_threads = 12;
    SumElems sum(array_size, quantity_threads);

    auto t_start = std::chrono::system_clock::now();
    int s = sum.calc_using_threads();
    auto t_end = std::chrono::system_clock::now();
    long t_sumElem = std::chrono::duration_cast<std::chrono::milliseconds>(t_end - t_start).count();
    std::cout << "Сумма с задействованием: " << quantity_threads << " потоков равна " << s << ".  Время вычисления (мс): " << t_sumElem << std::endl;

    t_start = std::chrono::system_clock::now();
    s = sum.calc_with_threads();
    t_end = std::chrono::system_clock::now();
    t_sumElem = std::chrono::duration_cast<std::chrono::milliseconds>(t_end - t_start).count();
    std::cout << "Сумма с задействованием 1 потока равна " << s << ".  Время вычисления (мс): " << t_sumElem << std::endl;

    return 0;
}
