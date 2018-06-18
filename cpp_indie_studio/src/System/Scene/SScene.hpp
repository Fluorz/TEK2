/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** SScene.hpp
*/


#ifndef INDIESTUDIO_SSCENE_HPP
#define INDIESTUDIO_SSCENE_HPP

#include "ECS/System/MSystem.hpp"
#include "ECS/Component/MComponent.hpp"
#include "ECS/Event/MEvent.hpp"
#include "Component/Id.hpp"

#include "System/Menu/SRenderMenu.hpp"
#include "System/Menu/SMenu.hpp"
#include "System/Menu/MenuNewGame/SRenderMenuNewGame.hpp"
#include "System/Menu/MenuNewGame/SMenuNewGame.hpp"
#include "System/Menu/MenuCtrl/SRenderMenuCtrl.hpp"
#include "System/Menu/MenuCtrl/SMenuCtrl.hpp"
#include "System/Menu/MenuSave/SRenderMenuSave.hpp"
#include "System/Menu/MenuSave/SMenuSave.hpp"
#include "System/Game/SRenderGame.hpp"
#include "System/Game/SGame.hpp"
#include "System/Game/SPosition/SPosition.hpp"
#include "System/Game/Rotation/SRotation.hpp"
#include "System/Menu/MenuLoading/SMenuLoadingRender.hpp"
#include "Events/EScene.hpp"

class SScene : public ECS::ISystem<SScene> {
public:
	void handleEvents() override;
};


#endif /* INDIESTUDIO_SSCENE_HPP */
