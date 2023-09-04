#include "sum_elems.h"
#include <cstdlib>
#include <ctime>
#include <thread>
#include <iostream>

SumElems::SumElems(int _size, int _quant_threads) : size(_size), quant_threads(_quant_threads)
{
    const int min_value = 0;
    const int max_value = 20;
    srand(std::time(0));
    for (int i = 0; i < size; i++)
    {
        values.push_back(min_value + rand() % (max_value - min_value + 1));  // Заполнение массива случайными числами в интервале от 0 до 20
    }
}

SumElems::~SumElems()
{

}

void SumElems::printElems()
{
    std::cout << "Элемент: " << std::endl;
    for (int i = 0; i < size; i++)
        std::cout << values[i] << " ";
    std::cout << "\n" << std::endl;
}

void SumElems::calc_sum_part(int l_index, int r_index, int index)
{
    int s = 0;
    while (l_index <= r_index)
    {
        s += values[l_index++];
    }
    result += s;
}

int SumElems::calc_with_threads()
{
    int s = 0;
    for (int i = 0; i < values.size(); i++)
    {
        s += values[i];
    }
    return s;
}

int SumElems::calc_using_threads()
{
    std::vector<std::thread> threads;
    int l_index = 0;
    int r_index = 0;
    int bunch_size = size / quant_threads;
    result = 0;

    for (int i = 0; i < quant_threads; i++)
    {
        if (i == quant_threads - 1)
            r_index = values.size();
        else
            r_index += bunch_size;

        std::thread t(&SumElems::calc_sum_part, this, l_index, r_index - 1, i);
        threads.push_back(std::move(t));
        l_index += bunch_size;
    }

    for (auto& t : threads)
    {
        if (t.joinable())
            t.join();
    }

    return result;
}
