#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
using namespace std;
using namespace sf;
#define max_number_of_items 4 
class menu
{
public:
	// set texts of the main menu
	menu(float width, float height);
	// draw the texts of the main menu
	void draw(RenderWindow& window);
	// set texts of the option menu
	void option1(float width, float height);
	// draw the texts of the main menu
	void drawoption(RenderWindow& window);
	// functions for change the color of the selected text of the main menu
	void moveup();
	void movedown();
	// functions for change the color of the selected text of the option menu
	void moveupoption();
	void movedownoption();
	// volume control 
	void soundhigh();
	void soundlow();
	// set photos of the character 
	void photoofcharactars(float width, float height);
	// draw photos of the character 
	void drawcharacters(RenderWindow& window, int y);
	// set photos of the backdrounds 
	void setbackground(int width, int height);
	// draw photos of the backdrounds
	void drawbackground(RenderWindow& window, int l);
	// set and draw the photo of instructions
	void setinstrctphoto();
	void drawinstrctphoto(RenderWindow& window);
	// function to determind the selected iteme in main and option menu
	int Blue();
	// function to take the number of the screen 
	void y(int x);
private:
	int screen = 0;
	int selecteditemindex = 0, selecteditemindex2 = 0, selectedchracter, selectedtheme;
	int volume = 100;
	Font font;
	// array text for main menu and option menu
	Text text[max_number_of_items], option[4];
	// photos for characters of the game 
	Texture v1;
	Sprite sv1;
	Texture v2;
	Sprite sv2;
	Texture v3;
	Sprite sv3;
	// photos for background of the game 
	Texture b1;
	Sprite sb1;
	Texture b2;
	Sprite sb2;
	Texture b3;
	Sprite sb3;
	// photo to instuction
	Texture i1;
	Sprite si1;


};

