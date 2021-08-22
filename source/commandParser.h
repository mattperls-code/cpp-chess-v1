#pragma once

class CommandParser
{
    private:
        static void awaitNextCommand(Board board)
        {
            std::string command;
            std::getline(std::cin, command);
            handle(command, board);
        };
        static void handleMoveCommand(std::string command, Board board)
        {
            BoardPiece target = board.getPieceByName(command.substr(0, 2));
            if(target.exists){
                std::vector<Move> targetsMoves = (target.team == "red" ? board.redPieces : board.bluePieces)[target.index].moves;
                std::string moveInfo = command.substr(3);
                std::string moveName = moveInfo.substr(0, moveInfo.find(" *"));
                int moveIterationCount = std::stoi(moveInfo.substr(moveInfo.find("*") + 1));
                for(int i = 0;i<targetsMoves.size();i++)
                {
                    if(targetsMoves[i].name == moveName){
                        if(moveIterationCount != 1 && !(target.team == "red" ? board.redPieces : board.bluePieces)[target.index].canMoveUntilBlocked){
                            std::cout << "piece \"" + (target.team == "red" ? board.redPieces : board.bluePieces)[target.index].name + "\" can only move 1 iteration" << std::endl;
                            awaitNextCommand(board);
                        } else if(moveIterationCount <= 0) {
                            std::cout << "move iteration count must be a positive integer" << std::endl;
                            awaitNextCommand(board);
                        } else {
                            if((target.team == "red" ? board.redPieces : board.bluePieces)[target.index].name.substr(0, 1) == "p"){
                                if(moveName == "up"){
                                    if(target.team == "red"){
                                        if(board.getPieceByPosition((target.team == "red" ? board.redPieces : board.bluePieces)[target.index].x, (target.team == "red" ? board.redPieces : board.bluePieces)[target.index].y + 1).exists){
                                            std::cout << "move is not legal" << std::endl;
                                            return awaitNextCommand(board);
                                        };
                                    } else if(board.getPieceByPosition((target.team == "red" ? board.redPieces : board.bluePieces)[target.index].x, (target.team == "red" ? board.redPieces : board.bluePieces)[target.index].y - 1).exists){
                                        std::cout << "move is not legal" << std::endl;
                                        return awaitNextCommand(board);
                                    };
                                } else if(moveName == "up two"){
                                    if(!(target.team == "red" && (target.team == "red" ? board.redPieces : board.bluePieces)[target.index].y == 1) && !(target.team == "blue" && (target.team == "red" ? board.redPieces : board.bluePieces)[target.index].y == 6)){
                                        std::cout << "move is not legal" << std::endl;
                                        return awaitNextCommand(board);
                                    };
                                } else if(moveName == "left and up"){
                                    if(target.team == "red"){
                                        BoardPiece currentLeftAndUp = board.getPieceByPosition((target.team == "red" ? board.redPieces : board.bluePieces)[target.index].x - 1, (target.team == "red" ? board.redPieces : board.bluePieces)[target.index].y + 1);
                                        if(!currentLeftAndUp.exists || currentLeftAndUp.team == "red"){
                                            std::cout << "move is not legal" << std::endl;
                                            return awaitNextCommand(board);
                                        };
                                    } else {
                                        BoardPiece currentLeftAndUp = board.getPieceByPosition((target.team == "red" ? board.redPieces : board.bluePieces)[target.index].x + 1, (target.team == "red" ? board.redPieces : board.bluePieces)[target.index].y - 1);
                                        if(!currentLeftAndUp.exists || currentLeftAndUp.team == "blue"){
                                            std::cout << "move is not legal" << std::endl;
                                            return awaitNextCommand(board);
                                        };
                                    };
                                } else if(moveName == "right and up"){
                                    if(target.team == "red"){
                                        BoardPiece currentRightAndUp = board.getPieceByPosition((target.team == "red" ? board.redPieces : board.bluePieces)[target.index].x + 1, (target.team == "red" ? board.redPieces : board.bluePieces)[target.index].y + 1);
                                        if(!currentRightAndUp.exists || currentRightAndUp.team == "red"){
                                            std::cout << "move is not legal" << std::endl;
                                            return awaitNextCommand(board);
                                        };
                                    } else {
                                        BoardPiece currentRightAndUp = board.getPieceByPosition((target.team == "red" ? board.redPieces : board.bluePieces)[target.index].x - 1, (target.team == "red" ? board.redPieces : board.bluePieces)[target.index].y - 1);
                                        if(!currentRightAndUp.exists || currentRightAndUp.team == "blue"){
                                            std::cout << "move is not legal" << std::endl;
                                            return awaitNextCommand(board);
                                        };
                                    };
                                };
                            } else if((target.team == "red" ? board.redPieces : board.bluePieces)[target.index].name.substr(0, 1) == "r"){
                                if(moveName == "castle"){
                                    if((target.team == "red" ? board.redPieces : board.bluePieces)[target.index].hasMoved || (target.team == "red" ? board.redPieces : board.bluePieces)[board.getPieceByName("K*").index].hasMoved){
                                        std::cout << "move is not legal" << std::endl;
                                        return awaitNextCommand(board);
                                    } else {
                                        if(target.team == "red"){
                                            if((target.team == "red" ? board.redPieces : board.bluePieces)[target.index].x == 0){
                                                if(board.getPieceByPosition(1, 0).exists || board.getPieceByPosition(2, 0).exists || board.getPieceByPosition(3, 0).exists){
                                                    std::cout << "move is not legal" << std::endl;
                                                    return awaitNextCommand(board);
                                                };
                                            } else {
                                                if(board.getPieceByPosition(5, 0).exists || board.getPieceByPosition(6, 0).exists){
                                                    std::cout << "move is not legal" << std::endl;
                                                    return awaitNextCommand(board);
                                                };
                                            };
                                        } else {
                                            if((target.team == "red" ? board.redPieces : board.bluePieces)[target.index].x == 0){
                                                if(board.getPieceByPosition(1, 7).exists || board.getPieceByPosition(2, 7).exists || board.getPieceByPosition(3, 7).exists){
                                                    std::cout << "move is not legal" << std::endl;
                                                    return awaitNextCommand(board);
                                                };
                                            } else {
                                                if(board.getPieceByPosition(5, 7).exists || board.getPieceByPosition(6, 7).exists){
                                                    std::cout << "move is not legal" << std::endl;
                                                    return awaitNextCommand(board);
                                                };
                                            };
                                        };
                                        int tempX = (target.team == "red" ? board.redPieces : board.bluePieces)[target.index].x;
                                        (target.team == "red" ? board.redPieces : board.bluePieces)[target.index].x = (target.team == "red" ? board.redPieces : board.bluePieces)[board.getPieceByName("K*").index].x;
                                        (target.team == "red" ? board.redPieces : board.bluePieces)[board.getPieceByName("K*").index].x = tempX;
                                        (target.team == "red" ? board.redPieces : board.bluePieces)[target.index].hasMoved = true;
                                        (target.team == "red" ? board.redPieces : board.bluePieces)[board.getPieceByName("K*").index].hasMoved = true;
                                        board.nextTurn();
                                        board.draw();
                                        return awaitNextCommand(board);
                                    };
                                };
                            };
                            int x = (target.team == "red" ? board.redPieces : board.bluePieces)[target.index].x;
                            int y = (target.team == "red" ? board.redPieces : board.bluePieces)[target.index].y;
                            for(int j = 0;j<moveIterationCount - 1;j++)
                            {
                                if(board.turn == "red"){
                                    x += targetsMoves[i].x;
                                    y += targetsMoves[i].y;
                                } else {
                                    x -= targetsMoves[i].x;
                                    y -= targetsMoves[i].y;
                                };
                                if(x < 0 || x > 7 || y < 0 || y > 7 || board.getPieceByPosition(x, y).exists){
                                    std::cout << "move is not legal" << std::endl;
                                    return awaitNextCommand(board);
                                };
                            };
                            if(board.turn == "red"){
                                x += targetsMoves[i].x;
                                y += targetsMoves[i].y;
                            } else {
                                x -= targetsMoves[i].x;
                                y -= targetsMoves[i].y;
                            };
                            BoardPiece finalPosition = board.getPieceByPosition(x, y);
                            if(x < 0 || x > 7 || y < 0 || y > 7 || (finalPosition.exists && finalPosition.team == board.turn)){
                                std::cout << "move is not legal" << std::endl;
                            } else {
                                if(finalPosition.exists && finalPosition.team != board.turn){
                                    if((finalPosition.team == "red" ? board.redPieces : board.bluePieces)[finalPosition.index].name == "K*"){
                                        board.killPiece(finalPosition);
                                        (target.team == "red" ? board.redPieces : board.bluePieces)[target.index].x = x;
                                        (target.team == "red" ? board.redPieces : board.bluePieces)[target.index].y = y;
                                        board.draw();
                                        std::cout << std::endl << board.turn << " team wins" << std::endl << std::endl;
                                        std::cout << "play again? (y/n) > ";
                                        std::string playAgain;
                                        std::cin >> playAgain;
                                        std::cout << std::endl;
                                        if(playAgain == "y"){
                                            board = Board();
                                            board.draw();
                                            std::string firstCommand;
                                            std::cin >> firstCommand;
                                            return CommandParser::handle(firstCommand, board);
                                        } else {
                                            std::cout << "thank you for playing cpp-chess-v1 by mattperls-code" << std::endl;
                                            return;
                                        };
                                    } else {
                                        board.killPiece(finalPosition);
                                    };
                                };
                                (target.team == "red" ? board.redPieces : board.bluePieces)[target.index].x = x;
                                (target.team == "red" ? board.redPieces : board.bluePieces)[target.index].y = y;
                                (target.team == "red" ? board.redPieces : board.bluePieces)[target.index].hasMoved = true;
                                board.nextTurn();
                                board.draw();
                            };
                            awaitNextCommand(board);
                        };
                        return;
                    };
                };
                std::cout << "move \"" << moveName << "\" is not a valid move for piece \"" << (target.team == "red" ? board.redPieces : board.bluePieces)[target.index].name << "\"" << std::endl;
                awaitNextCommand(board);
            } else {
                std::cout << "piece named \"" << command.substr(0, 2) << "\" is not valid" << std::endl;
                awaitNextCommand(board);
            };
        };
    public:
        static void handle(std::string command, Board board)
        {
            if(command.size() < 4){
                std::cout << "the command provided is not valid" << std::endl;
                awaitNextCommand(board);
            } else {
                if(command.substr(0, 4) == "move"){
                    if(command.size() < 7){
                        std::cout << "the command provided is incomplete" << std::endl;
                        awaitNextCommand(board);
                    } else {
                        handleMoveCommand(command.substr(5), board);
                    };
                } else if(command.substr(0, 4) == "quit"){
                    std::cout << "thank you for playing cpp-chess-v1 by mattperls-code" << std::endl;
                } else {
                    std::cout << "the command provided is not valid" << std::endl;
                    awaitNextCommand(board);
                };
            };
        };
};