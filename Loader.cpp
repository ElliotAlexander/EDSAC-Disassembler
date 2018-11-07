#include "headers/Loader.h"
using namespace std;

Loader::Loader(){
  cout << "Initialising file loader\n";
};

bool Loader::LoadFile(string fileName, vector<string> & vecOfStrs){
  {
    ifstream in(fileName.c_str());
    if(!in)
    {
      cerr << "Cannot open the File : "<<fileName<<endl;
      return false;
    } else {
      string str;
      while (getline(in, str))
      {
        if(str.size() > 0)
          vecOfStrs.push_back(str);
      }
      in.close();
      return true;
    }
  }
};

