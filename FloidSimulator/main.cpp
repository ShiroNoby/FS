#include <SFML/Graphics.hpp>
#include <iostream>

#include "const.h"
#include "Repository.h"
#include "GameLogic.h"


RP::Repository field(1000);




int main() 
{
	sf::RenderWindow window(sf::VideoMode(cnst::W_Lenght, cnst::W_Weight), "FS");

	//create texture
	sf::Texture T_Water, T_Stone;

	//load texture
	T_Stone.loadFromFile("C:/Users/Anrokyr/Desktop/project/Programm/FloidSimulator/Stone.jpg", sf::IntRect(603, 492, 255, 206));
	T_Water.loadFromFile("C:/Users/Anrokyr/Desktop/project/Programm/FloidSimulator/Water.jpg", sf::IntRect(366, 550, 213, 190));

	//create sprite
	sf::Sprite S_Water, S_Stone;

	//load sprite
	S_Water.setTexture(T_Water);
	S_Water.setTextureRect(sf::IntRect(0, 0, cnst::vertical, cnst::horizontal));
	
	S_Stone.setTexture(T_Stone);
	S_Stone.setTextureRect(sf::IntRect(0, 0, cnst::vertical, cnst::horizontal));

	
	RP::ObjectType O_Tmp = RP::ObjectType::STONE;

	RP::CreateObject water1{ 15, 15, RP::ObjectType::WATER };
	field.push_back(water1);


	RP::CreateObject stone1{ 15, 16, RP::ObjectType::STONE};
	field.push_back(stone1);

	




	while (window.isOpen())
	{
		sf::Event event;
		
		//ген-сообщ
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}

			//FS ввод/ввывод
			//выбор объекта
			if (event.type == sf::Event::KeyPressed) 
			{ 
			
				if (event.key.code == sf::Keyboard::Space) 
				{
					std::cout << "Enter is pressing" << std::endl;
					if (O_Tmp == RP::ObjectType::STONE) { O_Tmp = RP::ObjectType::WATER; }
					else { O_Tmp = RP::ObjectType::STONE; }
				}
				
			}

			//создание/уничтожение объекта
			if (event.type ==  sf::Event::MouseButtonPressed)
			{

				
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					std::cout << "Left click" << std::endl;
					
					GL::Create((event.mouseButton.x / cnst::horizontal), (event.mouseButton.y / cnst::vertical) , O_Tmp, field);

				}
				
				if (event.mouseButton.button == sf::Mouse::Right) 
				{ 
					std::cout << "Right click" << std::endl; 
				
					
					GL::Erase((event.mouseButton.x /cnst::horizontal), (event.mouseButton.y / cnst::vertical), field);

				}
			}
		}

		//физическ. действие
		field.update(field);
				
		//рисовка
		window.clear(sf::Color::Black);
				
		//отрисовка field
		for (int index = 0; index < field.m_size; index++) 
		{
			if (field[index].m_type == RP::ObjectType::STONE) 
			{
				S_Stone.setPosition(static_cast<int>(field[index].m_x* cnst::horizontal), static_cast<int>(field[index].m_y* cnst::vertical));
				window.draw(S_Stone);
			}
			if (field[index].m_type == RP::ObjectType::WATER) 
			{
				S_Water.setPosition(static_cast<int>(field[index].m_x* cnst::horizontal), static_cast<int>(field[index].m_y* cnst::vertical));
				window.draw(S_Water);
			}
		}
				
		window.display();

		sf::sleep(sf::Time((sf::microseconds)(100000)));
	}
	return 0;
}


/*

	*/ 