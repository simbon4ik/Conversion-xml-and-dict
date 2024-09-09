#include <iostream>
#include "input.h"
#include "library.h"

using std::cin;
using std::endl;
using std::cout;
using std::string;
using std::getline;


int main(){
        int (*funcs[])() = {conv_f_dialog, conv_s_dialog};
        int number(0), status(0);
        int& num = number;
        do{
                std::cout << "1. Conversion dict -> xml\n2. Conversion xml -> dict\n Enter the number of operation:" << std::endl;
                int er = getint(num, 1, 2);
                if (er == EOF){
                        return 0;
                }
               status = funcs[number-1]();
        }while (status == 0);
        return 0;
}
