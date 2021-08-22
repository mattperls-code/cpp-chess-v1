#include <iostream>
#include <vector>
#include <string>

#include "source/move.h"
#include "source/piece.h"
#include "source/standardMoves.h"
#include "source/board.h"
#include "source/commandParser.h"

int main()
{
    std::cout << std::endl << "welcome to cpp-chess-v1 by mattperls-code" << std::endl;

    Board board;
    board.draw();
    
    std::string command;
    std::getline(std::cin, command);
    CommandParser::handle(command, board);
    
    return 0;
};