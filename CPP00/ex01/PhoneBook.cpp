#include "PhoneBook.hpp"
#include <cctype>


static bool isDigits(const std::string& str) 
{
    for (size_t i = 0; i < str.length(); i++) 
    {
        if (!std::isdigit(static_cast<unsigned char>(str[i])))
            return false;
    }
    return !str.empty();
}

static bool isPrintable(const std::string& str)
{
    for (size_t i = 0; i < str.length(); i++)
    {
        if (!std::isprint(static_cast<unsigned char>(str[i])))
            return false;
    }
    return !str.empty();
}

static std::string truncate(const std::string& text)
{
    if (text.length() > 10)
        return text.substr(0, 9) + ".";
    return text;
}

PhoneBook::PhoneBook() : nbrOfContacts(0), lastContactIndex(0)
{

}

PhoneBook::~PhoneBook() 
{

}

bool PhoneBook::getContactInput(const std::string& prompt, std::string& field, bool isPhone) 
{
    std::string input;
    while (true) {
        std::cout << prompt;
        if (!std::getline(std::cin, input))
        {
            if (std::cin.eof())
                return false;
            std::cin.clear();
            continue;
        }
        if (input.empty() || !isPrintable(input))
        {
            std::cout << "Invalid input" << std::endl;
            continue;
        }
        if (isPhone && !isDigits(input))
        {
            std::cout << "Invalid input" << std::endl;
            continue;
        }
        field = input;
        return true;
    }
}

void PhoneBook::addContact()
{
    std::string input;
    
    if (!getContactInput("Enter first name: ", input, false))
        return;
    contacts[lastContactIndex].setFirstName(input);
    
    if (!getContactInput("Enter last name: ", input, false))
        return;
    contacts[lastContactIndex].setLastName(input);
    
    if (!getContactInput("Enter nickname: ", input, false))
        return;
    contacts[lastContactIndex].setNickname(input);
    
    if (!getContactInput("Enter phone number: ", input, true))
        return;
    contacts[lastContactIndex].setPhoneNumber(input);
    
    if (!getContactInput("Enter darkest secret: ", input, false))
        return;
    contacts[lastContactIndex].setDarkestSecret(input);
    
    lastContactIndex = (lastContactIndex + 1) % maxContacts;
    if (nbrOfContacts < maxContacts)
        nbrOfContacts++;
    
    std::cout << "Contact added" << std::endl;
}

void PhoneBook::printContact(int i) const {
    const Contact& contact = contacts[i];
    std::cout << "First name: " << contact.getFirstName() << std::endl
              << "Last name: " << contact.getLastName() << std::endl
              << "Nickname: " << contact.getNickname() << std::endl
              << "Phone number: " << contact.getPhoneNumber() << std::endl
              << "Darkest secret: " << contact.getDarkestSecret() << std::endl;
}

void PhoneBook::searchContacts() const 
{
    int displayCount;

    if (nbrOfContacts == 0) 
    {
        std::cout << "No contacts" << std::endl;
        return;
    }
    std::cout << std::endl;
    
    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First name" << "|"
              << std::setw(10) << "Last name" << "|"
              << std::setw(10) << "Nickname" << std::endl;

    if (nbrOfContacts > maxContacts)
        displayCount = maxContacts;
    else
        displayCount = nbrOfContacts;

    for (int i = 0; i < displayCount; i++)
    {
        std::cout << std::setw(10) << i << "|"
                  << std::setw(10) << truncate(contacts[i].getFirstName()) << "|"
                  << std::setw(10) << truncate(contacts[i].getLastName()) << "|"
                  << std::setw(10) << truncate(contacts[i].getNickname()) << std::endl;
    }
    
    getContactIndex();
}

void PhoneBook::getContactIndex() const
{
    int maxIndex;
    int index;

    if (nbrOfContacts == 0) 
        return;

    if (nbrOfContacts > maxContacts)
        maxIndex = maxContacts;
    else
        maxIndex = nbrOfContacts;

    std::string input;
    
    while (true) {
        std::cout << "Enter index: ";
        if (!std::getline(std::cin, input)) 
        {
            if (std::cin.eof()) 
                return;
            std::cin.clear();
            continue;
        }
        
        std::stringstream ss(input);
        if (!(ss >> index) || !ss.eof() || index < 0 || index >= maxIndex)
        {
            std::cout << "Invalid index" << std::endl;
            std::cout << "Enter index: ";
            continue;
        }
        
        printContact(index);
        break;
    }
}
