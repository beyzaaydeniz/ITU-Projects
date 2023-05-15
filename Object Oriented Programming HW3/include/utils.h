//--- 2021-2022 Summer Object Oriented Programing Assignment 3 ---//
//--------------------------//
//---Name & Surname: Beyza Aydeniz
//---Student Number: 150200039
//--------------------------//

//-------------Do Not Add New Libraries-------------//
//-------------All Libraries Needed Were Given-------------//

#ifndef __UTILS_H
#define __UTILS_H
using namespace std;

#include "statistics.h"

StatisticalDistribution *choose_function(int);
double many_trials(StatisticalDistribution *, vector<double>, double, int, int, int);

#endif