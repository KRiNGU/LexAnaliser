#include <iostream>
#pragma once

enum class LexemType {
	num, chr, str, id, lpar, rpar, lbrace, rbrace, lbracket, rbracket, semicolon, comma, colon, opassign, opplus,
	opminus, opmult, opinc, opeq, opne, oplt, opgt, ople, opnot, opor, opand, kwint, kwchar, kwif, kwelse, kwswitch, kwcase, kwwhile, 
	kwfor, kwreturn, kwin, kwout, eof, error
};

class Token
{
private:
	LexemType _type;
	int _value;
	std::string _str;
public:
	Token(LexemType type);
	Token(int value);
	Token(LexemType type, const std::string& str);
	Token(char c);
	std::string typeToString();
	void print();
	LexemType type();
	int value();
	std::string str();
};

class Scanner
{
private:
	std::iostream _stream;
	int _state;
	char c;
public: 
	Scanner(std::iostream& stream);
	Token getNextToken();
};