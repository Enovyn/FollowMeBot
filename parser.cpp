#include <iostream>

using namespace std;

typedef struct token {
  char name[10];
  int& refer;
  token(char namenew[10], int&refernew) : refer(refernew) {copy(namenew, namenew+10, name);}
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

   var1 = 12;
   var2 = 42;
   var3 = 1;

   cout << t1.name << " " << t1.refer << endl;
   cout << t2.name << " " << t2.refer << endl;
   cout << t3.name << " " << t3.refer << endl;

   return 0;
}
