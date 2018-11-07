#include "headers/parser.h"
using namespace std;

Parser::Parser()
{
    std::cout << "Initialising Parser...\n";
    buildOperandMeaningShort();
    buildOperamingMeaningLong();
    buildOperandLetterRepresentation();
};

void Parser::ParseLine(StructuredInstruction si)
{
    Operators opcode = static_cast<Operators>(si.operand);
    string meaning = si.extended ? operandMeaningLong.find(opcode)->second : operandMeaningShort.find(opcode)->second;
    meaning = replaceAddress(si.address, meaning);

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
        << "\t| Meaning: " << meaning
        //<< replaceAddress(s)
        << endl;
}

void Parser::buildOperandMeaningShort()
{
    operandMeaningShort[Operators::A] = "A += m[$1]";
    operandMeaningShort[Operators::S] = "A -= m[$1]";
    operandMeaningShort[Operators::H] = "R += m[$1]";
    operandMeaningShort[Operators::V] = "AB += m[$1] * R";
    operandMeaningShort[Operators::N] = "AB -= m[$1] * R";
    operandMeaningShort[Operators::T] = "m[$1] = A; ABC = 0";
    operandMeaningShort[Operators::U] = "m[$1] = A";
    operandMeaningShort[Operators::C] = "AB += m[$1] & R";
    operandMeaningShort[Operators::R] = "ABC << <position of least significant bit>";                      // TODO - Ask about this
    operandMeaningShort[Operators::L] = "ABC >> <position of least significant one in shift instruction>"; // See above
    operandMeaningShort[Operators::E] = "if A >= 0 goto $1";
    operandMeaningShort[Operators::G] = "if A < 0 goto $1";
    operandMeaningShort[Operators::I] = "Place the next paper tape character in the least significant 5 bits of N.";
    operandMeaningShort[Operators::O] = "wr(m[$1])";
    operandMeaningShort[Operators::F] = "<verify last character output>";
    operandMeaningShort[Operators::X] = "No operation";
    operandMeaningShort[Operators::Y] = "Add one to bit position 35 of ABC";
    operandMeaningShort[Operators::Z] = "stop";
    operandMeaningShort[Operators::HASH] = "data 11<<12";        // ???? - TODO
    operandMeaningShort[Operators::EXCLAMATION] = "data 20<<12"; // ??? Space character? TODO
    operandMeaningShort[Operators::AMPERSAND] = "data 24<<12";   // line feed
    operandMeaningShort[Operators::AT] = "data 18<<12";          // CR s
};

void Parser::buildOperamingMeaningLong()
{
    operandMeaningLong[Operators::A] = "AB += m[$1]";
    operandMeaningLong[Operators::S] = "AB -= m[$1]";
    operandMeaningLong[Operators::H] = "RS += m[$1]";
    operandMeaningLong[Operators::V] = "ABC += m[$1] * R";
    operandMeaningLong[Operators::N] = "ABC -= m[$1] * R";
    operandMeaningLong[Operators::T] = "m[$1] = AB; ABC = 0";
    operandMeaningLong[Operators::U] = "m[$1] = AB";
    operandMeaningLong[Operators::C] = "ABC += m[$1] & RS";
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
operandLetterRepresentation[Operators::HASH] = '#';
operandLetterRepresentation[Operators::EXCLAMATION] = '!';
operandLetterRepresentation[Operators::AMPERSAND] = '&';
operandLetterRepresentation[Operators::AT] = '@';
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
