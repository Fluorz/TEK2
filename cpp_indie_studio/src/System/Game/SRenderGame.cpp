/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** SRenderGame.cpp
*/

#include <string>
#include <Component/Game/CTimeScd.hpp>
#include "SRenderGame.hpp"
#include "Component/Irrlicht/irrlichtComponent.hpp"
#include "tool/FontTool.hpp"

void SRenderGame::init()
{
	addBackgroundMap();
	addCameraMap();
	createLight();
}

void SRenderGame::handleEvents()
{
	//destructBloc(1, 1, 1);
}

static void drawTeamLife()
{
	auto &DeviceContener = ECS::MComponent<CIrrMain>::getAll();
	auto &wormList = ECS::MComponent<CName>::getAll();
	if (DeviceContener.empty() || wormList.empty())
		return;
	auto &env = DeviceContener.begin()->second.env;
	auto &driv = DeviceContener.begin()->second.driver;

	std::map<ECS::Entity , int> lifeMap;

	for (auto it = wormList.begin();
	     it != wormList.end(); std::advance(it, 1)) {
		auto life = ECS::MComponent<CLife>::get(it->first)->life;
		auto team = ECS::MComponent<CTeam>::get(it->first)->team;
		if (lifeMap.find(team) == lifeMap.end())
			lifeMap.emplace(team, 0);
		auto itLife = lifeMap.find(team);
		itLife->second += life;
	}
	int i = 0;
	for (auto it = lifeMap.begin();
	     it != lifeMap.end(); std::advance(it, 1)) {
		auto color = ECS::MComponent<CColor>::get(it->first)->color;
		const irr::core::dimension2du &s = driv->getScreenSize();
		irr::core::stringw str = std::string(std::to_string(it->second)
			+ " / 400").c_str();
		FontTool::getFont(L"AAAAAAAAAA", 0.2)
			->draw(str, irr::core::rect<irr::s32>(
				(int)(s.Width / lifeMap.size() *
				      i + s.Width / lifeMap.size() / 4),
				15,
				(int)(s.Width / lifeMap.size() * (i + 1)),
				60),
			       color);
		i++;
	}
}

static void drawName()
{
	auto &DeviceContener = ECS::MComponent<CIrrMain>::getAll();
	auto &wormList = ECS::MComponent<CName>::getAll();
	if (DeviceContener.empty() || wormList.empty())
		return;
	auto &env = DeviceContener.begin()->second.env;
	auto &driv = DeviceContener.begin()->second.driver;
	for (auto it = wormList.begin();
		it != wormList.end(); std::advance(it, 1)) {
		auto pos = ECS::MComponent<CPos>::get(it->first);
		ECS::Entity team = ECS::MComponent<CTeam>::get(it->first)->team;
		auto color = ECS::MComponent<CColor>::get(team)->color;
		irr::core::stringw str = it->second.name.c_str();
		const irr::core::dimension2du &s = driv->getScreenSize();
		FontTool::getFont(L"AAAAAAA", 0.07)
			->draw(str, irr::core::rect<irr::s32>(
				(int)((500 - pos->x) / 500.0 * s.Width - 15),
				(int)((270 - pos->y) / 270.0 * s.Height - 50),
				(int)((500 - pos->x) / 500.0 * s.Width + 15.0),
				(int)((270 - pos->y) / 270.0 * s.Height - 40)),
			       color);
		auto life = ECS::MComponent<CLife>::get(it->first)->life;
		str = std::to_string(life).c_str();
		FontTool::getFont(L"AAAAAAA", 0.07)
			->draw(str, irr::core::rect<irr::s32>(
				(int)((500 - pos->x) / 500.0 * s.Width - 5),
				(int)((270 - pos->y) / 270.0 * s.Height - 63),
				(int)((500 - pos->x) / 500.0 * s.Width + 10),
				(int)((270 - pos->y) / 270.0 * s.Height - 55)),
			       irr::video::SColor(255, 255, 150, 150));
	}
}

static void drawTime()
{
	auto &DeviceContener = ECS::MComponent<CIrrMain>::getAll();
	if (DeviceContener.empty())
		return;
	auto &driv = DeviceContener.begin()->second.driver;
	auto &timeList = ECS::MComponent<CTimeScd>::getAll();
	CTimeScd *timeGame = nullptr;

	for (auto it = timeList.begin(); it != timeList.end();
	     std::advance(it, 1))
		if (it->second.id == id_time::TIME_GAME)
			timeGame = &(it->second);
	if (!timeGame)
		return;

	irr::video::SColor color(255, 0, 0, 0);
	std::time_t diff = timeGame->waiting - std::time(nullptr);
	if (diff < 0)
		diff = 0;
	if (diff < 10)
		color.setRed((int)((float)(10.0 - diff) / 10.0 * 255));

	const irr::core::dimension2du &s = driv->getScreenSize();
	irr::core::stringw str = std::string(std::to_string(diff)).c_str();
	FontTool::getFont(L"AAAAAAA", 0.2)
		->draw(str, irr::core::rect<irr::s32>(
			(int)(s.Width * 0.9),
			(int)(s.Height * 0.1),
			(int)(s.Width),
			(int)(s.Height * 0.2)),
		       color);

}

static void drawCurrent()
{
	auto &DeviceContener = ECS::MComponent<CIrrMain>::getAll();
	auto &wormList = ECS::MComponent<CName>::getAll();
	if (DeviceContener.empty() || wormList.empty())
		return;
	auto &env = DeviceContener.begin()->second.env;
	auto &driv = DeviceContener.begin()->second.driver;
	auto turn = ECS::MComponent<CTurn>::getAll().begin()->second;
	auto color = ECS::MComponent<CColor>::get(turn.currentTeam)->color;
	const irr::core::dimension2du &s = driv->getScreenSize();
	std::string name = ECS::MComponent<CName>
	        ::get(turn.currentWorm.at(turn.currentTeam))->name;

	FontTool::getFont(L"AAAAAAA", 0.2)
		->draw(irr::core::stringw(name.c_str()),
		       irr::core::rect<irr::s32>(
			(int)(s.Width * 0.05), (int)(s.Height * 0.1),
			(int)(s.Width * 0.25), (int)(s.Height * 0.2)), color);
}

static void drawCurrentWeapon()
{
	auto &DeviceContener = ECS::MComponent<CIrrMain>::getAll();
	auto &wormList = ECS::MComponent<CName>::getAll();
	if (DeviceContener.empty() || wormList.empty())
		return;
	auto &env = DeviceContener.begin()->second.env;
	auto &driv = DeviceContener.begin()->second.driver;
	auto &turn = ECS::MComponent<CTurn>::getAll().begin()->second;
	const irr::core::dimension2du &s = driv->getScreenSize();

	auto id = ECS::MComponent<CWeapon>
		::get(turn.currentWorm.at(turn.currentTeam))->weapon;
	std::string weapName = "";
	switch (id) {
		case Eweapon::NONE:
			weapName = "None";
			break;
		case Eweapon::GRENADE:
			weapName = "Bomb";
			break;
		case Eweapon::BAZOOKA:
			weapName = "Rocket";
			break;
		case Eweapon::SKY_STRIKER:
			weapName = "Sky Drop";
			break;
	}
	FontTool::getFont(L"AAAAAAA", 0.12)
		->draw(irr::core::stringw(weapName.c_str()),
		       irr::core::rect<irr::s32>(
			       (int)(s.Width * 0.05), (int)(s.Height * 0.2),
			       (int)(s.Width * 0.25), (int)(s.Height * 0.25)),
		irr::video::SColor(255, 255, 255, 255));
}

void SRenderGame::update(ECS::DeltaTime delta)
{
	auto &DeviceContener = ECS::MComponent<CIrrMain>::getAll();
	if (DeviceContener.empty())
		return;
	auto &env = DeviceContener.begin()->second.env;
	auto &driver = DeviceContener.begin()->second.driver;
	auto &device = DeviceContener.begin()->second.device;
	irr::scene::ISceneManager* sceneManager =
		device->getSceneManager();
	irr::video::SColor color(255, 255, 255, 255);
	driver->beginScene(true, true, color);
	auto nbTeam = ECS::MComponent<CInventory>::getAll().size();
	if (nbTeam >= 2) {
		sceneManager->drawAll();
		drawName();
		drawTeamLife();
		drawTime();
		drawCurrent();
		drawCurrentWeapon();
	} else {
		sceneManager->drawAll();
		const irr::core::dimension2du &s = driver->getScreenSize();
		auto ccolor = ECS::MComponent<CColor>::getAll()
			.begin()->second.color;
		irr::core::stringw str = "You Win !";
		FontTool::getFont(L"AAAAAAA", 1)
			->draw(str, irr::core::rect<irr::s32>(
				(int)(s.Width * 0.3),
				(int)(s.Height * 0.4),
				(int)(s.Width * 0.7),
				(int)(s.Height * 0.6)),
			       ccolor);
	}
	driver->endScene ();
}

void SRenderGame::postUpdate(ECS::DeltaTime delta)
{
}

void SRenderGame::preUpdate(ECS::DeltaTime delta)
{
}
