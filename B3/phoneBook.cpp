#include "phoneBook.hpp"

PhoneBook::PhoneBook()
{
  tabs_["current"] = rec_.end();
}

PhoneBook::PhoneBook(const PhoneBook & object)
{
  *this = object;
}

PhoneBook & PhoneBook::operator=(const PhoneBook & object)
{
  if (this != &object)
  {
    rec_ = object.rec_;
    tabs_.clear();
    for (auto i : object.tabs_)
    {
      std::list<EntryElem>::const_iterator tabs = i.second;
      tabs_[i.first] = std::next(rec_.begin(), std::distance(object.rec_.cbegin(), tabs));
    }
  }
  return *this;
}

void PhoneBook::replaceEntry(const std::string & tab, const PhoneBookEntry & entry)
{
  auto iter = getIterator(tab);
  iter->second->entry = entry;
}

void PhoneBook::showCurrent(const std::string & tab)
{
  auto iter = getIterator(tab);
  if (iter->second == rec_.end())
  {
    std::cout << "<EMPTY>" << std::endl;
  }
  else
  {
    std::cout << iter->second->entry.number << " " << iter->second->entry.name << std::endl;
  }
}

void PhoneBook::addtoEnd(const PhoneBookEntry & entry)
{
  EntryElem element;
  element.entry = entry;
  if (rec_.empty())
  {
    element.tabs.insert("current");
    rec_.push_back(element);
    tabs_["current"] = rec_.begin();
  }
  else
  {
    rec_.push_back(element);
  }
}

void PhoneBook::addTab(const std::string & current_tab, const std::string & new_tab)
{
  auto iter = getIterator(current_tab);
  tabs_[new_tab] = iter->second;
  if (iter->second != rec_.end())
  {
    iter->second->tabs.insert(new_tab);
  }
}

void PhoneBook::insertBefore(const std::string & tab, const PhoneBookEntry & entry)
{
  insert(tab, entry, false);
}

void PhoneBook::insertAfter(const std::string & tab, const PhoneBookEntry & entry)
{
  insert(tab, entry, true);
}

void PhoneBook::insert(const std::string & tab, const PhoneBookEntry & entry, const bool after)
{
  if (rec_.empty())
  {
    addtoEnd(entry);
    return;
  }
  auto iter = getIterator(tab);
  if (iter->second != rec_.end())
  {
    if (!after)
    {
      rec_.insert(iter->second, EntryElem{ entry, });
    }
    else
    {
      rec_.insert(std::next(iter->second), EntryElem{ entry, });
    }
  }
  else
  {
    rec_.push_back(EntryElem{ entry, });
  }
}

void PhoneBook::removeEntry(const std::string & tab)
{
  auto iter = getIterator(tab);
  if (iter->second != rec_.end())
  {
    auto elem = iter->second;
    for (auto i : elem->tabs)
    {
      if ((std::next(elem) == rec_.end()) && (rec_.size() > 1))
      {
        tabs_.at(i) = std::prev(elem);
        std::prev(elem)->tabs.insert(i);
      }
      else
      {
        tabs_.at(i) = std::next(elem);
        if (std::next(elem) != rec_.end())
        {
          std::next(elem)->tabs.insert(i);
        }
      }
    }
    rec_.erase(elem);
  }
}

void PhoneBook::moveToPrev(const std::string & tab)
{
  moveTab(tab, -1);
}

void PhoneBook::moveToNext(const std::string & tab)
{
  moveTab(tab, 1);
}

PhoneBook::tabIter PhoneBook::getIterator(const std::string & tab)
{
  auto iter = tabs_.find(tab);
  if (iter == tabs_.end())
  {
    throw std::invalid_argument("error");
  }
  return iter;
}

void PhoneBook::moveTab(const std::string & tab, const int position)
{
  auto iter = getIterator(tab);
  if (iter->second != rec_.end())
  {
    iter->second->tabs.erase(tab);
  }
  std::advance(iter->second, position);

  if (iter->second != rec_.end())
  {
    iter->second->tabs.insert(tab);
  }
}

void PhoneBook::moveTab(const std::string & tab, const std::string & position)
{
  auto iter = getIterator(tab);
  if (position != "first" && position != "last")
  {
    std::cout << "<INVALID STEP>" << std::endl;
  }
  else
  {
    if (iter->second != rec_.end())
    {
      iter->second->tabs.erase(tab);
    }
    if (rec_.empty())
    {
      iter->second = rec_.end();
    }
    else
    {
      if (position == "first")
      {
        iter->second = rec_.begin();
      }
      else
      {
        iter->second = std::prev(rec_.end());
      }
      iter->second->tabs.insert(tab);
    }
  }
}
