#include <iostream>
#include "input.h"
#include "library.h"

using std::cin;
using std::endl;
using std::cout;
using std::string;
using std::getline;


int main(){
        try{

                int (*funcs[])() = {conv_f_dialog, conv_s_dialog};
                int number(0), status(1);
                do{
                        std::cout << "1. Conversion dict -> xml\n2. Conversion xml -> dict\n Enter the number of operation:" << std::endl;
                        number = getint(1,2);
                        status = funcs[number-1]();
                }while (status == 0);
        }
        catch(const std::runtime_error& e){
                std::cerr << e.what() << endl;
        }
        catch(const std::exception& e){
                std::cerr  << e.what() << endl;
        }
        return 0;
}
