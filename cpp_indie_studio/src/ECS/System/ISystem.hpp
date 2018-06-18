/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** ISystem.hpp
*/


#ifndef INDIESTUDIO_ISYSTEM_HPP
#define INDIESTUDIO_ISYSTEM_HPP

namespace ECS {

	typedef float DeltaTime;

	class SourceSystem {
	public:
		virtual bool isStart() = 0;

		virtual void init() = 0;

		virtual void preUpdate(DeltaTime delta) = 0;
		virtual void update(DeltaTime delta) = 0;
		virtual void postUpdate(DeltaTime delta) = 0;

		virtual void handleEvents() = 0;

	private:
	};

	template<class T>
	class ISystem : public SourceSystem {
	public:
		virtual ~ISystem() = default;

		ISystem(const ISystem &) = delete;
		ISystem &operator=(const ISystem &) = delete;

		static ISystem &getInstance()
		{
			static T instance;
			return instance;
		};

		bool isStart() override
		{
			return enable;
		};

		static void start()
		{
			getInstance().enable = true;
		};

		static void stop()
		{
			getInstance().enable = false;
		};

		void init() override
		{};

		void preUpdate(DeltaTime delta) override
		{ (void) delta; };

		void update(DeltaTime delta) override
		{ (void) delta; };

		void postUpdate(DeltaTime delta) override
		{ (void) delta; };

		void handleEvents() override
		{};

	protected:
		ISystem() = default;

		bool enable{false};
	};

}

#endif /* INDIESTUDIO_ISYSTEM_HPP */
