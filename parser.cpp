#include <iostream>
#include <fstream>
#include <array>
#include <string>

using namespace std;

typedef struct token{
    string name;
    int& refer;
    token(string namenew, int& refernew) : name(namenew), refer(refernew){} //constructor
};

void parser(string file, token* input, int size){
    ifstream fin;
    fin.open(file, ios::in); //open file

    if (fin.is_open()){  //checks if file was opened
        string storage;

        while(getline(fin, storage)){  //read data from file object and put it into buffer
            if(!storage.empty()){    //chechs if line is empty
                size_t pos = storage.find("=");
                string name = storage.substr(0, pos);
                for(int i = 0; i < size; i++){
                    if(name == input[i].name){  //search for variable in token array
                        storage = storage.substr(pos+1);
                        input[i].refer = stoi(storage); //assign value
                    }
                }
            }
        }
        fin.close();
    }
    else{    //if file couldn't be opened print error message
        cerr << "error: open file for parser failed!" << endl;
        abort();
    }
}

int main (){
    // declare variables
    int var1;
    int var2;
    int var3;

    // declare reference variables
    int& ref1 = var1;
    int& ref2 = var2;
    int& ref3 = var3;

    //create token
    token t1("var1", ref1);
    token t2("var2", ref2);
    token t3("var3", ref3);

    array<token, 3> input = {t1, t2, t3};

    string file = "config.txt";

    parser(file, &input[0], input.size());

    cout << input[0].name << " " << input[0].refer << endl;
    cout << t2.name << " " << t2.refer << endl;
    cout << t3.name << " " << t3.refer << endl;

    return 0;
}
