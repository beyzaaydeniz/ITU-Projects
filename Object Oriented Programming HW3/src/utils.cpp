//--- 2021-2022 Summer Object Oriented Programing Assignment 3 ---//
//--------------------------//
//---Name & Surname: Beyza Aydeniz
//---Student Number: 150200039
//--------------------------//

//-------------Do Not Add New Libraries-------------//
//-------------All Libraries Needed Were Given-------------//

#include "utils.h"

using namespace std;

StatisticalDistribution *choose_function(int dist_type){
    NormalDistribution *normal = new NormalDistribution;
    UniformDistribution *uniform = new UniformDistribution;
    ExponentialDistribution *exponential = new ExponentialDistribution;
    switch (dist_type){ // input chooses a distribution function
        case 0:
            return normal;
            break;
        case 1:
            return uniform;
            break;
        case 2:
            return exponential;
            break;
        default:
            throw "Unidentified distribution function!";
            break;
    }
}

double many_trials(StatisticalDistribution *dist, vector<double> random_sample, double t_value, int trials,
                                                                        int sample_size, int seed_value){
    int successes = 0;
    double precision = 0.0;
    for (int i = 0; i < trials; i++){
        random_sample = dist->sample(sample_size, seed_value);
        vector<double> confidence_interval = dist->calculate_confidence_interval(random_sample, sample_size, t_value);
        if (dist->getmean() >= confidence_interval[0] && dist->getmean() <= confidence_interval[2])
            successes++; //increases if calculated confidence interval coveres the theoretical mean
        seed_value++; //increment seed_value by 1 at each trial not to get same sample 
    }
    precision = successes / (double)trials; //precision equation
    return precision;
}