#ifndef PHONEBOOKMANAGMENT_HPP
#define PHONEBOOKMANAGMENT_HPP

#include "phoneBook.hpp"

class PhoneBookManagment
{
public:
  std::string readName(std::stringstream &input);
  std::string readNumber(std::stringstream & input);
  std::string readMarkName(std::stringstream & input);

  void addEntry(std::stringstream& input, PhoneBook & book);
  void remove(std::stringstream& input, PhoneBook & book);
  void show(std::stringstream& input, PhoneBook & book);
  void insert(std::stringstream& input, PhoneBook & book);
  void store(std::stringstream& input, PhoneBook & book);
  void move(std::stringstream& input, PhoneBook & book);
};

#endif // PHONEBOOKMANAGMENT_HPP
