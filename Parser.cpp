#include "headers/parser.h"
using namespace std;

Parser::Parser()
{
    std::cout << "Initialising Parser...\n";
    buildOperandMeaningShort();
    buildOperandLetterRepresentation();
};

void Parser::ParseLine(StructuredInstruction si)
{
    Operators opcode = static_cast<Operators>(si.operand);
    string meaning = replaceAddress(si.address, operandMeaningShort.find(opcode)->second);

    // Print full binary string.
    cout << si.operand_binary << "  " << si.unused_bit_binary << "  " << si.address_binary << "  " << si.length_bit_binary;
    cout << "|\t" 
        // Print Operator representation in Letter form - i.e. S
        << operandLetterRepresentation.find(static_cast<Operators>(si.operand))->second 
        // Print address field
        << si.address 
        // Print S / L depending on whether the address field is extended.
        << getExtendedString(si.extended)
        // Print generic meaning for each statement, with arguments substituted in.
        << "\t| " << meaning
        //<< replaceAddress(s)
        << endl;
}

void Parser::buildOperandMeaningShort()
{
    operandMeaningShort[Operators::A] = "Add the number in storage location $1 into the accumulator";
    operandMeaningShort[Operators::S] = "Subtract the number in storage location $1 from the accumulator";
    operandMeaningShort[Operators::H] = "Copy the number in storage location $1 into the multiplier register";
    operandMeaningShort[Operators::V] = "Multiply the number in storage location $1 by the number in the multiplier register and add the product into the accumulator";
    operandMeaningShort[Operators::N] = "Multiply the number in storage location $1 by the number in the multiplier register and subtract the product from the accumulator";
    operandMeaningShort[Operators::T] = "Transfer the contents of the accumulator to storage location $1 and clear the accumulator";
    operandMeaningShort[Operators::U] = "Transfer the contents of the accumulator to storage location $1 and do not clear the accumulator";
    operandMeaningShort[Operators::C] = "Collate [logical and] the number in storage location $1 with the number in the multiplier register and add the result into the accumulator";
    operandMeaningShort[Operators::R] = "Shift the number in the accumulator $1 places to the right";                      
    operandMeaningShort[Operators::L] = "Shift the number in the accumulator n places to the left";
    operandMeaningShort[Operators::E] = "If the sign of the accumulator is positive, jump to location $1; otherwise proceed serially";
    operandMeaningShort[Operators::G] = "If the sign of the accumulator is negative, jump to location $1; otherwise proceed serially";
    operandMeaningShort[Operators::I] = "Read the next character from paper tape, and store it as the least significant 5 bits of location $1";
    operandMeaningShort[Operators::O] = "Print the character represented by the most significant 5 bits of storage location $1";
    operandMeaningShort[Operators::F] = "Read the last character output for verification";
    operandMeaningShort[Operators::X] = "No operation";
    operandMeaningShort[Operators::Y] = "Round the number in the accumulator to 34 bits";
    operandMeaningShort[Operators::K] = "// TODO?";
    operandMeaningShort[Operators::Z] = "stop";
    operandMeaningShort[Operators::HASH] = "data 11<<12";        // ???? - TODO
    operandMeaningShort[Operators::EXCLAMATION] = "data 20<<12"; // ??? Space character? TODO
    operandMeaningShort[Operators::AMPERSAND] = "data 24<<12";   // line feed
    operandMeaningShort[Operators::AT] = "data 18<<12";          // CR s
    operandMeaningShort[Operators::P] = "data $1 - Meaning?";
};

void Parser::buildOperandLetterRepresentation()
{
operandLetterRepresentation[Operators::A] = 'A';
operandLetterRepresentation[Operators::S] = 'S';
operandLetterRepresentation[Operators::H] = 'H';
operandLetterRepresentation[Operators::V] = 'V';
operandLetterRepresentation[Operators::N] = 'N';
operandLetterRepresentation[Operators::T] = 'T';
operandLetterRepresentation[Operators::U] = 'U';
operandLetterRepresentation[Operators::C] = 'C';
operandLetterRepresentation[Operators::R] = 'R';
operandLetterRepresentation[Operators::L] = 'L';
operandLetterRepresentation[Operators::E] = 'E';
operandLetterRepresentation[Operators::G] = 'G';
operandLetterRepresentation[Operators::I] = 'I';
operandLetterRepresentation[Operators::O] = 'O';
operandLetterRepresentation[Operators::F] = 'F';
operandLetterRepresentation[Operators::X] = 'X';
operandLetterRepresentation[Operators::Y] = 'Y';
operandLetterRepresentation[Operators::Z] = 'Z';
operandLetterRepresentation[Operators::K] = 'K';
operandLetterRepresentation[Operators::HASH] = '#';
operandLetterRepresentation[Operators::EXCLAMATION] = '!';
operandLetterRepresentation[Operators::AMPERSAND] = '&';
operandLetterRepresentation[Operators::AT] = '@';
operandLetterRepresentation[Operators::P] = 'P';
};

string Parser::getExtendedString(int i){
    return (i == 1 ? "L" : "S");
}


string Parser::replaceAddress(int address, string meaning){
    size_t index = 0;
    index = meaning.find("$1", index);
    if (index == std::string::npos) return meaning;

     /* Make the replacement. */
    meaning.replace(index, to_string(address).length(), to_string(address));
    return meaning;
}
