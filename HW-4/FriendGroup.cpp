#include "FriendGroup.h"

#include <iostream>
#include <algorithm>
#include <ranges>

FriendGroup::FriendGroup(std::string name, std::list<Person*> friendList) : m_name{name}, m_friendList{friendList}
{
}

void FriendGroup::addPerson(Person* person)
{
	m_friendList.push_back(person);
}

void FriendGroup::removePerson(const std::string& name)
{
	std::list<Person*>::iterator personIterator = std::ranges::find_if(m_friendList, [name](const Person* person)
	{
		return person->getName() == name;
	});


	delete *personIterator;
	m_friendList.remove(*personIterator);
}

void FriendGroup::removePerson(Person* person)
{
	delete person;
	m_friendList.remove(person);
}

void FriendGroup::updatePerson(const std::string& name, Person* newData)
{
	std::list<Person*>::iterator personIterator = std::ranges::find_if(m_friendList, [name](const Person* person)
	{
		return person->getName() == name;
	});

	*personIterator = newData;
}

void FriendGroup::updatePerson(Person* person, Person* newData)
{
	std::list<Person*>::iterator personIterator = std::ranges::find(m_friendList, person);

	*personIterator = newData;
}

std::list<Person*> FriendGroup::getFriendList() const
{
	return m_friendList;
}

std::ostream& operator<<(std::ostream& out, const FriendGroup& friendGroup)
{
	for (const Person* currentFriend : friendGroup.getFriendList()) {
		out << "Friend(" << currentFriend->getName() << ", " << currentFriend->getAge() << ")\n";
	}

	return out;
}
