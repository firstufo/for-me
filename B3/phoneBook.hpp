#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <list>
#include <map>
#include <set>
#include <sstream>
#include <algorithm>

struct PhoneBookEntry
{
  std::string number, name;
};
struct EntryElem
{
  PhoneBookEntry entry;
  std::set<std::string> tabs;
};
class PhoneBook
{
public:
  PhoneBook();
  PhoneBook(const PhoneBook &item);
  PhoneBook(PhoneBook && item) = default;

  PhoneBook& operator=(const PhoneBook& item);
  PhoneBook& operator=(PhoneBook &&item) = default;

  void addtoEnd(const PhoneBookEntry & entry);
  void addTab(const std::string & current_tab, const std::string &newtab);
  void showCurrent(const std::string &tab);
  void moveToNext(const std::string &tab);
  void moveToPrev(const std::string &tab);
  void insertBefore(const std::string & tab, const PhoneBookEntry &entry);
  void insertAfter(const std::string & tab, const PhoneBookEntry &entry);
  void moveTab(const std::string &tab, const int position);
  void moveTab(const std::string &tab, const std::string &position);
  void removeEntry(const std::string &tab);
  void replaceEntry(const std::string &tab, const PhoneBookEntry &entry);

private:

  typedef std::list<EntryElem> record_type;
  typedef std::map<std::string, record_type::iterator> tab_type;
  typedef tab_type::iterator tabIter;

  record_type rec_;
  tab_type tabs_;

  tabIter getIterator(const std::string &tab);
  void insert(const std::string & tab, const PhoneBookEntry & entry, const bool after);
};

#endif // PHONEBOOK_HPP
