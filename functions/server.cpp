// Contains server functions
#include "../curve.h"

void Server_Sync_Clients(const Config &config,Game &game,Player player[]){
    for(int i=0;i<MAX_PLAYERS;i++){
        Pending pending;
        pending.packet << Packet::Sync << i << player[i].name << player[i].enabled << player[i].ready;
        pending.send_id.push_back(-1);
        game.mutex.lock();
        game.pending.push_back(pending);
        game.mutex.unlock();
    }
}
//
void Server_Start_Game(const Config &config,Game &game,Player player[]){
    // Check keys
    if(player[game.id].keyL!=sf::Keyboard::Unknown&&player[game.id].keyR!=sf::Keyboard::Unknown&&game.players>1&&game.server[1]){
        // Loop Players
        bool NReady=false;
        player[0].points=0;
        for(int i=1;i<MAX_PLAYERS&&!NReady;i++){
            if(player[i].enabled&&!player[i].ready){
                NReady=true;
                break;
            }
            else{
                player[i].points=0;
                player[i].left=player[i].right=false;
                player[i].place=i;
                player[i].ready=false;
            }
        }
        // If everyone ready start game!
        if(!NReady){
            std::cout << "Start Game" << std::endl;
            // Send Start Packages
            Pending pending;
            pending.packet << Packet::StartGame;
            pending.send_id.push_back(-1);
            game.mutex.lock();
            game.pending.push_back(pending);
            game.mutex.unlock();
            // Set the seed
            sf::Time time=game.randclock.getElapsedTime();
            srand (time.asSeconds()+time.asMilliseconds());
            // Initialize game and round
            game.round=0;
            sf::sleep(sf::milliseconds(20));
            Initialize_New_Round_Server(config,game,player);
            game.update_thread[0]=true;
            game.mode=Game::Mode::Play_MP;
        }
    }
}
//
void Config_Package(Game &game){
// Send
    Pending pending;
    pending.packet << Packet::Config << game.maxpoints << game.powerup_enabled;
    pending.send_id.push_back(-1);
    game.mutex.lock();
    game.pending.push_back(pending);
    game.mutex.unlock();
}
//
