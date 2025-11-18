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
int main()
{
	setlocale(LC_ALL, "rus");
	std::string text;
	std::cout << "Введите строку\n";
	getline(std::cin, text);
	std::vector<std::string> words;
	std::vector<std::string> numbers_str;
	std::vector<int> numbers_int;
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
	for (int i=0; i <(int) words.size(); i++)
	{
		if (IsDigitsOnly(words[i]))
		{
			numbers_str.push_back(words[i]);
		}
	}
	for (int i = 0; i < (int)numbers_str.size(); i++)
	{
		numbers_int.push_back(std::stoi(numbers_str[i]));
	}
	int big = FindingBiggestNumber(numbers_int);
	std::string biggest_number=std::to_string(big);
	std::string::size_type biggest_number_start_index = text.find(biggest_number);
	std::string::size_type biggest_number_end_index = text.find_first_of(" ", biggest_number_start_index);
	text.erase(biggest_number_start_index, (biggest_number_end_index-biggest_number_start_index));
	biggest_number = biggest_number + " ";
	text.insert(0,biggest_number);
	std::string::size_type biggest_number_index= text.find_first_of(" ", beg_index);

	


	std::cout << text << std::endl;
	







	return 0;
}
