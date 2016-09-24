/*
 * random.c
 *
 *  Created on: Sep 19, 2016
 *      Author: YS
 */

#include <stdlib.h>
#include <time.h>

//
// 最好能改一下第二个函数名使之与作业要求相同。
// assignment asks for 2 functions :[urand(),randexp()]
//

double urand(void){
    srand((unsigned)time(NULL));
    return (rand()%100)/100.0;
}


double get_exp_rand(double mean){
    return  -mean*(log(1.0 - urand()));
}
