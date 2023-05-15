//--- 2021-2022 Summer Object Oriented Programing Assignment 3 ---//
//--------------------------//
//---Name & Surname: Beyza Aydeniz
//---Student Number: 150200039
//--------------------------//

//-------------Do Not Add New Libraries-------------//
//-------------All Libraries Needed Were Given-------------//

#include "statistics.h"
#include <random>
#include <iostream>
using namespace std;

// Statistical distribution part

double StatisticalDistribution::getmean() const{ // since "mean" is protected, we use getmean to acccess mean
    return this->mean;
}
vector<double> StatisticalDistribution::calculate_confidence_interval(std::vector<double> random_sample, int size, 
                                                                                                    double val){
    vector<double> confidence_interval;
    double sample_mean = 0.0;
    double sum_of_terms = 0.0; //to sum of all the elements in random sample
    double sample_standard_deviation = 0.0;
    double first = 0.0; //confidence_interval[0]
    //since confidence_interval[1] equals to sample_mean, no need to declare second variable
    double third = 0.0; //confidence_interval[2]

    for (int i = 0; i < size; i++)
        sum_of_terms += random_sample[i];
    sample_mean = sum_of_terms / size; //sum of all the elements in random sample divided by size equals to mean

    for (int i = 0; i < size; i++)
        sample_standard_deviation += (random_sample[i] - sample_mean) * (random_sample[i] - sample_mean);
    sample_standard_deviation = sample_standard_deviation / size;
    sample_standard_deviation = sqrt(sample_standard_deviation);

    first = sample_mean - val * sample_standard_deviation / sqrt(size); //lower bound
    third = sample_mean + val * sample_standard_deviation / sqrt(size); //upper bound

    confidence_interval.push_back(first); //lower bound is pushed to the confidence_interval[0]
    confidence_interval.push_back(sample_mean); //sample mean is pushed to the confidence_interval[1]
    confidence_interval.push_back(third); //upper bound is pushed to the confidence_interval[2]
    return confidence_interval;
}

// Normal distribution part
NormalDistribution::NormalDistribution(){
    mean = 0.0;
    stddev = 1.0;
}
vector<double> NormalDistribution::sample(int sample_size, int seed_value){
    //creates a sample from a Normal Distribution
    vector<double> random_sample;
    default_random_engine generator;
    generator.seed(seed_value);
    normal_distribution<double> distribution(getmean(), stddev);
    double number;
    for (int i = 0; i < sample_size; i++){
        number = distribution(generator);
        random_sample.push_back(number);
    }
    return random_sample;
}

// Uniform Distribution part
UniformDistribution::UniformDistribution(){
    mean = 0.0;
    a = -1.0;
    b = 1.0;
}
vector<double> UniformDistribution::sample(int sample_size, int seed_value){
    //creates a sample from a Uniform Distribution
    vector<double> random_sample;
    default_random_engine generator;
    generator.seed(seed_value);
    uniform_real_distribution<double> distribution(a, b);
    double number;
    for (int i = 0; i < sample_size; i++){
        number = distribution(generator);
        random_sample.push_back(number);
    }
    return random_sample;
    ;
}

// Exponential distribution part
ExponentialDistribution::ExponentialDistribution(){
    mean = 1.0;
    lambda = 1.0;
}
vector<double> ExponentialDistribution::sample(int sample_size, int seed_value){
     //creates a sample from a Exponential Distribution
    vector<double> random_sample;
    default_random_engine generator;
    generator.seed(seed_value);
    exponential_distribution<double> distribution(lambda);
    double number;
    for (int i = 0; i < sample_size; i++){
        number = distribution(generator);
        random_sample.push_back(number);
    }
    return random_sample;
}