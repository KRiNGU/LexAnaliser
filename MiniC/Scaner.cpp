#include <iostream>
#include <string>
#include "LexicalAnalyser.h"
#include <ctype.h>
#include <map>

std::map<char, LexemType> punctuation{ { '[', LexemType::lbracket}, {']', LexemType::rbracket}, { '(', LexemType::lpar}, {')', LexemType::lpar},
{'{', LexemType::lbrace}, {'}', LexemType::rbrace}, {';', LexemType::semicolon}, {':', LexemType::colon}, {',', LexemType::comma} };

std::map<std::string, LexemType> keywords{ {"int", LexemType::kwint}, {"char", LexemType::kwchar}, {"if", LexemType::kwif}, {"else", LexemType::kwelse}, {"switch", LexemType::kwswitch},
{"case", LexemType::kwcase }, { "while", LexemType::kwwhile }, { "for", LexemType::kwfor }, { "return", LexemType::kwreturn }, { "in", LexemType::kwin }, { "out", LexemType::kwout }};
	

	Token::Token(LexemType type)
	{
		_type = type;
	}

	Token::Token(int value)
	{
		_type = LexemType::num;
		_value = value;
	}

	Token::Token(LexemType type, const std::string& str)
	{
		_type = type;
		_str = str;
	}

	Token::Token(char c)
	{
		_type = LexemType::chr;
		_value = c;
	}

	std::string Token::typeToString()
	{
		switch (_type)
		{
		case LexemType::num:
			return "num";
			break;
		case LexemType::chr:
			return "chr";
			break;
		case LexemType::str:
			return "str";
			break;
		case LexemType::id:
			return "id";
			break;
		case LexemType::lpar:
			return "lpar";
			break;
		case LexemType::rpar:
			return "rpar";
			break;
		case LexemType::lbrace:
			return "lbrace";
			break;
		case LexemType::rbrace:
			return "rbrace";
			break;
		case LexemType::lbracket:
			return "lbracket";
			break;
		case LexemType::rbracket:
			return "rbracket";
			break;
		case LexemType::semicolon:
			return "semicolon";
			break;
		case LexemType::comma:
			return "comma";
			break;
		case LexemType::colon:
			return "colon";
			break;
		case LexemType::opassign:
			return "opassign";
			break;
		case LexemType::opplus:
			return "opplus";
			break;
		case LexemType::opminus:
			return "opminus";
			break;
		case LexemType::opmult:
			return "opmult";
			break;
		case LexemType::opinc:
			return "opinc";
			break;
		case LexemType::opeq:
			return "opeq";
			break;
		case LexemType::opne:
			return "opne";
			break;
		case LexemType::oplt:
			return "oplt";
			break;
		case LexemType::opgt:
			return "opgt";
			break;
		case LexemType::ople:
			return "ople";
			break;
		case LexemType::opnot:
			return "opnot";
			break;
		case LexemType::opor:
			return "opor";
			break;
		case LexemType::opand:
			return "opand";
			break;
		case LexemType::kwint:
			return "kwint";
			break;
		case LexemType::kwchar:
			return "kwchar";
			break;
		case LexemType::kwif:
			return "kwif";
			break;
		case LexemType::kwelse:
			return "kwelse";
			break;
		case LexemType::kwswitch:
			return "kwswitch";
			break;
		case LexemType::kwcase:
			return "kwcase";
			break;
		case LexemType::kwwhile:
			return "kwwhile";
			break;
		case LexemType::kwfor:
			return "kwfor";
			break;
		case LexemType::kwreturn:
			return "kwreturn";
			break;
		case LexemType::kwin:
			return "kwin";
			break;
		case LexemType::kwout:
			return "kwout";
			break;
		case LexemType::eof:
			return "eof";
			break;
		case LexemType::error:
			return "error";
			break;
		default:
			return "???";
		}
	}

	void Token::print()
	{
		if (_type == LexemType::num or _type == LexemType::chr)
		{
			std::cout << '[' << typeToString() << ',' << ' ' << "'" << _value << "'" << ']';
		}
		else if (_type == LexemType::str or _type == LexemType::error or _type == LexemType::id)
		{
			std::cout << '[' << typeToString() << ',' << ' ' << '"' << _str << '"' << ']';
		}
		else
		{
			std::cout << '[' << typeToString() << ']';
		}
	}

	LexemType Token::type()
	{
		return _type;
	}

	int Token::value()
	{
		return _value;
	}

	std::string Token::str()
	{
		return _str;
	}

	Scanner::Scanner(std::iostream& stream)
	{
		std::iostream& _stream = stream;
		char c;
		int _state = 0;
	}

	Token Scanner::getNextToken()
	{
		int intValue;
		char chValue;
		std::string strValue = "";
		for (;;)
		{
			_stream >> c;
			if (!_stream)
			{
				return LexemType::eof;
			}
			switch (Scanner::_state)
			{
			case 0:
				if (c >= '0' && c <= '9')
				{
					_state = 1;
					intValue = c;
				}
				else if (c == '\'')
				{
					_state = 2;
				}
				else if (c == '\"')
				{
					_state = 4;
				}
				else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_')
				{
					_state = 5;
					strValue += c;
				}
				else if (c = '-')
				{
					_state = 6;
				}
				else if (c == '!')
				{
					_state = 7;
				}
				else if (c == '<')
				{
					_state = 8;
				}
				else if (c == '=')
				{
					_state = 9;
				}
				else if (c == '+')
				{
					_state = 10;
				}
				else if (c == '|')
				{
					_state = 11;
				}
				else if (c == '&')
				{
					_state = 12;
				}
				else if (c == '$')
				{
					_state = 0;
					return LexemType::eof;
				}
				else if (c == '>')
				{
					_state = 0;
					return LexemType::opgt;
				}
				else if (c == '(' || c == ')' || c == '{' || c == '}' || c == '[' || c == ']' || c == ';' || c == ',' || c == ':')
				{
					_state = 0;
					LexemType result = punctuation[c];
					return result;
				}
				else if (c == '*')
				{
					_state = 0;
					return LexemType::opmult;
				}
				else if (iswspace(c))
				{
					_state = 0;
				}
				else
				{
					return Token(LexemType::error, "no separator between operation characters");
				}
			case 1:
				if (c >= '0' && c <= '9')
				{
					intValue += c;
				}
				else
				{
					_state = 0;
					_stream << c;
					return Token(intValue);
				}
			case 2:
				if (c == '\'')
				{
					return Token(LexemType::error, "empty character constant");
				}
				else
				{
					chValue = c;
					_state = 3;
				}
			case 3:
				if (c == '\'')
				{
					_state = 0;
					return Token(c);
				}
				else
				{
					return Token(LexemType::error, "character constant containing more than one character");
				}
			case 4:
				if (c == '$')
				{
					return Token(LexemType::error, "language unsupported character");
				}
				else if (c == '\"')
				{
					_state = 0;
					return Token(LexemType::str, strValue);
				}
				else
				{
					strValue += c;
				}
			case 5:
				if (((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_') || (c <= '9' && c >= '0'))
				{
					strValue += c;
				}
				else
				{
					std::map<std::string, LexemType>::iterator it;
					it = keywords.find(strValue);
					if (it != keywords.end())
					{
						_state = 0;
						_stream << c;
						return keywords[strValue];
					}
					else
					{
						_state = 0;
						_stream << c;
						return Token(LexemType::id, strValue);
					}
				}
			case 6:
				if (c >= '0' && c <= '9')
				{
					_state = 1;
					intValue = -1 * c;
				}
				else
				{
					_state = 0;
					_stream << c;
					return Token(LexemType::opminus);
				}
			case 7:
				if (c == '!')
				{
					_state = 0;
					return Token(LexemType::opne);
				}
				else
				{
					_state = 0;
					_stream << c;
					return Token(LexemType::opnot);
				}
			case 8:
				if (c == '=')
				{
					_state = 0;
					return Token(LexemType::ople);
				}
				else
				{
					_state = 0;
					_stream << c;
					return Token(LexemType::oplt);
				}
			case 9:
				if (c == '=')
				{
					_state = 0;
					return Token(LexemType::opassign);
				}
				else
				{
					_state = 0;
					_stream << c;
					return Token(LexemType::opeq);
				}
			case 10:
				if (c == '+')
				{
					_state = 0;
					return Token(LexemType::opinc);
				}
				else
				{
					_state = 0;
					_stream << c;
					return Token(LexemType::opplus);
				}
			case 11:
				if (c == '|')
				{
					_state = 0;
					return Token(LexemType::opor);
				}
				else
				{
					return Token(LexemType::error, "single character |");
				}
			case 12:
				if (c == '&')
				{
					_state = 0;
					return Token(LexemType::opand);
				}
				else
				{
					return Token(LexemType::error, "single character &");
				}
			}
		}
	}