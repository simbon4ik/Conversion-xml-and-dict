#include <iostream>
#include <string>
#include "input.h"
#include <cstring>

using std::cin;
using std::endl;
using std::cout;
using std::string;
using std::getline;


struct dict
{
        char word[20];
        string meaning;
        int emphasis;
};


dict conversion_second(string input);
dict conversion_second(const char* input);              //const char*
dict conversion_second(const char* symbols, size_t length);


int conv_s_dialog(){
        string input;
        cout << "Enter xml string (format: <record> <word>apple</word> <meaning>round fruit</meaning> <emphasis>1</emphasis> </record>" << endl;
        getline(cin, input);
        
        //1const char* input = "<record> <word>apple</word> <meaning>round fruit</meaning> <emphasis>1</emphasis> </record>";   for test const char*
        
        //2const char symbols[] = {'<','r','>','<','w','o','r','d','>','a','<','/','w','o','r','d','>','<','m','e','a','n','i','n','g','>','r',' ','f','<','/','m','e','a','n','i','n','g','>','<','e','m','p','h','a','s','i','s','>','1','<','/','e','m','p','h','a','s','i','s','<','/','r','>'};
        //2size_t length = 64; 
        //2dict result = conversion_second(symbols, length);            for test const char* + size_t 

        dict result = conversion_second(input);
        cout << "Result is:\nword = " << result.word << "\nmeaning = " << result.meaning << "\nemphasis = " << result.emphasis << endl;
        return 0;
}

        
dict conversion_second(const char* input){              //const char*
        string input_mod = input;
        return conversion_second(input_mod);
}


dict conversion_second(const char* symbols, size_t length){
        char* input = new char[length+1];
        for (int i = 0; i < length; i++)
                input[i] = symbols[i];
        input[length] = '\0';
        string input_mod = input;
        delete[] input;
        return conversion_second(input_mod);
}


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


string conversion_first(dict item, string name);


int conv_f_dialog(){
        string name;
        dict item;
        cout << "Enter the word (Max len is 20 symbols)" << endl;
        cin.getline(item.word, 20);
        cout << "Enter the meaning" << endl;
        getline(cin, item.meaning);
        cout << "Enter the name of record" << endl;
        getline(cin, name);
        cout << "Enter the emphasis" << endl;
        cin >> item.emphasis;
        string result = conversion_first(item, name);
        cout << "Result is:\n" << result << endl;
        return 0;
}


string conversion_first(dict item, string name){
        string result = '<' + name + '>' + "\n\t<word>" + item.word + "</word>\n\t<meaning>" + item.meaning + "<meaning>\n\t<emphasis>" +std::to_string(item.emphasis) + "</emphasis>\n</"+ name + ">\n";
        return result;
}


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
        


