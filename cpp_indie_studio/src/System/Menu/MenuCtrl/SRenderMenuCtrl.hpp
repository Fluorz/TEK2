/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** SRenderMenuCtrl.hpp
*/


#ifndef INDIESTUDIO_SRENDERMENUCTRL_HPP
#define INDIESTUDIO_SRENDERMENUCTRL_HPP

#include "ECS/System/MSystem.hpp"
#include "ECS/Component/MComponent.hpp"
#include "ECS/Event/MEvent.hpp"
#include "Component/Irrlicht/irrlichtComponent.hpp"
#include "Events/EScene.hpp"
#include "Component/Id.hpp"
#include "tool/FontTool.hpp"

class SRenderMenuCtrl : public ECS::ISystem<SRenderMenuCtrl> {
public:
	void preUpdate(ECS::DeltaTime delta) override;
	void update(ECS::DeltaTime delta) override;
	void postUpdate(ECS::DeltaTime delta) override;
};

#endif //INDIESTUDIO_SRENDERMENUCTRL_HPP
