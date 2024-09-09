#ifndef LIBRARY_H
#define LIBRARY_H

using std::string;

struct dict
{
        char word[20];
        string meaning;
        int emphasis;
};


int conv_f_dialog();
string conversion_first(dict item, string name);

int conv_s_dialog();
dict conversion_second(string input);                       //string
dict conversion_second(const char* input);                  //const char*
dict conversion_second(const char* symbols, size_t length); //const char* + size_t


#endif
