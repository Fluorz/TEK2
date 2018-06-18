/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** main.cpp
*/

#include <ctime>
#include <ECS/Component/MComponent.hpp>
#include <ECS/System/MSystem.hpp>
#include <ECS/System/ISystem.hpp>
#include <ECS/Event/MEvent.hpp>
#include <irrlicht.h>
#ifdef PACK
#include <zconf.h>
#endif
#include "Component/Irrlicht/irrlichtComponent.hpp"
#include "Component/Graphical/CSceneNode.hpp"
#include "System/IrrlichtEvent/SIrrlichtEvent.hpp"
#include "System/Menu/SRenderMenu.hpp"
#include "System/Menu/SMenu.hpp"
#include "System/Menu/MenuLoading/SMenuLoadingRender.hpp"
#include "System/Menu/MenuNewGame/SRenderMenuNewGame.hpp"
#include "System/Menu/MenuNewGame/SMenuNewGame.hpp"
#include "System/Menu/MenuCtrl/SRenderMenuCtrl.hpp"
#include "System/Menu/MenuCtrl/SMenuCtrl.hpp"
#include "System/Menu/MenuSave/SRenderMenuSave.hpp"
#include "System/Menu/MenuSave/SMenuSave.hpp"
#include "System/Scene/SScene.hpp"
#include "System/Resize/SResize.hpp"
#include "System/Game/Rotation/SRotation.hpp"
#include "System/Game/Gravity/SCravity.hpp"
#include "System/Game/FallDamage/SFallDamage.hpp"
#include "System/Game/SMunition/SMunition.hpp"
#include "System/Game/Kill/SKill.hpp"
#include "AI/include/AiCore.hpp"

int main()
{
#ifdef PACK
	chdir("/usr/bin/COP");
#endif
	irr::IrrlichtDevice *device = irr::createDevice(irr::video::EDT_OPENGL,
		irr::core::dimension2d<irr::u32>(1280, 720));
	if (device == 0)
		return 1;

	device->setWindowCaption(L"Call Of Penguin");
	device->setResizable(false);
	MyEventReceiver receiver;
	device->setEventReceiver(&receiver);

	ECS::MComponent<CIrrMain>::create(ECS::MEntity::create(),
					  CIrrMain{device});
	ECS::MComponent<CSceneNode>::create(ECS::MEntity::create(),
					    CSceneNode());
	ECS::MSystem::add(&SIrrlichtEvent::getInstance());
	ECS::MSystem::add(&SMenuLoadingRender::getInstance());
	ECS::MSystem::add(&SRenderMenu::getInstance());
	ECS::MSystem::add(&SMenu::getInstance());
	ECS::MSystem::add(&SRenderMenuSave::getInstance());
	ECS::MSystem::add(&SMenuSave::getInstance());
	ECS::MSystem::add(&SRenderMenuNewGame::getInstance());
	ECS::MSystem::add(&SMenuNewGame::getInstance());
	ECS::MSystem::add(&SRenderMenuCtrl::getInstance());
	ECS::MSystem::add(&SMenuCtrl::getInstance());
	ECS::MSystem::add(&SIrrlichtEvent::getInstance());
	ECS::MSystem::add(&SScene::getInstance());
	ECS::MSystem::add(&SResize::getInstance());
	ECS::MSystem::add(&SRenderGame::getInstance());
	ECS::MSystem::add(&SGame::getInstance());
	ECS::MSystem::add(&SPosition::getInstance());
	ECS::MSystem::add(&SRotation::getInstance());
	ECS::MSystem::add(&SGravity::getInstance());
	ECS::MSystem::add(&SFallDamage::getInstance());
	ECS::MSystem::add(&SMunition::getInstance());
	ECS::MSystem::add(&SKill::getInstance());

	SScene::start();
	SIrrlichtEvent::start();
	SMenuLoadingRender::start();
	SResize::start();
	ECS::MEvent<ERefreshScene, void*>::push(nullptr);

	clock_t t;
	ECS::DeltaTime timeDelta = 0;
	t = clock();
	while (device->run()) {
		if (device->isWindowActive()) {
			t = clock() - t;
			ECS::MSystem::updateAll(timeDelta);
			timeDelta = (float) t / CLOCKS_PER_SEC;
		}
	}

	device->drop();
	return 0;
}
