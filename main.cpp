#include "Engine/GameStates/HomeState.h"
#include "Engine/Game.h"


int main(){

    Game game(new HomeState());

    game.run();
    return 0;
}