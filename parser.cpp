#include <iostream>
#include <fstream>
#include <array>

using namespace std;

typedef struct token{
    char name[10];
    int& refer;
    token(char namenew[10], int&refernew) : refer(refernew)
    {
        copy(namenew, namenew+10, name);
    }
};
//char* file, token* input
void parser(char* file){
    ifstream fin;
    fin.open(file, ios::in); //open file

    if (fin.is_open()){ //checks if file was opened
        char storage[20];

        while(fin.getline(storage, 20)){ //read data from file object and put it into buffer
         cout << storage << "\n"; //print the data
        }
        fin.close();
    }
    else{   //if file couldn't be opened print error message
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

    var1 = 8;
    var2 = 16;
    var3 = 70;

    cout << input[0].name << " " << input[0].refer << endl;
    cout << t2.name << " " << t2.refer << endl;
    cout << t3.name << " " << t3.refer << endl;

    char file[] = "C:\\Users\\yvonn\\Desktop\\OTH\\6.Semester\\DatenverarbeitungTechnik\\Parser\\config.txt";

    parser(file);


    return 0;
}
