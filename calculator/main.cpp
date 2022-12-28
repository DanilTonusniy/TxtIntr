#include <iostream>
#include <getopt.h>
using namespace std;
int main(int argc, char *argv[])
{
    if(argc == 1) {
        cout << "Calculator " << endl << "Доступные операции:" << endl <<
             "-m - произведение введённых значений;" << endl <<
             "-d - деление первого операнда на все остальные." << endl;
        return 0;
    }
    int i, opt, multiplication_result = 1, division_result = 1, a, b = 1, x;
    while((opt = getopt(argc, argv, "m:d")) != -1) {
        switch(opt) {
        case 'm':
            for(i=2; i<argc; i++) {
                x = strtol(argv[i], NULL, 10);
                multiplication_result = multiplication_result*x;
            }
            printf("Результат выполнения операции = %d\n", multiplication_result);
            break;
        case 'd': {
            a = strtol(argv[2], NULL, 10);
            for(i=2; i<argc; i++) {
                x = strtol(argv[i], NULL, 10);
                b = b*x;
                division_result = a/(b/a);
            }
            if(division_result < 1) {
                cout << "Операнды были введены неверно" << endl;
                break;
            } else {
                printf("Результат выполнения операции = %d\n", division_result);
                break;
            }
        }
        }
    }
}
