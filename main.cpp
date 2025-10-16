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
	}
	string[5] = '\0';
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
		char* lString1 = ToggleLow(string1);
		char* lString2 = ToggleLow(string2);
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
int main()
{
	//ConcatenateStringMain();
	//FindCharacterMain();
	CompareStringMain();
	
	/*
	const char* string = "salut";
	for (int i = 0; i < GetLength(string); i++)
	{
		int j = (int)string[i];
		std::cout << j << std::endl;
	}
	*/

	return 0;
}