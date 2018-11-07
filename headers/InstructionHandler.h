#ifndef INSTRUCTIONS_H_   /* Include guard */
#define INSTRUCTIONS_H_

#include <string>
#include <vector>
#include <iostream>
#include <cstring>

struct StructuredInstruction {
    std::string operand_binary;
    std::string unused_bit_binary;
    std::string address_binary;
    std::string length_bit_binary;
    int operand;
    int address;
    int extended;
    bool valid;     // is this strucure set - or empty. 
};

class InstructionHandler {
    public:
        StructuredInstruction parseInstruction(std::string str_in);
};

#endif 
