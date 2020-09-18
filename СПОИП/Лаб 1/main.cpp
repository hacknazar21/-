/*

** What I need to do? **

*** Создать функцию Delete(s,n,l) 
*** удаление из строки s подстроки, начиная с позиции n, длиной l 

*/

/*
**Explanes of the variables names**

*** l - длина
*** n - позиция
*** s - подстрока
*** ch - char
*** cc - counted chars

*/
#define N 256

char const_string[13] = "Hello World!", edited_string[13], ch;
int i, cc = 0;
long int code_error;

#include <iostream>

void Error(long int err_code)
{
	switch(err_code)
	{
		case 100:
		break;
	}
}

bool isAllCorrect(char* s, int n, int l)
{
	ch = s[n-1];
	i = n-1;
	while(ch != '\0') // Пока позиция не в конце строки
	{
		if(
			i < n+l // Позиция за пределами заданной границы
		   )
		{
			if(
				ch != const_string[i++] // Символы не совпадают
				) 
				return false;
			ch = s[i];
		}
		else return false;
		if(const_string[i] == '\0' && ch != 0) return false;
	}
	return true;
}

char* Delete(char* s, int n, int l)
{
	if (!isAllCorrect(s, n, l)) // Ищем проблемы
	{
		Error(code_error); // Если есть ошибки, то выводим его пользователю
		return "\0"; // Возращаем нулевой байт в качестве указания, что что-то пошло не так
	}
	i = n-1;
	ch = const_string[i];
	while(ch != '\0') 
	{
		if (i < n + l - 1 && i >= n-1) i++;
		else 
		{
			ch = const_string[i++];
			edited_string[cc++] = ch;
		}
	}
	return edited_string;
}


int main(int argc, char const *argv[])
{

	char L[13] = "Hello";

	std::cout << "NO Edited: " << const_string << "\n";
	std::cout << "Edited: " << Delete(L, 1, 5) << "\n";

	std::cin.get();
	return 0;
}