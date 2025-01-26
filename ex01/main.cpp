/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-fihr <mel-fihr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 11:51:41 by mel-fihr          #+#    #+#             */
/*   Updated: 2025/01/26 10:58:38 by mel-fihr         ###   ########.fr       */
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
        for (size_t i = 0; i < input.length(); i++) {
            if (!isprint(input[i]) || isspace(input[i])) {
                std::cout << "Invalid input!" << std::endl;
                input.clear();
                break;
            }  
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
            
            if (indexStr.length() != 1 || !isdigit(indexStr[0]))
            {
                std::cout << "Invalid index!" << std::endl;
                continue;
            }
            int index = indexStr[0] - '0';
            phoneBook.displayContact(index);
        }
    }
    
    return 0;
}