/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** SMenuNewGame.cpp
*/

#include <Component/Game/CGameStatus.hpp>
#include <Component/Game/CTimeScd.hpp>
#include "SMenuNewGame.hpp"
#if defined(_WIN32) || defined(_WIN64)
#include <time.h>
#endif // defined(_WIN32) || defined(_WIN64)

void SMenuNewGame::handleEvents() {
	void *data;
	int id;

	if (ECS::MEvent<ERefreshScene, void *>::pop(data))
		this->refresh();
	if (ECS::MEvent<EClickBox, int>::pop(id))
		this->boxGestion(id);
	if (ECS::MEvent<EStartNewGame, void *>::pop(data))
		this->startGestion();
}

irr::gui::IGUICheckBox *
SMenuNewGame::addCheckBox(const irr::core::rect<irr::s32> boxRect,
			  const irr::core::rect<irr::s32> textRect,
			  const wchar_t *textStatic, int id, bool check) {
	static irr::video::SColor colorList[] = {
		{255, 0, 0, 255},
		{255, 255, 0, 0},
		{255, 0, 255, 0},
		{255, 255, 255, 0}
	};
	auto env = ECS::MComponent<CIrrMain>::getAll().begin()->second.env;
	auto driv = ECS::MComponent<CIrrMain>::getAll().begin()->second.driver;
	const irr::core::dimension2du &s = driv->getScreenSize();
	irr::gui::IGUIStaticText *text = nullptr;
	irr::gui::IGUICheckBox *checkBox = nullptr;

	checkBox = env->addCheckBox(check, boxRect, 0, id);
	text = env->addStaticText(textStatic, textRect, true);
	text->setOverrideFont(
		FontTool::getFont(L"AAAAAAAAAA", 0.15,
				  false, CLOSEST_DOWN));
	text->setTextAlignment(irr::gui::EGUIA_UPPERLEFT,
			       irr::gui::EGUIA_UPPERLEFT);
	text->setDrawBorder(false);
	if (id >= id_gui::CHECK_BOX_1_PLAYER &&
	    id <= id_gui::CHECK_BOX_4_PLAYER)
		text->setOverrideColor(
			colorList[id - id_gui::CHECK_BOX_1_PLAYER]);
	return checkBox;
}

void SMenuNewGame::init()
{
	ECS::MComponent<CCheckBoxs>::create(ECS::MEntity::create(),
					    CCheckBoxs());
}

void SMenuNewGame::refresh()
{
	auto &env = ECS::MComponent<CIrrMain>::getAll().begin()->second.env;
	auto &driv = ECS::MComponent<CIrrMain>::getAll().begin()->second.driver;
	auto &boxList = ECS::MComponent<CCheckBoxs>::getAll()
		.begin()->second;

	env->clear();
	auto textureList = ECS::MComponent<CImageTexture>::getAll();
	irr::video::ITexture *imgBack = nullptr;
	irr::gui::IGUIButton *button = nullptr;
	irr::gui::IGUIImage *img = nullptr;

	for (auto it = textureList.begin();
	     it != textureList.end();
	     std::advance(it, 1))
		if (it->second.id == "back1")
			imgBack = it->second.img;
	const irr::core::dimension2du &s = driv->getScreenSize();
	env->addButton(irr::core::rect<irr::s32>(
		(10), (10),
		(int) (s.Width / 8.0),
		(int) (s.Height / 10.0)
	), 0, BUTTON_MENU_NEW_GAME_BACK, L"BACK");
	button = env->addButton(irr::core::rect<irr::s32>(
		(int) (s.Width / 2 - s.Width * 0.1),
		(int) (s.Height * 0.8),
		(int) (s.Width / 2 + s.Width * 0.1),
		(int) (s.Height * 0.90)
	), 0, BUTTON_MENU_NEW_GAME_START, L"START");
	if (imgBack) {
		button->setOverrideFont(
			FontTool::getFont(L"START", 0.07));
		button->setImage(imgBack);
		button->setScaleImage(true);
	}
	img = env->addImage(irr::core::rect<irr::s32>(
		(int)(s.Width * 0.15),
		(int)(s.Height * 0.2),
		(int)(s.Width * 0.85),
		(int)(s.Height * 0.75)
		));
	img->setImage(imgBack);
	img->setScaleImage(true);
	this->addCheckBox(irr::core::rect<irr::s32>(
		(int) (s.Width * 0.23), (int) (s.Height * 0.3),
		(int) (s.Width * 0.26), (int) (s.Height * 0.33)),
					    irr::core::rect<irr::s32>(
						    (int) (s.Width * 0.27),
						    (int) (s.Height * 0.3),
						    (int) (s.Width * 0.5),
						    (int) (s.Height * 0.35)
					    ), L"1 Player",
					    id_gui::CHECK_BOX_1_PLAYER,
			  boxList.player == id_gui::CHECK_BOX_1_PLAYER);

	this->addCheckBox(irr::core::rect<irr::s32>(
		(int) (s.Width * 0.23), (int) (s.Height * 0.4),
		(int) (s.Width * 0.26), (int) (s.Height * 0.43)),
					    irr::core::rect<irr::s32>(
						    (int) (s.Width * 0.27),
						    (int) (s.Height * 0.4),
						    (int) (s.Width * 0.5),
						    (int) (s.Height * 0.45)
					    ), L"2 Players",
					    id_gui::CHECK_BOX_2_PLAYER,
			  boxList.player == id_gui::CHECK_BOX_2_PLAYER);

	this->addCheckBox(irr::core::rect<irr::s32>(
		(int) (s.Width * 0.23), (int) (s.Height * 0.5),
		(int) (s.Width * 0.26), (int) (s.Height * 0.53)),
					    irr::core::rect<irr::s32>(
						    (int) (s.Width * 0.27),
						    (int) (s.Height * 0.5),
						    (int) (s.Width * 0.5),
						    (int) (s.Height * 0.55)
					    ), L"3 Players",
					    id_gui::CHECK_BOX_3_PLAYER,
			  boxList.player == id_gui::CHECK_BOX_3_PLAYER);

	this->addCheckBox(irr::core::rect<irr::s32>(
		(int) (s.Width * 0.23), (int) (s.Height * 0.6),
		(int) (s.Width * 0.26), (int) (s.Height * 0.63)),
					    irr::core::rect<irr::s32>(
						    (int) (s.Width * 0.27),
						    (int) (s.Height * 0.6),
						    (int) (s.Width * 0.5),
						    (int) (s.Height * 0.65)
					    ), L"4 Players",
					    id_gui::CHECK_BOX_4_PLAYER,
			  boxList.player == id_gui::CHECK_BOX_4_PLAYER);

	this->addCheckBox(irr::core::rect<irr::s32>(
		(int) (s.Width * 0.63), (int) (s.Height * 0.4),
		(int) (s.Width * 0.66), (int) (s.Height * 0.43)),
					  irr::core::rect<irr::s32>(
						  (int) (s.Width * 0.67),
						  (int) (s.Height * 0.4),
						  (int) (s.Width * 0.9),
						  (int) (s.Height * 0.45)
					  ), L"2 Teams",
					  id_gui::CHECK_BOX_2_TEAM,
			  boxList.team == id_gui::CHECK_BOX_2_TEAM);

	this->addCheckBox(irr::core::rect<irr::s32>(
		(int) (s.Width * 0.63), (int) (s.Height * 0.5),
		(int) (s.Width * 0.66), (int) (s.Height * 0.53)),
					  irr::core::rect<irr::s32>(
						  (int) (s.Width * 0.67),
						  (int) (s.Height * 0.5),
						  (int) (s.Width * 0.9),
						  (int) (s.Height * 0.55)
					  ), L"3 Teams",
					  id_gui::CHECK_BOX_3_TEAM,
			  boxList.team == id_gui::CHECK_BOX_3_TEAM);

	this->addCheckBox(irr::core::rect<irr::s32>(
		(int) (s.Width * 0.63), (int) (s.Height * 0.6),
		(int) (s.Width * 0.66), (int) (s.Height * 0.63)),
					  irr::core::rect<irr::s32>(
						  (int) (s.Width * 0.67),
						  (int) (s.Height * 0.6),
						  (int) (s.Width * 0.9),
						  (int) (s.Height * 0.65)
					  ), L"4 Teams",
					  id_gui::CHECK_BOX_4_TEAM,
			  boxList.team == id_gui::CHECK_BOX_4_TEAM);
}

void SMenuNewGame::boxGestion(int id)
{
	auto &boxList = ECS::MComponent<CCheckBoxs>::getAll().begin()->second;

	if (id >= id_gui::CHECK_BOX_2_TEAM && id <= id_gui::CHECK_BOX_4_TEAM) {
		if (id - id_gui::CHECK_BOX_2_TEAM + 1 >=
		    boxList.player - id_gui::CHECK_BOX_1_PLAYER)
			boxList.team = id;
		this->refresh();
	} else if (id >= id_gui::CHECK_BOX_1_PLAYER &&
		   id <= id_gui::CHECK_BOX_4_PLAYER) {
		if (id - id_gui::CHECK_BOX_1_PLAYER <=
		    boxList.team - id_gui::CHECK_BOX_2_TEAM + 1)
			boxList.player = id;
		this->refresh();
	}
}

void SMenuNewGame::startGestion()
{
	auto &boxList = ECS::MComponent<CCheckBoxs>::getAll().begin()->second;
	auto dev = ECS::MComponent<CIrrMain>::getAll().begin()->second.device;
	auto driv = ECS::MComponent<CIrrMain>::getAll().begin()->second.driver;
	//auto smgr = dev->getSceneManager();

	while (!ECS::MComponent<CGameStatus>::getAll().empty())
		ECS::MComponent<CGameStatus>::
		remove(ECS::MComponent<CGameStatus>::getAll().begin()->first);

	while (!ECS::MComponent<CMap>::getAll().empty())
		ECS::MComponent<CMap>::
		remove(ECS::MComponent<CMap>::getAll().begin()->first);

	while (!ECS::MComponent<CKeyMap>::getAll().empty())
		removePlayer(ECS::MComponent<CKeyMap>::getAll().begin()->first);

	while (!ECS::MComponent<CInventory>::getAll().empty())
		removeTeam(ECS::MComponent<CInventory>::getAll()
				   .begin()->first);

	while (!ECS::MComponent<CName>::getAll().empty())
		removeWorms(ECS::MComponent<CName>::getAll().begin()->first);

	while (!ECS::MComponent<CTurn>::getAll().empty())
		ECS::MComponent<CTurn>::
		        remove(ECS::MComponent<CTurn>::getAll().begin()->first);

	ECS::MComponent<CSceneNode>::getAll().begin()->second.mapNode->removeAll();
	ECS::MComponent<CSceneNode>::getAll().begin()->second.meshNode->removeAll();
	ECS::MComponent<CSceneNode>::getAll().begin()->second.munitionNode->removeAll();
	ECS::MComponent<CSceneNode>::getAll().begin()->second.weaponNode->removeAll();

	std::map<int, irr::scene::IMeshSceneNode*> m;
	irr::scene::ISceneManager* sceneManager =
		dev->getSceneManager();
	createMap(sceneManager, driv, m, 600);

	srand(std::time(nullptr));
	ECS::MComponent<CMap>::create(ECS::MEntity::create(), CMap(m, 600));
	ECS::MComponent<CGameStatus>::
	        create(ECS::MEntity::create(), CGameStatus());

	auto &timeList = ECS::MComponent<CTimeScd>::getAll();
	CTimeScd *timeGame = nullptr;

	for (auto it = timeList.begin(); it != timeList.end();
	     std::advance(it, 1))
		if (it->second.id == id_time::TIME_GAME)
			timeGame = &(it->second);
	if (!timeGame)
		ECS::MComponent<CTimeScd>::create(ECS::MEntity::create(),
						  CTimeScd(id_time::TIME_GAME));

	int i;

	for (i = id_gui::CHECK_BOX_1_PLAYER; i <= boxList.player; i++)
		createPlayer();
	for (i -= id_gui::CHECK_BOX_1_PLAYER;
		i <= boxList.team - id_gui::CHECK_BOX_2_TEAM + 1; i++)
		createTeam();

	ECS::MComponent<CTurn>::create(ECS::MEntity::create(), CTurn());
	ECS::MEvent<ECloseScene, int>::push(id_scene::SCENE_MENU_NEW_GAME);
	ECS::MEvent<EStartScene, int>::push(id_scene::SCENE_GAME);
}
