#pragma once

class StandardMoves
{
    public:
        static std::vector<Move> rook()
        {
            std::vector<Move> moves;
            moves.push_back(Move(-1, 0, "left"));
            moves.push_back(Move(1, 0, "right"));
            moves.push_back(Move(0, -1, "back"));
            moves.push_back(Move(0, 1, "up"));
            moves.push_back(Move(0, 0, "castle"));
            return moves;
        };
        static std::vector<Move> knight()
        {
            std::vector<Move> moves;
            moves.push_back(Move(-1, 2, "left and up two"));
            moves.push_back(Move(1, 2, "right and up two"));
            moves.push_back(Move(-1, -2, "left and back two"));
            moves.push_back(Move(1, -2, "right and back two"));
            moves.push_back(Move(-2, -1, "left two and back"));
            moves.push_back(Move(-2, 1, "left two and up"));
            moves.push_back(Move(2, -1, "right two and back"));
            moves.push_back(Move(2, 1, "right two and up"));
            return moves;
        };
        static std::vector<Move> bishop()
        {
            std::vector<Move> moves;
            moves.push_back(Move(-1, -1, "left and back"));
            moves.push_back(Move(1, -1, "right and back"));
            moves.push_back(Move(-1, 1, "left and up"));
            moves.push_back(Move(1, 1, "right and up"));
            return moves;
        };
        static std::vector<Move> king()
        {
            std::vector<Move> moves;
            moves.push_back(Move(-1, -1, "left and back"));
            moves.push_back(Move(-1, 0, "left"));
            moves.push_back(Move(-1, 1, "left and up"));
            moves.push_back(Move(0, -1, "back"));
            moves.push_back(Move(0, 1, "up"));
            moves.push_back(Move(1, -1, "right and back"));
            moves.push_back(Move(1, 0, "right"));
            moves.push_back(Move(1, 1, "right and up"));
            return moves;
        };
        static std::vector<Move> queen()
        {
            std::vector<Move> moves;
            moves.push_back(Move(-1, -1, "left and back"));
            moves.push_back(Move(-1, 0, "left"));
            moves.push_back(Move(-1, 1, "left and up"));
            moves.push_back(Move(0, -1, "back"));
            moves.push_back(Move(0, 1, "up"));
            moves.push_back(Move(1, -1, "right and back"));
            moves.push_back(Move(1, 0, "right"));
            moves.push_back(Move(1, 1, "right and up"));
            return moves;
        };
        static std::vector<Move> pawn()
        {
            std::vector<Move> moves;
            moves.push_back(Move(0, 1, "up"));
            moves.push_back(Move(0, 2, "up two"));
            moves.push_back(Move(-1, 1, "left and up"));
            moves.push_back(Move(1, 1, "right and up"));
            return moves;
        };
};