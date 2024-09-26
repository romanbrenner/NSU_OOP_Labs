#include "module1.h"
#include "module2.h"
#include "module3.h"
#include <iostream>

int main(int argc, char** argv)
{
  std::cout << "Hello world!" << "\n";

  std::cout << Module1::getMyName() << "\n";
  std::cout << Module2::getMyName() << "\n";

  using namespace Module1;
  std::cout << getMyName() << "\n"; // (A)
  std::cout << Module2::getMyName() << "\n";

  //using namespace Module2; // (B)
  //std::cout << getMyName() << "\n"; // COMPILATION ERROR (C)

  using Module2::getMyName;
  std::cout << getMyName() << "\n"; // (D)

  std::cout << Module3::getMyName() << "\n";
}
/*Этот вывод соответствует работе программы, где:
- Сначала выводится "Hello world!".
- Затем вызываются функции Module1::getMyName и Module2::getMyName, выводя строки "John" и "James".
- После использования using namespace Module1; снова вызывается Module1::getMyName.
- Повторно вызывается Module2::getMyName.
- Наконец, using Module2::getMyName; позволяет вызывать Module2::getMyName без полного квалификационного имени.*/