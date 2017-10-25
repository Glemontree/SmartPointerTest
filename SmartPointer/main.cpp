#include "SmartPointer.h"
#include "Person.h"
#include <iostream>

void main() {
	Person* person = new Person;
	SmartPointer<Person> smartPerson(person);
	std::cout << "¼ÆÊýÎª£º" << smartPerson.getRefCount() << std::endl;
}