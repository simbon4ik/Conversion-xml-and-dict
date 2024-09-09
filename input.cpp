#include <stdio.h>
#include <iostream>

using namespace std;

int getint(int& cnt, int a, int b){
        int op = 1;
        do{
                op = scanf("%d", &cnt);
                if (op == EOF) return EOF;
                if ((op == 0) || (a > cnt) || (cnt > b)){
                        cout << "Repeat input" << endl;
                        op = 0;
                        scanf("%*[^\n]");
                }
                if (op == 1){
                        scanf("%*c");
                        return 1;
                }
        }while (op == 0);
        return op;
}
