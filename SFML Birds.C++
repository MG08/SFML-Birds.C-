#include<SFML/Graphics.hpp>


//function declaration
void drawBirb(int xpos, int ypos, int color[3]);

void flower(int xpos, int ypos, int color[3]);


sf::RenderWindow window(sf::VideoMode(800, 800), "Happy Spring!"); //set up game window

int main() {//////////////////////////////////////////////////////////////////////////////////////////////////

	//this next line is an array. Arrays are a lot like python lists.
	int birbColor[] = { 255, 200, 200 }; //set up an array of colors to make your birb PINK!
	int birbColor2[] = { 120, 100, 100 };
	int birbColor3[] = { 25, 100, 300 };
	int birbColor4[] = { 20, 50, 100 };
	birbColor4[1] = 90;
	int flowercolor[] = { 255, 100, 50 };
	//doesnt do anything^
	

	while (1) {//GAME LOOP OMG-------------------------------------
		window.clear();
		drawBirb(200, 200, birbColor);
		drawBirb(400, 200, birbColor2);
		drawBirb(600, 200, birbColor3);
		drawBirb(200, 400, birbColor4);//function call
		flower(500, 600, flowercolor);
		flower(300, 600, flowercolor);
		flower(500, 400, flowercolor);
		flower(300, 400, flowercolor);
		
		window.display();
	}//end game loop-----------------------------------------------

}//////////////////////////////////////////////////////////////////////////////////////////////////


//function definition
void drawBirb(int xpos, int ypos, int color[3]) {
	//SFML stuff
	sf::CircleShape body;
	sf::CircleShape beak; //SFML lets you set the number of sides of a circle, so this is how we make a triangle!
	sf::RectangleShape feets;

	//leggies
	feets.setPosition(xpos + 10, ypos + 35);
	feets.setFillColor(sf::Color(200, 150, 0));
	feets.setSize(sf::Vector2f(5, 15));
	window.draw(feets); //first leg
	feets.setPosition(xpos + 25, ypos + 35);
	window.draw(feets); //second leg

	//body 
	body.setRadius(20);
	body.setFillColor((sf::Color(color[0], color[1], color[2]))); //noticing accessing slots of an array is just like getting to slots of a list
	body.setPosition(xpos, ypos);
	window.draw(body);

	//birb eyes
	body.setRadius(4);
	body.setFillColor((sf::Color(0, 0, 0))); //black
	body.setPosition(xpos + 15, ypos + 10);
	window.draw(body); //first eye
	body.setPosition(xpos + 30, ypos + 10);
	window.draw(body); //second eye

	//birb beak
	beak.setPointCount(3); //make it a triangle
	beak.setRadius(10);
	beak.setFillColor((sf::Color(200, 150, 0))); //orange
	beak.setPosition(xpos + 17, ypos + 10);
	window.draw(beak);

}

void flower(int xpos, int ypos, int color[3]) {

	sf::CircleShape circle; //tell the program we're using this shape
	sf::RectangleShape rect;

	//left branch
	circle.setRadius(30);
	circle.setFillColor((sf::Color(0, 100, 80)));
	circle.setPosition(xpos, ypos);
	window.draw(circle);

	//right branch
	circle.setRadius(30);
	circle.setFillColor((sf::Color(80, 100, 0)));
	circle.setPosition(xpos+50, ypos);
	window.draw(circle);

	//top branch
	circle.setRadius(30);
	circle.setFillColor((sf::Color(0, 100, 0)));
	circle.setPosition(xpos + 25, ypos - 30);
	window.draw(circle);

	//trunk
	rect.setPosition(xpos + 45, ypos + 20);
	rect.setFillColor(sf::Color(100, 80, 0));
	rect.setSize(sf::Vector2f(20, 100));
	window.draw(rect);
}
