#include "Fish.h"

Fish::Fish(string F, float x, float y, float Rs1, float Rs2, float w, float h) {
	dx = 0; dy = 0; dir = 0;
	File = F;
	image.loadFromFile(File);
	texture.loadFromImage(image);
	sprite.setTexture(texture);
	this->x = x; this->y = y;
	tempx = x; tempy = y;
	this->w = w; this->h = h;
	this->Rs1 = Rs1; this->Rs2 = Rs2;
	sprite.setTextureRect(IntRect(Rs1, Rs2, w, h));
}

GoldenFish::GoldenFish() : Fish("GoldenFish.png", 100, 150, 0, 2, 53, 38) {
	FishNumber = 3;
	this->Ls1 = 0; this->Ls2 = 50;
	RightOrigin = { 53, 18 };
	LeftOrigin = { 0, 18 };
	this->speed = 0.1;
	this->sprite.setOrigin(RightOrigin.x, RightOrigin.y);
	this->sprite.setPosition(x, y);
	clock.restart();
}

CatFish::CatFish() : Fish("catfish.png", 262, 250, 0, 94, 99, 36) {
	FishNumber = 2;
	this->Ls1 = 0; this->Ls2 = 51;
	RightOrigin = { 99, 20 };
	LeftOrigin = { 0, 20 };
	this->speed = 0.09;
	this->sprite.setOrigin(RightOrigin.x, RightOrigin.y);
	this->sprite.setPosition(x, y);
	clock.restart();
	rep = 0;
}

BettaFish::BettaFish() : Fish("bettafish.png", 100, 300, 12, 22, 76, 52) {
	FishNumber = 1;
	this->Ls1 = 12; this->Ls2 = 80;
	RightOrigin = { 76, 14 };
	LeftOrigin = { 0, 13 };
	this->speed = 0.1;
	this->sprite.setOrigin(RightOrigin.x, RightOrigin.y);
	this->sprite.setPosition(x, y);
	clock.restart();
}

DanioFish::DanioFish() : Fish("danio.png", 100, 200, 20, 15, 79, 17) {
	FishNumber = 4;
	this->Ls1 = 0; this->Ls2 = 63;
	RightOrigin = { 79, 0 };
	LeftOrigin = { 0, 0 };
	this->speed = 0.1;
	counter = 0.1;
	this->sprite.setOrigin(RightOrigin.x, RightOrigin.y);
	this->sprite.setPosition(x, y);
	clock.restart();
}

void Fish::Checking() {
	if ((dir == 0) && (x + 80 >= 784)) {
		dir = 1;
		this->sprite.setTextureRect(IntRect(this->Ls1, this->Ls2, this->w, this->h));
		x = x - w; tempx = x;
		sprite.setOrigin(this->LeftOrigin.x, this->LeftOrigin.y);
	}
	else if ((dir == 1) && ((x - 80) <= 15)) {
		dir = 0;
		this->sprite.setTextureRect(IntRect(this->Rs1, this->Rs2, this->w, this->h));
		x = x + w; tempx = x;
		sprite.setOrigin(this->RightOrigin.x, this->RightOrigin.y);
	}
}

void Fish::BreathUp() {
	float distance;
	if (this->dir == 0) {
		distance = sqrt(((40 + x) - tempx) * ((40 + x) - tempx) + (tempy - 104) * (tempy - 104));
		this->tempx += 0.05 * ((40 + x) - tempx) / distance;
		this->tempy -= 0.05 * ((this->tempy) - 104) / distance;
		sprite.setPosition(tempx, tempy);
	}
	else {
		distance = sqrt(((tempx)-(x - 40)) * ((tempx)-(x - 40)) + (tempy - 104) * (tempy - 104));
		this->tempx -= 0.05 * ((tempx)-(x - 40)) / distance;
		this->tempy -= 0.05 * ((this->tempy) - 104) / distance;
		sprite.setPosition(tempx, tempy);
	}
}

void Fish::BreathDown() {
	float distance;
	if (this->dir == 0) {
		distance = sqrt(((80 + x) - tempx) * ((80 + x) - tempx) + (y - tempy) * (y - tempy));
		this->tempx += 0.05 * ((80 + x) - tempx) / distance;
		this->tempy += 0.05 * (y - tempy) / distance;
		sprite.setPosition(tempx, tempy);
	}
	else {
		distance = sqrt((tempx - (x - 80)) * (tempx - (x - 80)) + (y - tempy) * (y - tempy));
		this->tempx -= 0.05 * (tempx - (x - 80)) / distance;
		this->tempy += 0.05 * (y - tempy) / distance;
		sprite.setPosition(tempx, tempy);
	}
}

void Fish::EatingUp() {
	float distance;
	if (dir == 0) { // âïðàâî
		distance = sqrt(((40 + x) - tempx) * ((40 + x) - tempx) + (tempy - 120) * (tempy - 120));
		this->tempx += 0.05 * ((40 + x) - tempx) / distance;
		this->tempy -= 0.05 * ((this->tempy) - 120) / distance;
		sprite.setPosition(tempx, tempy);
	}
	else if (dir == 1) { // âëåâî
		distance = sqrt(((tempx)-(x - 40)) * ((tempx)-(x - 40)) + (tempy - 120) * (tempy - 120));
		this->tempx -= 0.05 * ((tempx)-(x - 40)) / distance;
		this->tempy -= 0.05 * ((this->tempy) - 120) / distance;
		sprite.setPosition(tempx, tempy);
	}
}

void Fish::EatingDown() {
	float distance;
	if (dir == 0) { // âïðàâî
		distance = sqrt(((80 + x) - tempx) * ((80 + x) - tempx) + (y - tempy) * (y - tempy));
		this->tempx += 0.05 * ((80 + x) - tempx) / distance;
		this->tempy += 0.05 * (y - tempy) / distance;
		sprite.setPosition(tempx, tempy);
	}
	else if (dir == 1) { // âëåâî
		distance = sqrt((tempx - (x - 80)) * (tempx - (x - 80)) + (y - tempy) * (y - tempy));
		this->tempx -= 0.05 * (tempx - (x - 80)) / distance;
		this->tempy += 0.05 * (y - tempy) / distance;
		sprite.setPosition(tempx, tempy);
	}
}

int Fish::GetFishNumber() {
	return FishNumber;
}

Clock& Fish::SetClock() {
	return this->clock;
}

float Fish::GetX() {
	return x;
}

void Fish::SetX(float x) {
	this->x = x;
}

void Fish::SetY(float y) {
	this->y = y;
}

float Fish::GetY() {
	return y;
}

float Fish::GetTempX() {
	return tempx;
};

float Fish::GetTempY() {
	return tempy;
};

Sprite Fish::GetSprite() {
	return sprite;
}

int Fish::GetDir() {
	return dir;
}

User::User() {
	menu.loadFromFile("createmenu.png");
	menus.setTexture(menu);
	desision = 0;
	food.loadFromFile("food.png");
	foods.setTexture(food);
	foods.setOrigin(4, 5);
	c = 0;
	feed = 1;
	GF = BF = DF = CF = 1;
}

void User::ToCreate(RenderWindow& window) {
	desision = 0;
	while (desision == 0) {
		window.draw(menus);
		window.display();
		while (window.pollEvent(UserEvent)) {
			if (UserEvent.mouseButton.button == sf::Mouse::Left) {
				if ((UserEvent.mouseButton.y <= 367) && (UserEvent.mouseButton.y >= 190) && (UserEvent.mouseButton.x >= 174) && (UserEvent.mouseButton.x <= 307)) {
					if (BF) {
						fish.push_back((Fish*)new BettaFish);
					}
					BF = 0;
					desision = 1;
				}
				else if ((UserEvent.mouseButton.y <= 367) && (UserEvent.mouseButton.y >= 190) && (UserEvent.mouseButton.x >= 312) && (UserEvent.mouseButton.x <= 447)) {
					if (CF) {
						fish.push_back((Fish*)new CatFish);
					}
					CF = 0;
					desision = 1;
				}
				else if ((UserEvent.mouseButton.y <= 367) && (UserEvent.mouseButton.y >= 190) && (UserEvent.mouseButton.x >= 452) && (UserEvent.mouseButton.x <= 587)) {
					if (GF) {
						fish.push_back((Fish*)new GoldenFish);
					}
					GF = 0;
					desision = 1;
				}
				else if ((UserEvent.mouseButton.y <= 367) && (UserEvent.mouseButton.y >= 190) && (UserEvent.mouseButton.x >= 592) && (UserEvent.mouseButton.x <= 725)) {
					if (DF) {
						fish.push_back((Fish*)new DanioFish);
					}
					DF = 0;
					desision = 1;
				}
			}
		}
	}
}

void User::ToDelete(RenderWindow& window) {
	desision = 0;
	while (desision == 0) {
		window.draw(menus);
		window.display();
		while (window.pollEvent(UserEvent)) {
			if (UserEvent.mouseButton.button == sf::Mouse::Left) {
				if ((UserEvent.mouseButton.y <= 367) && (UserEvent.mouseButton.y >= 190) && (UserEvent.mouseButton.x >= 174) && (UserEvent.mouseButton.x <= 307)) {
					for (int i = 0; i < fish.size(); i++) {
						if (fish[i]->GetFishNumber() == 1) {
							delete fish[i];
							fish.erase(fish.begin() + i);
							BF = 1;
						}
					}
					desision = 1;
				}
				else if ((UserEvent.mouseButton.y <= 367) && (UserEvent.mouseButton.y >= 190) && (UserEvent.mouseButton.x >= 312) && (UserEvent.mouseButton.x <= 447)) {
					for (int i = 0; i < fish.size(); i++) {
						if (fish[i]->GetFishNumber() == 2) {
							delete fish[i];
							fish.erase(fish.begin() + i);
							CF = 1;
						}
					}
					desision = 1;
				}
				else if ((UserEvent.mouseButton.y <= 367) && (UserEvent.mouseButton.y >= 190) && (UserEvent.mouseButton.x >= 452) && (UserEvent.mouseButton.x <= 587)) {
					for (int i = 0; i < fish.size(); i++) {
						if (fish[i]->GetFishNumber() == 3) {
							delete fish[i];
							fish.erase(fish.begin() + i);
							GF = 1;
						}
					}
					desision = 1;
				}
				else if ((UserEvent.mouseButton.y <= 367) && (UserEvent.mouseButton.y >= 190) && (UserEvent.mouseButton.x >= 592) && (UserEvent.mouseButton.x <= 725)) {
					for (int i = 0; i < fish.size(); i++) {
						if (fish[i]->GetFishNumber() == 4) {
							delete fish[i];
							fish.erase(fish.begin() + i);
							DF = 1;
						}
					}
					desision = 1;
				}
			}
		}
	}
}

void User::ToFeed(RenderWindow& window, Sprite& herosprite) {
	feed++;
	if (feed % 2 == 1) {
		int m;
		c++;
		if (c > fish.size()) c = 1;
		for (m = 0; m < fish.size(); m++) {
			if (m != (c - 1))  {
				fish[m]->Update();
					if (fish[m]->Breath()) {
						Up(m, window, herosprite);
						Down(m, window, herosprite);
						fish[m]->SetX(fish[m]->GetTempX());
						fish[m]->SetY(fish[m]->GetTempY());
						fish[m]->SetClock().restart();
					}
				
				Draw(window, herosprite);
			}
			else {
				fish[m]->Checking();
				if (fish[m]->GetDir() == 0) {
					foods.setPosition(fish[m]->GetX(), 120);
				}
				else {
					foods.setPosition(fish[m]->GetX() - 40, 120);
				}
				while (fish[m]->GetTempY() > 120) {
					fish[m]->EatingUp();
					for (int k = 0; k < fish.size(); k++) {
						if (k != m)  fish[k]->Update();
					}
					window.clear();
					window.draw(herosprite);
					window.draw(foods);
					for (int j = 0; j < fish.size(); j++) {
						window.draw(fish[j]->GetSprite());
					}
					window.display();
				}
				Down(m, window, herosprite);
				fish[m]->SetX(fish[m]->GetTempX());
				fish[m]->SetY(fish[m]->GetTempY());
				fish[m]->SetClock().restart();
			}
		}
	}
}

void User::GetInfo(RenderWindow& window) {
	desision = 0;
	while (desision == 0) {
		window.draw(menus);
		window.display();
		while (window.pollEvent(UserEvent)) {
			if (UserEvent.mouseButton.button == sf::Mouse::Left) {
				if ((UserEvent.mouseButton.y <= 367) && (UserEvent.mouseButton.y >= 190) && (UserEvent.mouseButton.x >= 174) && (UserEvent.mouseButton.x <= 307)) {
					Clock BF;
					while (BF.getElapsedTime().asSeconds() < 5) {
						info.loadFromFile("AboutBF.png");
						infos.setTexture(info);
						window.draw(infos);
						window.display();
					}
					desision = 1;
				}
				else if ((UserEvent.mouseButton.y <= 367) && (UserEvent.mouseButton.y >= 190) && (UserEvent.mouseButton.x >= 312) && (UserEvent.mouseButton.x <= 447)) {
					Clock CF;
					while (CF.getElapsedTime().asSeconds() < 5) {
						info.loadFromFile("AboutCF.png");
						infos.setTexture(info);
						window.draw(infos);
						window.display();
					}
					desision = 1;
				}
				else if ((UserEvent.mouseButton.y <= 367) && (UserEvent.mouseButton.y >= 190) && (UserEvent.mouseButton.x >= 452) && (UserEvent.mouseButton.x <= 587)) {
					Clock GF;
					while (GF.getElapsedTime().asSeconds() < 5) {
						info.loadFromFile("AboutGF.png");
						infos.setTexture(info);
						window.draw(infos);
						window.display();
					}
					desision = 1;
				}
				else if ((UserEvent.mouseButton.y <= 367) && (UserEvent.mouseButton.y >= 190) && (UserEvent.mouseButton.x >= 592) && (UserEvent.mouseButton.x <= 725)) {
					Clock DF;
					while (DF.getElapsedTime().asSeconds() < 5) {
						info.loadFromFile("AboutDF.png");
						infos.setTexture(info);
						window.draw(infos);
						window.display();
					}
					desision = 1;
				}
			}
		}
	}
}

void User::Up(int i, RenderWindow& window, Sprite& herosprite) {
	fish[i]->Checking();
	while (fish[i]->GetTempY() > 105) {
		fish[i]->BreathUp();
		for (int k = 0; k < fish.size(); k++) {
			if (k != i)  fish[k]->Update();
		}
		Draw(window, herosprite);
	}
}

void User::Down(int i, RenderWindow& window, Sprite& herosprite) {
	while (fish[i]->GetTempY() < fish[i]->GetY()) {
		fish[i]->BreathDown();
		for (int k = 0; k < fish.size(); k++) {
			if (k != i)  fish[k]->Update();
		}
		Draw(window, herosprite);
	}
}

void User::Show(RenderWindow& window, Sprite& herosprite) {
	for (int i = 0; i < fish.size(); i++) {
		fish[i]->Update();
		if (fish[i]->Breath()) {
				Up(i, window, herosprite);
				Down(i, window, herosprite);
				fish[i]->SetX(fish[i]->GetTempX());
				fish[i]->SetY(fish[i]->GetTempY());
				fish[i]->SetClock().restart();
		}
	}
	Draw(window, herosprite);
}

void User::Draw(RenderWindow& window, Sprite& herosprite) {
	window.clear();
	window.draw(herosprite);
	for (int j = 0; j < fish.size(); j++) {
		window.draw(fish[j]->GetSprite());
	}
	window.display();
}

Event& User::GetUserEvent() {
	return UserEvent;
}

vector <Fish*>& User::GetFish() {
	return fish;
};

User::~User() {
	for (int i = 0; i < fish.size(); i++) {
		delete fish[i];
	}
}

void GoldenFish::Update() {
	if (x + dx >= 783) {
		dir = 1;
		this->sprite.setTextureRect(IntRect(this->Ls1, this->Ls2, this->w, this->h));
		sprite.setOrigin(this->LeftOrigin.x, this->LeftOrigin.y);
		x = x - w; tempx = x;
	}
	if (x - dx <= 16) {
		dir = 0;
		this->sprite.setTextureRect(IntRect(this->Rs1, this->Rs2, this->w, this->h));
		sprite.setOrigin(this->RightOrigin.x, this->RightOrigin.y);
		x = x + w; tempx = x;
	}
	switch (dir) {
	case 0: dx = speed; dy = 0; break;
	case 1: dx = -speed; dy = 0; break;
	}
	x += dx * 0.5;
	tempx = x;
	sprite.setPosition(x, y);
}

void CatFish::Update() {
	if (rep == 0) {
		if  (x + dx >= 522) {
			dir = 1;
			this->sprite.setTextureRect(IntRect(this->Ls1, this->Ls2, this->w, this->h));
			sprite.setOrigin(this->LeftOrigin.x, this->LeftOrigin.y);
			x = x - w; tempx = x;
		}
		else if  (x - dx <= 260) {
			dir = 0;
			this->sprite.setTextureRect(IntRect(this->Rs1, this->Rs2, this->w, this->h));
			sprite.setOrigin(this->RightOrigin.x, this->RightOrigin.y);
			x = x + w; tempx = x;
			rep = 1;
		}
	}
	else if (rep == 1) {
		if  (x + dx >= 785) {
		    dir = 1;
			this->sprite.setTextureRect(IntRect(this->Ls1, this->Ls2, this->w, this->h));
			sprite.setOrigin(this->LeftOrigin.x, this->LeftOrigin.y);
			x = x - w; tempx = x;
		}
		else if  (x - dx <= 16) {
			dir = 0;
			this->sprite.setTextureRect(IntRect(this->Rs1, this->Rs2, this->w, this->h));
			sprite.setOrigin(this->RightOrigin.x, this->RightOrigin.y);
			x = x + w; tempx = x;
		}
	}
	switch (dir) {
	case 0: dx = speed; dy = 0; break;
	case 1: dx = -speed; dy = 0; break;
	}
	x += dx * 0.5;
	tempx = x;
	sprite.setPosition(x, y);
}

void BettaFish::Update() {
	if (x + dx >= 783) {
		dir = 1;
		this->sprite.setTextureRect(IntRect(this->Ls1, this->Ls2, this->w, this->h));
		sprite.setOrigin(this->LeftOrigin.x, this->LeftOrigin.y);
		x = x - w; tempx = x;
		speed = speed - 0.01;
	}
	if (x - dx <= 16) {
		dir = 0;
		this->sprite.setTextureRect(IntRect(this->Rs1, this->Rs2, this->w, this->h));
		sprite.setOrigin(this->RightOrigin.x, this->RightOrigin.y);
		x = x + w; tempx = x;
		speed = speed - 0.01;
	}
	if (speed <= 0) speed = 0.1;
	switch (dir) {
	case 0: dx = speed; dy = 0; break;
	case 1: dx = -speed; dy = 0; break;
	}
	x += dx * 0.5;
	tempx = x;
	sprite.setPosition(x, y);
}

void DanioFish::Update() {
	if (x + dx >= 785) {
		dir = 1;
		this->sprite.setTextureRect(IntRect(this->Ls1, this->Ls2, this->w, this->h));
		sprite.setOrigin(this->LeftOrigin.x, this->LeftOrigin.y);
		x = x - w; tempx = x;
	}
	if (x - dx <= 16) {
		dir = 0;
		this->sprite.setTextureRect(IntRect(this->Rs1, this->Rs2, this->w, this->h));
		sprite.setOrigin(this->RightOrigin.x, this->RightOrigin.y);
		x = x + w; tempx = x;
	}
	if (speed < 0.4) {
		speed = speed * 1.0001;
	}
	switch (dir) {
	case 0: dx = speed; dy = 0; break;
	case 1: dx = -speed; dy = 0; break;
	}
	x += dx * 0.5;
	tempx = x;
	sprite.setPosition(x, y);
}

bool  GoldenFish::Breath() {
	float time;
	time = this->clock.getElapsedTime().asSeconds();
	if (time > 10) return 1;
	else return 0;
}

bool CatFish ::Breath() {
	float time;
	time = this->clock.getElapsedTime().asSeconds();
	if (time > 15) return 1;
	else return 0;
}

bool  BettaFish::Breath() {
	float time;
	time = this->clock.getElapsedTime().asSeconds();
	if (time > 5) return 1;
	else return 0;
}

bool  DanioFish ::Breath() {
	float time;
	time = this->clock.getElapsedTime().asSeconds();
	if (time > 20) return 1;
	else return 0;
}
