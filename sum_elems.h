#include <vector>

class SumElems
{
private:
    int size;
    int quant_threads;
    std::vector<int> values;
    int result;
    void calc_sum_part(int l_index, int r_index, int index);
public:
    SumElems(int _size, int _quant_threads);
    ~SumElems();
    int calc_using_threads();
    int calc_with_threads();
    void printElems();
};
