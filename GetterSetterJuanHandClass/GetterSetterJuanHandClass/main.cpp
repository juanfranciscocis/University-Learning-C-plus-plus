//
//  main.cpp
//  GetterSetterJuanHandClass
//
//  Created by Juan Cisneros on 9/29/21.
//



#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

int main() {
    ifstream inFile;
    inFile.open("temp.txt");
    
    string type;
    string varName;
    const string parameter="in";
    string total="";
    if(!inFile.is_open()){
        cout<<"Bad";
        return 9;
    }
    
    string className;
    inFile>>className;
    
    while(inFile>>type){
        inFile>>varName;
        char firstChar=toupper(varName.substr(0,1).c_str()[0]);
        string newVarName=firstChar+varName.substr(1,varName.size()-2);
        
        
        total+="void set"+newVarName+"("+type+" in);\n\n";
        total+=type+" get"+newVarName+"();\n\n";
    }
    
    inFile.close();
    inFile.open("temp.txt");
    
    if(!inFile.is_open()){
        cout<<"Bad";
        return 9;
    }
    
    inFile>>className;
    
    while(inFile>>type){
        inFile>>varName;
        char firstChar=toupper(varName.substr(0,1).c_str()[0]);
        string newVarName=firstChar+varName.substr(1,varName.size()-2);
        
        
        total+="void "+className+"::set"+newVarName+"("+type+" in){\n"+varName.substr(0,varName.size()-1)+"="+"in;"+"\n}\n\n";
        total+=type+" "+className+"::get"+newVarName+"() const {\nreturn "+varName+"\n}\n\n";
        
    }
    inFile.close();
    
    ofstream out;
    out.open("temp.txt");
    
    out<<endl;
    out<<total;
    out<<endl;
    out.close();
}
