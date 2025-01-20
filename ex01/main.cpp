/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-fihr <mel-fihr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 11:51:41 by mel-fihr          #+#    #+#             */
/*   Updated: 2025/01/12 18:03:24 by mel-fihr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <string>
#include "PhoneBook.hpp"

std::string getInput(const std::string& prompt) {
    std::string input;
    do {
        std::cout << prompt;
        std::getline(std::cin, input);
        if (std::cin.eof()) {
            std::cout << "\nExiting program." << std::endl;
            exit(0);
        }
    } while (input.empty());
    return input;
}

int main() {
    PhoneBook phoneBook;
    std::string command;

    while (true)
    {
        std::cout << "\nEnter command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, command);
        
        if (std::cin.eof())
        {
            std::cout << "\nExiting program." << std::endl;
            break;
        }
        if (command == "EXIT")
        {
            break;
        }
        else if (command == "ADD")
        {
            Contact newContact;
            std::string firstName = getInput("Enter first name: ");
            std::string lastName = getInput("Enter last name: ");
            std::string nickname = getInput("Enter nickname: ");
            std::string phoneNumber = getInput("Enter phone number: ");
            std::string darkestSecret = getInput("Enter darkest secret: ");
            
            newContact.setContact(firstName, lastName, nickname, phoneNumber, darkestSecret);
            phoneBook.addContact(newContact);
            std::cout << "Contact added successfully!" << std::endl;
        }
        else if (command == "SEARCH")
        {
            if (phoneBook.getTotalContacts() == 0)
            {
                std::cout << "Phonebook is empty!" << std::endl;
                continue;
            }
            
            phoneBook.displayContacts();
            
            std::string indexStr;
            std::cout << "\nEnter index to display: ";
            std::getline(std::cin, indexStr);
            
            try {
                int index = std::stoi(indexStr);
                phoneBook.displayContact(index);
            }
            catch (std::exception&) {
                std::cout << "Invalid index!" << std::endl;
            }
        }
    }
    
    return 0;
}