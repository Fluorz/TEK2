/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** SRenderMenuSave.hpp
*/


#ifndef INDIESTUDIO_SRENDERMENUSAVE_HPP
#define INDIESTUDIO_SRENDERMENUSAVE_HPP

#include "ECS/System/MSystem.hpp"
#include "ECS/Component/MComponent.hpp"
#include "ECS/Event/MEvent.hpp"
#include "Component/Irrlicht/irrlichtComponent.hpp"
#include "Events/EScene.hpp"
#include "Component/Id.hpp"
#include "tool/FontTool.hpp"

class SRenderMenuSave : public ECS::ISystem<SRenderMenuSave> {
public:
	void preUpdate(ECS::DeltaTime delta) override;
	void update(ECS::DeltaTime delta) override;
	void postUpdate(ECS::DeltaTime delta) override;
};

#endif //INDIESTUDIO_SRENDERMENUSAVE_HPP
