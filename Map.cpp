
#include"Game.h"
#include"Map.h"

Map::Map(const LoaderParams* pParams)
	:SDLGameObject(pParams)
{
}

Map::~Map()
{
}

void Map::draw() {
	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			SDL_Rect tempRect = { 10 * j,10 * i + 300,10,10 };
			if (maps[i][j] == 1) {
				SDL_SetRenderDrawColor(Game::Instance()->getRenderer(), 255, 0, 0, 255);
				SDL_RenderFillRect(Game::Instance()->getRenderer(), &tempRect);
			}
		}
	}
}