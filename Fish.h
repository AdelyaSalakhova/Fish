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
	int dir, FishNumber, c, feed;
	Clock clock;
public:
	Fish(string F, float x, float y, float Rs1, float Rs2, float w, float h); 
	void BreathUp(); 
    void BreathDown(); 
	void EatingUp();
	void EatingDown();
	void Checking();
	virtual void Update() = 0; 
	virtual bool Breath() = 0;
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
protected:
	Texture menu, food, info;
	Sprite menus, foods, infos;
	int c, feed;
	bool GF, BF, DF, CF, desision;
	Event UserEvent;
	vector <Fish*> fish;
public:
	void ToFeed(RenderWindow& window, Sprite& herosprite);
	void ToCreate(RenderWindow& window);
	void ToDelete(RenderWindow& window);
	void GetInfo(RenderWindow& window);
	void Show(RenderWindow& window, Sprite& herosprite);
	void Draw(RenderWindow& window, Sprite& herosprite);
	void Up(int i, RenderWindow& window, Sprite& herosprite);
	void Down(int i, RenderWindow& window, Sprite& herosprite);
	Event& GetUserEvent();
	vector <Fish*>& GetFish();
	User();
	~User();
};

class GoldenFish : public Fish {
public:
	GoldenFish();
	void Update() override;
	bool Breath() override;
};

class CatFish : public Fish {
private :
	bool rep;
public:
	CatFish();
	void Update() override;
	bool Breath() override;
};

class BettaFish : public Fish {
public:
	BettaFish();
	void Update() override;
	bool Breath() override;
};

class DanioFish : public Fish {
private :
	float counter;
public:
	DanioFish();
	void Update() override;
	bool Breath() override;
};
