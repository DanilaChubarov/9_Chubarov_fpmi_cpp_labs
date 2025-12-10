#include <iostream>
#include <string>
#include<cctype>
#include<vector>
bool IsDigitsOnly(std::string word)
{
	for (char symbol : word)
	{
		if (!isdigit(symbol))
		{
			return false;
		}
	}
	return true;
	
}
int FindingBiggestNumber(std::vector<int> numbers_int)
{
	int big = numbers_int[0];
	for (int i = 1; i < (int) numbers_int.size(); i++)
	{
		if (big < numbers_int[i])
		{
			big = numbers_int[i];
		}
	}
	return big;
}
std::vector<std::string>  ParsingWords (std::string& text)
{ 
	std::vector<std::string> words;
    std::string::size_type beg_index = 0;
    std::string::size_type end_index = text.find_first_of(" ", beg_index);
	while (beg_index != std::string::npos) {
		std::string word = text.substr(beg_index, end_index - beg_index);
		if (!word.empty()) {
			words.push_back(word);
		}

		beg_index = text.find_first_not_of(" ", end_index);
		end_index = text.find_first_of(" ", end_index + 1);
	}
	return words;
}
void FillNumbersStr(const std::vector<std::string>& words, std::vector<std::string>& numbers_str)
{
	for (int i = 0; i < (int)words.size(); i++)
	{
		if (IsDigitsOnly(words[i]))
		{
			numbers_str.push_back(words[i]);
		}
	}
}
void FillNumbersInt(const std::vector<std::string>& numbers_str, std::vector<int>& numbers_int)
{
	for (int i = 0; i < (int)numbers_str.size(); i++)
	{
		numbers_int.push_back(std::stoi(numbers_str[i]));
	}
}
int main()
{
	setlocale(LC_ALL, "rus");

	std::string text;
	std::cout << "Введите строку\n";
	getline(std::cin, text);
	if (text.empty())
	{
		std::cerr << "Вы ничего не ввели!" << std::endl;
		return 0;
	}

	std::vector<std::string> words;
	words = ParsingWords(text);

	std::vector<std::string> numbers_str;
	FillNumbersStr(words, numbers_str);
	if (numbers_str.empty())
	{
		std::cerr << "В строке нет чисел!" << std::endl;
		return 0;
	}
	if (numbers_str.size()==1)
	{
		std::cout << text << std::endl;
		return 0;
	}

	std::vector<int> numbers_int;
	FillNumbersInt(numbers_str, numbers_int);

	int big = FindingBiggestNumber(numbers_int);
	std::string biggest_number=std::to_string(big);
	std::string::size_type biggest_number_start_index = text.find(biggest_number);
	std::string::size_type biggest_number_end_index = text.find_first_of(" ", biggest_number_start_index)+1;
	text.erase(biggest_number_start_index, (biggest_number_end_index-biggest_number_start_index));
	biggest_number = biggest_number + " ";
	text.insert(0,biggest_number);
	std::cout << text << std::endl;
	return 0;
}
