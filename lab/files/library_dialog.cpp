#include <iostream>
#include <string>
#include <cstring>
#include <limits>
#include "input.h"
#include "library.h"

using std::cin;
using std::endl;
using std::cout;
using std::string;
using std::getline;


/*!
    \brief Dialog function xml to dict
    
    In this function we can conversion xml string to the dictionary type, also we can use different types for input (like string, const char *, const char [] and size_t
*/


int conv_s_dialog(){
        string input;
        cout << "Enter xml string (format: <record> <word>apple</word> <meaning>round fruit</meaning> <emphasis>1</emphasis> </record>)" << endl;\
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        getline(cin, input);

        //1const char* input = "<record> <word>apple</word> <meaning>round fruit</meaning> <emphasis>1</emphasis> </record>";   for test const char*

        //2const char symbols[] = {'<','r','>','<','w','o','r','d','>','a','<','/','w','o','r','d','>','<','m','e','a','n','i','n','g','>','r',' ','f','<','/','m','e','a','n','i','n','g','>','<','e','m','p','h','a','s','i','s','>','1','<','/','e','m','p','h','a','s','i','s','<','/','r','>'};
        //2size_t length = 64;
        //2dict result = conversion_second(symbols, length);            for test const char* + size_t

        dict result = conversion_second(input);
        cout << "Result is:\nword = " << result.word << "\nmeaning = " << result.meaning << "\nemphasis = " << result.emphasis << endl;
        return 0;
}


/*!
    \brief Dialog function dict to xml
    
    In this function we can conversion dictionary type to xml string
*/

int conv_f_dialog(){
        string name; dict item;
        cout << "Enter the name of record" << endl;
        getline(cin >> std::ws, name);
        cout << "Enter the word (Max len is 20 symbols)" << endl;
        cin.getline(item.word, 20);
        cout << "Enter the meaning" << endl;
        getline(cin, item.meaning);
        cout << "Enter the emphasis" << endl;
        cin >> item.emphasis;
        string result = conversion_first(item, name);
        cout << "Result is:\n" << result << endl;
        return 0;
}
