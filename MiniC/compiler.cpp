#include <iostream>
#include "LexicalAnalyser.h"
#include <string>

int main()
{
	Token file1 = LexemType::eof;
	Token token2(LexemType::str, "string");
	Token token3(100);
	Token token4('a');
	file1.print();
	token2.print();
	token3.print();
	token4.print();
}