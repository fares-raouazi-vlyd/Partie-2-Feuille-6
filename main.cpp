#include <iostream>

int GetLength(const char* str)
{
	int length = 0;
	for (length = 0; str[length] != '\0'; ++length);
	return length;
}
char* ToggleLow(const char* c)
{
	char* string = (char*)malloc(sizeof(char) * GetLength(c));
	if (string == nullptr)
		exit(1);
	for (int i = 0; i < GetLength(c); i++)
	{
		if (c[i] >= 'A' && c[i] <= 'Z')
		{
			string[i] = c[i] + 32;
		}
		else
		{
			string[i] = c[i];
		}
	}
	string[GetLength(c)] = '\0';
	return string;
}
const char* ConcatenateString(const char* string1,const char* string2)
{
	
	int size = GetLength(string1) + GetLength(string2) +1;
	char* string = (char*)malloc(sizeof(char) * size);
	int h = 0;
	int i = 0;
	int j = 0;
	if (string == nullptr)
		exit(1);
	while ( h < size)
	{
		while (i < GetLength(string1))
		{
			string[h++] = string1[i++];
		}
		string[h++] = ' ';
		while (j < GetLength(string2))
		{
			string[h++] = string2[j++];
		}
		
	}
	string[h] = '\0';
	return string;
}
void ConcatenateStringMain()
{
	const char string1[] = "Hello";
	const char string2[] = "World";
	const char* string = ConcatenateString(string1, string2);
	std::cout << string << std::endl;
}
int FindCharacter(const char* string, char str)
{
	for (int i = 0; i < GetLength(string); i++)
	{
		if (string[i] == str)
		{
			return i;
		}
	}
	return 0;
}
void FindCharacterMain()
{
	const char* string = "abcdef";
	char str;
	std::cout << "Char ? " << std::endl;
	std::cin >> str;
	std::cout << "Index : " << FindCharacter(string, str) << std::endl;
}
int CompareString(const char* string1, const char* string2, bool caseSensitive)
{
	int same = 0;
	if (caseSensitive)
	{
		if (GetLength(string1) != GetLength(string2))
		{
			return same;
		}

		else
		{
			for (int i = 0; i < GetLength(string1); i++)
			{
				if (string1[i] != string2[i])
				{
					return same;
				}
			}
		}
		same = 1;
		return same;
	}



	if(!caseSensitive)
	{
		const char* lString1 = ToggleLow(string1);
		const char* lString2 = ToggleLow(string2);
		if (GetLength(string1) != GetLength(string2))
		{
			return same;
		}

		else
		{
			for (int i = 0; i < GetLength(string1); i++)
			{
				if (lString1[i] != lString2[i])
				{
					std::cout << lString1;
					return same;
				}
			}
		}
		same = 1;
		return same;
	}
	return same;
}
void CompareStringMain()
{
	const char* string1 = "Test";
	const char* string2 = "test";
	bool caseSensitive;
	int i = CompareString(string1, string2, 0);
	switch(i)
	{
	case 0:
		std::cout << "Not the same" << std::endl;
		break;
	case 1:
		std::cout << "Same" << std::endl;
		break;
	}
	int j = CompareString(string1, string2, 1);
	switch (j)
	{
	case 0:
		std::cout << "Not the same" << std::endl;
		break;
	case 1:
		std::cout << "Same" << std::endl;
		break;
	}

}
int CountCharacterFrequency(const char* string, char target)
{
	char lTarget = *ToggleLow(&target);
	const char* lString = ToggleLow(string);
	int occurence = 0;
	for (int i = 0; i < GetLength(lString); i++)
	{
		if (lString[i] == lTarget)
		{
			occurence++;
		}
	}
	return occurence;
}
void CountCharacterFrequencyMain()
{
	const char* string = "heLlo worLd";
	char target;
	std::cout << "Targeted character ?" << std::endl;
	std::cin >> target;
	std::cout << "There is : " << CountCharacterFrequency(string, target) << "  '" << target << "' in " << string;
}
bool IsPalindrome(const char* string)
{
	int size = GetLength(string);
	char* reverseString = (char*)malloc(sizeof(char) * size);
	int h = 0;
	if (reverseString == nullptr)
		exit(1);
	reverseString[size] = '\0';
	for (int i = size - 1; h < size; i--)
	{
		reverseString[i] = string[h++];
	}
	
	if (CompareString(string, reverseString, 0) == 1)
	{
		return true;
	}
	return false;
}
void IsPalindromeMain()
{
	const char* string1 = "radar";
	const char* string2 = "salut";
	if (IsPalindrome(string1))
	{
		std::cout << "Palindrome : Oui" << std::endl;
	}
	else if (!IsPalindrome(string1))
	{
		std::cout << "Palindrome : Non" << std::endl;
	}
	if (IsPalindrome(string2))
	{
		std::cout << "Palindrome : Oui" << std::endl;
	}
	else if (!IsPalindrome(string2))
	{
		std::cout << "Palindrome : Non" << std::endl;
	}
}
char* SubString(const char* string, int startPos, int size)
{
	char* subString = (char*)malloc(sizeof(char) * size);
	
	if (subString == nullptr)
		exit(1);
	for (int i = 0; i < size; i++)
	{
		subString[i] = string[startPos++];
	}
	subString[size] = '\0';
	return subString;
}
void SubStringMain()
{
	const char* string = "abcdef";
	int startPos;
	int size;
	std::cout << "Starting position ? " << std::endl;
	std::cin >> startPos;
	std::cout << "Extracting size ? " << std::endl;
	std::cin >> size;
	std::cout << SubString(string, startPos, size);
}

int main()
{
	//ConcatenateStringMain();
	//FindCharacterMain();
	//CompareStringMain();
	//CountCharacterFrequencyMain();
	//IsPalindromeMain();
	SubStringMain();
	/*
	const char* string = "salut";
	for (int i = 0; i < GetLength(string); i++)
	{
		int j = (int)string[i];
		std::cout << j << std::endl;
	}
	

	const char* test = "TEST  JJJ";
	std::cout << ToggleLow(test);
	*/
	return 0;
}