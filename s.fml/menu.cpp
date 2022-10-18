#include "menu.h"
#include<iostream>
using namespace std;
using namespace sf;
menu::menu(float width, float height)
{
	if (!font.loadFromFile("unispace rg.ttf")) {
		// handle Error
	}
	text[0].setFont(font);
	text[0].setCharacterSize(40);
	text[0].setFillColor(Color::Blue);
	text[0].setStyle(Text::Bold);
	text[0].setString("New Game");
	text[0].setPosition(Vector2f::Vector2(width / 12, height / 1.8));

	text[1].setFont(font);
	text[1].setCharacterSize(40);
	text[1].setFillColor(Color::White);
	text[1].setStyle(Text::Bold);
	text[1].setString("Options");
	text[1].setPosition(Vector2f::Vector2(width / 12, height / 1.5));

	text[2].setFont(font);
	text[2].setCharacterSize(40);
	text[2].setFillColor(Color::White);
	text[2].setStyle(Text::Bold);
	text[2].setString("instructions");
	text[2].setPosition(Vector2f::Vector2(width / 12, height / 1.29));

	text[3].setFont(font);
	text[3].setCharacterSize(40);
	text[3].setFillColor(Color::White);
	text[3].setStyle(Text::Bold);
	text[3].setString("Exit");
	text[3].setPosition(Vector2f::Vector2(width / 12, height / 1.13));
}

void menu::draw(RenderWindow& window)
{
	for (int i = 0; i < 4; i++) {
		window.draw(text[i]);
	}
}

void menu::option1(float width, float height)
{
	if (!font.loadFromFile("unispace rg.ttf")) {
		// handle Error
	}
	option[0].setFont(font);
	option[0].setCharacterSize(30);
	option[0].setFillColor(Color::Blue);
	option[0].setStyle(Text::Bold);
	option[0].setString("Sound Level 100 ");
	option[0].setPosition(Vector2f::Vector2(width / 12, height / 1.8));

	option[1].setFont(font);
	option[1].setCharacterSize(30);
	option[1].setFillColor(Color::White);
	option[1].setStyle(Text::Bold);
	option[1].setString("Back ground");
	option[1].setPosition(Vector2f::Vector2(width / 12, height / 1.5));

	option[2].setFont(font);
	option[2].setCharacterSize(30);
	option[2].setFillColor(Color::White);
	option[2].setStyle(Text::Bold);
	option[2].setString("character");
	option[2].setPosition(Vector2f::Vector2(width / 12, height / 1.29));

	option[3].setFont(font);
	option[3].setCharacterSize(30);
	option[3].setFillColor(Color::White);
	option[3].setStyle(Text::Bold);
	option[3].setString("Back");
	option[3].setPosition(Vector2f::Vector2(width / 12, height / 1.13));

}

void menu::drawoption(RenderWindow& window)
{
	for (int i = 0; i < 4; i++) {
		window.draw(option[i]);
	}
}

void menu::moveup()
{

	if (selecteditemindex - 1 >= 0) {
		text[selecteditemindex].setFillColor(Color::White);
		selecteditemindex--;
		text[selecteditemindex].setFillColor(Color::Blue);
	}
}

void menu::movedown()
{
	if (selecteditemindex + 1 < max_number_of_items) {
		text[selecteditemindex].setFillColor(Color::White);
		selecteditemindex++;
		text[selecteditemindex].setFillColor(Color::Blue);
	}
}

void menu::moveupoption()
{
	if (selecteditemindex2 - 1 >= 0) {
		option[selecteditemindex2].setFillColor(Color::White);
		selecteditemindex2--;
		option[selecteditemindex2].setFillColor(Color::Blue);
	}
}

void menu::movedownoption()
{
	if (selecteditemindex2 + 1 < 4) {
		option[selecteditemindex2].setFillColor(Color::White);
		selecteditemindex2++;
		option[selecteditemindex2].setFillColor(Color::Blue);
	}
}

void menu::soundhigh()
{
	if (volume == 0) {
		volume += 10;
		option[0].setString("Sound Level 10");
	}
	else if (volume == 10) {
		volume += 10;
		option[0].setString("Sound Level 20");
	}
	else if (volume == 20) {
		volume += 10;
		option[0].setString("Sound Level 30");
	}
	else if (volume == 30) {
		volume += 10;
		option[0].setString("Sound Level 40");
	}
	else if (volume == 40) {
		volume += 10;
		option[0].setString("Sound Level 50");
	}
	else if (volume == 50) {
		volume += 10;
		option[0].setString("Sound Level 60");
	}
	else if (volume == 60) {
		volume += 10;
		option[0].setString("Sound Level 70");
	}
	else if (volume == 70) {
		volume += 10;
		option[0].setString("Sound Level 80");
	}
	else if (volume == 80) {
		volume += 10;
		option[0].setString("Sound Level 90");
	}
	else if (volume == 90) {
		volume += 10;
		option[0].setString("Sound Level 100");
	}
}

void menu::soundlow()
{
	if (volume == 100) {
		volume -= 10;
		option[0].setString("Sound Level 90");
	}
	else if (volume == 90) {
		volume -= 10;
		option[0].setString("Sound Level 80");
	}
	else if (volume == 80) {
		volume -= 10;
		option[0].setString("Sound Level 70");
	}
	else if (volume == 70) {
		volume -= 10;
		option[0].setString("Sound Level 60");
	}
	else if (volume == 60) {
		volume -= 10;
		option[0].setString("Sound Level 50");
	}
	else if (volume == 50) {
		volume -= 10;
		option[0].setString("Sound Level 40");
	}
	else if (volume == 40) {
		volume -= 10;
		option[0].setString("Sound Level 30");
	}
	else if (volume == 30) {
		volume -= 10;
		option[0].setString("Sound Level 20");
	}
	else if (volume == 20) {
		volume -= 10;
		option[0].setString("Sound Level 10");
	}
	else if (volume == 10) {
		volume -= 10;
		option[0].setString("Sound Level 0");
	}
}

void menu::photoofcharactars(float width, float height)
{

	v1.loadFromFile("stand up.png");
	sv1.setTexture(v1);
	sv1.setPosition(width / 2.5, height / 1.28);
	v2.loadFromFile("pop.png");
	sv2.setTexture(v2);
	sv2.setPosition(width / 2.5, height / 1.28);
	v3.loadFromFile("new boy.png");
	sv3.setTexture(v3);
	sv3.setPosition(width / 2.5, height / 1.28);
}


void menu::drawcharacters(RenderWindow& window, int y)
{
	selectedchracter = y;
	if (y == 1) window.draw(sv1);
	else if (y == 2) window.draw(sv2);
	else if (y == 3) window.draw(sv3);
}

void menu::setbackground(int width, int height)
{
	b1.loadFromFile("8855.png");
	sb1.setTexture(b1);
	sb1.setPosition(width / 2.5, height / 1.5);
	b2.loadFromFile("Capture3265.png");
	sb2.setTexture(b2);
	sb2.setPosition(width / 2.5, height / 1.5);
	b3.loadFromFile("14785699.png");
	sb3.setTexture(b3);
	sb3.setPosition(width / 2.5, height / 1.5);

}

void menu::drawbackground(RenderWindow& window, int l)
{
	selectedtheme = l;
	if (l == 1) window.draw(sb1);
	else if (l == 2) window.draw(sb2);
	else if (l == 3) window.draw(sb3);
}

void menu::setinstrctphoto()
{
	i1.loadFromFile("instructions26.png");
	si1.setTexture(i1);
}

void menu::drawinstrctphoto(RenderWindow& window)
{
	window.draw(si1);
}


int menu::Blue()
{
	if (screen == 0) {
		if (selecteditemindex == 0)
			return 0;
		else if (selecteditemindex == 1)
			return 1;
		else if (selecteditemindex == 2)
			return 2;
		else if (selecteditemindex == 3)
			return 3;

	}
	else if (screen == 2) {
		if (selecteditemindex2 == 0)
			return 3;
		else if (selecteditemindex2 == 1)
			return 4;
		else if (selecteditemindex2 == 2)
			return 5;
		else if (selecteditemindex2 == 3)
			return 6;
	}
	else if (screen == 3)
		return 0;
}

void menu::y(int x)
{
	screen = x;
}