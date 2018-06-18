/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** SMenuLoadingRender.cpp
*/


#include "SMenuLoadingRender.hpp"

void SMenuLoadingRender::init()
{
	int loading_switch = 10000;
	int loading_quit = 600000;
#ifdef _WIN32
	loading_switch /= 10;
	loading_quit = 10000;
#endif // _WIN32

	ECS::MComponent<CTime>::create(ECS::MEntity::create(),
				       CTime(id_time::TIME_LOADING_QUIT,
					     clock(),
					     clock() + loading_quit));
	ECS::MComponent<CTime>::create(ECS::MEntity::create(),
				       CTime(id_time::TIME_LOADING_SWITCH,
					     clock(),
					     clock() + loading_switch));
	ECS::MComponent<CLoading>::create(ECS::MEntity::create(), CLoading());
	ECS::MComponent<CImageTexture>
	::create(ECS::MEntity::create(),
		 CImageTexture("./media/loading1-1.png",
			       "loading1"));
	ECS::MComponent<CImageTexture>
	::create(ECS::MEntity::create(),
		 CImageTexture("./media/loading1-2.png",
			       "loading2"));
}

void SMenuLoadingRender::update(ECS::DeltaTime delta)
{
	auto driv = ECS::MComponent<CIrrMain>::getAll().begin()->second.driver;
	auto env = ECS::MComponent<CIrrMain>::getAll().begin()->second.env;
	auto &timeList = ECS::MComponent<CTime>::getAll();
	auto &loading = ECS::MComponent<CLoading>::getAll().begin()->second;
	const irr::core::dimension2du &s = driv->getScreenSize();
	int toAddWaiting = 10000;
#ifdef _WIN32
	toAddWaiting /= 10;
#endif // _WIN32


	CTime *timeS = nullptr;
	CTime *timeQ = nullptr;

	for (auto it = timeList.begin(); it != timeList.end();
	     std::advance(it, 1)) {
		if (it->second.id == id_time::TIME_LOADING_SWITCH)
			timeS = &(it->second);
		if (it->second.id == id_time::TIME_LOADING_QUIT)
			timeQ = &(it->second);
	}
	if (!timeQ || !timeS)
		return;
	if (timeQ->waiting < clock()) {
		ECS::MEvent<ECloseScene, int>::push(id_scene::SCENE_LOADING);
		ECS::MEvent<EStartScene, int>::push(id_scene::SCENE_MENU);
	}
	if (timeS->waiting < clock()) {
		loading.img = !loading.img;
		timeS->waiting = clock() + toAddWaiting;
	}

	driv->beginScene(true, true, irr::video::SColor(255, 255, 240, 255));
	auto textureList = ECS::MComponent<CImageTexture>::getAll();
	irr::video::ITexture *imgload = nullptr;
	irr::video::ITexture *imgTitle = nullptr;

	for (auto it = textureList.begin();
	     it != textureList.end();
	     std::advance(it, 1)) {
		if (it->second.id ==
		    (loading.img ? "loading1" : "loading2"))
			imgload = it->second.img;
		if (it->second.id == "menuTile")
			imgTitle = it->second.img;
	}
	if (imgload) {
		irr::core::dimension2d<irr::u32> imgS = imgload->getSize();
		driv->draw2DImage(imgload, irr::core::rect<irr::s32>(
			(int) (s.Width * 0.35), (int) (s.Height * 0.1),
			(int) (s.Width * 1), (int) (s.Height * 0.8)),
				  irr::core::rect<irr::s32>(0, 0, imgS.Width,
							    imgS.Height), 0, 0,
				  true);
	}
	if (imgTitle) {
		irr::core::dimension2d<irr::u32> imgS = imgTitle->getSize();
		driv->draw2DImage(imgTitle, irr::core::rect<irr::s32>(
			(int) (s.Width * 0.2), (int) (s.Height * 0.08),
			(int) (s.Width * 0.8), (int) (s.Height * 0.08 +
						      ((float) imgS.Height /
						       (float) imgS.Width *
						       (float) s.Width * 0.6))),
				  irr::core::rect<irr::s32>(0, 0, imgS.Width,
							    imgS.Height), 0, 0,
				  true);
	}
	env->drawAll();
	driv->endScene();
	timeS->last = clock();
	timeQ->last = clock();
}
