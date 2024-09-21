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

/*! 
    \brief Assembling the result in xml format

    \param name, item.word, item.meaning, item.emphasis are terms
    \return result in string xml format
*/
string conversion_first(dict item, string name){
        string result = '<' + name + '>' + "\n\t<word>" + item.word + "</word>\n\t<meaning>" + item.meaning + "<meaning>\n\t<emphasis>" +std::to_string(item.emphasis) + "</emphasis>\n</"+ name + ">\n";
        return result;
}
