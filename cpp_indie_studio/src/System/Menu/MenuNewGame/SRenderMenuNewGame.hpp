/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** SRenderMenuNewGame.hpp
*/


#ifndef INDIESTUDIO_SRENDERMENUNEWGAME_HPP
#define INDIESTUDIO_SRENDERMENUNEWGAME_HPP

#include "ECS/System/MSystem.hpp"
#include "ECS/Component/MComponent.hpp"
#include "ECS/Event/MEvent.hpp"
#include "Component/Irrlicht/irrlichtComponent.hpp"
#include "Events/EScene.hpp"
#include "Component/Id.hpp"
#include "tool/FontTool.hpp"

class SRenderMenuNewGame : public ECS::ISystem<SRenderMenuNewGame> {
public:
	void preUpdate(ECS::DeltaTime delta) override;
	void update(ECS::DeltaTime delta) override;
	void postUpdate(ECS::DeltaTime delta) override;
};

#endif //INDIESTUDIO_SRENDERMENUNEWGAME_HPP
