#ifndef PARSER_H_   /* Include guard */
#define PARSER_H_

#include "main.h"
#include <map>
#include <string>
#include "../InstructionBits.cpp"

class Parser
{
    public:
        std::map<Operators,std::string> operandMeaningShort;
        std::map<int,std::string> operandLetterRepresentation;


        Parser();
        void ParseLine(StructuredInstruction si);

    private: 
        void buildOperandMeaningShort();
        void buildOperamingMeaningLong();
        void buildOperandLetterRepresentation();
        std::string getExtendedString(int i);
        std::string replaceAddress(int address, std::string meaning);
};

#endif 