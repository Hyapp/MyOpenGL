#pragma once
#include"Game.h"


namespace AllControl
{
	enum class SightIndex
	{
		allSight,
		sight0, sight1, sight2, sight3, sight4, sight5, sight6
	};

	class Sight 
	{
	public:
		Sight(const std::string & Path);

		bool InitSign();
		bool LoadGame(unsigned int pathIndex, unsigned int gameIndex);

		void Loop();
		void GetKeyProcess();
		std::unique_ptr<MyOpenGL::_CreateWindow> window;
	private:


		std::unique_ptr<Game0::Game> currentGame;	bool currentGameAvailable;
		std::unique_ptr<Game0::Game> allGame;		bool allGameAvailable;
		std::unique_ptr<Game0::Game> nextGame;		bool nextGameAvailable;
		std::unique_ptr<Game0::Game> lastGame;		bool lastGameAvailable;

		std::vector<std::string> gamePaths;

		MyCamera::_Camera camera;

		bool Available = true;
		bool currentChanged;
	};
}