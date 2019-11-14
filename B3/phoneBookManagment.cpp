#include "phoneBookManagment.hpp"

std::string PhoneBookManagment::readName(std::stringstream &input)
{
  input.ignore();
  std::string name;
  std::getline(input, name);
  if (name.empty())
  {
    return name;
  }

  if ((name.front() != '\"') || (name.back() != '\"'))
  {
    throw std::invalid_argument("incorrect name");
  }
  name.erase(std::remove(name.begin(), name.end(), '\\'), name.end());
  name.erase(0,1);
  name.pop_back();
  return name;
}

std::string PhoneBookManagment::readNumber(std::stringstream & input)
{
  std::string number;
  input >> number;
  for (auto i : number)
  {
    if (!isdigit(i))
    {
      throw std::invalid_argument("<INVALID COMMAND>");
    }
  }
  return number;
}

void PhoneBookManagment::show(std::stringstream& input, PhoneBook & PhBook)
{
  std::string markname = readMarkName(input);
  PhBook.showCurrent(markname);
}

void PhoneBookManagment::insert(std::stringstream& input, PhoneBook & PhBook)
{
  std::string position;
  input >> position;

  if ((position != "before") && (position != "after"))
  {
    throw std::invalid_argument("incorrect parameter");  
  }
  else
  {
    std::string markname = readMarkName(input);
    std::string number = readNumber(input);
    std::string name = readName(input);
    if (position == "after")
    {
      PhBook.insertAfter(markname, PhoneBookEntry{ number,name });
    }
    else
    {
      PhBook.insertBefore(markname, PhoneBookEntry{ number,name });
    }
  }
}

void PhoneBookManagment::addEntry(std::stringstream& input, PhoneBook & PhBook)
{
  std::string number = readNumber(input);
  std::string name = readName(input);
  PhBook.addtoEnd(PhoneBookEntry{ number,name });
}

void PhoneBookManagment::move(std::stringstream& input, PhoneBook & PhBook)
{
  std::string markname = readMarkName(input);
  std::string position;
  input >> position;
  if (position != "first" && position != "last")
  {
    try
    {
      PhBook.moveTab(markname, std::stoi(position));
    }
    catch (std::invalid_argument &)
    {
      std::cout << "<INVALID STEP>" << std::endl;
    }
  }
  else
  {
    PhBook.moveTab(markname, position);
  }
}

void PhoneBookManagment::remove(std::stringstream& input, PhoneBook & PhBook)
{
  std::string markname = readMarkName(input);
  PhBook.removeEntry(markname);
}

std::string PhoneBookManagment::readMarkName(std::stringstream & input)
{
  std::string markname;
  input >> markname;
  for (auto i : markname)
  {
    if ((!isalnum(i)) && (i != '-'))
    {
      throw std::invalid_argument("<INVALID BOOKMARK>");
    }
  }
  return markname;
}

void PhoneBookManagment::store(std::stringstream& input, PhoneBook & PhBook)
{
  std::string old_mark = readMarkName(input);
  std::string new_mark = readMarkName(input);
  PhBook.addTab(old_mark, new_mark);
}
