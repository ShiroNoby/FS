#include <SFML/Graphics.hpp>
#include <iostream>

#include "const.h"
#include "Repository.h"
#include "GameLogic.h"


RP::Repository field(100);




int main() 
{
	sf::RenderWindow window(sf::VideoMode(cnst::W_Lenght, cnst::W_Weight), "FS");

	sf::Texture T_Water, T_Stone;

	T_Stone.loadFromFile("C:/Users/Anrokyr/Desktop/project/Programm/FloidSimulator/Stone.jpg", sf::IntRect(603, 492, 255, 206));
	T_Water.loadFromFile("C:/Users/Anrokyr/Desktop/project/Programm/FloidSimulator/Water.jpg", sf::IntRect(366, 550, 213, 190));

	sf::Sprite S_Water, S_Stone;

	S_Water.setTexture(T_Water);
	S_Water.setTextureRect(sf::IntRect(0, 0, cnst::vertical, cnst::horizontal));
	
	S_Stone.setTexture(T_Stone);
	S_Stone.setTextureRect(sf::IntRect(0, 0, cnst::vertical, cnst::horizontal));

	RP::ObjectType O_Tmp = RP::ObjectType::STONE;

	while (window.isOpen())
	{
		sf::Event event;
		


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
					field.update(field);
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
					
					GL::Create(event.mouseButton.x , event.mouseButton.y , O_Tmp, field);

					field.update(field);
				}
				
				if (event.mouseButton.button == sf::Mouse::Right) 
				{ 
					std::cout << "Right click" << std::endl; 
				
					
					GL::Erase(event.mouseButton.x, event.mouseButton.y, field);

					field.update(field);
				}
			}
		}

		window.clear(sf::Color::White);


		field.update(field);
		//отрисовка field
		for (int index = 0; index < field.m_size; index++) 
		{
			if (field[index].m_type == RP::ObjectType::STONE) 
			{
				S_Stone.setPosition(static_cast<float>(field[index].m_x), static_cast<float>(field[index].m_y));
				window.draw(S_Stone);
			}
			if (field[index].m_type == RP::ObjectType::WATER) 
			{
				S_Water.setPosition(static_cast<float>(field[index].m_x), static_cast<float>(field[index].m_y));
				window.draw(S_Water);
			}
		}
		
		


		window.display();

		
	}
	return 0;
}


/*

	*/ 