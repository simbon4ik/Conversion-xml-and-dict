/*! 
   \file
   \brief Header file with description main functions
*/

#ifndef LIBRARY_H
#define LIBRARY_H

using std::string;

/*!
    \brief Dictionary class
*/

struct dict
{
        ///word in dictionary
        char word[20];      
        /// meaning of word
        string meaning;     
        /// emphasis word
        int emphasis;      
};

int conv_f_dialog();
string conversion_first(dict item, string name);

int conv_s_dialog();
dict conversion_second(string input);                       //string
dict conversion_second(const char* input);                  //const char*
dict conversion_second(const char* symbols, size_t length); //const char* + size_t


#endif
