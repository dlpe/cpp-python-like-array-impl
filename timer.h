#ifndef _MACRO_H
#define _MACRO_H

#include <iostream>
#include <memory>
#include <chrono>
#include <cmath>

class Timer {
private:
   static std::shared_ptr<const Timer> timer;
   static bool stopped;

   std::chrono::time_point<std::chrono::high_resolution_clock> start;

   Timer() {
       Timer::timer = NULL;
       Timer::stopped = false;
       start = std::chrono::high_resolution_clock::now();
   }

   void stopInstance() const {
       if (Timer::stopped) return;
       Timer::stopped = true;

       auto end = std::chrono::high_resolution_clock::now();
       auto duration = end - start;
       auto ms =  std::chrono::duration_cast<std::chrono::milliseconds>(duration);
       std::cout << ms.count() / 1000.0 << "s" << std::endl;
   }

public:
   ~Timer() {
      this->stopInstance();
   }

   static std::shared_ptr<const Timer> getInstance() {
      if (timer == NULL)
         timer = std::shared_ptr<const Timer>(new Timer());

      return timer;
   }

   static std::shared_ptr<const Timer> time() {
      return Timer::getInstance();
   }

   static void stop() {
      return Timer::getInstance()->stopInstance();
   }
};

std::shared_ptr<const Timer> Timer::timer = NULL;
bool Timer::stopped = false;
#endif
