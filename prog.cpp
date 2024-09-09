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

int conv_s_dialog(){                    //string
        string input;
        cout << "Enter xml string (format: <record> <word>apple</word> <meaning>round fruit</meaning> <emphasis>1</emphasis> </record>" << endl;
        getline(cin, input);
        dict result = conversion_second(input);
        cout << "Result is:\nword = " << result.word << "\nmeaning = " << result.meaning << "\nemphasis = " << result.emphasis << endl;
        return 0;
}

dict conversion_second(string input){
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
        


