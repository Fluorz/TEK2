/*
** EPITECH PROJECT, 2018
** Indie
** File description:
** AI
*/

#ifndef AICORE_HPP_
    #define AICORE_HPP_
    
    extern "C" {
        #include "lua.h"
        #include "lauxlib.h"
        #include "lualib.h"
    };
    
    #include <string>
    #include <iostream>
    #include <fstream>
    #include <vector>
    
#ifdef _WIN32
	#define SCRIPT "./AI/ai.lua"
#else 
	#define SCRIPT "./src/AI/script/ai.lua"
#endif // _WIN32

   
    
    #include "ECS/Entity/MEntity.hpp"
    #include "ECS/Component/MComponent.hpp"
    #include "System/Game/SGame.hpp"

    #include <Component/Physic/CPos.hpp>
    #include <Component/Physic/CMovement.hpp>
    #include <Component/Game/CLife.hpp>
    #include <Component/Physic/CFall.hpp>
    #include <Component/Game/CName.hpp>
    #include <Component/Game/CTeam.hpp>

    #include <Component/Game/CTurn.hpp>

    #include <Component/Game/CInventory.hpp>
    #include "Component/Game/CWeapon.hpp"
    
    typedef struct dataAi_s {
        std::vector<unsigned long int> worm;
        std::vector<std::string> name;
        std::vector<float> posX;
        std::vector<float> posY;
        std::vector<float> moveX;
        std::vector<float> moveY;
        std::vector<int> life;
        std::vector<int> fall;
        std::vector<unsigned long int> team;
    } dataAi_t;

    typedef struct currWorm_s {
        unsigned long int worm;
        std::string name;
        float posX;
        float posY;
        float moveX;
        float moveY;
        int life;
        int fall;
        unsigned long int team;
    } currWorm_t;

    typedef struct weapon_s {
        std::vector<int> weapon_id;
        std::vector<int> ammo;
        std::vector<int> damage;
        std::vector<int> max_range;
    } weapon_t;

    class AiCore {
        public:
            AiCore();
            ~AiCore();
            
            void print_error();

            void mainAi(ECS::Entity team);            
            void loadScript();

            void setDatas();
            void sendDatas();

            void setCurrentWorms();
            void sendCurrentWorms();

            float moveAI(ECS::Entity team);
            unsigned long int getTarget();
            int getWeapon();


            void execute();
            
        protected:
        private:
            lua_State *_state;
            std::string _file;
            int _result;
            int _size;
            int _nb_weapon;
            dataAi_t _data;
            currWorm_t _currentWorm;
            weapon_t _weapon;

            unsigned long int _targetId;
            int _weaponToUse;
            float _move;
            ECS::Entity _currWorm;
    };
    
#endif /* !AICORE_HPP_ */