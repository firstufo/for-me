#ifndef FACTORIALSCONTAINER_HPP
#define FACTORIALSCONTAINER_HPP

#include <iterator>

class FactorialsContainer
{
public:
  class Iterator;
  FactorialsContainer() = default;
  Iterator begin();
  Iterator end();
};

class FactorialsContainer::Iterator : public std::iterator<std::bidirectional_iterator_tag, size_t>
  {
  public:
    Iterator(size_t id, unsigned int value);
    Iterator(const Iterator &other) = default;

    const unsigned int* operator->() const;
    const unsigned int& operator*() const;

    Iterator& operator ++();
    Iterator operator++(int);
    Iterator& operator--();
    Iterator operator--(int);
    Iterator& operator=(const Iterator &object) = default;

    bool operator==(const Iterator& ite) const;
    bool operator!=(const Iterator& ite) const;

  private:
    size_t index_;
    unsigned int value_;
  };

#endif // FACTORIALSCONTAINER_HPP
