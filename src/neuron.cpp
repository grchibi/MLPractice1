#include <iostream>

#include "neuron.h"


namespace ML
{
    Neuron::Neuron(const char* name)
    {
        myName_ = name;
        
        weights_.fill(-1);

        std::cout << "Name: " << myName_ << std::endl;
        std::cout << "  sz: " << weights_.size() << std::endl;

        for (auto ite = weights_.cbegin(); ite != weights_.cend(); ++ite)
            std::cout << "  <" << *ite << ">" << std::endl;
    }
}
