#include<stdio.h>
#include<string.h>
#include<stdlib.h>

enum lexem_kind_t { OP, BRACE, NUM };
enum operation_t { ADD, SUB, MUL, DIV };
enum braces_t { LBRAC, RBRAC };


struct lexem_t 
{
	enum lexem_kind_t kind;
	union 
	{
		enum operation_t op;
		enum braces_t b;
		int num;
	} 
};
struct lex_array_t
{
	struct lexem_t *lexems;
	int size;
	int capacity;
};


struct lex_array_t* lex_string (const char* str)
{
	struct lex_array_t lex_array;
        lex_array.lexems = (struct lexem_t*)calloc(100 , sizeof(struct lexem_t));
	lex_array.size = 0;
	lex_array.capacity = 100;	
	if (*str == '/0')
		return lex_array;
	int lenght = strlen(str);
	for (int i = 0 ; i < lenght ; i++)
	{
		if ((str[i] == '\n') || (str[i] == ' '))
			continue;
		if (str[i] == '(')
		{
			(lex_array.lexems + lex_array.size) -> kind  = BRACE;
		        (lex_array.lexems + lex_array.size) -> b = LBRAC;
			lex_array.size++;
			continue;
		};
		if (str[i] == ')')
		{
			(lex_array.lexems + lex_array.size) -> kind = BRACE;
			(lex_array.lexems + lex_array.size) -> b = RBRAC;
			lex_array.size++;
		};
		if ((str[i] >= '0') && (str[i] <= '9'))
		{
			int j = i;
			int a = 0;
			while((str[j] != ' ') && (str[j] != '\n'))
			{
				a = a * 10 + (int)(str[i] - '0');
				j++;
			};
			(lex_array.lexems + lex_array.size) -> kind  = NUM;
			(lex_array.lexems + lex_array.size) -> num = a;
		        lex_array.size++;	
			continue;
		};
		if (str[i] == '+')
		{
			(lex_array.lexems + lex_array.size) -> kind = OP;
			(lex_array.lexems + lex_array.size) -> op = ADD;
			lex_array.size++;
			continue;
		};
		if (str[i] == '-')
		{
			(lex_array.lexems + lex_array.size) -> kind = OP;
			(lex_array.lexems + lex_array.size) -> op = SUB;
			lex_array.size++;
			continue;
		};
		if (str[i] == '*')
		{
			(lex_array.lexems + lex_array.size) -> kind = OP;
			(lex_array.lexems + lex_array.size) -> op = OP;
			lex_array.size++;
			continue;
		};
		if (str[i] == '/')
		{
			(lex_array.lexems + lex_array.size) -> kind = OP;
			(lex_array.lexems + lex_array.size) -> op = OP;
			lex_array.size++;
			continue;
		};
	};
	return lex_array;
}
	






int main()
{
	return 0;
}
