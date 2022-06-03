#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

using namespace std;
using namespace sf;

class Fish {
protected:
	float x, y, dx, dy, Rs1, Rs2, w, h, Ls1, Ls2, tempx, tempy, speed;
	String File;
	Sprite sprite;
	Image image;
	Texture texture;
	Vector2i RightOrigin, LeftOrigin;
	int dir, FishNumber;
	Clock clock;
public:
	Fish(string F, float x, float y, float Rs1, float Rs2, float w, float h); //  онструктор, определ€ютс€ размеры спрайтов, координаты, направление. скорость и т.д.
	void BreathUp(); // ¬сплытие вверх за кислородом.
	void BreathDown(); // ¬озвращение на траекторию после всплыти€ за кислородом.
	void EatingUp();
	void EatingDown();
	void Checking();
	void Update(); // ќтвечает за посто€нное движение рыб по траектории и смену направлени€.
	int GetFishNumber();
	float GetX();
	void SetX(float x);
	float GetY();
	void SetY(float y);
	float GetTempX();
	float GetTempY();
	Sprite GetSprite();
	int GetDir();
	Clock& SetClock();
};

class User {
protected :
	Texture menu;
	Sprite menus;
	Texture food;
	Sprite foods;
	Texture info;
	Sprite infos;
	bool desision;
	int c, feed;
	bool GF, BF, DF, CF;
	Event UserEvent;
	vector <Fish*> fish;
public :
	void ToFeed(RenderWindow& window, Sprite& herosprite);
	void ToCreate(RenderWindow& window);
	void ToDelete(RenderWindow& window);
	void GetInfo(RenderWindow& window);
	void Show(RenderWindow& window, Sprite& herosprite);
	Event& GetUserEvent();
	vector <Fish*>& GetFish();
	User();
	~User();
};

class GoldenFish : public Fish {
private :

public:
	GoldenFish();
};

class CatFish : public Fish {
public:
	CatFish();
};

class BettaFish : public Fish {
public:
	BettaFish();
};

class DanioFish : public Fish {
public:
	DanioFish();
};
