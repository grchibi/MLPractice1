#ifndef _NEURON_H_
#define _NEURON_H_


#include <array>
#include <iostream>
#include <string>


namespace ML
{
    template <std::size_t INPNO>
    class NeuronBase
    {
        std::string myName_;
        double u_;
        std::array<double, INPNO> weights_;

    protected:
        virtual double transFunc(double in);
    
    public:
        NeuronBase(const char* name);
        virtual ~NeuronBase() {}
        
        double calcOutput(const double (&inp)[INPNO]);
        double calcOutput(const std::array<double, INPNO>& inp);
        void init(const double (&ws)[INPNO], double u);
        
        void print(void);
    };
    
    template <std::size_t INPNO>
    class NeuronWithStepFunc : public NeuronBase<INPNO>
    {
        protected:
            double transFunc(double in) override;
            
        public:
            NeuronWithStepFunc(const char* name) : NeuronBase<INPNO>(name) {}
            ~NeuronWithStepFunc() {}
            
    };
    
    #include "neuron_impl.h"
}


#endif  // _NEURON_H_
