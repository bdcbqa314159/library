#ifndef ODESOLVERS_H
#define ODESOLVERS_H

class AbstractOdeSolver
{
protected:
    double stepSize, initialtime, finalTime, initialValue;

public:
    void setStepSize(double h);
    void setTimeInterval(double t0, double t1);
    void setIntialValue(double y0);
    virtual double rightHandSide(double y, double t) = 0;
    virtual double solveEquation() = 0;
    ~AbstractOdeSolver();
};

#endif