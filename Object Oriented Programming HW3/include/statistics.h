//--- 2021-2022 Summer Object Oriented Programing Assignment 3 ---//
//--------------------------//
//---Name & Surname: Beyza Aydeniz
//---Student Number: 150200039
//--------------------------//

#ifndef __STATISTICS_H
#define __STATISTICS_H
using namespace std;

//-------------Do Not Add New Libraries-------------//
//-------------All Libraries Needed Were Given-------------//

#include <vector>

class StatisticalDistribution{
protected:
    double mean; //mean is used in other derived classes so we declare it as protected
public:
    double getmean() const; //to use mean in many_trials function
    virtual vector<double> sample(int, int) = 0; //pure virtual method
    vector<double> calculate_confidence_interval(vector<double>, int, double);
};

class NormalDistribution : public StatisticalDistribution{
private:
    double stddev;
public:
    NormalDistribution();
    vector<double> sample(int, int);
};

class UniformDistribution : public StatisticalDistribution{
private:
    double a;
    double b;
public:
    UniformDistribution();
    vector<double> sample(int, int);
};

class ExponentialDistribution : public StatisticalDistribution{
private:
    double lambda;
public:
    ExponentialDistribution();
    vector<double> sample(int, int);
};

#endif