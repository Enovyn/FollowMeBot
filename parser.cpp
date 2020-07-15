#include <iostream>
#include <string>

using namespace std;

typedef struct token {
  string name;
  int& refer;
  token(string namenew, int&refernew) : name(namenew), refer(refernew) {}
};

int main () {
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

   //test print
   var1 = 12;
   var2 = 42;
   var3 = 1;

   cout << t1.refer << endl;
   cout << t2.refer << endl;
   cout << t3.refer << endl;

   return 0;
}
