/*
 *сделать программму которая если ли рядки анаграмми(регистр и пробелы не учитываются)
 *
 *
 **/
#include <iostream>
#include <string>

std::string RemoveSpaceAndPunctuation(const std::string& word)
{
    std::string res;
    for (char c : word)
    {
        if(std::isalnum(c))
        {
            res += c;
        }
    }
    return res;
}

std::string Anagram(std::string& word1, std::string& word2)
{
    word1 = RemoveSpaceAndPunctuation(word1);
    word2 = RemoveSpaceAndPunctuation(word2);

    std::string word2_copy {word2};
    for (char c : word1)
    {
        for(size_t i {}; i < word2_copy.length(); ++i)
        {
            if(std::tolower(word2_copy[i] == std::tolower(c)))
            {
                word2_copy.erase(i, 1);
                break;
            }
        }

    }
    return word2_copy;
}

int main()
{
    std::cout << "Anagram check" << std::endl;

    std::string word1;
    std::cout << "Enter the first word: " ;
    std::getline(std::cin, word1);

    std::string word2;
    std::cout << "Enter the second word: ";
    std::getline(std::cin, word2);
    std::string word2_copy{word2};


    if (word1.length() != word2.length())
    {
        std::cout << word1 << " and " << word2 << " is not anagram";
    }
    else
    {
        std::string res  = Anagram(word1, word2);
        if(res.empty())
        {
            std::cout << word2 << " and " << word1 << " is anagram";
        }

        else
        {
            std::cout << word2 << " and " << word1 << " is not anagram";
        }
    }
    return 0;
}
