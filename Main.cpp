#include "Fish.h"

void main(int argc, char** argv[]) {

	RenderWindow window(sf::VideoMode(900, 560), "FishTank");

	Texture herotexture1;
	herotexture1.loadFromFile("phon.png");
	Sprite herosprite;
	herosprite.setTexture(herotexture1);
	herosprite.setPosition(0, 0);

	User game;

	window.clear();
	window.draw(herosprite);
	window.display();

	while (window.isOpen())
	{
		if (window.pollEvent(game.GetUserEvent()))
		{
			if (game.GetUserEvent().type == Event::Closed)
				window.close();
			else if (game.GetUserEvent().mouseButton.button == Mouse::Left) {
				if ((game.GetUserEvent().mouseButton.y <= 109) && (game.GetUserEvent().mouseButton.y >= 2) && (game.GetUserEvent().mouseButton.x >= 802) && (game.GetUserEvent().mouseButton.x <= 897)) {
					if (game.GetFish().size() < 4) {
						game.ToCreate(window);
					}
				}
				else if ((game.GetUserEvent().mouseButton.y <= 251) && (game.GetUserEvent().mouseButton.y >= 144) && (game.GetUserEvent().mouseButton.x >= 802) && (game.GetUserEvent().mouseButton.x <= 897)) {
					if (game.GetFish().size() >= 1) {
						game.ToDelete(window);
					}
				}
				else if ((game.GetUserEvent().mouseButton.y <= 394) && (game.GetUserEvent().mouseButton.y >= 287) && (game.GetUserEvent().mouseButton.x >= 802) && (game.GetUserEvent().mouseButton.x <= 897)) {
					if (game.GetFish().size() >= 1) {
						game.ToFeed(window, herosprite);
					}
				}
				else if ((game.GetUserEvent().mouseButton.y <= 537) && (game.GetUserEvent().mouseButton.y >= 430) && (game.GetUserEvent().mouseButton.x >= 802) && (game.GetUserEvent().mouseButton.x <= 897)) {
					game.GetInfo(window);
				}
			}
		}
		game.Show(window, herosprite);
	}
}