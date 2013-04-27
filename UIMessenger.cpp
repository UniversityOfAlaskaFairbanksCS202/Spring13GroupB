#include "UIMessenger.h"

using std::ostringstream;

UIMessenger::UIMessenger(Player &player)
{
	_player = &player;

	_x = 0.0f/640;
	_y = 400.0f/480;
	_x2 = 300.0f/640;
	_y2 = 400.0f/480;
	// Default colors provide yellow text
	_red = 1.0f;
	_green = 1.0f;
	_blue = 0.0f;
	// _size is used to scale size of font depending on window size
	_size = 32.0f/480;
	UIMessenger::update();
}

void UIMessenger::update()
{
	ostringstream oss;


	oss << "Hit Points: " << _player->getHitPoints();
	_row11 = oss.str();
	oss.str("");
	
	oss << "HP Potions: " << _player->getHPPotions();
	_row21 = oss.str();
	oss.str("");

	oss << "Manna: " <<_player->getMana();
	_row12 = oss.str();
	oss.str("");
	
	oss << "Manna Potions: " << _player->getManaPotions();
	_row22 = oss.str();
	oss.str("");
}

void UIMessenger::draw() const
{
	// msgBox and msgTexture are created here
	// because they must be created after GDI+
	// is started as so cannot be member variables.
	TextLayout msgBox1;
	TextLayout msgBox2;
	gl::Texture msgTexture1;
	gl::Texture msgTexture2;

	msgBox1.clear(ColorA(0.0f,0.0f,0.0f,0.0f));
	msgBox1.setColor(Color(_red,_green,_blue)); 
	msgBox1.setFont(Font("Courier New",getWindowHeight()*_size));
		
	msgBox2.clear(ColorA(0.0f,0.0f,0.0f,0.0f));
	msgBox2.setColor(Color(_red,_green,_blue)); 
	msgBox2.setFont(Font("Courier New",getWindowHeight()*_size));

	msgBox1.addLine(_row11);
	msgBox1.addLine(_row21);
	msgBox2.addLine(_row12);
	msgBox2.addLine(_row22);

	msgTexture1 = msgBox1.render(true,false);
	msgTexture2 = msgBox2.render(true,false);

		// Have to turn alpha blending on and off to get it
		// to work right. It might be better to do this in the main
		// application setup function.
		gl::enableAlphaBlending();
		gl::draw(msgTexture1,Vec2f(getWindowWidth()*_x, getWindowHeight()*_y));
		gl::draw(msgTexture2,Vec2f(getWindowWidth()*_x2, getWindowHeight()*_y2));
		gl::disableAlphaBlending();
}
