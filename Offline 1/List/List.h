#ifndef LIST_H
#define LIST_H

template <typename M> class List {

private:

void operator =(const List&) {} // Protect assignment

List(const List&) {} // Protect copy constructor

public:

List() {} // Default constructor

virtual ~List(){} // Base destructor

virtual void clear() = 0;

virtual void insert(const M& item) = 0;

virtual void append(const M& item) = 0;

virtual M remove() = 0;

virtual void moveToStart() = 0;

virtual void moveToEnd() = 0;

virtual void prev() = 0;

virtual void next() = 0;

virtual int length() const = 0;

//virtual int maxLength() const = 0;

virtual int currPos() const = 0;

virtual void moveToPos(int pos) = 0;

virtual const M& getValue() const = 0;

virtual int Search(const M& item) const = 0;

};

#endif // LIST_H


