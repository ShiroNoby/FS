#ifndef _GAME_LOGIC_
#define _GAME_LOGIC_

#include "Repository.h"
#include "const.h"

namespace GL 
{
	class Stone : public RP::CreateObject
	{
	public:

		Stone() { m_type = RP::ObjectType::STONE; }
		Stone(int x, int y, int lenght = cnst::horizontal, int weight = cnst::vertical);
		Stone(int* x, int* y, int lenght = cnst::horizontal, int weight = cnst::vertical);

		virtual void update(){}

		virtual ~Stone() {}
	};

	class Water : public RP::CreateObject
	{
	public:

		int dx = 0, dy = 1;


		Water() { m_type = RP::ObjectType::WATER; }
		Water(int x, int y, int lenght = cnst::horizontal, int weight = cnst::vertical);
		Water(int* x, int* y, int lenght = cnst::horizontal, int weight = cnst::vertical);

		virtual void update(RP::Repository& array);
		
		

		~Water() {};
	};

	
	//классы ответственные за создание и удаление объектов
	void Create(int x, int y, RP::ObjectType& type, RP::Repository &array);
	
	//классы ответственные за создание и удаление объектов
	void Erase(int x, int y, RP::Repository& array);
	
	/*
	int Find_Y(RP::Repository& array, const GL::Water* water); //return index element

	int Find_X(RP::Repository& array, const GL::Water* water, int index); //return water.m_x
	*/
}
#endif