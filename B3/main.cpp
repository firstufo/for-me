#include <iostream>
#include "phoneBookManagment.hpp"
#include "phoneBook.hpp"
#include "taskHeaders.hpp"

int main(int args, char *argv[])
{
  if(args != 2)
  {
    std::cerr << "Enter the task number, please [1-2]" << std::endl;;
    return 1;
  }

  try
  {
    int variant = std::stoi(argv[1]);
    switch(variant)
    {
    case 1:
      task1();
      break;
    case 2:
      task2();
      break;
    default:
      std::cerr << "The wrong task number [1-2]" << std::endl;;
      return 1;
    }
  }

  catch(const std::invalid_argument &e)
  {
    std::cerr << e.what();
    return 1;
  }

}
