#include <iostream>
#include <iterator>
#include "neuron.h"


using namespace ML;

template <class T, std::size_t N>
std::ostream& operator<<(std::ostream& o, const std::array<T, N>& arr)
{
    std::copy(arr.cbegin(), arr.cend(), std::ostream_iterator<T>(o, " "));
    return o;
}

int main(int argc, char const *argv[])
{

    NeuronWithStepFunc<2> nr("AND");
    
    nr.init({1.0, 1.0}, 1.5);
    nr.print();
    
    std::array< std::array<double, 2>, 4> inpdata = {{ {0, 0}, {0, 1}, {1, 0}, {1, 1} }};
    for (int row = 0; row < 4; ++row)
    {
        std::cout << "IN: " << inpdata[row] << "    OUT: " << nr.calcOutput(inpdata[row]) << std::endl;
    }
    
    return 0;
}
