#include <iostream>
#include <vector>
#include <string>
#include <fstream>
bool IsEmptyFile(std::ifstream& file) {
	return file.peek() == std::ifstream::traits_type::eof();
}
void ReadLinesFromFile(const std::string& path, std::vector < std::string>& text)
{

	std::ifstream fin{ path };
	if (!fin.is_open())
	{
		throw ("Error: Could not open the file \"" + path + "\"...");
	}
	if (IsEmptyFile(fin))
	{
		throw ("Error: \"" + path + "\" is empty...");
	}
	std::string line;
	while (std::getline(fin, line))
	{
		if (line.empty())
		{
			continue;
		}
		text.push_back(line);
	}
	fin.close();
}
int FindingAmountOfWords(std::string line, std::string alphabet)
{
	int WordsCount = 0;
	std::string::size_type beg_index = 0;
	std::string::size_type end_index = line.find_first_not_of(alphabet, beg_index);
	while (beg_index != std::string::npos) {

		std::string word = line.substr(beg_index, end_index - beg_index);
		if (!word.empty()) {
			WordsCount++;
		}

		beg_index = line.find_first_of(alphabet, end_index);
		end_index = line.find_first_not_of(alphabet, beg_index);
	}
	return WordsCount;
}
int FindingBiggestAmountOfWords(std::vector<int> lines)
{
	int biggest = 0;
	for (int i = 0; i < lines.size(); ++i)
	{
		if (biggest <= lines[i])
		{
			biggest = lines[i];
		}
	}
	return biggest;
}


int main()
{
	setlocale(LC_ALL, "rus");
	std::string alphabet = "ÀÁÂÃÄÅ¨ÆÇÈÉÊËÌÍÎÏÐÑÒÓÔÕÖ×ØÙÚÛÜÝÞßàáâãäå¸æçèéêëìíîïðñòóôõö÷øùúûüýþÿ";
	std::string path = "input.txt";
	std::vector<std::string> text;
	try {
		ReadLinesFromFile(path, text);
	}
	catch (const std::string& msg) {
		std::cerr << msg << std::endl;
	}
	
	std::vector<int> AmountOfWordsInLine(text.size());
	for (int amount, i = 0; i < text.size(); ++i)
	{
		amount = FindingAmountOfWords(text[i],alphabet);
		AmountOfWordsInLine[i] = amount;
	}
	int BiggestAmountOfWords = FindingBiggestAmountOfWords(AmountOfWordsInLine);
	if (BiggestAmountOfWords==0)
	{
		std::cout << "Íåò ðóññêèõ ñëîâ íå â îäíîé èç ñòðîê" << std::endl;
	}
	for (int lineouts = 0, i = 0; i < text.size(); ++i)
	{
		if (AmountOfWordsInLine[i] == BiggestAmountOfWords)
		{
			std::cout << text[i] << std::endl;
			lineouts++;
		}
		if (lineouts == 10)
		{
			break;
		}
	}


	return 0;
}