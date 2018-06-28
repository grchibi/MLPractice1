#include "neuron.h"


/**
 * NeuronBase Class
 */
 
template <std::size_t INPNO>
NeuronBase<INPNO>::NeuronBase(const char* name)
{
    myName_ = name;
    
    weights_.fill(0.0);
}

template <std::size_t INPNO>
double NeuronBase<INPNO>::calcOutput(const double (&inp)[INPNO])
{
    double u = 0;
    for (unsigned int i = 0; i < INPNO; ++i)
        u += weights_[i] * inp[i];
    
    u -= u_;
    
    return transFunc(u);
}

template <std::size_t INPNO>
double NeuronBase<INPNO>::calcOutput(const std::array<double, INPNO>& inp)
{
    double u = 0;
    int idx = 0;
    for (auto ite = inp.cbegin(); ite != inp.cend(); ++ite, ++idx)
        u += weights_[idx] * *ite;
    
    u -= u_;
    
    return transFunc(u);
}

template <std::size_t INPNO>
void NeuronBase<INPNO>::init(const double (&ws)[INPNO], double u)
{
    int idx = 0;
    for (auto ite = std::begin(ws), end = std::end(ws); ite != end; ++ite)
    {
        weights_[idx++] = *ite;
    }
    
    u_ = u;
}

template <std::size_t INPNO>
void NeuronBase<INPNO>::print()
{
    std::cout << "Name: " << myName_ << std::endl;
    std::cout << "  sz: " << weights_.size() << std::endl;

    int idx = 0;
    for (auto ite = weights_.cbegin(); ite != weights_.cend(); ++ite, ++idx)
        std::cout << "  W[" << idx << "]  <" << *ite << ">" << std::endl;
    
    std::cout << "  U: " << u_ << std::endl;
}

template <std::size_t INPNO>
double NeuronBase<INPNO>::transFunc(double in)
{
    return in;
}


/**
 * NeuronWithStepFunc Class
 */

template <std::size_t INPNO>
double NeuronWithStepFunc<INPNO>::transFunc(double in)
{
    return (0 <= in) ? 1.0 : 0.0;
}


// end of neuron_impl.h