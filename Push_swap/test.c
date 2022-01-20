#include "push_swap.h"

void free_move(t_move *move)
{
    free(move);
}


int main()
{
    t_move *move;
    move = malloc(sizeof(t_move*));
    move->move_from = 5;
    printf("%d",move->move_from);
    free_move(move);
    //move->move_from = 42;
    //rintf("%d",move->move_from);
    return 0;
}

