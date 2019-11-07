#include <iostream>
#include <string>
#include "LexicalAnalyser.h"

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

	Scanner::Scanner(std::istream& stream)
	{
		std::istream& _stream = stream;
		int _state = 0;
		char c;
		for (;;)
		{
			_stream >> c;
			if (!_stream)
			{
				return LexemType::eof;
			}
			switch (_state)
			{
			case 0:

			}
		}
	}
