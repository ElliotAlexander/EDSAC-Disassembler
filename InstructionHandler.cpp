#include "headers/InstructionHandler.h"
using namespace std;
StructuredInstruction InstructionHandler::parseInstruction(string str_in) {
    if(str_in.length() > 35 || str_in.length() < 17){
      cout << ((str_in.length() > 35) ? 
        ("\nWarning: Input line:\n\t" + str_in + "\nIs too long, and will be ignored.\n") :
        ("\nWarning: Input line \n\t" + str_in + "\nIs too short, and will be ignored.\n\n"));
      return (StructuredInstruction) {};
    } else {
      return (StructuredInstruction) {
        str_in.substr(0,5),
        str_in.substr(5,1),
        str_in.substr(6,10),
        str_in.substr(16, 1),
        stoi(str_in.substr(0, 5), nullptr, 2),
        stoi(str_in.substr(6, 10), nullptr, 2),
        (int) (str_in.back()),
        true
      };
    }
}
