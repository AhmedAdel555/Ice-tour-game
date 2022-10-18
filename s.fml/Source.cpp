#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<iostream>
#include<time.h>
#include<sstream>
#include<ostream>
#include<fstream>
#include"menu.h"
using namespace std;
using namespace sf;
int screen = 0;
double  dx = 0, dy = 0;
char char_movement_horisontal = 'S';
char char_movement_vertical = 'N';
int z = 0;
float char_x = 375, char_y = 605;
int counter = 0;
int  counter4 = 0;
int counter_plats = 7;
int Still_move = 0;
float volume = 100;
int k = 0;
struct platform {
	float plat_x, plat_y;
};
struct longplatform {
	float longplat_x, longplat_y;
};

int h_plat = 550;
bool isplay = false;
bool firstbutton = false;
int score = 0;
int maxscore = 0;
int current = -1;
int Next = -1;
int sec;
float changespeed = 2;
float changeheightjump = 7;
int num_sel_char = 1;
int num_sel_theme = 1;
int selectedresumeiteme = 0;
RenderWindow window(VideoMode(750, 630), "Icy Tower");
Clock cl1;
Time t1;
Music music;
Texture picture;
Sprite s;
Texture picture2;
Sprite s2;
Texture picture3;
Sprite s3;
Texture picture4;
Sprite s4;
Texture photo;
Sprite pho;
Texture photo1[10];
Sprite pho1;
Texture photo2;
Sprite pho2;
Texture platform_photo[8];
Sprite splatform;
Texture lond_platform_photo;
Sprite slong_platform;
platform platform1[8];
longplatform lpf;
Texture gameover;
Sprite sgameover;
Text text_game_over[4];
Font font1;
SoundBuffer sound_jumb;
Sound ssound_jumb;
SoundBuffer sound_falling;
Sound ssound_falling;
Text scoretext;
Font scorefont;
ostringstream sscore;
Text maxscoretext;
Font maxscorefont;
ostringstream maxsscore;
SoundBuffer Harryup;
Sound sHarryup;
Text textharryup;
Font font2;
Text resumetext[2];
void settextharruup();
void soundharryup();
void soundfalling();
void soundJumb();
void startdraw();
void game();
void song();
void loadphoto1();
void loadphoto2(Texture photo[10], int size);
void loadphoto3();
void set_photo1();
void set_photo2();
void set_photo3();
void load_set_platforms();
void load_set_longplatform();
void move_right();
void move_left();
void move_up();
void DM_character();
void position_platform();
void draw_plats();
void is_play();
bool onplatform();
void Animation_platforms();
void Animation_character_plat();
void scoreplayer();
void setgameover();
void settextgameover();
void draw_game_over();
void Updategame();
void textresume();
void moveupitememenu();
void movedownitememenu();
// loading max score 
void loadmaxscore();
int main() {
	window.setFramerateLimit(25);
	//handling sounds
	menu medo(750, 630);
	medo.option1(750, 630);
	medo.photoofcharactars(750, 630);
	medo.setbackground(750, 630);
	medo.setinstrctphoto();
	settextharruup();
	song();
	soundJumb();
	soundfalling();
	soundharryup();
	loadphoto1();
	set_photo1();
	loadphoto2(photo1, 10);
	set_photo2();
	loadphoto3();
	set_photo3();
	load_set_platforms();
	load_set_longplatform();
	position_platform();
	scoreplayer();
	setgameover();
	settextgameover();
	textresume();
	cout << "Ahmed";
	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event)) {
			switch (event.type)
			{
			case Event::Closed:
				window.close(); break;
			case Event::KeyPressed:
				switch (event.key.code) {
				case Keyboard::Up:
					if (screen == 0)
						medo.moveup();
					else if (screen == 2)
						medo.moveupoption();
					else if (screen == 5)
						moveupitememenu();
					break;
				case Keyboard::Down:
					if (screen == 0)
						medo.movedown();
					else if (screen == 2)
						medo.movedownoption();
					else if (screen == 5)
						movedownitememenu();
					break;
				case Keyboard::Enter:
					if (screen == 0) {
						if (medo.Blue() == 3) {
							window.close();
						}
						else if (medo.Blue() == 0) {
							screen = 1;
							medo.y(screen);
						}
						else if (medo.Blue() == 1) {
							screen = 2;
							medo.y(screen);
						}
						else if (medo.Blue() == 2) {
							screen = 3;
						}


					}
					else if (screen == 2) {
						if (medo.Blue() == 6)
						{
							screen = 0;
							medo.y(screen);
						}
					}
					else if (screen == 3) {
						screen = 0;
						medo.y(screen);
					}
					else if (screen == 5) {
						if (selectedresumeiteme == 0) {
							screen = 1;
							medo.y(screen);
						}
						else if (selectedresumeiteme == 1) {
							screen = 0;
							medo.y(screen);
							Updategame();
							music.play();
						}

					}
					break;
				case Keyboard::Right:
					if (screen == 2 && medo.Blue() == 3) {
						if (volume != 100) {
							medo.soundhigh();
							volume += 10;
							music.setVolume(volume);
						}
					}
					else if (screen == 2 && medo.Blue() == 5) {
						if (num_sel_char < 3) {
							num_sel_char++;
							loadphoto1();
							set_photo1();
							loadphoto2(photo1, 10);
							set_photo2();
							loadphoto3();
							set_photo3();

						}
					}
					else if (screen == 2 && medo.Blue() == 4) {
						if (num_sel_theme < 3) {
							num_sel_theme++;
							load_set_platforms();
							load_set_longplatform();
						}
					}
					else if (screen == 1 && pho1.getPosition().x < 640) {
						char_movement_horisontal = 'R';
					}
					break;
				case Keyboard::Left:
					if (screen == 2 && medo.Blue() == 3) {
						if (volume != 0) {
							medo.soundlow();
							volume -= 10;
							music.setVolume(volume);
						}
					}
					else if (screen == 2 && medo.Blue() == 5) {
						if (num_sel_char > 1)
						{
							num_sel_char--;
							loadphoto1();
							set_photo1();
							loadphoto2(photo1, 10);
							set_photo2();
							loadphoto3();
							set_photo3();
						}
					}
					else if (screen == 2 && medo.Blue() == 4) {
						if (num_sel_theme > 1) {
							num_sel_theme--;
							load_set_platforms();
							load_set_longplatform();
						}
					}
					else if (screen == 1 && pho1.getPosition().x > 112) {
						char_movement_horisontal = 'L';
					}
					break;
				case Keyboard::Space:
					if (screen == 1 && char_y < 650 && char_y > 60) {
						if (Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::Left)) {
							char_movement_vertical = 'U';
							firstbutton = true;
						}
						else {
							char_movement_vertical = 'U';
						}
					}
					break;
				case Keyboard::Escape:
					if (screen == 4) {
						screen = 0;
						medo.y(screen);
						Updategame();
						ssound_falling.stop();
						music.play();
					}
					else if (screen == 3) {
						screen = 0;
						medo.y(screen);
					}
					else if (screen == 1) {
						screen = 5;
					}
				}
				break;
			}
		}
		window.clear();
		if (screen == 0) {
			startdraw();
			medo.draw(window);
		}
		else if (screen == 1)
		{
			game();
			Animation_platforms();
			DM_character();
			if (score == 40) cl1.restart();
			if (score > 40) {
				t1 = cl1.getElapsedTime();
				sec = t1.asSeconds();
				if ((sec + 1) % 30 == 0) {
					changespeed += 0.02;
					sHarryup.play();
				}
				if ((sec + 1) % 32 == 0) {
					window.draw(textharryup);
				}
			}

			music.pause();
		}
		else if (screen == 2)
		{
			startdraw();
			medo.drawoption(window);
			medo.drawcharacters(window, num_sel_char);
			medo.drawbackground(window, num_sel_theme);
		}
		if (screen == 3) {
			medo.drawinstrctphoto(window);
		}
		else if (screen == 4) {
			draw_game_over();
			if (sec > 20) cl1.restart();

		}
		else if (screen == 5) {
			window.draw(s2);
			window.draw(resumetext[0]);
			window.draw(resumetext[1]);
		}
		window.display();
	}

	return 0;
}
void startdraw()
{
	picture.loadFromFile("menu background .png");
	s.setTexture(picture);
	window.draw(s);
}

void game()
{
	if (num_sel_theme == 1) {
		picture2.loadFromFile("gg.png");
		s2.setTexture(picture2);
		window.draw(s2);
		draw_plats();
		window.draw(scoretext);
	}
	else if (num_sel_theme == 2) {
		picture2.loadFromFile("fe0a1b7d-b988-45b3-bd3a-e39a7d033b34.jpg");
		s2.setTexture(picture2);
		window.draw(s2);
		draw_plats();
		window.draw(scoretext);
	}
	else if (num_sel_theme == 3) {
		picture2.loadFromFile("Capture123456789.png");
		s2.setTexture(picture2);
		window.draw(s2);
		draw_plats();
		window.draw(scoretext);
	}

}

void song()
{
	music.openFromFile("iBenji-Boom-feat-Talabun-full-HD-version1-Part.wav");
	music.play();
	music.setLoop(true);
}

void loadphoto2(Texture photo1[10], int size)
{
	for (int i = 0; i < 10; i++) {
		if (num_sel_char == 1)
			photo1[i].loadFromFile("Right 1.png");
		else if (num_sel_char == 2)
			photo1[i].loadFromFile("cape character (2).png");
		else if (num_sel_char == 3)
			photo1[i].loadFromFile("black boy (3).png");
	}
}

void loadphoto1()
{
	if (num_sel_char == 1)
		photo.loadFromFile("stand up.png");
	else if (num_sel_char == 2)
		photo.loadFromFile("pop.png");
	else if (num_sel_char == 3)
		photo.loadFromFile("new boy.png");
}

void loadphoto3()
{
	if (num_sel_char == 1)
		photo2.loadFromFile("Jump.png");
	else if (num_sel_char == 2)
		photo2.loadFromFile("cape character (4).png");
	else if (num_sel_char == 3)
		photo2.loadFromFile("black boy (6).png");


}

void set_photo1()
{
	pho.setTexture(photo);
	pho.setOrigin(Vector2f(14, 25));
	pho.setPosition(Vector2f(char_x, char_y));
}

void set_photo2()
{
	pho1.setTexture(photo1[counter]);
	pho1.setOrigin(Vector2f(14, 25));
	pho1.setPosition(Vector2f(char_x, char_y));
}

void set_photo3()
{
	pho2.setTexture(photo2);
	pho2.setOrigin(14, 25);
	pho2.setPosition(Vector2f(char_x, char_y));
}

void load_set_platforms()
{
	for (int i = 0; i < 8; i++) {
		if (num_sel_theme == 1)
			platform_photo[i].loadFromFile("ground1.png");
		else if (num_sel_theme == 2)
			platform_photo[i].loadFromFile("Block122.jpg");
		else if (num_sel_theme == 3)
			platform_photo[i].loadFromFile("plat form white.png");
	}

}

void load_set_longplatform()
{
	if (num_sel_theme == 1) {
		lond_platform_photo.loadFromFile("Block_22.png");
		slong_platform.setTexture(lond_platform_photo);
		slong_platform.setOrigin(0, 0);
	}
	else if (num_sel_theme == 2)
	{
		lond_platform_photo.loadFromFile("Block.jpg");
		slong_platform.setTexture(lond_platform_photo);
		slong_platform.setOrigin(0, 0);
	}
	else if (num_sel_theme == 3)
	{
		lond_platform_photo.loadFromFile("long plat form white.png");
		slong_platform.setTexture(lond_platform_photo);
		slong_platform.setOrigin(0, 0);
	}


}

void move_right()
{

	if (char_y == 605 || onplatform() == true)
	{
		if (counter < 9)
		{
			counter++;
		}
		else
		{
			counter = 0;
		}
		if (z == 0)
		{
			pho1.setTexture(photo1[counter]);
			dx += 10;
			pho.move(dx, 0);
			pho1.move(dx, 0);
			pho2.move(dx, 0);
			window.draw(pho1);
			char_x += dx;
			dx = 0;
			char_movement_horisontal = 'S';
		}
		else
		{
			pho1.setTexture(photo1[counter]);
			pho1.setScale(1, 1);
			dx += 10;
			pho.move(dx, 0);
			pho1.move(dx, 0);
			pho2.move(dx, 0);
			window.draw(pho1);
			char_x += dx;
			dx = 0;
			char_movement_horisontal = 'S';
			z = 0;
		}
	}
	else {
		char_movement_vertical = 'U';
		counter4 = 13;
	}
}

void move_left() {
	if (char_y == 605 || onplatform() == true)
	{
		if (counter < 9) {
			counter++;
		}
		else {
			counter = 0;
		}
		pho1.setTexture(photo1[counter]);
		pho1.setScale(-1, 1);
		dx -= 10;
		pho.move(dx, 0);
		pho1.move(dx, 0);
		pho2.move(dx, 0);
		window.draw(pho1);
		char_x += dx;
		dx = 0;
		z = 1;
		char_movement_horisontal = 'S';
	}
	else {
		char_movement_vertical = 'U';
		counter4 = 13;
	}
}

void move_up()
{
	if (counter4 < 13)
	{
		if (char_y < 30) counter4 = 13;
		if (isplay == true) dy += 6;
		else  dy += 6.5;
		char_y -= dy;
		counter4++;
		ssound_jumb.play();
	}
	else
	{
		is_play();
		if (isplay == true) dy += 10;
		else  dy += 6.5;
		char_y += dy;
		onplatform();
		if (onplatform()) {
			if (Next > current) {
				if (Next == 6 && current == -1)
					score -= 10;
				else if (Next == 5 && current == -1)
					score -= 20;
				else if (Next == 4 && current == -1)
					score -= 30;
				else if (Next == 3 && current == -1)
					score -= 40;
				else if (Next == 2 && current == -1)
					score -= 50;
				else if (Next == 1 && current == -1)
					score -= 60;
				else
					score += 10;
				current = Next;
				if (Next == 7) current = -1;
			}
			else if (Next < current) {
				if ((char_x >= lpf.longplat_x && char_y <= lpf.longplat_y - 10 && char_y >= lpf.longplat_y - 25) && Next != current)
					score += 10;
				else
					score -= 10 * (current - Next);
				current = Next;
				if (Next == 7) current = -1;

			}

			sscore.str("");
			sscore << "score : " << score;
			scoretext.setString(sscore.str());
		}
		if (char_y > 604 && isplay == true) {
			char_y += 30;
			screen = 4;
			ssound_falling.play();

		}
		else if (char_y > 604) {
			dy = 0;
			counter4 = 0;
			Still_move = 0;
			char_movement_horisontal = 'S';
			char_movement_vertical = 'N';
			firstbutton = false;
			current = -1; Next = -1;
			score = 0;
			sscore.str("");
			sscore << "score : " << score;
			scoretext.setString(sscore.str());
		}
	}
	if (char_y < 600)
	{
		if (Keyboard::isKeyPressed(Keyboard::Right) && pho1.getPosition().x < 640) {
			if (firstbutton == true)  char_x += 20;
			else  char_x += 8;
			pho.setPosition(char_x, char_y);
			pho1.setPosition(char_x, char_y);
			pho2.setPosition(char_x, char_y);
			if (z == 1) {
				pho1.setScale(1, 1);
				z = 0;
			}
			window.draw(pho1);
			Still_move = 1;
			dy = 0;

		}
		else if (Keyboard::isKeyPressed(Keyboard::Left) && pho1.getPosition().x > 112) {
			if (firstbutton == true)  char_x -= 20;
			else  char_x -= 8;
			pho.setPosition(char_x, char_y);
			pho1.setPosition(char_x, char_y);
			pho2.setPosition(char_x, char_y);
			if (z == 0) {
				pho1.setScale(-1, 1);
				z = 1;
			}
			window.draw(pho1);
			Still_move = 1;
			dy = 0;
		}
		else {
			pho.setPosition(char_x, char_y);
			pho1.setPosition(char_x, char_y);
			pho2.setPosition(char_x, char_y);
			if (Still_move == 0)  window.draw(pho2);
			else if (Still_move == 1) window.draw(pho1);
			dy = 0;

		}
	}
	else {
		pho.setPosition(char_x, char_y);
		pho1.setPosition(char_x, char_y);
		pho2.setPosition(char_x, char_y);
		window.draw(pho2);
		dy = 0;
	}
}

void DM_character()
{
	if (char_movement_vertical == 'U') {
		move_up();
	}
	else if (char_movement_horisontal == 'R' && onplatform() == true)
	{
		Animation_character_plat();
	}
	else if (char_movement_horisontal == 'R')
	{
		move_right();
	}
	else if (char_movement_horisontal == 'L' && onplatform() == true)
	{
		Animation_character_plat();
	}
	else if (char_movement_horisontal == 'L') {

		move_left();
	}
	else if (char_movement_horisontal == 'S' && onplatform() == true)
	{
		Animation_character_plat();
	}
	else if (char_movement_horisontal == 'S')
	{
		if (Keyboard::isKeyPressed(Keyboard::Space))	char_movement_vertical = 'U';
		else if (onplatform() == false && char_y < 604) {
			counter4 = 13;
			move_up();
		}
		else if (char_y > 604 && isplay == true) {
			char_y += 30;
			screen = 4;
			ssound_falling.play();
		}
		else
			window.draw(pho);
	}
}

void position_platform()
{
	srand(time(0));
	for (int i = 0; i < 8; i++) {
		platform1[i].plat_x = (rand() % 405) + 82;
		platform1[i].plat_y = h_plat;
		h_plat -= 80;
	}
	h_plat = 550;
	lpf.longplat_x = 75;
	lpf.longplat_y = -10;
}

void draw_plats()
{
	for (int i = 0; i < 8; i++) {
		splatform.setTexture((platform_photo[i]));
		splatform.setPosition(platform1[i].plat_x, platform1[i].plat_y);
		window.draw(splatform);
		if (counter_plats % 50 == 0) {
			slong_platform.setPosition(lpf.longplat_x, lpf.longplat_y);
			window.draw(slong_platform);
			k = i;
		}
	}


}

void is_play()
{
	if (char_y < 350) {
		isplay = true;
	}
}

bool onplatform()
{
	for (int i = 0; i < 8; i++) {
		if ((char_x >= platform1[i].plat_x - 10 && char_x <= platform1[i].plat_x + 190 && char_y <= platform1[i].plat_y - 10 && char_y >= platform1[i].plat_y - 25) || (char_x >= lpf.longplat_x && char_y <= lpf.longplat_y - 10 && char_y >= lpf.longplat_y - 25)) {
			char_movement_horisontal = 'S';
			char_movement_vertical = 'N';
			dy = 0;
			counter4 = 0;
			Still_move = 0;
			firstbutton = false;
			Next = i;
			return true;
		}
	}
	return false;

}

void Animation_platforms()
{
	is_play();
	if (isplay == true)
	{

		if (counter_plats % 50 == 0) {
			lpf.longplat_y += changespeed;
		}
		for (int i = 0; i < 8; i++)
		{
			platform1[i].plat_y += changespeed;

			if (platform1[i].plat_y > 630)
			{
				platform1[i].plat_x = (rand() % 405) + 82;
				platform1[i].plat_y = -10;
				if (counter_plats % 50 != 0) counter_plats++;
			}
			if (lpf.longplat_y > 630) {
				counter_plats = 7;
				lpf.longplat_y = -10;
			}

		}
	}
}

void Animation_character_plat()
{
	is_play();
	if (isplay == true) {
		if (onplatform())
		{
			char_y += changespeed;
			if (Keyboard::isKeyPressed(Keyboard::Right) && pho1.getPosition().x < 640) {
				if (Keyboard::isKeyPressed(Keyboard::Space) && pho1.getPosition().y > 0) {
					firstbutton = true;
					move_up();
				}
				else {
					char_x += 10;
					pho.setPosition(char_x, char_y);
					pho1.setPosition(char_x, char_y);
					pho2.setPosition(char_x, char_y);
					if (z == 1) {
						pho1.setScale(1, 1);
						z = 0;
					}
					window.draw(pho1);
					Still_move = 1;
				}
				dy = 0;


			}
			else if (Keyboard::isKeyPressed(Keyboard::Left) && pho1.getPosition().x > 112) {
				if (Keyboard::isKeyPressed(Keyboard::Space) && pho1.getPosition().y > 0) {
					firstbutton = true;
					move_up();
				}
				else {
					char_x -= 10;
					pho.setPosition(char_x, char_y);
					pho1.setPosition(char_x, char_y);
					pho2.setPosition(char_x, char_y);
					if (z == 0) {
						pho1.setScale(-1, 1);
						z = 1;
					}
					window.draw(pho1);
					Still_move = 1;
				}
				dy = 0;

			}
			else if (Keyboard::isKeyPressed(Keyboard::Space) && pho1.getPosition().y > 0)
			{
				move_up();
			}
			else
			{
				pho.setPosition(char_x, char_y);
				pho1.setPosition(char_x, char_y);
				pho2.setPosition(char_x, char_y);
				if (Still_move == 0)  window.draw(pho);
				else if (Still_move == 1) window.draw(pho1);
				dy = 0;
			}

			Still_move = 0;
		}
		else {
			counter4 = 13;
			move_up();
			firstbutton = false;
		}
	}
	else {
		if (onplatform()) {

			if (Keyboard::isKeyPressed(Keyboard::Right) && pho1.getPosition().x < 640) {
				if (Keyboard::isKeyPressed(Keyboard::Space) && pho1.getPosition().y > 0) {
					firstbutton = true;
					move_up();
				}
				else {
					char_x += 10;
					pho.setPosition(char_x, char_y);
					pho1.setPosition(char_x, char_y);
					pho2.setPosition(char_x, char_y);
					if (z == 1) {
						pho1.setScale(1, 1);
						z = 0;
					}
					window.draw(pho1);
					Still_move = 1;
				}
				dy = 0;

			}
			else if (Keyboard::isKeyPressed(Keyboard::Left) && pho1.getPosition().x > 112) {
				if (Keyboard::isKeyPressed(Keyboard::Space) && pho1.getPosition().y > 0) {
					firstbutton = true;
					move_up();
				}
				else {
					char_x -= 10;
					pho.setPosition(char_x, char_y);
					pho1.setPosition(char_x, char_y);
					pho2.setPosition(char_x, char_y);
					if (z == 0) {
						pho1.setScale(-1, 1);
						z = 1;
					}
					window.draw(pho1);
					Still_move = 1;
				}
				dy = 0;
			}
			else {
				if (Keyboard::isKeyPressed(Keyboard::Space) && pho1.getPosition().y > 0) {
					move_up();
				}
				else {
					pho.setPosition(char_x, char_y);
					pho1.setPosition(char_x, char_y);
					pho2.setPosition(char_x, char_y);
					if (Still_move == 0)  window.draw(pho);
					else if (Still_move == 1) window.draw(pho1);
					dy = 0;
				}
			}
			Still_move = 0;
		}
	}
}

void setgameover()
{
	gameover.loadFromFile("game over.png");
	sgameover.setTexture(gameover);
}

void settextgameover()
{
	font1.loadFromFile("unispace rg.ttf");
	text_game_over[0].setFont(font1);
	text_game_over[0].setFillColor(Color::White);
	text_game_over[0].setCharacterSize(25);
	text_game_over[0].setStyle(Text::Bold);
	text_game_over[0].setString(" Click Esc to return to the main menu");
	text_game_over[0].setPosition(100, 400);

	text_game_over[1].setFont(font1);
	text_game_over[1].setFillColor(Color::Blue);
	text_game_over[1].setCharacterSize(70);
	text_game_over[1].setStyle(Text::Bold);
	text_game_over[1].setString("Game over");
	text_game_over[1].setPosition(160, 75);

	text_game_over[2].setFont(font1);
	text_game_over[2].setFillColor(Color::Magenta);
	text_game_over[2].setCharacterSize(40);
	text_game_over[2].setStyle(Text::Bold);
	text_game_over[2].setString(" Thanks Dr : Hadeer ");
	text_game_over[2].setPosition(150, 500);

	text_game_over[3].setFont(font1);
	text_game_over[3].setFillColor(Color::White);
	text_game_over[3].setCharacterSize(15);
	text_game_over[3].setStyle(Text::Bold);
	text_game_over[3].setString("Suborted by :  \n  Eng : Salma ramy  \n  Eng : Mohamed.ibrahem ");
	text_game_over[3].setPosition(10, 550);

}

void draw_game_over()
{
	window.draw(text_game_over[0]);
	window.draw(text_game_over[1]);
	window.draw(text_game_over[2]);
	window.draw(text_game_over[3]);
	sscore.str("");
	sscore << "score : " << score;
	scoretext.setCharacterSize(50);
	scoretext.setFillColor(Color::Blue);
	scoretext.setPosition(200, 200);
	scoretext.setString(sscore.str());
	window.draw(scoretext);
	loadmaxscore();
	maxsscore.str("");
	maxsscore << "maxscore : " << maxscore;
	maxscoretext.setString(maxsscore.str());
	window.draw(maxscoretext);
}
void Updategame()
{
	dx = 0, dy = 0;
	char_movement_horisontal = 'S';
	char_movement_vertical = 'N';
	z = 0;
	char_x = 375, char_y = 605;
	counter = 0;
	counter4 = 0;
	Still_move = 0;
	isplay = false;
	firstbutton = false;
	counter_plats = 7;
	Next = -1; current = -1;
	changespeed = 2.5;
	changeheightjump = 7;
	score = 0;
	sscore.str("");
	sscore << "score : " << score;
	scoretext.setCharacterSize(30);
	scoretext.setPosition(10, 10);
	scoretext.setFont(scorefont);
	scoretext.setFillColor(Color::White);
	scoretext.setStyle(Text::Bold);
	scoretext.setString(sscore.str());
	set_photo1();
	set_photo2();
	set_photo3();
	load_set_platforms();
	load_set_longplatform();
	position_platform();
}
void textresume()
{
	font1.loadFromFile("unispace rg.ttf");
	resumetext[0].setFont(font1);
	resumetext[0].setFillColor(Color::Magenta);
	resumetext[0].setCharacterSize(30);
	resumetext[0].setStyle(Text::Bold);
	resumetext[0].setString("continue");
	resumetext[0].setPosition(300, 200);

	resumetext[1].setFont(font1);
	resumetext[1].setFillColor(Color::White);
	resumetext[1].setCharacterSize(30);
	resumetext[1].setStyle(Text::Bold);
	resumetext[1].setString("main menu");
	resumetext[1].setPosition(300, 300);
}
void moveupitememenu()
{
	if (selectedresumeiteme - 1 >= 0) {
		resumetext[selectedresumeiteme].setFillColor(Color::White);
		selectedresumeiteme--;
		resumetext[selectedresumeiteme].setFillColor(Color::Magenta);
	}
}
void movedownitememenu()
{
	if (selectedresumeiteme + 1 < 2) {
		resumetext[selectedresumeiteme].setFillColor(Color::White);
		selectedresumeiteme++;
		resumetext[selectedresumeiteme].setFillColor(Color::Magenta);
	}
}
void soundJumb() {
	sound_jumb.loadFromFile("Sounds_jump.wav");
	ssound_jumb.setBuffer(sound_jumb);

}
void soundfalling() {
	sound_falling.loadFromFile("sounds_falling.wav");
	ssound_falling.setBuffer(sound_falling);
}
void soundharryup() {
	Harryup.loadFromFile("sound harryup.wav");
	sHarryup.setBuffer(Harryup);
}
void scoreplayer() {
	scorefont.loadFromFile("unispace rg.ttf");
	sscore << "score : " << score;
	scoretext.setCharacterSize(30);
	scoretext.setPosition(10, 10);
	scoretext.setFont(scorefont);
	scoretext.setFillColor(Color::White);
	scoretext.setStyle(Text::Bold);
	scoretext.setString(sscore.str());

	maxscorefont.loadFromFile("unispace rg.ttf");
	maxsscore << "maxscore : " << maxscore;
	maxscoretext.setCharacterSize(50);
	maxscoretext.setPosition(150, 300);
	maxscoretext.setFont(maxscorefont);
	maxscoretext.setFillColor(Color::Blue);
	maxscoretext.setStyle(Text::Bold);
	maxscoretext.setString(maxsscore.str());

}
void settextharruup() {
	font2.loadFromFile("IceCaps.ttf");
	textharryup.setFillColor(Color::White);
	textharryup.setCharacterSize(70);
	textharryup.setPosition(200, 300);
	textharryup.setFont(font2);
	textharryup.setString(" Harry Up ");
}
void loadmaxscore() {
	ifstream maxscorefile("maxscore.txt");
	if (maxscorefile.is_open()) {
		maxscorefile >> maxscore;
		if (score > maxscore) {
			maxscore = score;
		}
	}
	maxscorefile.close();
	ofstream savemaxscore("maxscore.txt");
	savemaxscore << maxscore;
}