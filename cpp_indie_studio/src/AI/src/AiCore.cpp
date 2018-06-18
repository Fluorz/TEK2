/*
** EPITECH PROJECT, 2018
** Indie
** File description:
** AI
*/

#include "../include/AiCore.hpp"

AiCore::AiCore()
{
    _state = luaL_newstate();
    _size = 0;
    _targetId = 0;
    _weaponToUse = 0;
    _move = 0;
    std::cout << "Ai created" << std::endl;
}

AiCore::~AiCore()
{
    if (_state != NULL) {
        std::cout << "Ai destroyed" << std::endl;
        lua_close(_state);
    }
}

void AiCore::print_error()
{
	std::string error_message = lua_tostring(_state, -1);
	std::cerr << error_message << std::endl;
	lua_pop(_state, 1);
}

void AiCore::mainAi(ECS::Entity team)
{
    loadScript();
    setCurrentWorms();
    sendCurrentWorms();
    setDatas();
    sendDatas();
    execute();
}

void AiCore::loadScript()
{
    luaL_openlibs(_state);
    _result = luaL_loadfile(_state, SCRIPT);
    
    if (_result != LUA_OK) {
        print_error();
        return;
    }
}

void AiCore::setDatas()
{
    for (auto &worms : ECS::MComponent<CName>::getAll()) {
        auto &name = worms.second;
        auto pos = ECS::MComponent<CPos>::get(worms.first);
        auto move = ECS::MComponent<CMovement>::get(worms.first);
        auto life = ECS::MComponent<CLife>::get(worms.first);
        auto fall = ECS::MComponent<CFall>::get(worms.first);
        auto team = ECS::MComponent<CTeam>::get(worms.first);

        _data.worm.push_back(worms.first);
        _data.name.push_back(name.name);
        _data.posX.push_back(pos->x);
        _data.posY.push_back(pos->y);
        _data.moveX.push_back(move->X);
        _data.moveY.push_back(move->Y);
        _data.life.push_back(life->life);
        _data.fall.push_back(fall->fall);
        _data.team.push_back(team->team);

        _size = _size + 1;
    }
}

void AiCore::sendDatas()
{
    lua_newtable(_state);
    for (int i = 0; i < _size; i++) {
        lua_newtable(_state);
        lua_pushnumber(_state, _data.worm[i]);
        lua_setfield(_state, -2, "worm");
        lua_pushstring(_state, _data.name[i].c_str());
        lua_setfield(_state, -2, "name");
        lua_pushnumber(_state, _data.posX[i]);
        lua_setfield(_state, -2, "posX");
        lua_pushnumber(_state, _data.posY[i]);
        lua_setfield(_state, -2, "posY");
        lua_pushnumber(_state, _data.moveX[i]);
        lua_setfield(_state, -2, "moveX");
        lua_pushnumber(_state, _data.moveY[i]);
        lua_setfield(_state, -2, "moveY");
        lua_pushnumber(_state, _data.life[i]);
        lua_setfield(_state, -2, "life");
        lua_pushnumber(_state, _data.fall[i]);
        lua_setfield(_state, -2, "fall");
        lua_pushnumber(_state, _data.fall[i]);
        lua_setfield(_state, -2, "fall");
        lua_pushnumber(_state, _data.team[i]);
        lua_setfield(_state, -2, "team");
        lua_rawseti(_state, -2, i + 1);
    }
        lua_setglobal(_state, "worms");
}

void AiCore::setCurrentWorms()
{
    std::cout << "\nstart setCurrentWorms\n" << std::endl;
    if (ECS::MComponent<CTurn>::getAll().empty()) {
        return;
    }
    auto turn = ECS::MComponent<CTurn>::getAll().begin()->second;
    _currWorm = turn.currentWorm.at(turn.currentTeam);
    auto name = ECS::MComponent<CName>::get(_currWorm);
    auto pos = ECS::MComponent<CPos>::get(_currWorm);
    auto move = ECS::MComponent<CMovement>::get(_currWorm);
    auto life = ECS::MComponent<CLife>::get(_currWorm);
    auto fall = ECS::MComponent<CFall>::get(_currWorm);
    auto team = ECS::MComponent<CTeam>::get(_currWorm);

    auto inventory = ECS::MComponent<CInventory>::get(team->team);

    _currentWorm.worm = _currWorm;
    _currentWorm.name = name->name;
    _currentWorm.posX = pos->x;
    _currentWorm.posY = pos->y;
    _currentWorm.moveX = move->X;
    _currentWorm.moveY = move->Y;
    _currentWorm.life = life->life;
    _currentWorm.fall = fall->fall;
    _currentWorm.team = team->team;

    _nb_weapon = 0;
    int nivel = 0;
    int range = 1;
    for (const auto &p : inventory->weaponList) {
        _weapon.weapon_id.push_back(p.first);
        _weapon.ammo.push_back(p.second);
        _weapon.damage.push_back(100 - nivel);
        _weapon.max_range.push_back(range);
        _nb_weapon = _nb_weapon + 1;
        nivel = nivel + 25;
        range = range + 10;
    }
    std::cout << "\nend setCurrentWorms\n" << std::endl;
}

void AiCore::sendCurrentWorms()
{
    std::cout << "\nstart sendCurrentWorms\n" << std::endl;
    lua_newtable(_state);
    for (int i = 0; i < 1; i++) {
        lua_newtable(_state);
        lua_pushnumber(_state, _currentWorm.worm);
        lua_setfield(_state, -2, "worm");
        lua_pushstring(_state, _currentWorm.name.c_str());
        lua_setfield(_state, -2, "name");
        lua_pushnumber(_state, _currentWorm.posX);
        lua_setfield(_state, -2, "posX");
        lua_pushnumber(_state, _currentWorm.posY);
        lua_setfield(_state, -2, "posY");
        lua_pushnumber(_state, _currentWorm.moveX);
        lua_setfield(_state, -2, "moveX");
        lua_pushnumber(_state, _currentWorm.moveY);
        lua_setfield(_state, -2, "moveY");
        lua_pushnumber(_state, _currentWorm.life);
        lua_setfield(_state, -2, "life");
        lua_pushnumber(_state, _currentWorm.fall);
        lua_setfield(_state, -2, "fall");
        lua_pushnumber(_state, _currentWorm.team);
        lua_setfield(_state, -2, "team");
        lua_rawseti(_state, -2, i + 1);
    }
    lua_setglobal(_state, "currentWorm");
    
    lua_newtable(_state);
    for (int i = 0; i < _nb_weapon; i++) {
        lua_newtable(_state);
        lua_pushnumber(_state, _weapon.weapon_id[i]);
        lua_setfield(_state, -2, "weapon_id");
        lua_pushnumber(_state, _weapon.ammo[i]);
        lua_setfield(_state, -2, "ammo");
        lua_pushnumber(_state, _weapon.damage[i]);
        lua_setfield(_state, -2, "damage");
        lua_pushnumber(_state, _weapon.max_range[i]);
        lua_setfield(_state, -2, "max_range");
        lua_rawseti(_state, -2, i + 1);
    }
    lua_setglobal(_state, "weapons");
    std::cout << "\nend sendCurrentWorms\n" << std::endl;
}

float AiCore::moveAI(ECS::Entity team)
{
    lua_getglobal(_state, "Move");
    lua_call(_state, -1, 1);
    _move = (float) lua_tonumber(_state, -1);
    std::cout << "I AM MOVING : " << _move << std::endl;
    auto pos = ECS::MComponent<CPos>::get(_currWorm);
    //pos->x = pos->x + _move;
    return _move;
}

unsigned long int AiCore::getTarget()
{
    //lua_getglobal(_state, "nearest_target");
    //lua_call(_state, LUA_MULTRET, 1);
    //_targetId = (unsigned long int)lua_tointeger(_state, -1);
    return _targetId;
}

int AiCore::getWeapon()
{
    return _weaponToUse;
}

void AiCore::execute()
{
    _result = lua_pcall(_state, 0, LUA_MULTRET, 0);
    if (_result != LUA_OK) {
        print_error();
        return;
    }
    else
        std::cout << "OK" << std::endl;
}