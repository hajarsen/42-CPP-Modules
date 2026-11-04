#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
private:
    static const int maxContacts = 8;
    Contact contacts[maxContacts];
    int nbrOfContacts;
    int lastContactIndex;
    bool getContactInput(const std::string& prompt, std::string& field, bool isPhone);
    void printContact(int index) const;
    void getContactIndex() const;

public:
    PhoneBook();
    ~PhoneBook();
    
    void addContact();
    void searchContacts() const;
};

#endif