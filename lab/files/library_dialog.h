/*! 
   \file
   \brief Header file with description dialog functions
*/

#ifndef LIBRARY_DIALOG_H
#define LIBRARY_DIALOG_H

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
int conv_s_dialog();


#endif
