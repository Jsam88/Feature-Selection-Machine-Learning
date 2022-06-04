#ifndef STRINGTONUM_H
#define STRINGTONUM_H
#include <string>
using namespace std;

double string_to_IEEE(string& data_IEEE) {                                

    double converted_number = stod(data_IEEE.substr(0, data_IEEE.find('e')));                //Position of first index till it hits e... String of IEEE to double
    int biased_exponent  = stoi(data_IEEE.substr(data_IEEE.find('e') + 1, 4));               //Position after e to get the biased exponent... String of exponent in IEEE integer

    if (biased_exponent <= 0) {                                                              //if its less than or equal to 0 (- sign) then we divide by 10
        for (int i = biased_exponent; i < 0; i++) {                                          //This is because we have to get rid of the e
            converted_number = converted_number / 10;
        }
    }

    else {                                                                                   //if its any value greater than 0 (+ sign) then we multiply by 10
        for (int i = 0; i < biased_exponent; i++) {                                          //we multiply by 10 x amount of times depending on the exponent.
            converted_number = converted_number * 10;                                        //(1 times if exponent 1, 2 times if exponent 2, etc)
        }
    }
    // cout << data_IEEE << endl;           //Testing if the string is properly brought over from data
    // cout << converted_number << endl;    //Testing if the number is properly converted and changed from biased exponent
    return converted_number;
}

#endif

//Sources used:
/*
https://www.geeksforgeeks.org/ieee-standard-754-floating-point-numbers/#:~:text=Special%20Values%3A%20IEEE%20has%20reserved,though%20they%20both%20are%20equal.
https://www.cplusplus.com/reference/string/stod/
https://www.cplusplus.com/reference/string/stoi/
*/