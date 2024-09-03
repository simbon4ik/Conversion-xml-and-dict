#include <iostream>
#include <string>

using namespace std;

class dict
{
        public:
        char word[20];
        string meaning;
        int emphasis;
};


string conversion_first(string &result, dict new_word){
        string name;
        cout << "Enter the name of record" << endl;
        cin >> name;
        result = '<' + name + '>' + "\n\t<word>" + new_word.word + "</word>\n\t<meaning>" + new_word.meaning + "<meaning>\n\t<emphasis>" + (char)new_word.emphasis+ "</emphasis>\n</"+ name + ">\n";
        return result;
}



int main(){
        string result;
        string &ref = result;
        dict new_word;
        cin >> new_word.word;
        new_word.meaning = "round fruit";
        new_word.emphasis = 1;
        cout << "Word is: " << new_word.word << endl << "Meaning is: " << new_word.meaning << endl << "Emphasis is: " << new_word.emphasis << endl;
        
        conversion_first(ref, new_word);

        cout << result << endl;

        return 0;
}



