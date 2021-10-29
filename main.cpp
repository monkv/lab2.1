#include <iostream>
#include <vector>
#include "binary.h"

std::vector<std::string> MENU_MSG = {"0. Quit", "1. Default Initialization", "2. Initialization by long ", "3.Initialization by array",
                                     "4. Initialization ", "5. Get two’s complement (доп. код)", "6. Addition two numbers",
                                     "7. Увеличить число до использования",
                                     "8. Уменьшить число после его использования", "9. Узнать знак числа"};
int main() {
    int c = 0;
    binary_num NUM;
    do {
        for (int i = 0; i < MENU_MSG.size(); i++)
            std::cout << MENU_MSG[i] << "\n";
        std::cout << "\nChoose an option: ";
        std::cin >> c;
        switch (c){
            case 0:{
                break;
            }
            case 1:{
                NUM = binary_num();
                break;
            }
            case 2:{
                std::cout << "\nEnter a decimal number (type long): ";
                long a;
                std::cin >> a;
                try {
                    NUM = binary_num(a);
                }
                catch (std::invalid_argument &msg){
                    std::cerr << msg.what() << std::endl;
                }
                break;
            }
            case 3:{
                std::cout << "\nEnter a decimal number (string): ";
                std::string input;
                std::cin >> input;
                try{
                    NUM = binary_num(input);
                }
                catch (std::invalid_argument &msg){
                    std::cerr << msg.what() << std::endl;
                }
                break;
            }
            case 4:{
                std::cout << "\nEnter a binary number (string): ";

                break;
            }
            case 5:{
                std::cout << "\nThe twos-component : ";
                char* buf = NUM.get_twos_complement();
                std::cout << buf; //нет
                break;
            }
            case 6:{
                if (NUM.get_sign()){
                    std::cout << "\nEnter a positive  number: ";
                }
                else{
                    std::cout << "\nEnter a negative  number: ";
                }

                break;
            }
            case 7:{
                char* result1 = NUM.increment();
                std::cout << "\nresult";
                std::cout << std::endl;
                break;
            }
            case 8:{
                char* result2 = NUM.decrement();
                std::cout << "\nresult";

                std::cout << std::endl;
                break;
            }
            case 9:{
                long a;
                if (NUM.get_sign())
                    std::cout << "\nthe number is negative" << std::endl;
                else
                    std::cout << "\nthe number is postive" << std::endl;
                break;
                std::cin >> a;
                binary_num NUM2 = binary_num(a);

            }
        }
    } while (c);
    return 0;
}