#include <iostream>

#pragma pack(1)

struct Struct {
   int inteiro;
   long longo;
   char caractere;

   void print() {
      std::cout << this->inteiro << std::endl;
   }
};


std::ostream& operator<<(std::ostream &os, const Struct& s) {
   os << "Struct {" << s.inteiro << "," << s.longo << "}" << std::endl;
   return os;
}

int main(int argc, char **argv) {

   Struct s = {3, 5, 'a'};
   
   std::cout << (long)&s << std::endl; 
   std::cout << *&s << std::endl; 
   std::cout << *(int*)&s << std::endl;

   for (int i=0; i < 20; i++) {
       std::cout << (int*)&s + i << " " << *(bool*)((int*)&s + i) << std::endl;
   }

   for (int i=0; i < 20; i++) {
       std::cout << (int*)&s - i << " " << *(bool*)((int*)&s - i) << std::endl;
   }

   std::cin.get();

   long inteiro = 4294967200;
   std::cout << inteiro << std::endl;
   std::cout << sizeof(inteiro) << std::endl;
   std::cout << &inteiro << std::endl;
   std::cout << sizeof(&inteiro) << std::endl;


   std::cout << *(&inteiro + 0) << std::endl;
   std::cout << *(&inteiro + 1) << std::endl;
   std::cout << *(&inteiro + 2) << std::endl;
   std::cout << *(&inteiro + 3) << std::endl;

   std::cout << *(&inteiro + 3) << std::endl;
}
