#include "taskHeaders.hpp"
#include "factorialsContainer.hpp"
#include "phoneBook.hpp"
#include "phoneBookManagment.hpp"

void task1()
{
  PhoneBook PhBook;
  std::string string;
  while (std::getline(std::cin, string))
  {
    try
    {
      PhoneBookManagment phm;
      std::stringstream input(string);
      std::string command;
      input >> command;
      if (command == "add")
      {
        phm.addEntry(input, PhBook);
      }
      else if (command == "insert")
      {
        phm.insert(input, PhBook);
      }
      else if (command == "delete")
      {
        phm.remove(input, PhBook);
      }
      else if (command == "store")
      {
        phm.store(input, PhBook);
      }
      else if (command == "move")
      {
       phm.move(input, PhBook);
      }
      else if (command == "show")
      {
        try
        {
          phm.show(input, PhBook);
        }
        catch (std::invalid_argument &)
        {
          std::cout << "<INVALID BOOKMARK>" << std::endl;
        }
      }
      else
      {
        throw std::invalid_argument("");
      }
    }
    catch (std::invalid_argument &)
    {
      std::cout << "<INVALID COMMAND>" << std::endl;
    }
  }
}
