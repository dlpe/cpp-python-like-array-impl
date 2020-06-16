#include "timer.h"

int main(int argc, char **argv) {
   long soma = 0;

   Timer::time();

   auto ate = pow(100, 4);
   for (int i = 0; i < ate; i++) {
      soma++;
   }

   Timer::stop();

   std::cout << "Soma: " << soma << std::endl;
}

