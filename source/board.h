#pragma once

class BoardPiece
{
    public:
        bool exists;
        std::string team;
        int index;
        BoardPiece()
        {
            exists = false;
        };
        BoardPiece(std::string Team, int Index)
        {
            exists = true;
            team = Team;
            index = Index;
        };
};

class Board
{
    public:
        std::string turn;
        std::vector<Piece> redPieces;
        std::vector<Piece> bluePieces;
        Board()
        {
            turn = "red";

            // Red Back Layer
            redPieces.push_back(Piece(0, 0, true, StandardMoves::rook(), "r1"));
            redPieces.push_back(Piece(1, 0, false, StandardMoves::knight(), "k1"));
            redPieces.push_back(Piece(2, 0, true, StandardMoves::bishop(), "b1"));
            redPieces.push_back(Piece(3, 0, true, StandardMoves::queen(), "q1"));
            redPieces.push_back(Piece(4, 0, false, StandardMoves::king(), "K*"));
            redPieces.push_back(Piece(5, 0, true, StandardMoves::bishop(), "b2"));
            redPieces.push_back(Piece(6, 0, false, StandardMoves::knight(), "k2"));
            redPieces.push_back(Piece(7, 0, true, StandardMoves::rook(), "r2"));

            // Red Front Layer
            redPieces.push_back(Piece(0, 1, false, StandardMoves::pawn(), "p1"));
            redPieces.push_back(Piece(1, 1, false, StandardMoves::pawn(), "p2"));
            redPieces.push_back(Piece(2, 1, false, StandardMoves::pawn(), "p3"));
            redPieces.push_back(Piece(3, 1, false, StandardMoves::pawn(), "p4"));
            redPieces.push_back(Piece(4, 1, false, StandardMoves::pawn(), "p5"));
            redPieces.push_back(Piece(5, 1, false, StandardMoves::pawn(), "p6"));
            redPieces.push_back(Piece(6, 1, false, StandardMoves::pawn(), "p7"));
            redPieces.push_back(Piece(7, 1, false, StandardMoves::pawn(), "p8"));

            // Blue Back Layer
            bluePieces.push_back(Piece(0, 7, true, StandardMoves::rook(), "r2"));
            bluePieces.push_back(Piece(1, 7, false, StandardMoves::knight(), "k2"));
            bluePieces.push_back(Piece(2, 7, true, StandardMoves::bishop(), "b2"));
            bluePieces.push_back(Piece(3, 7, true, StandardMoves::queen(), "q1"));
            bluePieces.push_back(Piece(4, 7, false, StandardMoves::king(), "K*"));
            bluePieces.push_back(Piece(5, 7, true, StandardMoves::bishop(), "b1"));
            bluePieces.push_back(Piece(6, 7, false, StandardMoves::knight(), "k1"));
            bluePieces.push_back(Piece(7, 7, true, StandardMoves::rook(), "r1"));

            // Blue Front Layer
            bluePieces.push_back(Piece(0, 6, false, StandardMoves::pawn(), "p8"));
            bluePieces.push_back(Piece(1, 6, false, StandardMoves::pawn(), "p7"));
            bluePieces.push_back(Piece(2, 6, false, StandardMoves::pawn(), "p6"));
            bluePieces.push_back(Piece(3, 6, false, StandardMoves::pawn(), "p5"));
            bluePieces.push_back(Piece(4, 6, false, StandardMoves::pawn(), "p4"));
            bluePieces.push_back(Piece(5, 6, false, StandardMoves::pawn(), "p3"));
            bluePieces.push_back(Piece(6, 6, false, StandardMoves::pawn(), "p2"));
            bluePieces.push_back(Piece(7, 6, false, StandardMoves::pawn(), "p1"));
        }
        BoardPiece getPieceByName(std::string name)
        {
            if(turn == "red"){
                for(int i = 0;i<redPieces.size();i++)
                {
                    if(redPieces[i].name == name){
                        return BoardPiece(turn, i);
                    };
                };
            } else {
                for(int i = 0;i<bluePieces.size();i++)
                {
                    if(bluePieces[i].name == name){
                        return BoardPiece(turn, i);
                    };
                };
            };
            return BoardPiece();
        };
        BoardPiece getPieceByPosition(int x, int y)
        {
            for(int i = 0;i<redPieces.size();i++)
            {
                if(redPieces[i].x == x && redPieces[i].y == y){
                    return BoardPiece("red", i);
                };
            };
            for(int i = 0;i<bluePieces.size();i++)
            {
                if(bluePieces[i].x == x && bluePieces[i].y == y){
                    return BoardPiece("blue", i);
                };
            };
            return BoardPiece();
        };
        void killPiece(BoardPiece piece)
        {
            if(piece.team == "red"){
                redPieces.erase(redPieces.begin() + piece.index);
            } else {
                bluePieces.erase(bluePieces.begin() + piece.index);
            };
        };
        void nextTurn()
        {
            if(turn == "red"){
                turn = "blue";
            } else {
                turn = "red";
            };
        };
        std::string tuiPiece(int x, int y)
        {
            BoardPiece piece = getPieceByPosition(x, y);
            if(piece.exists){
                if(piece.team == "red"){
                    return "\033[31m" + redPieces[piece.index].name + "\033[0m";
                } else {
                    return "\033[34m" + bluePieces[piece.index].name + "\033[0m";
                };
            } else {
                return "  ";
            };
        };
        void draw()
        {
            std::cout << std::endl << "---------------------------------------------------------" << std::endl;
            for(int i = 0;i<8;i++)
            {
                std::cout << "|";
                for(int j = 0;j<8;j++)
                {
                    std::cout << "      |";
                };
                std::cout << std::endl << "|";
                for(int j = 0;j<8;j++)
                {
                    if(turn == "red"){
                        std::cout << "  " << tuiPiece(j, 7 - i) << "  |";
                    } else {
                        std::cout << "  " << tuiPiece(7 - j, i) << "  |";
                    };
                };
                std::cout << std::endl;
                std::cout << "---------------------------------------------------------" << std::endl;
            };
        };
};