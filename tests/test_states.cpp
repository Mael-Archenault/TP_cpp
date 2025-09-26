#include "GameStates/HomeState.h"
#include "Game.h"


int main(){

    Game game(new HomeState());

    game.run();
    return 0;
}