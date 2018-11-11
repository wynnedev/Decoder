/*
 * Decoder
 * Wynne Nicholas
 * This program decodes messages using three decoders
 * One for UpperCase using  modulo of 27
 * One for LowerCase using modulo of 27
 * One for Punctuation using Modulo of 9
 * The program will shift to the next decoder when modulo of value is 0
 *
 */

#include <iostream>
#define EOL 10
#define DELIMETER ','

enum Decoder{UPPER = 64, LOWER = 96, PUNCTUATION = 32};

int main() {
    int num = 0;
    int position = 10;
    char digit{'0'};
    char output;
    char punctuation[] = {' ','!','?',',','.',' ',';','"','\''};
    Decoder decoder = UPPER;



    while(digit != EOL){
        if(DELIMETER == digit) {
            num = 0;
        }
            digit = std::cin.get();
        while((digit != DELIMETER) && (digit != EOL)) {
            num = num * position + int(digit - 48);
            digit = std::cin.get();
        }
        switch(decoder){
            case UPPER:
                output = num%27;
                if(0 == output){
                    decoder = LOWER;
                }

                else{
                    std::cout << char(output + UPPER);
                }
                break;

            case LOWER:
                output = num%27;
                if(0 == output){
                    decoder = PUNCTUATION;
                }

                else{
                    std::cout << char(output + LOWER);
                }
                break;

            case PUNCTUATION:
                output = num%9;
                if(0 == output){
                    decoder = UPPER;
                }

                else{
                    std::cout << punctuation[(output)];
                }
                break;
        }
    }
    return 0;
}