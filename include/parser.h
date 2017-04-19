#ifndef PARSER_H
#define PARSER_H

#include "grammar.h"

class Parser {
private:
	GrammarWord[][] parse_table;
	
	parse_table[PLUS][INDEX] = {(EPSILON)};
	parse_table[PLUS][OP_EXP] = {(OP, EXP)};
	parse_table[PLUS][OP] = {(PLUS)};
	parse_table[MINUS][INDEX] = {(EPSILON)};
	parse_table[MINUS][OP_EXP] = {(OP, EXP)};
	parse_table[MINUS][OP] = {(MINUS)};
	parse_table[COLON][INDEX] = {(EPSILON)};
	parse_table[COLON][OP_EXP] = {(OP, EXP)};
	parse_table[COLON][OP] = {(COLON)};
	parse_table[ASTERISK][INDEX] = {(EPSILON)};
	parse_table[ASTERISK][OP_EXP] = {(OP, EXP)};
	parse_table[ASTERISK][OP] = {(ASTERISK)};
	parse_table[LESS_THAN][INDEX] = {(EPSILON)};
	parse_table[LESS_THAN][OP_EXP] = {(OP, EXP)};
	parse_table[LESS_THAN][OP] = {(LESS_THAN)};
	parse_table[GREATER_THAN][INDEX] = {(EPSILON)};
	parse_table[GREATER_THAN][OP_EXP] = {(OP, EXP)};
	parse_table[GREATER_THAN][OP] = {(GREATER_THAN)};
	parse_table[EQUALITY][INDEX] = {(EPSILON)};
	parse_table[EQUALITY][OP_EXP] = {(OP, EXP)};
	parse_table[EQUALITY][OP] = {(EQUALITY)};
	parse_table[ASSIGNMENT][INDEX] = {(EPSILON)};
	parse_table[WHATEVER][INDEX] = {(EPSILON)};
	parse_table[WHATEVER][OP_EXP] = {(OP, EXP)};
	parse_table[WHATEVER][OP] = {(WHATEVER)};
	parse_table[NOT][EXP] = {(EXP_2, OP_EXP)};
	parse_table[NOT][EXP_2] = {(NOT, EXP_2)};
	parse_table[LOGICAL_AND][INDEX] = {(EPSILON)};
	parse_table[LOGICAL_AND][OP_EXP] = {(OP, EXP)};
	parse_table[LOGICAL_AND][OP] = {(LOGICAL_AND)};
	parse_table[SEMICOLON][OP_EXP] = {(EPSILON)};
	parse_table[PARENTHESIS_OPEN][EXP] = {(EXP_2, OP_EXP)};
	parse_table[PARENTHESIS_OPEN][EXP_2] = {(PARENTHESIS_OPEN, EXP, PARENTHESIS_CLOSE)};
	parse_table[PARENTHESIS_CLOSE][OP_EXP] = {(EPSILON)};
	parse_table[CURLY_BRACKET_OPEN][DECLS] = {(EPSILON)};
	parse_table[CURLY_BRACKET_OPEN][STATEMENTS] = {(STATEMENT, SEMICOLON, STATEMENTS)};
	parse_table[CURLY_BRACKET_OPEN][STATEMENT] = {(CURLY_BRACKET_OPEN, STATEMENTS, CURLY_BRACKET_CLOSE)};
	parse_table[CURLY_BRACKET_CLOSE][STATEMENTS] = {(EPSILON)};
	parse_table[SQUARE_BRACKET_OPEN][PROG] = {(SQUARE_BRACKET_OPEN, INTEGER, SQUARE_BRACKET_CLOSE)};
	parse_table[SQUARE_BRACKET_OPEN][INDEX] = {(SQUARE_BRACKET_OPEN, EXP, SQUARE_BRACKET_CLOSE)};
	parse_table[SQUARE_BRACKET_CLOSE][OP_EXP] = {(EPSILON)};
	parse_table[INTEGER][EXP] = {(EXP_2, OP_EXP)};
	parse_table[INTEGER][EXP_2] = {(INTEGER)};
	parse_table[IDENTIFIER][DECLS] = {(EPSILON)};
	parse_table[IDENTIFIER][ARRAY] = {(EPSILON)};
	parse_table[IDENTIFIER][EXP] = {(EXP_2, OP_EXP)};
	parse_table[IDENTIFIER][EXP_2] = {(IDENTIFIER, INDEX)};
	parse_table[IF][DECLS] = {(EPSILON)};
	parse_table[IF][STATEMENTS] = {(STATEMENT, SEMICOLON, STATEMENTS)};
	parse_table[IF][STATEMENT] = {(EPSILON)};
	parse_table[ELSE][STATEMENTS] = {(STATEMENT, SEMICOLON, STATEMENTS)};
	parse_table[ELSE][OP_EXP] = {(EPSILON)};
	parse_table[WHILE][DECLS] = {(EPSILON)};
	parse_table[WHILE][STATEMENTS] = {(STATEMENT, SEMICOLON, STATEMENTS)};
	parse_table[WHILE][STATEMENT] = {(EPSILON)};
	parse_table[READ][DECLS] = {(EPSILON)};
	parse_table[READ][STATEMENTS] = {(STATEMENT, SEMICOLON, STATEMENTS)};
	parse_table[READ][STATEMENT] = {(EPSILON)};
	parse_table[WRITE][DECLS] = {(EPSILON)};
	parse_table[WRITE][STATEMENTS] = {(STATEMENT, SEMICOLON, STATEMENTS)};	
	parse_table[WRITE][STATEMENTS] = {(EPSILON)};
	parse_table[INT][PROG] = {(DECLS, STATEMENTS)};
	parse_table[INT][DECLS] = {(DECL, SEMICOLON, DECLS)};	
	parse_table[INT][DECL] = {(INT, ARRAY, IDENTIFIER)};	
};