#pragma once

class Piece
{
    public:
        int x;
        int y;
        bool canMoveUntilBlocked;
        std::vector<Move> moves;
        std::string name;
        bool hasMoved;
        Piece(){};
        Piece(int X, int Y, bool CanMoveUntilBlocked, std::vector<Move> Moves, std::string Name)
        {
            x = X;
            y = Y;
            canMoveUntilBlocked = CanMoveUntilBlocked;
            moves = Moves;
            name = Name;
            hasMoved = false;
        };
};