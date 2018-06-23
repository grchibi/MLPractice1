#ifndef _NEURON_H_
#define _NEURON_H_


#include <array>
#include <string>


namespace ML
{
    class Neuron
    {
        std::string myName_;
        int u_;
        std::array<int, 2> weights_;

    public:
        Neuron(const char* name);
        ~Neuron() {}
        
    };
}


#endif  // _NEURON_H_
