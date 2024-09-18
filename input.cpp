#include <iostream>
#include <limits>

using namespace std;

bool tryinput(int& num, int min, int max);


int getint(int a, int b){
        int res;
        while (!tryinput(res,a,b));
        return res;
}


bool tryinput(int& num, int min, int max){
        cin >> num;
        if (cin.eof()){
                throw runtime_error("EOF! Good bye!");
        }
        else if (cin.bad()){
                throw logic_error("Invalid input");
        }
        else if (cin.fail()){
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cout << "Repeat input, please, use int" << endl;
                return false;
        }
        else if ((num < min) || (num > max)){
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cout << "Repeat input, please\n";
                return false;
        }
        return true;
}
