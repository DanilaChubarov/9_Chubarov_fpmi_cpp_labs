#include <exception>
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
		throw std::runtime_error("Error: Could not open the file \"" + path + "\"...");
	}
	if (IsEmptyFile(fin))
	{
		throw std::runtime_error("Error: \"" + path + "\" is empty...");
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
std::vector<std::string> ParsingWords(const std::string& line, const std::string& alphabet)
{
	std::vector<std::string> words;
	std::string::size_type beg_index = 0;
	std::string::size_type end_index = line.find_first_not_of(alphabet, beg_index);
	while (beg_index != std::string::npos) {

		std::string word = line.substr(beg_index, end_index - beg_index);
		std::string word_with_same_letters;
		if (!word.empty()) {
			for (size_t i = 0; i < word.size(); i++)
			{
				if (word[i] == word[i + 1])
				{
					word_with_same_letters.push_back(word[i]);
				}
			}
			words.push_back(word_with_same_letters);
		}

		beg_index = line.find_first_of(alphabet, end_index);
		end_index = line.find_first_not_of(alphabet, beg_index);
	}
	return words;
}
int FindingBiggestWord(const std::vector<std::string>& line)
{
	std::vector<int> LettersInWord(line.size(), 0);
	for (int i = 0; i < line.size(); ++i)
	{
		for (char c : line[i])
		{
			LettersInWord[i]++;
		}
	}
	int biggest_word = 0;
	for (int i = 0; i < line.size(); ++i)
	{
		if (biggest_word < LettersInWord[i])
		{
			biggest_word = LettersInWord[i];
		}
	}
	return biggest_word;
}
int FindingBiggestEverWord(const std::vector<int>& lines)
{
	int biggest = 0;
	for (int i = 0; i < lines.size(); ++i)
	{
		if (biggest < lines[i])
		{
			biggest = lines[i];
		}
	}
	return biggest;
}


int main()
{
	setlocale(LC_ALL, "rus");
	std::string alphabet = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯабвгдеёжзийклмнопрстуфхцчшщъыьэюя";
	std::string path = "input.txt";
	std::vector<std::string> text;
	try {
		ReadLinesFromFile(path, text);
	}
	catch (const std::exception& msg) {
		std::cerr << msg.what() << std::endl;
		return 0;
	}
	std::vector<std::vector<std::string> > RussianWords(text.size());
	for (int i = 0; i < text.size(); ++i)
	{
		RussianWords[i] = ParsingWords(text[i], alphabet);
	}
	std::vector <int> BiggestWordInLine(RussianWords.size());
	for (int i = 0; i < RussianWords.size(); ++i)
	{
		BiggestWordInLine[i] = FindingBiggestWord(RussianWords[i]);
	}
	int biggest_word_ever = FindingBiggestEverWord(BiggestWordInLine);
	if (biggest_word_ever == 0)
	{
		std::cerr << "Нет русских слов в файле!" << std::endl;
		return 1;
	}

	for (int lineouts = 0, i = 0; i < text.size(); ++i)
	{
		if (BiggestWordInLine[i] == biggest_word_ever)
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
