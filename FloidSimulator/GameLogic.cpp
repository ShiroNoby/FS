#include "GameLogic.h"



namespace GL 
{
	Stone::Stone(int* x, int* y, int lenght, int weight)
		: CreateObject(x, y, lenght, weight) {
		m_type = RP::ObjectType::STONE;
	}

	Stone::Stone(int x, int y, int lenght, int weight)
		: CreateObject(x, y, lenght, weight) {
		m_type = RP::ObjectType::STONE;
	}



	Water::Water(int* x, int* y, int lenght, int weight)
		: CreateObject(x, y, lenght, weight) {
		m_type = RP::ObjectType::WATER;
	}

	Water::Water(int x, int y, int lenght, int weight)
		: CreateObject(x, y, lenght, weight) {
		m_type = RP::ObjectType::WATER;
	}

	/*
	void Water::update(RP::Repository& array)
	{
		//проверка по y на столкновение с объектом
			//m_y += 1;

		int index = GL::Find_Y(array, this); //0 для продолжения

		if (!index) { this->m_y += this->dy; return; }

		//проверка по x на столкновение
			//m_y +=1, m_x +=(-=) index;

		this->dy = GL::Find_X(array, this, index);

		this->m_x += this->dx, this->m_y += this->dy;

		//dx = 0, dy = 0;	
	}
	*/
	
	void Water::update(RP::Repository& array)
	{

		int x0 = 0, x1 = 0, x2 = 0, x3 = 0, x4 = 0;

		for (int index = 0; index < array.m_size; index++) 
		{
			if (array[index].m_y == (this->m_y + 1))
			{
				if (array[index].m_x == (this->m_x - 2))	{ x0 = index; }
				if (array[index].m_x == (this->m_x - 1))	{ x1 = index; }

				if (array[index].m_x == this->m_x)			{ x2 = index; }

				if (array[index].m_x == (this->m_x + 1))	{ x3 = index; }
				if (array[index].m_x == (this->m_x + 2))	{ x4 = index; continue; }
			}
		}
		
		if (!(array[x2].m_type == RP::ObjectType::STONE) && !(array[x2].m_type == RP::ObjectType::WATER)) { this->m_y += this->dy; return; }
		
		if (!(array[x1].m_type == RP::ObjectType::STONE) && !(array[x1].m_type == RP::ObjectType::WATER))
		{
			dx = 1;
			this->m_x -= this->dx, this->m_y += this->dy;
			return;
		}
		if (!(array[x3].m_type == RP::ObjectType::STONE) && !(array[x3].m_type == RP::ObjectType::WATER))
		{ 
			dx = 1; 
			this->m_x += this->dx, this->m_y += this->dy; 
			return;
		}

		if (!(array[x0].m_type == RP::ObjectType::STONE) && !(array[x0].m_type == RP::ObjectType::WATER))
		{
			dx = 2;
			this->m_x -= this->dx, this->m_y += this->dy;
			return;
		}
		if (!(array[x4].m_type == RP::ObjectType::STONE) && !(array[x4].m_type == RP::ObjectType::WATER))
		{
			dx = 2;
			this->m_x += this->dx, this->m_y += this->dy;
			return;
		}

	}


	void Create(int x, int y, RP::ObjectType& type, RP::Repository& array)
	{
		switch (type)
		{
		case RP::ObjectType::STONE: 
		{
			GL::Stone stone{ x, y };
			array.push_back(stone);
			return;
		}

		case RP::ObjectType::WATER: 
		{
			GL::Water water{ x, y };
			array.push_back(water);
			return;
		}
		default: return;
		}
	}

	void Erase(int x, int y, RP::Repository& array)
	{
		//find index
		//array.erase(index)
		//return

		for (int index = 0; index < array.m_size; index++) 
		{
			if (array[index].m_y == (y)) 
			{
				if (array[index].m_x == (x)) 
				{
					array.Erase(index);

					return; 
				}
			}
		}
	}
	
	/* издержки производства
	int Find_Y(RP::Repository& array, const GL::Water *water)
	{		
		for (int index = 0; index < array.m_size; index++)
		{
			if (array[index].m_y == ((water->m_y) + 1) ) 
			{
				if (array[index].m_x == water->m_x) { return index; }
			}
		}
		return 0;
	}

	int Find_X(RP::Repository& array, const GL::Water* water, int index)
	{
		int x = 0;

		for (int i = index; i > 0; i--) 
		{
			if (array[index].m_y == ((water->m_y) + 1))
			{
				//
				x--;
			}

			if (array[index].m_y == water->m_y) { continue; }
		}
		
		for (int i = index; i < array.m_size; i++)
		{
			if (array[index].m_y == ((water->m_y) + 1))
			{
				//
				x++;
			}

			if (array[index].m_y == ((water->m_y) + 2)) { continue; }
		}
		

		return x;
	}
	*/
}
