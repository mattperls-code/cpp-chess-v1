#pragma once

class Move
{
    public:
        int x;
        int y;
        std::string name;
        Move(int X, int Y, std::string Name)
        {
            x = X;
            y = Y;
            name = Name;
        };
};