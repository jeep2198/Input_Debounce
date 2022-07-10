/**
 * @file inputDebounce.cpp
 * @author Felícito Manzano (felicito.manzano@detektor.com.sv)
 * @brief 
 * @version 0.1
 * @date 2020-10-01
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "mbed.h"


/**
 * @brief 
 * 
 */
const int SAMPLES_INPUT = 4;  
const int SAMPLES_RAIN  = 10;    



/**
 * @brief 
 * 
 * @param Ign 
 * @param arrayIgn 
 * @param actIgn 
 * @param preIgn 
 * @param cont 
 * @return int 
 */
int exeIgnition(DigitalIn *Ign, bool arrayIgn[], bool *actIgn, bool *preIgn, int *cont) {
    bool are_equal = false;
    int answer = 0;
    int i;

    arrayIgn[*cont] = Ign -> read();   
    *cont = *cont + 1; 

    if (*cont == SAMPLES_INPUT) {
        *cont = 0;                
        
        //are_equal = (((arrayIgn[0] == arrayIgn[1]) == arrayIgn[2]) == arrayIgn[3]);
        for (i = 0; i < SAMPLES_INPUT; i++) {
            if (arrayIgn[i] != arrayIgn[0]) {
                are_equal = false;
                break;
            } else {
                are_equal = true;
            }
        }
        if(are_equal) {
            *actIgn = arrayIgn[0];
            if (*actIgn != *preIgn) {
                *preIgn = *actIgn;
                if (*actIgn) {
                    answer = 1;
                } else {
                    answer = -1;              
                }
            } else {
                answer = 0;
            }
        }
    }
    return(answer);
}



/**
 * @brief 
 * 
 * @param my_Input 
 * @param my_arrayInput 
 * @param my_Input_read 
 * @param my_Input_previous 
 * @param cont 
 * @return int 
 */
int exeDigInput(DigitalIn *my_Input, bool my_arrayInput[], bool *my_Input_read, bool *my_Input_previous, int *cont) {
    bool are_equal = false;
    int answer = 0;
    int i;

    my_arrayInput[*cont] = my_Input -> read();
    *cont = *cont + 1; 
 
    if (*cont == SAMPLES_INPUT) {
        *cont = 0;                      
        //are_equal = (((my_arrayInput[0] == my_arrayInput[1]) == my_arrayInput[2]) == my_arrayInput[3]);
        for (i = 0; i < SAMPLES_INPUT; i++) {
            if (my_arrayInput[i] != my_arrayInput[0]) {
                are_equal = false;
                break;
            } else {
                are_equal = true;
            }
        }
        

        if (are_equal) {
            *my_Input_read = my_arrayInput[0];
            if (*my_Input_read != *my_Input_previous) {
                *my_Input_previous = *my_Input_read;
                if (*my_Input_read) {
                    answer = 1;
                } else {
                    answer = -1;
                }
            } 
        } else {
            answer = 0;
        }
    }
    return(answer);
 }


/**
 * @brief 
 * 
 * @param my_Input 
 * @param my_arrayInput 
 * @param my_Input_read 
 * @param my_Input_previous 
 * @param cont 
 * @return int 
 */
int exeDigRain(DigitalIn *my_Input, bool my_arrayInput[], bool *my_Input_read, bool *my_Input_previous, int *cont) {
    bool are_equal = false;
    int answer = 0;
    int i;

    my_arrayInput[*cont] = my_Input -> read();
    *cont = *cont + 1; 
 
    if (*cont == SAMPLES_RAIN) {
        *cont = 0;                      
        //are_equal = (((my_arrayInput[0] == my_arrayInput[1]) == my_arrayInput[2]) == my_arrayInput[3]);
        //are_equal = (((are_equal == my_arrayInput[4]) == my_arrayInput[5]) == my_arrayInput[6]);
        //are_equal = (((are_equal == my_arrayInput[7]) == my_arrayInput[8]) == my_arrayInput[9]);
        for (i = 0; i < SAMPLES_RAIN; i++) {
            if (my_arrayInput[i] != my_arrayInput[0]) {
                are_equal = false;
                break;
            } else {
                are_equal = true;
            }
        }


        if (are_equal) {
            *my_Input_read = my_arrayInput[0];
            if (*my_Input_read != *my_Input_previous) {
                *my_Input_previous = *my_Input_read;
                if (*my_Input_read) {
                    answer = 1;
                } else {
                    answer = -1;
                }
            } 
        } else {
            answer = 0;
        }
    }
    return(answer);
 }

