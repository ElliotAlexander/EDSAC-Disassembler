#include "headers/main.h"
using namespace std;

int main(int argc, char** argv){
    if (argc==1) { cout << "Failed to open file\n"; }
    else {
        InstructionHandler i = InstructionHandler();
        Parser p;
        std::vector<std::string> lines;
        if((Loader().LoadFile(argv[1], lines))){ 
            for(std::string & line : lines) {
                StructuredInstruction x = i.parseInstruction(line);
                if (x.valid)
                {
                    p.ParseLine(x);
                };
            }
        };
    }
}
