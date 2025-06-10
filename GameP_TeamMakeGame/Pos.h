#pragma once
typedef struct _pos
{
    int x;
    int y;
    void PlusXY(int plusX, int plusY);
    void SetPos(int setX, int setY);
    const bool operator ==(const _pos& _other) const
    {
        return (x == _other.x && y == _other.y);
    }
}POS, * PPOS;