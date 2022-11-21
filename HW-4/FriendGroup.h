#ifndef FRIEND_GROUP_H
#define FRIEND_GROUP_H

#include <string>
#include <list>
#include "Person.h"

class FriendGroup
{
private:
	std::string m_name;
	std::list<Person*> m_friendList;
public:
	FriendGroup(std::string name, std::list<Person*> friendList = {});

	void addPerson(Person* person);

	void removePerson(const std::string& name);
	void removePerson(Person* person);

	void updatePerson(const std::string& name, Person* newData);
	void updatePerson(Person* person, Person* newData);

	std::list<Person*> getFriendList() const;

	friend std::ostream& operator<<(std::ostream& out, const FriendGroup& friendGroup);
};

#endif