#include "SmartPointer.h"
#include "Person.h"
#include <iostream>

void main() {
	Person* person = new Person;
	SmartPointer<Person> smartPerson(person);
	std::cout << "����Ϊ��" << smartPerson.getRefCount() << std::endl;
}