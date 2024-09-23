#include <iostream>
#include <string>
#include <cstring>
#include <limits>
#include "input.h"
#include "library.h"

using std::string;

/*! 
    \brief First overload conversion xml to dict (const char*)
*/

dict conversion_second(const char* input){              //const char*
        string input_mod = input;
        return conversion_second(input_mod);
}


/*! 
    \brief Second overload conversion xml to dict (const char[] and size_t)
*/

dict conversion_second(const char* symbols, size_t length){
        char* input = new char[length+1];
        for (size_t i = 0; i < length; i++)
                input[i] = symbols[i];
        input[length] = '\0';
        string input_mod = input;
        delete[] input;
        return conversion_second(input_mod);
}

/*! 
    \brief Third overload conversion xml to dict (string) and main conversion

    For each area find start index and end + substr
*/


dict conversion_second(string input){                   //string
        dict result;
        int index = input.find("word") + 5;
        int index_2 = input.find("<",index);
        string word = input.substr(index , index_2 - index);
        strcpy(result.word, word.c_str());

        index = input.find("meaning") + 8;
        index_2 = input.find("<",index);
        result.meaning = input.substr(index, index_2 - index);

        index = input.find("emphasis") + 9;
        index_2 = input.find("<",index);
        result.emphasis = stoi(input.substr(index, index_2 - index));

        return result;
}


/*! 
    \brief Assembling the result in xml format

    \param name, item.word, item.meaning, item.emphasis are terms
    \return result in string xml format
*/
string conversion_first(dict item, string name){
        string result = '<' + name + '>' + "\n\t<word>" + item.word + "</word>\n\t<meaning>" + item.meaning + "</meaning>\n\t<emphasis>" +std::to_string(item.emphasis) + "</emphasis>\n</"+ name + ">\n";
        return result;
}
