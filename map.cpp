#include <cmath>

#include <vector>
#include "timer.h"

int main() {
   int size = pow(100,3);
   int soma = 0;
   int arr[size];
   int newArr[size];

   Timer::time();

   for (int i = 0; i < size; i++) {
      soma++;
      arr[i] = soma;
   }

   for (int i = 0; i < size; i++) {
      newArr[i] = arr[i] * 3;
   }

   Timer::stop();
}
