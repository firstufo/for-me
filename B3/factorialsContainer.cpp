#include "factorialsContainer.hpp"

FactorialsContainer::Iterator::Iterator(size_t index, unsigned int value)
{
  index_ = index;
  value_ = value;
}

const unsigned int * FactorialsContainer::Iterator::operator->() const
{
  return &value_;
}

const unsigned int & FactorialsContainer::Iterator::operator*() const
{
  return value_;
}

FactorialsContainer::Iterator FactorialsContainer::begin()
{
  return FactorialsContainer::Iterator(1, 1);
}

FactorialsContainer::Iterator FactorialsContainer::end()
{
  return FactorialsContainer::Iterator(11, 39916800);
}

FactorialsContainer::Iterator & FactorialsContainer::Iterator::operator++()
{
  if (index_ < 11)
  {
    ++index_;
    value_ *= index_;
  }
  return *this;
}

FactorialsContainer::Iterator FactorialsContainer::Iterator::operator++(int)
{
  Iterator prev = *this;
  ++(*this);
  return prev;
}

FactorialsContainer::Iterator & FactorialsContainer::Iterator::operator--()
{
  if (index_ > 1)
  {
    value_ /= index_;
    --index_;
  }
  return *this;
}

bool FactorialsContainer::Iterator::operator==(const Iterator & other) const
{
  return (index_ == other.index_);
}

bool FactorialsContainer::Iterator::operator!=(const Iterator & other) const
{
  return (!(other == *this));
}

FactorialsContainer::Iterator FactorialsContainer::Iterator::operator--(int)
{
  Iterator prev = *this;
  --(*this);
  return prev;
}
