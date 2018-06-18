/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
**        map.hpp
*/

#ifndef _MAP_
# define _MAP_

#include <string>
#include "irrlicht.h"

#include <vector>


using namespace irr;

extern bool _up;
extern bool _left;
extern bool _right;
extern bool _down;
extern int speed;

class MyEventReceiver : public IEventReceiver
{
public:
	MyEventReceiver(bool event):
		_event(event)
		{

		}
	bool OnEvent(const SEvent &event);
private:
	bool _event;
};

int	rand_a_b(int a, int b);
double frand_a_b(double a, double b);

void 	fillBloc4(double *first, double *second);
void 	fillBlocS(double *first, double *second);
void	fillMiddle(double *first, double *second);
void	fillLeft(double *first, double *second);
void	fillRight(double *first, double *second);
void	fillBotom(double *first, double *second);
void 	fillBloc(double *first, double *second);


void createMap(irr::scene::ISceneManager* sceneManager,
					irr::video::IVideoDriver* driver,
					std::vector<irr::scene::IMeshSceneNode*> &map,
					 int nbr_cube);
irr::scene::ILightSceneNode* createLight(irr::scene::ISceneManager* sceneManager);
void 	addBackgroundMap(irr::scene::ISceneManager* sceneManager,
					irr::video::IVideoDriver* driver);
void 	addCameraMap(irr::scene::ISceneManager* sceneManager);

bool	checkPosition(std::vector<irr::scene::IMeshSceneNode*> &map,
			scene::IAnimatedMeshSceneNode* mesh, const char *string);
#endif
