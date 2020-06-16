#include <iostream>
#include <chrono>
#include <cmath>

class Timer {
private:
   std::chrono::time_point<std::chrono::high_resolution_clock> start;

public:
   Timer() {
       start = std::chrono::high_resolution_clock::now();
   }

   ~Timer() {
       auto end = std::chrono::high_resolution_clock::now();
       auto duration = end - start;
       auto ms =  std::chrono::duration_cast<std::chrono::milliseconds>(duration);
       std::cout << ms.count() << "ms" << std::endl;
       std::cout << ms.count() / 1000.0 << "s" << std::endl;
   }
};

int main(int argc, char **argv) {
   long soma = 0;
   //int pot;
   //std::cin >> pot;
   //std::cout << pot << std::endl;
   Timer timer;
   auto ate = pow(100, 4);
   for (int i = 0; i < ate; i++) {
      soma++;
   }
   std::cout << "soma: " << soma << std::endl;
}
