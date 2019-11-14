#include "taskHeaders.hpp"
#include "factorialsContainer.hpp"
#include <iostream>
#include <algorithm>

void task2()
{
  FactorialsContainer container;

  std::copy(container.begin(), container.end(), std::ostream_iterator<int>(std::cout, " "));
  std::cout << std::endl;

  std::reverse_copy(container.begin(), container.end(), std::ostream_iterator<int>(std::cout, " "));
  std::cout << std::endl;
}
