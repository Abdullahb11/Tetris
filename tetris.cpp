#include<SFML/Graphics.hpp>
#include<iostream>
#include<iomanip>
#include<string> 
#include<fstream>
using namespace std;
class tetrimino
{
public:
	virtual void drawing(sf::RenderWindow& window)
	{
	}
	virtual void rotating(sf::RenderWindow& window, int** grid)
	{
	}
	virtual void droping(sf::RenderWindow& window)
	{
	}
	virtual void if_left(sf::RenderWindow& window, int** grid)
	{
	}
	virtual void if_right(sf::RenderWindow& window, int** grid)
	{
	}
	virtual void put_val_in_grid(int** grid)
	{
	}
	virtual bool if_stop(int** grid, int left, int right)
	{
		return true;
	}
	virtual bool leftblockcheckhori(int** grid)
	{
		return true;
	}
	virtual bool leftblockcheckvert(int** grid)
	{
		return true;
	}
	virtual void nextshape(sf::RenderWindow& window)
	{}
	virtual bool rightblockcheckhori(int** grid)
	{
		return true;
	}
	virtual bool rightblockcheckvert(int** grid)
	{
		return true;
	}
	virtual void fill_block(sf::RenderWindow& window, int i, int j)
	{
	}
	sf::RectangleShape r;
	virtual sf::RectangleShape get_f()
	{
		return r;
	}
	virtual int get_left()
	{
		return 0;
	}
	virtual int get_right()
	{
		return 0;
	}
	virtual bool leftblockcheck0(int** grid)
	{
		return true;
	}
	virtual bool leftblockcheck1(int** grid)
	{
		return true;
	}
	virtual bool leftblockcheck2(int** grid)
	{
		return true;
	}
	virtual bool leftblockcheck3(int** grid)
	{
		return true;
	}
	virtual bool rightblockcheck0(int** grid)
	{
		return true;
	}
	virtual bool rightblockcheck1(int** grid)
	{
		return true;
	}
	virtual bool rightblockcheck2(int** grid)
	{
		return true;
	}
	virtual bool rightblockcheck3(int** grid)
	{
		return true;
	}
	virtual bool upperboundry(int** grid)
	{
		for (int i = 0; i < 10; i++)
		{
			if (grid[0][i] != 0)
			{
				return true;
			}
		}
		return false;
	}
	~tetrimino()
	{
	}
};
class I :public tetrimino
{
	sf::RectangleShape i1, i2, i3, i4, f;
	int x1, y1, angle, left, right, down;
public:
	I()
	{
		down = 0; angle = 0; left = 3; right = 7; x1 = 160, y1 = 10;
	}
	virtual int get_left()
	{
		return left;
	}
	virtual int get_right()
	{
		return right;
	}
	void nextshape(sf::RenderWindow& window)
	{
		int a = 720, b = 580;
		i1.setPosition(a, b);
		i1.setSize(sf::Vector2f(50, 40));
		i1.setOutlineColor(sf::Color::White);
		i1.setOutlineThickness(1);
		i1.setFillColor(sf::Color::Cyan);
		i2.setPosition(a, b + 40);
		i2.setSize(sf::Vector2f(50, 40));
		i2.setOutlineColor(sf::Color::White);
		i2.setOutlineThickness(1);
		i2.setFillColor(sf::Color::Cyan);
		i3.setPosition(a, b + 80);
		i3.setSize(sf::Vector2f(50, 40));
		i3.setOutlineColor(sf::Color::White);
		i3.setOutlineThickness(1);
		i3.setFillColor(sf::Color::Cyan);
		i4.setPosition(a, b + 120);
		i4.setSize(sf::Vector2f(50, 40));
		i4.setOutlineColor(sf::Color::White);
		i4.setOutlineThickness(1);
		i4.setFillColor(sf::Color::Cyan);
		window.draw(i1);
		window.draw(i2);
		window.draw(i3);
		window.draw(i4);
	}
	void I_vert(sf::RenderWindow& window)
	{
		i1.setPosition(x1, y1);
		i1.setSize(sf::Vector2f(50, 40));
		i1.setOutlineColor(sf::Color::White);
		i1.setOutlineThickness(1);
		i1.setFillColor(sf::Color::Cyan);
		i2.setPosition(x1, y1 + 40);
		i2.setSize(sf::Vector2f(50, 40));
		i2.setOutlineColor(sf::Color::White);
		i2.setOutlineThickness(1);
		i2.setFillColor(sf::Color::Cyan);
		i3.setPosition(x1, y1 + 80);
		i3.setSize(sf::Vector2f(50, 40));
		i3.setOutlineColor(sf::Color::White);
		i3.setOutlineThickness(1);
		i3.setFillColor(sf::Color::Cyan);
		i4.setPosition(x1, y1 + 120);
		i4.setSize(sf::Vector2f(50, 40));
		i4.setOutlineColor(sf::Color::White);
		i4.setOutlineThickness(1);
		i4.setFillColor(sf::Color::Cyan);
	}
	void I_hori(sf::RenderWindow& window)
	{
		i1.setPosition(x1, y1);
		i1.setSize(sf::Vector2f(50, 40));
		i1.setOutlineColor(sf::Color::White);
		i1.setOutlineThickness(1);
		i1.setFillColor(sf::Color::Cyan);
		i2.setPosition(x1 + 50, y1);
		i2.setSize(sf::Vector2f(50, 40));
		i2.setOutlineColor(sf::Color::White);
		i2.setOutlineThickness(1);
		i2.setFillColor(sf::Color::Cyan);
		i3.setPosition(x1 + 100, y1);
		i3.setSize(sf::Vector2f(50, 40));
		i3.setOutlineColor(sf::Color::White);
		i3.setOutlineThickness(1);
		i3.setFillColor(sf::Color::Cyan);
		i4.setPosition(x1 + 150, y1);
		i4.setSize(sf::Vector2f(50, 40));
		i4.setOutlineColor(sf::Color::White);
		i4.setOutlineThickness(1);
		i4.setFillColor(sf::Color::Cyan);
	}
	virtual void drawing(sf::RenderWindow& window)
	{
		if (angle == 90)
		{
			I_vert(window);
			window.draw(i1);
			window.draw(i2);
			window.draw(i3);
			window.draw(i4);
			right = left + 1;
		}
		else if (angle == 0)
		{
			I_hori(window);
			window.draw(i1);
			window.draw(i2);
			window.draw(i3);
			window.draw(i4);
			right = left + 4;
		}
	}
	bool checkfordowntoshiftvert(int** grid)
	{
		for (int i = down; i < down + 3; i++)
		{
			if (grid[i][left] != 0)
				return false;
		}
		return true;
	}
	bool checkforleft(int** grid)
	{
		if (grid[down][left - 1] != 0)
		{
			return false;
		}
		return true;
	}
	bool boundryleft8(int** grid)
	{
		if (grid[down][left - 2] != 0)
		{
			return false;
		}
		return true;
	}
	bool boundryleft9(int** grid)
	{
		if (grid[down][left - 3] != 0)
		{
			return false;
		}
		return true;
	}
	virtual void rotating(sf::RenderWindow& window, int** grid)
	{
		if (angle == 90)
		{
			if ((left <= 3) && (grid[down][left + 1] != 0) && (grid[down][left + 2] != 0))
			{
				angle = 90;
			}
			else if ((left >= 7) && (checkforleft(grid) == false) || (left >= 7) && (boundryleft8(grid) == false) || (left >= 7) && (boundryleft9(grid) == false))
			{
				angle = 90;
			}
			else
			{
				x1 -= 50; left -= 1; right -= 1;
				if (left >= 7)
				{
					left = 6; right = 10; x1 = 310;
				}
				else if (left <= 1)
				{
					left = 0; right = 4; x1 = 10;
				}
				if (checkforright(right) == true)
				{
					angle = 0;
				}
				else
				{
					x1 = 310; right = 9; left = 6; angle = 0;
				}
			}
		}
		else if (angle == 0)
		{
			if (checkfordowntoshiftvert(grid) == true)
			{
				angle = 90;
				x1 += 50; left += 1; right += 1;
			}
			else
				angle = 0;
		}
	}
	virtual void fill_block(sf::RenderWindow& window, int i, int j)
	{
		int hori = 10, verti = 10;
		for (int k = 0; k < j; k++)
			hori += 50;
		for (int k = 0; k < i; k++)
			verti += 40;
		f.setPosition(hori, verti);
		f.setSize(sf::Vector2f(50, 40));
		f.setOutlineColor(sf::Color::White);
		f.setOutlineThickness(1);
		f.setFillColor(sf::Color::Cyan);
	}
	virtual sf::RectangleShape get_f()
	{
		return f;
	}
	virtual void put_val_in_grid(int** grid)
	{
		if (down > 0)
		{
			if (angle == 0)
			{
				for (int f = left; f <= left + 3; f++)
					grid[down][f] = 1;
			}
			else if (angle == 90)
			{
				for (int j = down - 1; j < down + 3; j++)
					for (int f = left; f < left + 1; f++)
						grid[j][f] = 1;
			}
			down = 0; angle = 0; left = 3; right = 7; x1 = 160, y1 = 10;
		}
	}
	bool right_boundry_hori(int right, int c)
	{
		if ((right <= 9) && (c <= 460))
			return true;
		return false;
	}
	bool left_boundry_hori(int left, int c)
	{
		if ((left > 0) && (c > 10))
			return true;
		return false;
	}
	virtual void droping(sf::RenderWindow& window)
	{
		y1 += 40;
		if (angle == 0)
		{
			if (down < 19)
			{
				down++;
			}
		}
		else if (angle == 90)
		{
			if (down <= 17)
			{
				down++;
			}
		}
	}
	virtual bool leftblockcheckhori(int** grid)
	{
		if (grid[down][left - 1] == 0)
			return true;
		return false;
	}
	virtual bool leftblockcheckvert(int** grid)
	{
		for (int h = down; h <= down + 3; h++)
		{
			if (grid[h][left - 1] != 0)
				return false;
		}
		return true;
	}
	virtual bool rightblockcheckhori(int** grid)
	{
		if (grid[down][right] == 0)
			return true;
		return false;
	}
	virtual bool rightblockcheckvert(int** grid)
	{
		for (int b = down; b <= down + 3; b++)
		{
			if (grid[b][right] != 0)
				return false;
		}
		return true;
	}
	virtual void if_left(sf::RenderWindow& window, int** grid)
	{
		if ((angle == 0) && (leftblockcheckhori(grid) == true) && (left_boundry_hori(left, x1) == true))
		{
			left--; right--; x1 -= 50;
		}
		else if ((angle == 90) && (leftblockcheckvert(grid) == true) && (left_boundry_hori(left, x1) == true))
		{
			left--; right--; x1 -= 50;
		}
	}
	bool checkforright(int right)
	{
		if (right > 7)
			return false;
		return true;
	}
	virtual bool if_stop(int** grid, int l, int r)
	{
		if (angle == 0)
		{
			if (y1 == 770)
				return true;
			else if (down < 19)
			{
				for (int i = left; i <= left + 3; i++)
				{
					if (grid[down + 1][i] != 0)
						return true;
				}
				return false;
			}
		}
		else if (angle == 90)
		{
			if (down == 17)
				return true;
			else
			{
				int h = down + 3;
				for (int k = left; k < left + 1; k++)
				{
					if (grid[down + 3][k] != 0)
						return true;
				}
				return false;
			}
		}
	}
	virtual void if_right(sf::RenderWindow& window, int** grid)
	{
		if (right_boundry_hori(right, x1) == true)
		{
			if ((angle == 0) && (rightblockcheckhori(grid) == true))
			{
				left++; right++; x1 += 50;
			}
			else if ((angle == 90) && (rightblockcheckvert(grid) == true))
			{
				left++; right++; x1 += 50;
			}
		}
	}
	~I()
	{
	}
};
class O :public tetrimino
{
	sf::RectangleShape o1, o2, o3, o4, f;
	int x2, y2, angle, left, right, down;
public:
	O()
	{
		left = 3; right = 5; down = 0; angle = 0; x2 = 160, y2 = 10;
	}
	void nextshape(sf::RenderWindow& window)
	{
		int a = 700, b = 600;
		o1.setPosition(a, b);
		o1.setSize(sf::Vector2f(50, 40));
		o1.setOutlineColor(sf::Color::White);
		o1.setOutlineThickness(2);
		o1.setFillColor(sf::Color::Yellow);
		o2.setPosition(a + 50, b);
		o2.setSize(sf::Vector2f(50, 40));
		o2.setOutlineColor(sf::Color::White);
		o2.setOutlineThickness(2);
		o2.setFillColor(sf::Color::Yellow);
		o3.setPosition(a, b + 40);
		o3.setSize(sf::Vector2f(50, 40));
		o3.setOutlineColor(sf::Color::White);
		o3.setOutlineThickness(2);
		o3.setFillColor(sf::Color::Yellow);
		o4.setPosition(a + 50, b + 40);
		o4.setSize(sf::Vector2f(50, 40));
		o4.setOutlineColor(sf::Color::White);
		o4.setOutlineThickness(2);
		o4.setFillColor(sf::Color::Yellow);
		window.draw(o1);
		window.draw(o2);
		window.draw(o3);
		window.draw(o4);
	}
	void o(sf::RenderWindow& window)
	{
		o1.setPosition(x2, y2);
		o1.setSize(sf::Vector2f(50, 40));
		o1.setOutlineColor(sf::Color::White);
		o1.setOutlineThickness(2);
		o1.setFillColor(sf::Color::Yellow);
		o2.setPosition(x2 + 50, y2);
		o2.setSize(sf::Vector2f(50, 40));
		o2.setOutlineColor(sf::Color::White);
		o2.setOutlineThickness(2);
		o2.setFillColor(sf::Color::Yellow);
		o3.setPosition(x2, y2 + 40);
		o3.setSize(sf::Vector2f(50, 40));
		o3.setOutlineColor(sf::Color::White);
		o3.setOutlineThickness(2);
		o3.setFillColor(sf::Color::Yellow);
		o4.setPosition(x2 + 50, y2 + 40);
		o4.setSize(sf::Vector2f(50, 40));
		o4.setOutlineColor(sf::Color::White);
		o4.setOutlineThickness(2);
		o4.setFillColor(sf::Color::Yellow);
	}
	virtual void drawing(sf::RenderWindow& window)
	{
		o(window); window.draw(o1); window.draw(o2); window.draw(o3); window.draw(o4);
	}
	virtual void rotating(sf::RenderWindow& window)
	{
		o(window); window.draw(o1); window.draw(o2); window.draw(o3); window.draw(o4);
	}
	bool left_boundry_hori(int left, int c)
	{
		if ((left > 0) && (c >= 10))
			return true;
		return false;
	}
	virtual bool leftblockcheckhori(int** grid)
	{
		for (int i = down; i < down + 2; i++)
		{
			if (grid[i][left - 1] != 0)
				return false;
		}
		return true;
	}
	virtual void if_left(sf::RenderWindow& window, int** grid)
	{
		if ((left_boundry_hori(left, x2) == true) && (leftblockcheckhori(grid) == true))
		{
			x2 -= 50; left--; right--;
		}
	}
	bool right_boundry_hori(int right, int c)
	{
		if ((right <= 9) && (c <= 460))
			return true;
		return false;
	}
	virtual bool rightblockcheckhori(int** grid)
	{
		for (int i = down; i < down + 2; i++)
			if (grid[i][right] != 0)
				return false;
		return true;
	}
	virtual void if_right(sf::RenderWindow& window, int** grid)
	{
		if ((right_boundry_hori(right, x2) == true) && (rightblockcheckhori(grid) == true))
		{
			left++; right++; x2 += 50;
		}
	}
	virtual void droping(sf::RenderWindow& window)
	{
		y2 += 40; down++;
	}
	virtual bool if_stop(int** grid, int l, int r)
	{
		if (y2 == 770)
			return true;
		for (int k = left; k < right; k++)
			if (grid[down + 1][k] != 0)
				return true;
		return false;
	}
	virtual void put_val_in_grid(int** grid)
	{
		if (down > 0)
		{
			for (int j = down - 1; j < down + 1; j++)
				for (int f = left; f < right; f++)
					grid[j][f] = 2;
			down = 0; left = 3; right = 5; x2 = 160, y2 = 10;
		}
	}
	virtual void fill_block(sf::RenderWindow& window, int i, int j)
	{
		int hori = 10, verti = 10;
		for (int k = 0; k < j; k++)
			hori += 50;
		for (int k = 0; k < i; k++)
			verti += 40;
		f.setPosition(hori, verti);
		f.setSize(sf::Vector2f(50, 40));
		f.setOutlineColor(sf::Color::White);
		f.setOutlineThickness(1);
		f.setFillColor(sf::Color::Yellow);
	}
	virtual	sf::RectangleShape get_f()
	{
		return f;
	}
	~O()
	{
	}
};
class L :public tetrimino
{
	sf::RectangleShape l1, l2, l3, l4, f;
	int x3, y3, angle, lef1, lef2, r1, r2, d1, d2;
public:
	L()
	{
		d1 = 0, d2 = 0; lef1 = 3, r1 = 4, lef2 = 4, r2 = 5; angle = 0; x3 = 160, y3 = 10;
	}
	void nextshape(sf::RenderWindow& window)
	{
		int a = 720, b = 580;
		l1.setPosition(a, b);
		l1.setSize(sf::Vector2f(50, 40));
		l1.setOutlineColor(sf::Color::White);
		l1.setOutlineThickness(1);
		l1.setFillColor(sf::Color::Magenta);
		l2.setPosition(a, b + 40);
		l2.setSize(sf::Vector2f(50, 40));
		l2.setOutlineColor(sf::Color::White);
		l2.setOutlineThickness(1);
		l2.setFillColor(sf::Color::Magenta);
		l3.setPosition(a, b + 80);
		l3.setSize(sf::Vector2f(50, 40));
		l3.setOutlineColor(sf::Color::White);
		l3.setOutlineThickness(1);
		l3.setFillColor(sf::Color::Magenta);
		l4.setPosition(a + 50, b + 80);
		l4.setSize(sf::Vector2f(50, 40));
		l4.setOutlineColor(sf::Color::White);
		l4.setOutlineThickness(1);
		l4.setFillColor(sf::Color::Magenta);
		window.draw(l1);
		window.draw(l2);
		window.draw(l3);
		window.draw(l4);
	}
	void L_1(sf::RenderWindow& window)
	{
		l1.setPosition(x3, y3);
		l1.setSize(sf::Vector2f(50, 40));
		l1.setOutlineColor(sf::Color::White);
		l1.setOutlineThickness(1);
		l1.setFillColor(sf::Color::Magenta);
		l2.setPosition(x3, y3 + 40);
		l2.setSize(sf::Vector2f(50, 40));
		l2.setOutlineColor(sf::Color::White);
		l2.setOutlineThickness(1);
		l2.setFillColor(sf::Color::Magenta);
		l3.setPosition(x3, y3 + 80);
		l3.setSize(sf::Vector2f(50, 40));
		l3.setOutlineColor(sf::Color::White);
		l3.setOutlineThickness(1);
		l3.setFillColor(sf::Color::Magenta);
		l4.setPosition(x3 + 50, y3 + 80);
		l4.setSize(sf::Vector2f(50, 40));
		l4.setOutlineColor(sf::Color::White);
		l4.setOutlineThickness(1);
		l4.setFillColor(sf::Color::Magenta);
	}
	void L_2(sf::RenderWindow& window)
	{
		l1.setPosition(x3, y3);
		l1.setSize(sf::Vector2f(50, 40));
		l1.setOutlineColor(sf::Color::White);
		l1.setOutlineThickness(1);
		l1.setFillColor(sf::Color::Magenta);
		l2.setPosition(x3 + 50, y3);
		l2.setSize(sf::Vector2f(50, 40));
		l2.setOutlineColor(sf::Color::White);
		l2.setOutlineThickness(1);
		l2.setFillColor(sf::Color::Magenta);
		l3.setPosition(x3 + 100, y3);
		l3.setSize(sf::Vector2f(50, 40));
		l3.setOutlineColor(sf::Color::White);
		l3.setOutlineThickness(1);
		l3.setFillColor(sf::Color::Magenta);
		l4.setPosition(x3 + 100, y3 - 40);
		l4.setSize(sf::Vector2f(50, 40));
		l4.setOutlineColor(sf::Color::White);
		l4.setOutlineThickness(1);
		l4.setFillColor(sf::Color::Magenta);
	}
	void L_3(sf::RenderWindow& window)
	{
		l1.setPosition(x3, y3);
		l1.setSize(sf::Vector2f(50, 40));
		l1.setOutlineColor(sf::Color::White);
		l1.setOutlineThickness(1);
		l1.setFillColor(sf::Color::Magenta);
		l2.setPosition(x3, y3 + 40);
		l2.setSize(sf::Vector2f(50, 40));
		l2.setOutlineColor(sf::Color::White);
		l2.setOutlineThickness(1);
		l2.setFillColor(sf::Color::Magenta);
		l3.setPosition(x3, y3 + 80);
		l3.setSize(sf::Vector2f(50, 40));
		l3.setOutlineColor(sf::Color::White);
		l3.setOutlineThickness(1);
		l3.setFillColor(sf::Color::Magenta);
		l4.setPosition(x3 - 50, y3);
		l4.setSize(sf::Vector2f(50, 40));
		l4.setOutlineColor(sf::Color::White);
		l4.setOutlineThickness(1);
		l4.setFillColor(sf::Color::Magenta);
	}
	void L_4(sf::RenderWindow& window)
	{
		l1.setPosition(x3, y3);
		l1.setSize(sf::Vector2f(50, 40));
		l1.setOutlineColor(sf::Color::White);
		l1.setOutlineThickness(1);
		l1.setFillColor(sf::Color::Magenta);
		l2.setPosition(x3 + 50, y3);
		l2.setSize(sf::Vector2f(50, 40));
		l2.setOutlineColor(sf::Color::White);
		l2.setOutlineThickness(1);
		l2.setFillColor(sf::Color::Magenta);
		l3.setPosition(x3 + 100, y3);
		l3.setSize(sf::Vector2f(50, 40));
		l3.setOutlineColor(sf::Color::White);
		l3.setOutlineThickness(1);
		l3.setFillColor(sf::Color::Magenta);
		l4.setPosition(x3, y3 + 40);
		l4.setSize(sf::Vector2f(50, 40));
		l4.setOutlineColor(sf::Color::White);
		l4.setOutlineThickness(1);
		l4.setFillColor(sf::Color::Magenta);
	}
	virtual void fill_block(sf::RenderWindow& window, int i, int j)
	{
		int hori = 10; int verti = 10;
		for (int k = 0; k < j; k++)
			hori += 50;
		for (int k = 0; k < i; k++)
			verti += 40;
		f.setPosition(hori, verti); f.setSize(sf::Vector2f(50, 40)); f.setOutlineColor(sf::Color::White); f.setOutlineThickness(1); f.setFillColor(sf::Color::Magenta);
	}
	virtual sf::RectangleShape get_f()
	{
		return f;
	}
	virtual void drawing(sf::RenderWindow& window)
	{
		if (angle == 0)
		{
			L_1(window);
			window.draw(l1);
			window.draw(l2);
			window.draw(l3);
			window.draw(l4);
		}
		else if (angle == 90)
		{
			L_2(window);
			window.draw(l1);
			window.draw(l2);
			window.draw(l3);
			window.draw(l4);
		}
		else if (angle == 270)
		{
			L_3(window);
			window.draw(l1);
			window.draw(l2);
			window.draw(l3);
			window.draw(l4);
		}
		else if (angle == 360)
		{
			L_4(window);
			window.draw(l1);
			window.draw(l2);
			window.draw(l3);
			window.draw(l4);
		}
	}
	void if_wanttoshiftat0()
	{
		if (d1 != 0)
			angle = 90;
		else
		{
			d1 = 1;
			y3 = 50;
			angle = 90;
		}
	}
	void ifshiftingatrightboundry()
	{
		if (lef1 + 1 == 9)
		{
			lef1 = 7;
			r1 = 8;
			x3 = 360;
			angle = 90;
		}
	}
	void ifshiftingatleftboundry()
	{
		if (lef1 >= 1)
		{
			angle = 270;
		}
		else
		{
			lef1 = 1;
			r1 = 2;
			x3 = 60;
			angle = 270;
		}
	}
	bool checkingleftblock(int** grid)
	{
		if (lef1 == 0)
			return false;
		if (grid[d1][lef1 - 1] != 0)
			return true;
		return false;
	}
	virtual void rotating(sf::RenderWindow& window, int** grid)
	{
		if (angle == 0)
		{
			x3 += 50; lef1++; r1++;

			if ((lef1 == 1) && (grid[d1][lef1 + 1] != 0))
			{
				angle = 0;
				x3 -= 50; lef1--; r1--;
			}
			else if ((lef1 >= 2 && lef1 < 9) && (grid[d1][lef1 + 1] != 0))
			{
				lef1 -= 2; r1 -= 2; x3 -= 100; angle = 90;
			}
			else if ((grid[d1][lef1 - 2] != 0) && (lef1 <= 8))
			{
				x3 -= 50; lef1--; r1--;
				angle = 90;
			}
			else if ((lef1 == 9) && (grid[d1][lef1 - 2] != 0))
			{
				angle = 0;
				x3 -= 50; lef1--; r1--;
			}
			else if (r1 == 10)
			{
				x3 = 360;
				lef1 = 7; r1 = 8; angle = 90;
			}

			else
			{
				if ((checkingleftblock(grid) == true) && (lef1 > 7))
				{
					angle = 0;
				}
				else if (checkingleftblock(grid) == true)
				{
					angle = 90;
				}
				else
				{
					if (lef1 == 0)
					{
						x3 += 50; lef1++; r1++; angle = 90;
					}
					if_wanttoshiftat0();
					ifshiftingatrightboundry();
					lef1--; r1--; x3 -= 50;
				}
			}
		}
		else if (angle == 90)
		{
			lef1++;
			x3 += 50;
			ifshiftingatleftboundry();
		}
		else if (angle == 270)
		{
			lef1--;
			x3 -= 50;
			if ((lef1 == 0) && (grid[d1][lef1 + 2] != 0))
			{
				lef1++;
				x3 += 50;
				r1++;
				angle = 270;
			}
			else if ((lef1 >= 1 && lef1 < 8) && (grid[d1][lef1 + 2] != 0))
			{
				lef1--; r1--; x3 -= 50; angle = 360;
			}
			else if ((lef1 == 8) && (grid[d1][lef1 - 1] != 0))
			{
				angle = 270;
				x3 += 50; lef1++; r1++;
			}
			else if (lef1 == 9)
			{
				lef1 = 7;
				r1 = 8;
				x3 = 360;
				angle = 360;
			}
			else if (lef1 == 8)
			{
				lef1 = 7;
				r1 = 8;
				x3 = 360;
				angle = 360;
			}
			else
				angle = 360;
		}
		else if (angle == 360)
		{
			/*lef1++; r1++; x3 += 50;*/ angle = 0;
		}
	}
	virtual void droping(sf::RenderWindow& window)
	{
		y3 += 40;
		if (d1 < 19)
			d1++;
	}
	virtual bool if_stop(int** grid, int left, int right)
	{
		if (angle == 0)
		{
			if (y3 == 730)
			{
				return true;
			}
			else if (d1 <= 17)
			{
				for (int i = lef1; i <= lef1 + 1; i++)
				{
					if (grid[d1 + 2][i] != 0)
						return true;
				}
				return false;
			}
		}
		else if (angle == 90)
		{
			if (y3 == 810)
			{
				return true;
			}
			else if (d1 < 19)
			{
				for (int i = lef1; i <= lef1 + 2; i++)
				{
					if (grid[d1 + 1][i] != 0)
						return true;
				}
				return false;
			}
		}
		else if (angle == 270)
		{
			if (y3 == 730)
			{
				return true;
			}
			else if (d1 <= 17)
			{

				for (int i = lef1; i < lef1 + 1; i++)
				{
					if (grid[d1 + 2][i] != 0)
						return true;
					else if (grid[d1][lef1 - 1] != 0)
						return true;
				}
				return false;
			}
		}
		else if (angle == 360)
		{
			if (y3 == 770)
			{
				return true;
			}
			else if (d1 <= 18)
			{
				for (int i = lef1 + 1; i <= lef1 + 2; i++)
				{
					if (grid[d1][i] != 0)
						return true;
					else if (grid[d1 + 1][lef1] != 0)
						return true;
				}
				return false;
			}
		}

	}
	virtual void put_val_in_grid(int** grid)
	{
		if (d1 > 0)
		{
			if (angle == 0)
			{
				d1 -= 1;
				if ((d1 <= 17) && (d1 >= 0))
				{
					for (int i = d1; i <= d1 + 2; i++)
					{
						grid[i][lef1] = 3;
					}
					grid[d1 + 2][r1] = 3;
				}
			}
			else if (angle == 90)
			{
				if (d1 <= 19)
				{
					for (int i = lef1; i <= lef1 + 2; i++)
						grid[d1][i] = 3;
				}
				else if (d1 == 20)
				{
					d1--;
					for (int i = lef1; i <= lef1 + 2; i++)
						grid[d1][i] = 3;
				}
				grid[d1 - 1][lef1 + 2] = 3;
			}
			else if (angle == 270)
			{
				d1 -= 1;
				if (d1 <= 17)
				{
					for (int i = d1; i <= d1 + 2; i++)
					{
						grid[i][lef1] = 3;
					}
					grid[d1][lef1 - 1] = 3;
				}
			}
			else if (angle == 360)
			{
				for (int i = lef1; i <= lef1 + 2; i++)
				{
					grid[d1 - 1][i] = 3;
				}
				grid[d1][lef1] = 3;
			}
			d1 = 0, d2 = 0; lef1 = 3, r1 = 4, lef2 = 4, r2 = 5; angle = 0; x3 = 160, y3 = 10;
		}
	}
	//left
	bool left_boundry_hori(int lef1, int c)
	{
		if ((lef1 > 0) && (c >= 10))
			return true;
		return false;
	}
	virtual bool leftblockcheck0(int** grid)
	{
		for (int i = d1; i <= d1 + 2; i++)
			if (grid[i][lef1 - 1] != 0)
				return false;
		return true;
	}
	virtual bool leftblockcheck1(int** grid)
	{
		if (grid[d1][lef1 - 1] != 0)
			return false;
		else if (grid[d1 - 1][lef1 + 1] != 0)
			return false;
		return true;
	}
	virtual bool leftblockcheck2(int** grid)
	{
		if (grid[d1][lef1 - 2] != 0)
			return false;
		else {
			for (int i = d1 + 1; i <= d1 + 2; i++)
				if (grid[i][lef1 - 1] != 0)
					return false;
		}
		return true;
	}
	virtual bool leftblockcheck3(int** grid)
	{
		for (int i = d1; i <= d1 + 1; i++)
			if (grid[i][lef1 - 1] != 0)
				return false;
		return true;
	}
	virtual void if_left(sf::RenderWindow& window, int** grid)
	{

		if (angle == 0)
		{
			if ((left_boundry_hori(lef1, x3) == true) && (leftblockcheck0(grid) == true))
			{
				lef1--, lef2--, r1--, r2--, x3 -= 50;
			}
		}
		else if (angle == 90)
		{
			if ((left_boundry_hori(lef1, x3) == true) && (leftblockcheck1(grid) == true))
			{
				lef1--, lef2--, r1--, r2--, x3 -= 50;
			}
		}
		else if (angle == 270)
		{
			if ((left_boundry_hori(lef1 - 1, x3) == true) && (leftblockcheck2(grid) == true))
			{
				lef1--, lef2--, r1--, r2--, x3 -= 50;
			}
		}
		else if (angle == 360)
		{
			if ((left_boundry_hori(lef1, x3) == true) && (leftblockcheck3(grid) == true))
			{
				lef1--, lef2--, r1--, r2--, x3 -= 50;
			}
		}

	}
	//right
	bool right_boundry_hori(int r1, int c)
	{
		if ((r1 <= 9) && (c <= 460))
			return true;
		return false;
	}
	virtual bool rightblockcheck0(int** grid)
	{
		for (int i = d1; i <= d1 + 1; i++)
			if (grid[i][r1] != 0)
				return false;
		if (grid[d1 + 2][r1 + 1] != 0)
			return false;
		return true;
	}
	virtual bool rightblockcheck1(int** grid)
	{
		for (int i = d1; i >= d1 - 1; i--)
			if (grid[i][r1 + 2] != 0)
				return false;
		return true;
	}
	virtual bool rightblockcheck2(int** grid)
	{
		for (int i = d1; i <= d1 + 2; i++)
			if (grid[i][r1 + 1] != 0)
				return false;
		return true;
	}
	virtual bool rightblockcheck3(int** grid)
	{
		if (grid[d1][r1 + 2] != 0)
			return false;
		else if (grid[d1 + 1][lef1 + 1] != 0)
			return false;
		return true;
	}
	virtual void if_right(sf::RenderWindow& window, int** grid)
	{

		if (angle == 0)
		{
			if ((right_boundry_hori(r1 + 1, x3) == true) && (rightblockcheck0(grid) == true))
			{
				lef1++, lef2++, r1++, r2++, x3 += 50;
			}
		}
		else if (angle == 90)
		{
			if ((right_boundry_hori(r1 + 2, x3) == true) && (rightblockcheck1(grid) == true))
			{
				lef1++, lef2++, r1++, r2++, x3 += 50;
			}
		}
		else if (angle == 270)
		{
			if ((right_boundry_hori(r1 + 1, x3) == true) && (rightblockcheck2(grid) == true))
			{
				lef1++, lef2++, r1++, r2++, x3 += 50;
			}
		}
		else if (angle == 360)
		{
			if ((right_boundry_hori(r1 + 2, x3) == true) && (rightblockcheck3(grid) == true))
			{
				lef1++, lef2++, r1++, r2++, x3 += 50;
			}
		}

	}
	~L()
	{
	}
};
class J :public tetrimino
{
	sf::RectangleShape j1, j2, j3, j4, f;
	int x4, y4, angle, d1, l, r;
public:
	J()
	{
		d1 = 0; l = 5; r = 6; angle = 0; x4 = 260, y4 = 10;
	}
	void nextshape(sf::RenderWindow& window)
	{
		int a = 720, b = 580;
		j1.setPosition(a, b);
		j1.setSize(sf::Vector2f(50, 40));
		j1.setOutlineColor(sf::Color::White);
		j1.setOutlineThickness(1);
		j1.setFillColor(sf::Color::Blue);
		j2.setPosition(a, b + 40);
		j2.setSize(sf::Vector2f(50, 40));
		j2.setOutlineColor(sf::Color::White);
		j2.setOutlineThickness(1);
		j2.setFillColor(sf::Color::Blue);
		j3.setPosition(a, b + 80);
		j3.setSize(sf::Vector2f(50, 40));
		j3.setOutlineColor(sf::Color::White);
		j3.setOutlineThickness(1);
		j3.setFillColor(sf::Color::Blue);
		j4.setPosition(a - 50, b + 80);
		j4.setSize(sf::Vector2f(50, 40));
		j4.setOutlineColor(sf::Color::White);
		j4.setOutlineThickness(1);
		j4.setFillColor(sf::Color::Blue);
		window.draw(j1);
		window.draw(j2);
		window.draw(j3);
		window.draw(j4);
	}
	virtual void fill_block(sf::RenderWindow& window, int i, int j)
	{
		int hori = 10, verti = 10;
		for (int k = 0; k < j; k++)
			hori += 50;
		for (int k = 0; k < i; k++)
			verti += 40;
		f.setPosition(hori, verti); f.setSize(sf::Vector2f(50, 40)); f.setOutlineColor(sf::Color::White); f.setOutlineThickness(1); f.setFillColor(sf::Color::Blue);
	}
	virtual sf::RectangleShape get_f()
	{
		return f;
	}
	void J_1(sf::RenderWindow& window)
	{
		j1.setPosition(x4, y4);
		j1.setSize(sf::Vector2f(50, 40));
		j1.setOutlineColor(sf::Color::White);
		j1.setOutlineThickness(1);
		j1.setFillColor(sf::Color::Blue);
		j2.setPosition(x4, y4 + 40);
		j2.setSize(sf::Vector2f(50, 40));
		j2.setOutlineColor(sf::Color::White);
		j2.setOutlineThickness(1);
		j2.setFillColor(sf::Color::Blue);
		j3.setPosition(x4, y4 + 80);
		j3.setSize(sf::Vector2f(50, 40));
		j3.setOutlineColor(sf::Color::White);
		j3.setOutlineThickness(1);
		j3.setFillColor(sf::Color::Blue);
		j4.setPosition(x4 - 50, y4 + 80);
		j4.setSize(sf::Vector2f(50, 40));
		j4.setOutlineColor(sf::Color::White);
		j4.setOutlineThickness(1);
		j4.setFillColor(sf::Color::Blue);
	}
	void J_2(sf::RenderWindow& window)
	{
		j1.setPosition(x4, y4);
		j1.setSize(sf::Vector2f(50, 40));
		j1.setOutlineColor(sf::Color::White);
		j1.setOutlineThickness(1);
		j1.setFillColor(sf::Color::Blue);
		j2.setPosition(x4 + 50, y4);
		j2.setSize(sf::Vector2f(50, 40));
		j2.setOutlineColor(sf::Color::White);
		j2.setOutlineThickness(1);
		j2.setFillColor(sf::Color::Blue);
		j3.setPosition(x4 + 100, y4);
		j3.setSize(sf::Vector2f(50, 40));
		j3.setOutlineColor(sf::Color::White);
		j3.setOutlineThickness(1);
		j3.setFillColor(sf::Color::Blue);
		j4.setPosition(x4 + 100, y4 + 40);
		j4.setSize(sf::Vector2f(50, 40));
		j4.setOutlineColor(sf::Color::White);
		j4.setOutlineThickness(1);
		j4.setFillColor(sf::Color::Blue);
	}
	void J_3(sf::RenderWindow& window)
	{
		j1.setPosition(x4, y4);
		j1.setSize(sf::Vector2f(50, 40));
		j1.setOutlineColor(sf::Color::White);
		j1.setOutlineThickness(1);
		j1.setFillColor(sf::Color::Blue);
		j2.setPosition(x4, y4 + 40);
		j2.setSize(sf::Vector2f(50, 40));
		j2.setOutlineColor(sf::Color::White);
		j2.setOutlineThickness(1);
		j2.setFillColor(sf::Color::Blue);
		j3.setPosition(x4, y4 + 80);
		j3.setSize(sf::Vector2f(50, 40));
		j3.setOutlineColor(sf::Color::White);
		j3.setOutlineThickness(1);
		j3.setFillColor(sf::Color::Blue);
		j4.setPosition(x4 + 50, y4);
		j4.setSize(sf::Vector2f(50, 40));
		j4.setOutlineColor(sf::Color::White);
		j4.setOutlineThickness(1);
		j4.setFillColor(sf::Color::Blue);
	}
	void J_4(sf::RenderWindow& window)
	{
		j1.setPosition(x4, y4);
		j1.setSize(sf::Vector2f(50, 40));
		j1.setOutlineColor(sf::Color::White);
		j1.setOutlineThickness(1);
		j1.setFillColor(sf::Color::Blue);
		j2.setPosition(x4 + 50, y4);
		j2.setSize(sf::Vector2f(50, 40));
		j2.setOutlineColor(sf::Color::White);
		j2.setOutlineThickness(1);
		j2.setFillColor(sf::Color::Blue);
		j3.setPosition(x4 + 100, y4);
		j3.setSize(sf::Vector2f(50, 40));
		j3.setOutlineColor(sf::Color::White);
		j3.setOutlineThickness(1);
		j3.setFillColor(sf::Color::Blue);
		j4.setPosition(x4, y4 - 40);
		j4.setSize(sf::Vector2f(50, 40));
		j4.setOutlineColor(sf::Color::White);
		j4.setOutlineThickness(1);
		j4.setFillColor(sf::Color::Blue);
	}
	virtual void drawing(sf::RenderWindow& window)
	{
		if (angle == 0)
		{
			J_1(window);
			window.draw(j1);
			window.draw(j2);
			window.draw(j3);
			window.draw(j4);
		}
		else if (angle == 90)
		{
			J_2(window);
			window.draw(j1);
			window.draw(j2);
			window.draw(j3);
			window.draw(j4);
		}
		else if (angle == 270)
		{
			J_3(window);
			window.draw(j1);
			window.draw(j2);
			window.draw(j3);
			window.draw(j4);
		}
		else if (angle == 360)
		{
			J_4(window);
			window.draw(j1);
			window.draw(j2);
			window.draw(j3);
			window.draw(j4);
		}
	}
	bool checkforrightblock(int** grid)
	{
		for (int i = d1; i <= d1 + 2; i++)
			if ((grid[i][r + 1] != 0) && (l == 1))
				return true;
		if (l >= 1)
		{
			l--; r--; x4 -= 50;
			return false;
		}
		return false;
	}
	bool checkforright270(int** grid)
	{
		if (grid[d1][r + 1] != 0)
			return true;
		return false;
	}
	virtual void rotating(sf::RenderWindow& window, int** grid)
	{
		if (angle == 0)
		{
			if ((l <= 8 && l > 1) && (grid[d1][l - 2] != 0))
			{
				x4 -= 50; l--; r--; angle = 90;
			}
			else if ((l == 9) && (grid[d1][l - 2] != 0))
			{
				angle = 0;
			}
			else if ((l == 1) && (checkforrightblock(grid) == true))
			{
				angle = 0;
			}
			else if (l == 0)
			{
				x4 = 10; l = 0; r = 1; angle = 90;

			}
			else
			{
				if (checkforrightblock(grid) == true)
				{
					angle = 0;
				}
				else
				{
					if (l <= 7)
					{
						l--; r--; x4 -= 50; angle = 90;
					}
					else
					{
						l = 7; r = 8; x4 = 360; angle = 90;
					}
				}
			}
		}
		else if (angle == 90)
		{
			x4 += 50; l++; r++;
			angle = 270;
		}
		else if (angle == 270)
		{
			if ((l == 8) && (grid[d1][l - 1] != 0))
			{
				angle = 270;
			}
			else if ((l == 0) && (checkforright270(grid) == true))
			{
				angle = 270;
			}
			else if (l == 0)
			{
				x4 = 10; l = 0; r = 1; angle = 360;
			}
			else
			{
				if (checkforright270(grid) == true)
				{
					x4 -= 50; l--; r--;
				}
				if (l < 8)
					angle = 360;
				else
				{
					l = 7; r = 8; x4 = 360; angle = 360;
				}
			}
		}
		else if (angle == 360)
		{
			if (l != 0)
			{
				l++; r++; x4 += 50; angle = 0;
			}
			else
			{
				l = 1; r = 2; x4 = 60; angle = 0;
			}
		}
	}
	virtual void droping(sf::RenderWindow& window)
	{
		y4 += 40;
		if (d1 < 19)
			d1++;
	}
	virtual bool if_stop(int** grid, int left, int right)
	{
		if (angle == 0)
		{
			if (y4 == 730)
				return true;
			else if (d1 <= 17)
			{
				for (int i = l; i >= l - 1; i--)
					if (grid[d1 + 2][i] != 0)
						return true;
				return false;
			}
		}
		else if (angle == 90)
		{
			if (y4 == 770)
				return true;
			else if (d1 < 19)
			{
				for (int i = l; i <= l + 2; i++)
				{
					if (grid[d1][i] != 0)
						return true;
					else if (grid[d1 + 1][l + 2] != 0)
						return true;
				}
				return false;
			}
		}
		else if (angle == 270)
		{
			if (y4 == 730)
				return true;
			else if (d1 <= 17)
			{
				for (int i = l; i < l + 1; i++)
				{
					if (grid[d1 + 2][i] != 0)
						return true;
					else if (grid[d1][l + 1] != 0)
						return true;
				}
				return false;
			}
		}
		else if (angle == 360)
		{
			if (y4 == 810)
				return true;
			else if (d1 < 19)
			{
				for (int i = l; i <= l + 2; i++)
					if (grid[d1 + 1][i] != 0)
						return true;
				return false;
			}
			else if (d1 >= 19)
			{
				d1--;
				for (int i = l; i <= l + 2; i++)
					if (grid[d1][i] != 0)
						return true;
				return false;
			}
		}

	}
	virtual void put_val_in_grid(int** grid)
	{
		if (d1 > 0)
		{
			if (angle == 0)
			{
				d1 -= 1;
				if (d1 <= 17)
				{
					for (int i = d1; i <= d1 + 2; i++)
					{
						grid[i][l] = 4;
					}
					grid[d1 + 2][l - 1] = 4;
				}
			}
			else if (angle == 90)
			{
				d1 -= 1;
				if (d1 < 19)
				{
					for (int i = l; i <= l + 2; i++)
					{
						grid[d1][i] = 4;
					}
					grid[d1 + 1][l + 2] = 4;
				}
			}
			else if (angle == 270)
			{
				d1 -= 1;
				if (d1 <= 17)
				{
					for (int i = d1; i <= d1 + 2; i++)
					{
						grid[i][l] = 4;
					}
					grid[d1][l + 1] = 4;
				}
			}
			else if (angle == 360)
			{
				d1 -= 1;
				if (d1 < 19)
				{
					for (int i = l; i <= l + 2; i++)
					{
						grid[d1 + 1][i] = 4;
					}
					grid[d1][l] = 4;
				}
			}
			d1 = 0; l = 5; r = 6; angle = 0; x4 = 260, y4 = 10;
		}
	}
	bool left_boundry_hori(int lef1, int c)
	{
		if ((lef1 > 0) && (c >= 10))
			return true;
		return false;
	}
	//left
	virtual bool leftblockcheck0(int** grid)
	{
		for (int i = d1; i <= d1 + 1; i++)
		{
			if (grid[i][l - 1] != 0)
				return false;
			else if (grid[d1 + 2][l - 2] != 0)
				return false;
		}
		return true;
	}
	virtual bool leftblockcheck1(int** grid)
	{
		if (grid[d1][l - 1] != 0)
			return false;
		else if (grid[d1 + 1][l + 1] != 0)
			return false;
		return true;
	}
	virtual bool leftblockcheck2(int** grid)
	{
		for (int i = d1; i <= d1 + 2; i++)
			if (grid[i][l - 1] != 0)
				return false;
		return true;
	}
	virtual bool leftblockcheck3(int** grid)
	{
		if (y4 == 770)
		{
			if (grid[18][l - 1] != 0)
				return false;
			else if (grid[19][l - 1] != 0)
				return false;
			return true;
		}
		for (int i = d1; i >= d1 - 1; i--)
			if (grid[i][l - 1] != 0)
				return false;
		return true;
	}
	virtual void if_left(sf::RenderWindow& window, int** grid)
	{
		if (angle == 0)
		{
			if ((left_boundry_hori(l - 1, x4) == true) && (leftblockcheck0(grid) == true))
			{
				l--, r--, x4 -= 50;
			}
		}
		else if (angle == 90)
		{
			if ((left_boundry_hori(l, x4) == true) && (leftblockcheck1(grid) == true))
			{
				l--, r--, x4 -= 50;
			}
		}
		else if (angle == 270)
		{
			if ((left_boundry_hori(l, x4) == true) && (leftblockcheck2(grid) == true))
			{
				l--, r--, x4 -= 50;
			}
		}
		else if (angle == 360)
		{
			if ((left_boundry_hori(l, x4) == true) && (leftblockcheck3(grid) == true))
			{
				l--, r--, x4 -= 50;
			}
		}

	}
	//right
	virtual bool rightblockcheck0(int** grid)
	{
		for (int i = d1; i <= d1 + 2; i++)
			if (grid[i][r] != 0)
				return false;
		return true;
	}
	virtual bool rightblockcheck1(int** grid)
	{
		for (int i = d1; i <= d1 + 1; i++)
			if (grid[i][l + 3] != 0)
				return false;
		return true;
	}
	virtual bool rightblockcheck2(int** grid)
	{
		for (int i = d1 + 1; i <= d1 + 2; i++)
		{
			if (grid[i][r] != 0)
				return false;
			else if (grid[d1][l + 2] != 0)
				return false;
		}
		return true;
	}
	virtual bool rightblockcheck3(int** grid)
	{
		if (y4 == 770)
		{
			if (grid[19][l + 3] != 0)
				return false;
			else if (grid[18][l + 1] != 0)
				return false;
			return true;
		}
		if (grid[d1][l + 3] != 0)
			return false;
		else if (grid[d1 - 1][l + 1] != 0)
			return false;
		return true;
	}
	bool right_boundry_hori(int r1, int c)
	{
		if ((r1 <= 9) && (c <= 460))
			return true;
		return false;
	}
	virtual void if_right(sf::RenderWindow& window, int** grid)
	{
		if (angle == 0)
		{
			if ((right_boundry_hori(r, x4) == true) && (rightblockcheck0(grid) == true))
			{
				l++, r++, x4 += 50;
			}
		}
		else if (angle == 90)
		{
			if ((right_boundry_hori(r + 2, x4) == true) && (rightblockcheck1(grid) == true))
			{
				l++, r++, x4 += 50;
			}
		}
		else if (angle == 270)
		{
			if ((right_boundry_hori(r + 1, x4) == true) && (rightblockcheck2(grid) == true))
			{
				l++, r++, x4 += 50;
			}
		}
		else if (angle == 360)
		{
			if ((right_boundry_hori(r + 2, x4) == true) && (rightblockcheck3(grid) == true))
			{
				l++, r++, x4 += 50;
			}
		}
	}
	~J()
	{}
};
class S :public tetrimino
{
	sf::RectangleShape s1, s2, s3, s4, f;
	int x5, y5, angle, d1, l, r;
public:
	S()
	{
		d1 = 0; angle = 0; l = 5; r = 6; x5 = 260, y5 = 10;
	}
	void nextshape(sf::RenderWindow& window)
	{
		int a = 720, b = 580;
		s1.setPosition(a, b);
		s1.setSize(sf::Vector2f(50, 40));
		s1.setOutlineColor(sf::Color::White);
		s1.setOutlineThickness(1);
		s1.setFillColor(sf::Color::Green);
		s2.setPosition(a + 50, b);
		s2.setSize(sf::Vector2f(50, 40));
		s2.setOutlineColor(sf::Color::White);
		s2.setOutlineThickness(1);
		s2.setFillColor(sf::Color::Green);
		s3.setPosition(a, b + 40);
		s3.setSize(sf::Vector2f(50, 40));
		s3.setOutlineColor(sf::Color::White);
		s3.setOutlineThickness(1);
		s3.setFillColor(sf::Color::Green);
		s4.setPosition(a - 50, b + 40);
		s4.setSize(sf::Vector2f(50, 40));
		s4.setOutlineColor(sf::Color::White);
		s4.setOutlineThickness(1);
		s4.setFillColor(sf::Color::Green);
		window.draw(s1);
		window.draw(s2);
		window.draw(s3);
		window.draw(s4);
	}
	void S_hori(sf::RenderWindow& window)
	{
		s1.setPosition(x5, y5);
		s1.setSize(sf::Vector2f(50, 40));
		s1.setOutlineColor(sf::Color::White);
		s1.setOutlineThickness(1);
		s1.setFillColor(sf::Color::Green);
		s2.setPosition(x5 + 50, y5);
		s2.setSize(sf::Vector2f(50, 40));
		s2.setOutlineColor(sf::Color::White);
		s2.setOutlineThickness(1);
		s2.setFillColor(sf::Color::Green);
		s3.setPosition(x5, y5 + 40);
		s3.setSize(sf::Vector2f(50, 40));
		s3.setOutlineColor(sf::Color::White);
		s3.setOutlineThickness(1);
		s3.setFillColor(sf::Color::Green);
		s4.setPosition(x5 - 50, y5 + 40);
		s4.setSize(sf::Vector2f(50, 40));
		s4.setOutlineColor(sf::Color::White);
		s4.setOutlineThickness(1);
		s4.setFillColor(sf::Color::Green);
	}
	void S_vert(sf::RenderWindow& window)
	{
		s1.setPosition(x5, y5);
		s1.setSize(sf::Vector2f(50, 40));
		s1.setOutlineColor(sf::Color::White);
		s1.setOutlineThickness(1);
		s1.setFillColor(sf::Color::Green);
		s2.setPosition(x5, y5 + 40);
		s2.setSize(sf::Vector2f(50, 40));
		s2.setOutlineColor(sf::Color::White);
		s2.setOutlineThickness(1);
		s2.setFillColor(sf::Color::Green);
		s3.setPosition(x5 + 50, y5 + 40);
		s3.setSize(sf::Vector2f(50, 40));
		s3.setOutlineColor(sf::Color::White);
		s3.setOutlineThickness(1);
		s3.setFillColor(sf::Color::Green);
		s4.setPosition(x5 + 50, y5 + 80);
		s4.setSize(sf::Vector2f(50, 40));
		s4.setOutlineColor(sf::Color::White);
		s4.setOutlineThickness(1);
		s4.setFillColor(sf::Color::Green);
	}
	virtual void drawing(sf::RenderWindow& window)
	{
		if ((angle == 0) || (angle == 270))
		{
			S_hori(window);
			window.draw(s1);
			window.draw(s2);
			window.draw(s3);
			window.draw(s4);
		}
		else if ((angle == 90) || (angle == 360))
		{
			S_vert(window);
			window.draw(s1);
			window.draw(s2);
			window.draw(s3);
			window.draw(s4);
		}

	}
	virtual void rotating(sf::RenderWindow& window, int** grid)
	{
		if (angle == 0)
		{
			y5 += 40; d1 += 1; angle = 90; x5 -= 50; l -= 1; r -= 1;
		}
		else if (angle == 90)
		{
			if ((l == 8) && (grid[d1][l - 1] != 0))
			{
				angle = 90;
			}
			else if ((l == 0) && (grid[d1][r + 1] != 0))
			{
				angle = 90;
			}
			else if (grid[d1][r + 1] != 0)
			{
				/*l -= 1; r -= 1; x5 -= 50; y5 -= 40;*/ angle = 270;
			}
			else
			{
				if (l == 8)
				{
					l -= 1; r -= 1; x5 -= 50;
				}
				angle = 270; l += 1; r += 1; x5 += 50;
			}
		}
		else if (angle == 270)
		{
			angle = 360; l -= 1; r -= 1; x5 -= 50; y5 -= 40; d1 -= 1;
		}
		else if (angle == 360)
		{
			if ((l == 8) && (grid[d1][l - 1] != 0))
			{
				angle = 90;
			}
			else if ((l == 0) && (grid[d1][r + 1] != 0))
			{
				angle = 360;
			}
			else if (grid[d1][r + 1] != 0)
			{
				/*l -= 1; r -= 1; x5 -= 50; y5 -= 40;*/ angle = 0;
			}
			else
			{
				if (l == 8)
				{
					l -= 1; r -= 1; x5 -= 50;
				}
				angle = 0; l += 1; r += 1; x5 += 50;
			}
		}
	}
	virtual void fill_block(sf::RenderWindow& window, int i, int j)
	{
		int hori = 10, verti = 10;
		for (int k = 0; k < j; k++)
			hori += 50;
		for (int k = 0; k < i; k++)
			verti += 40;
		f.setPosition(hori, verti); f.setSize(sf::Vector2f(50, 40)); f.setOutlineColor(sf::Color::White); f.setOutlineThickness(1); f.setFillColor(sf::Color::Green);

	}
	virtual sf::RectangleShape get_f()
	{
		return f;
	}
	virtual void droping(sf::RenderWindow& window)
	{
		y5 += 40;
		if (d1 < 19)
			d1++;
	}
	virtual bool if_stop(int** grid, int left, int right)
	{
		if ((angle == 0) || (angle == 270))
		{
			if (y5 == 770)
				return true;
			else if (d1 <= 18)
			{
				if (grid[d1][l + 1] != 0)
					return true;
				for (int i = l; i >= l - 1; i--)
					if (grid[d1 + 1][i] != 0)
						return true;
				return false;
			}
		}
		else if ((angle == 90) || (angle == 360))
		{
			if (y5 == 730)
				return true;
			else if (d1 <= 17)
			{
				if (grid[d1 + 1][l] != 0)
					return true;
				else if (grid[d1 + 2][l + 1] != 0)
					return true;
				return false;
			}
		}
	}
	virtual void put_val_in_grid(int** grid)
	{
		if (d1 > 0)
		{
			if ((angle == 0) || (angle == 270))
			{
				d1 -= 1;
				if ((d1 <= 18) && (d1 >= 0))
				{
					for (int i = l; i <= l + 1; i++)
					{
						grid[d1][i] = 5;
						grid[d1 + 1][i - 1] = 5;
					}
				}
			}
			else if ((angle == 90) || (angle == 360))
			{
				if (d1 <= 18)
				{
					d1 -= 1;
					grid[d1][l] = 5; grid[d1 + 1][l] = 5; grid[d1 + 1][l + 1] = 5; grid[d1 + 2][l + 1] = 5;
				}
			}
			d1 = 0; angle = 0; l = 5; r = 6; x5 = 260, y5 = 10;
		}
	}
	//left
	bool left_boundry_hori(int lef1, int c)
	{
		if ((lef1 > 0) && (c >= 10))
			return true;
		return false;
	}
	virtual bool leftblockcheck0(int** grid)
	{
		if (grid[d1][l - 1] != 0)
			return false;
		else if (grid[d1 + 1][l - 2] != 0)
			return false;
		return true;
	}
	virtual bool leftblockcheck1(int** grid)
	{
		for (int i = d1; i <= d1 + 1; i++)
			if (grid[i][l - 1] != 0)
				return false;
		if (grid[d1 + 2][l] != 0)
			return false;
		return true;
	}
	virtual void if_left(sf::RenderWindow& window, int** grid)
	{
		if ((angle == 0) || (angle == 270))
		{
			if ((left_boundry_hori(l - 1, x5) == true) && (leftblockcheck0(grid) == true))
			{
				l--, r--, x5 -= 50;
			}
		}
		else if ((angle == 90) || (angle == 360))
		{
			if ((left_boundry_hori(l, x5) == true) && (leftblockcheck1(grid) == true))
			{
				l--, r--, x5 -= 50;
			}
		}
	}
	//right
	bool right_boundry_hori(int r1, int c)
	{
		if ((r1 <= 9) && (c <= 460))
			return true;
		return false;
	}
	virtual bool rightblockcheck0(int** grid)
	{
		if (grid[d1][l + 2] != 0)
			return false;
		else if (grid[d1 + 1][l + 1] != 0)
			return false;

		return true;
	}
	virtual bool rightblockcheck1(int** grid)
	{
		for (int i = d1 + 1; i <= d1 + 2; i++)
			if (grid[i][l + 2] != 0)
				return false;
		if (grid[d1][l + 1] != 0)
			return false;
		return true;
	}
	virtual void if_right(sf::RenderWindow& window, int** grid)
	{
		if ((angle == 0) || (angle == 270))
		{
			if ((right_boundry_hori(r + 1, x5) == true) && (rightblockcheck0(grid) == true))
			{
				l++, r++, x5 += 50;
			}
		}
		else if ((angle == 90) || (angle == 360))
		{
			if ((right_boundry_hori(r + 1, x5) == true) && (rightblockcheck1(grid) == true))
			{
				l++, r++, x5 += 50;
			}
		}
	}
	~S()
	{}
};
class Z :public tetrimino
{
	sf::RectangleShape z1, z2, z3, z4, f;
	int x6, y6, angle, l, r, d1;
public:
	Z()
	{
		l = 3; r = 4; d1 = 0; angle = 0; x6 = 160, y6 = 10;
	}
	void nextshape(sf::RenderWindow& window)
	{
		int a = 720, b = 580;
		z1.setPosition(a, b);
		z1.setSize(sf::Vector2f(50, 40));
		z1.setOutlineColor(sf::Color::White);
		z1.setOutlineThickness(1);
		z1.setFillColor(sf::Color::Red);
		z2.setPosition(a, b + 40);
		z2.setSize(sf::Vector2f(50, 40));
		z2.setOutlineColor(sf::Color::White);
		z2.setOutlineThickness(1);
		z2.setFillColor(sf::Color::Red);
		z3.setPosition(a - 50, b + 40);
		z3.setSize(sf::Vector2f(50, 40));
		z3.setOutlineColor(sf::Color::White);
		z3.setOutlineThickness(1);
		z3.setFillColor(sf::Color::Red);
		z4.setPosition(a - 50, b + 80);
		z4.setSize(sf::Vector2f(50, 40));
		z4.setOutlineColor(sf::Color::White);
		z4.setOutlineThickness(1);
		z4.setFillColor(sf::Color::Red);
		window.draw(z1);
		window.draw(z2);
		window.draw(z3);
		window.draw(z4);
	}
	void Z_vert(sf::RenderWindow& window)
	{
		z1.setPosition(x6, y6);
		z1.setSize(sf::Vector2f(50, 40));
		z1.setOutlineColor(sf::Color::White);
		z1.setOutlineThickness(1);
		z1.setFillColor(sf::Color::Red);
		z2.setPosition(x6, y6 + 40);
		z2.setSize(sf::Vector2f(50, 40));
		z2.setOutlineColor(sf::Color::White);
		z2.setOutlineThickness(1);
		z2.setFillColor(sf::Color::Red);
		z3.setPosition(x6 - 50, y6 + 40);
		z3.setSize(sf::Vector2f(50, 40));
		z3.setOutlineColor(sf::Color::White);
		z3.setOutlineThickness(1);
		z3.setFillColor(sf::Color::Red);
		z4.setPosition(x6 - 50, y6 + 80);
		z4.setSize(sf::Vector2f(50, 40));
		z4.setOutlineColor(sf::Color::White);
		z4.setOutlineThickness(1);
		z4.setFillColor(sf::Color::Red);
	}
	void Z_hori(sf::RenderWindow& window)
	{
		z1.setPosition(x6, y6);
		z1.setSize(sf::Vector2f(50, 40));
		z1.setOutlineColor(sf::Color::White);
		z1.setOutlineThickness(1);
		z1.setFillColor(sf::Color::Red);
		z2.setPosition(x6 + 50, y6);
		z2.setSize(sf::Vector2f(50, 40));
		z2.setOutlineColor(sf::Color::White);
		z2.setOutlineThickness(1);
		z2.setFillColor(sf::Color::Red);
		z3.setPosition(x6 + 50, y6 + 40);
		z3.setSize(sf::Vector2f(50, 40));
		z3.setOutlineColor(sf::Color::White);
		z3.setOutlineThickness(1);
		z3.setFillColor(sf::Color::Red);
		z4.setPosition(x6 + 100, y6 + 40);
		z4.setSize(sf::Vector2f(50, 40));
		z4.setOutlineColor(sf::Color::White);
		z4.setOutlineThickness(1);
		z4.setFillColor(sf::Color::Red);
	}
	virtual void drawing(sf::RenderWindow& window)
	{
		if ((angle == 0) || (angle == 270))
		{
			Z_hori(window);
			window.draw(z1);
			window.draw(z2);
			window.draw(z3);
			window.draw(z4);
		}
		else if ((angle == 90) || (angle == 360))
		{
			Z_vert(window);
			window.draw(z1);
			window.draw(z2);
			window.draw(z3);
			window.draw(z4);
		}
	}
	virtual void put_val_in_grid(int** grid)
	{
		if (d1 > 0)
		{
			if ((angle == 0) || (angle == 270))
			{
				d1 -= 1;
				if (d1 <= 18)
				{
					for (int i = l; i <= l + 1; i++)
					{
						grid[d1][i] = 6;
						grid[d1 + 1][i + 1] = 6;
					}
				}
			}
			else if ((angle == 90) || (angle == 360))
			{
				if (d1 <= 18)
				{
					d1 -= 1;
					grid[d1][l] = 6; grid[d1 + 1][l] = 6; grid[d1 + 1][l - 1] = 6; grid[d1 + 2][l - 1] = 6;
				}
			}
			l = 3; r = 4; d1 = 0; angle = 0; x6 = 160, y6 = 10;
		}
	}
	virtual void droping(sf::RenderWindow& window)
	{
		y6 += 40;
		if (d1 < 19)
			d1++;
	}
	virtual void fill_block(sf::RenderWindow& window, int i, int j)
	{
		int hori = 10, verti = 10;
		for (int k = 0; k < j; k++)
			hori += 50;
		for (int k = 0; k < i; k++)
			verti += 40;
		f.setPosition(hori, verti); f.setSize(sf::Vector2f(50, 40)); f.setOutlineColor(sf::Color::White); f.setOutlineThickness(1); f.setFillColor(sf::Color::Red);
	}
	virtual sf::RectangleShape get_f()
	{
		return f;
	}
	virtual void rotating(sf::RenderWindow& window, int** grid)
	{
		if (angle == 0)
		{
			angle = 90; l += 1; r += 1; x6 += 50;
		}
		else if (angle == 90)
		{
			if ((l == 9) && (grid[d1][l - 2] != 0))
			{
				angle = 90;
			}
			else if (l == 9)
			{
				l -= 1; r -= 1; x6 -= 50;
				angle = 270; l -= 1; r -= 1; x6 -= 50;
			}
			else if ((l == 1) && (grid[d1][r + 1] != 0))
			{
				angle = 90;
			}
			else if ((l >= 1) && (grid[d1][r + 1] != 0))
			{
				l -= 2; r -= 2; x6 -= 100;
				angle = 270;
			}
			else
			{
				angle = 270; l -= 1; r -= 1; x6 -= 50;
			}
		}
		else if (angle == 270)
		{
			angle = 360; l += 1; r += 1; x6 += 50;
		}
		else if (angle == 360)
		{
			if ((l == 9) && (grid[d1][l - 2] != 0))
			{
				angle = 360;
			}
			else if (l == 9)
			{
				angle = 0; l -= 2; r -= 2; x6 -= 100;
			}
			else if ((l == 1) && (grid[d1][r + 1] != 0))
			{
				x6 += 50; l++; r++;
				angle = 360;
			}
			else
			{
				angle = 0; l -= 1; r -= 1; x6 -= 50;
			}
		}
	}
	virtual bool if_stop(int** grid, int left, int right)
	{
		if ((angle == 0) || (angle == 270))
		{
			if (y6 == 770)
				return true;
			else if (d1 <= 18)
			{
				for (int i = l + 1; i <= l + 2; i++)
					if (grid[d1 + 1][i] != 0)
						return true;
				if (grid[d1][l] != 0)
					return true;
				return false;
			}
		}
		else if ((angle == 90) || (angle == 360))
		{
			if (y6 == 730)
				return true;
			else if (d1 <= 17)
			{
				if (grid[d1 + 1][l] != 0)
					return true;
				else if (grid[d1 + 2][l - 1] != 0)
					return true;
				return false;
			}

		}
	}
	//left
	bool left_boundry_hori(int lef1, int c)
	{
		if ((lef1 > 0) && (c >= 10))
			return true;
		return false;
	}
	virtual bool leftblockcheck0(int** grid)
	{
		if (grid[d1][l - 1] != 0)
			return false;
		else if (grid[d1 + 1][l] != 0)
			return false;
		return true;
	}
	virtual bool leftblockcheck1(int** grid)
	{
		for (int i = d1 + 1; i <= d1 + 2; i++)
			if (grid[i][l - 2] != 0)
				return false;
		if (grid[d1][l - 1] != 0)
			return false;
		return true;
	}
	virtual void if_left(sf::RenderWindow& window, int** grid)
	{
		if ((angle == 0) || (angle == 270))
		{
			if ((left_boundry_hori(l, x6) == true) && (leftblockcheck0(grid) == true))
			{
				l--, r--, x6 -= 50;
			}
		}
		else if ((angle == 90) || (angle == 360))
		{
			if ((left_boundry_hori(l - 1, x6) == true) && (leftblockcheck1(grid) == true))
			{
				if (leftblockcheck1(grid) == true)
				{
					l--, r--, x6 -= 50;
				}
			}
		}
	}
	//right
	bool right_boundry_hori(int r1, int c)
	{
		if ((r1 <= 9) && (c <= 460))
			return true;
		return false;
	}
	virtual bool rightblockcheck0(int** grid)
	{
		if (grid[d1][l + 2] != 0)
			return false;
		else if (grid[d1 + 1][l + 3] != 0)
			return false;

		return true;
	}
	virtual bool rightblockcheck1(int** grid)
	{
		for (int i = d1; i <= d1 + 1; i++)
			if (grid[i][l + 1] != 0)
				return false;
		if (grid[d1 + 2][l] != 0)
			return false;
		return true;
	}
	virtual void if_right(sf::RenderWindow& window, int** grid)
	{
		if ((angle == 0) || (angle == 270))
		{
			if ((right_boundry_hori(r + 2, x6) == true) && (rightblockcheck0(grid) == true))
			{
				l++, r++, x6 += 50;
			}
		}
		else if ((angle == 90) || (angle == 360))
		{
			if ((right_boundry_hori(r, x6) == true) && (rightblockcheck1(grid) == true))
			{
				l++, r++, x6 += 50;
			}
		}
	}
	~Z()
	{}
};
class T :public tetrimino
{
	sf::RectangleShape t1, t2, t3, t4, f;
	int x7, y7, angle, d1, l, r;
public:
	T()
	{
		d1 = 1; l = 3; r = 5; angle = 0; x7 = 160, y7 = 50;
	}
	void nextshape(sf::RenderWindow& window)
	{
		int a = 670, b = 620;
		t1.setPosition(a, b);
		t1.setSize(sf::Vector2f(50, 40));
		t1.setOutlineColor(sf::Color::White);
		t1.setOutlineThickness(1);
		t1.setFillColor(sf::Color::Color(160, 40, 100));
		t2.setPosition(a + 50, b);
		t2.setSize(sf::Vector2f(50, 40));
		t2.setOutlineColor(sf::Color::White);
		t2.setOutlineThickness(1);
		t2.setFillColor(sf::Color::Color(160, 40, 100));
		t3.setPosition(a + 100, b);
		t3.setSize(sf::Vector2f(50, 40));
		t3.setOutlineColor(sf::Color::White);
		t3.setOutlineThickness(1);
		t3.setFillColor(sf::Color::Color(160, 40, 100));
		t4.setPosition(a + 50, b - 40);
		t4.setSize(sf::Vector2f(50, 40));
		t4.setOutlineColor(sf::Color::White);
		t4.setOutlineThickness(1);
		t4.setFillColor(sf::Color::Color(160, 40, 100));
		window.draw(t1);
		window.draw(t2);
		window.draw(t3);
		window.draw(t4);
	}
	void T_4(sf::RenderWindow& window)
	{
		t1.setPosition(x7, y7);
		t1.setSize(sf::Vector2f(50, 40));
		t1.setOutlineColor(sf::Color::White);
		t1.setOutlineThickness(1);
		t1.setFillColor(sf::Color::Color(160, 40, 100));
		t2.setPosition(x7, y7 + 40);
		t2.setSize(sf::Vector2f(50, 40));
		t2.setOutlineColor(sf::Color::White);
		t2.setOutlineThickness(1);
		t2.setFillColor(sf::Color::Color(160, 40, 100));
		t3.setPosition(x7, y7 + 80);
		t3.setSize(sf::Vector2f(50, 40));
		t3.setOutlineColor(sf::Color::White);
		t3.setOutlineThickness(1);
		t3.setFillColor(sf::Color::Color(160, 40, 100));
		t4.setPosition(x7 + 50, y7 + 40);
		t4.setSize(sf::Vector2f(50, 40));
		t4.setOutlineColor(sf::Color::White);
		t4.setOutlineThickness(1);
		t4.setFillColor(sf::Color::Color(160, 40, 100));
	}
	void T_1(sf::RenderWindow& window)
	{
		t1.setPosition(x7, y7);
		t1.setSize(sf::Vector2f(50, 40));
		t1.setOutlineColor(sf::Color::White);
		t1.setOutlineThickness(1);
		t1.setFillColor(sf::Color::Color(160, 40, 100));
		t2.setPosition(x7 + 50, y7);
		t2.setSize(sf::Vector2f(50, 40));
		t2.setOutlineColor(sf::Color::White);
		t2.setOutlineThickness(1);
		t2.setFillColor(sf::Color::Color(160, 40, 100));
		t3.setPosition(x7 + 100, y7);
		t3.setSize(sf::Vector2f(50, 40));
		t3.setOutlineColor(sf::Color::White);
		t3.setOutlineThickness(1);
		t3.setFillColor(sf::Color::Color(160, 40, 100));
		t4.setPosition(x7 + 50, y7 - 40);
		t4.setSize(sf::Vector2f(50, 40));
		t4.setOutlineColor(sf::Color::White);
		t4.setOutlineThickness(1);
		t4.setFillColor(sf::Color::Color(160, 40, 100));
	}
	void T_2(sf::RenderWindow& window)
	{
		t1.setPosition(x7, y7);
		t1.setSize(sf::Vector2f(50, 40));
		t1.setOutlineColor(sf::Color::White);
		t1.setOutlineThickness(1);
		t1.setFillColor(sf::Color::Color(160, 40, 100));
		t2.setPosition(x7, y7 + 40);
		t2.setSize(sf::Vector2f(50, 40));
		t2.setOutlineColor(sf::Color::White);
		t2.setOutlineThickness(1);
		t2.setFillColor(sf::Color::Color(160, 40, 100));
		t3.setPosition(x7, y7 + 80);
		t3.setSize(sf::Vector2f(50, 40));
		t3.setOutlineColor(sf::Color::White);
		t3.setOutlineThickness(1);
		t3.setFillColor(sf::Color::Color(160, 40, 100));
		t4.setPosition(x7 - 50, y7 + 40);
		t4.setSize(sf::Vector2f(50, 40));
		t4.setOutlineColor(sf::Color::White);
		t4.setOutlineThickness(1);
		t4.setFillColor(sf::Color::Color(160, 40, 100));
	}
	void T_3(sf::RenderWindow& window)
	{
		t1.setPosition(x7, y7);
		t1.setSize(sf::Vector2f(50, 40));
		t1.setOutlineColor(sf::Color::White);
		t1.setOutlineThickness(1);
		t1.setFillColor(sf::Color::Color(160, 40, 100));
		t2.setPosition(x7 + 50, y7);
		t2.setSize(sf::Vector2f(50, 40));
		t2.setOutlineColor(sf::Color::White);
		t2.setOutlineThickness(1);
		t2.setFillColor(sf::Color::Color(160, 40, 100));
		t3.setPosition(x7 + 100, y7);
		t3.setSize(sf::Vector2f(50, 40));
		t3.setOutlineColor(sf::Color::White);
		t3.setOutlineThickness(1);
		t3.setFillColor(sf::Color::Color(160, 40, 100));
		t4.setPosition(x7 + 50, y7 + 40);
		t4.setSize(sf::Vector2f(50, 40));
		t4.setOutlineColor(sf::Color::White);
		t4.setOutlineThickness(1);
		t4.setFillColor(sf::Color::Color(160, 40, 100));
	}
	virtual void fill_block(sf::RenderWindow& window, int i, int j)
	{
		int hori = 10, verti = 10;
		for (int k = 0; k < j; k++)
			hori += 50;
		for (int k = 0; k < i; k++)
			verti += 40;
		f.setPosition(hori, verti); f.setSize(sf::Vector2f(50, 40)); f.setOutlineColor(sf::Color::White); f.setOutlineThickness(1); f.setFillColor(sf::Color::Color(160, 40, 100));
	}
	virtual sf::RectangleShape get_f()
	{
		return f;
	}
	virtual void drawing(sf::RenderWindow& window)
	{
		if (angle == 0)
		{
			T_1(window);
			window.draw(t1);
			window.draw(t2);
			window.draw(t3);
			window.draw(t4);
		}
		else if (angle == 90)
		{
			T_2(window);
			window.draw(t1);
			window.draw(t2);
			window.draw(t3);
			window.draw(t4);
		}
		else if (angle == 270)
		{
			T_3(window);
			window.draw(t1);
			window.draw(t2);
			window.draw(t3);
			window.draw(t4);
		}
		else if (angle == 360)
		{
			T_4(window);
			window.draw(t1);
			window.draw(t2);
			window.draw(t3);
			window.draw(t4);
		}
	}
	virtual void rotating(sf::RenderWindow& window, int** grid)
	{
		if (angle == 0)
		{
			d1 -= 1; y7 -= 40; l++; r++; x7 += 50; angle = 90;
		}
		else if (angle == 90)
		{
			if ((l == 1) && (grid[d1][r - 1] != 0))
			{
				angle = 90;
			}
			else if ((l >= 1) && (grid[d1][r - 1] != 0) && (grid[d1][l - 2] != 0))
			{
				angle = 90;
			}
			else if ((l >= 1) && (grid[d1][r - 1] != 0))
			{
				angle = 270; x7 -= 100; l -= 2; r -= 2;
			}
			else if ((l == 9) && (grid[d1][l - 2] != 0))
			{
				angle = 90;
			}
			else if (l == 9)
			{
				l -= 2; r -= 2; x7 -= 100; angle = 270;
			}
			else
			{
				l--; r--; x7 -= 50; y7 += 40; d1 += 1; angle = 270;
			}
		}
		else if (angle == 270)
		{
			d1 -= 1;	y7 -= 40; l++; r++; x7 += 50; angle = 360;
		}
		else if (angle == 360)
		{
			if ((l == 0) && (grid[d1][r] != 0))
			{
				angle = 360;
			}
			else if ((l >= 1) && (grid[d1][r] != 0) && (grid[d1][l - 1] != 0))
			{
				angle = 360;
			}
			else if ((l == 8) && (grid[d1][l - 1] != 0))
			{
				angle = 360;
			}
			else if (l == 0)
			{
				angle = 0;
			}
			else
			{
				l--; r--; x7 -= 50; y7 += 40; d1 += 1; angle = 0;
			}
		}

	}
	virtual void droping(sf::RenderWindow& window)
	{
		y7 += 40;
		if (d1 < 19)
			d1++;
	}
	virtual void put_val_in_grid(int** grid)
	{
		if (d1 > 0)
		{
			if (angle == 0)
			{
				if (d1 <= 19)
				{
					for (int i = l; i <= r; i++)
						grid[d1][i] = 7;
					grid[d1 - 1][l + 1] = 7;
				}
			}
			else if (angle == 90)
			{
				d1 -= 1;
				for (int i = d1; i <= d1 + 2; i++)
					grid[i][l] = 7;
				grid[d1 + 1][l - 1] = 7;
			}
			else if (angle == 270)
			{
				d1 -= 1;
				if (d1 <= 18)
				{
					for (int i = l; i <= l + 2; i++)
						grid[d1][i] = 7;
					grid[d1 + 1][l + 1] = 7;
				}
			}
			else if (angle == 360)
			{
				d1 -= 1;
				for (int i = d1; i <= d1 + 2; i++)
					grid[i][l] = 7;
				grid[d1 + 1][l + 1] = 7;
			}
			d1 = 1; l = 3; r = 5; angle = 0; x7 = 160, y7 = 50;
		}
	}
	virtual bool if_stop(int** grid, int left, int right)
	{
		if (angle == 0)
		{
			if (y7 == 810)
				return true;
			else
			{
				if (d1 < 19)
				{
					for (int i = l; i <= r; i++)
						if (grid[d1 + 1][i] != 0)
							return true;
					return false;
				}
			}
		}
		else if (angle == 90)
		{
			if (y7 == 730)
				return true;
			else if (d1 <= 17)
			{
				if (grid[d1 + 2][l] != 0)
					return true;
				else if (grid[d1 + 1][l - 1] != 0)
					return true;
				return false;
			}
		}
		else if (angle == 270)
		{
			if (y7 == 770)
				return true;
			else if (d1 <= 18)
			{
				if (grid[d1][l] != 0)
					return true;
				else if (grid[d1][l + 2] != 0)
					return true;
				else if (grid[d1 + 1][l + 1] != 0)
					return true;
				return false;
			}
		}
		else if (angle == 360)
		{
			if (y7 == 730)
				return true;
			else if (d1 <= 17)
			{
				if (grid[d1 + 2][l] != 0)
					return true;
				else if (grid[d1 + 1][l + 1] != 0)
					return true;
				return false;
			}
		}
	}
	//left
	virtual bool leftblockcheck0(int** grid)
	{
		if (d1 < 19)
		{
			if (grid[d1][l - 1] != 0)
				return false;
			else if (grid[d1 - 1][l] != 0)
				return false;
			return true;
		}
	}
	virtual bool leftblockcheck1(int** grid)
	{
		if (grid[d1][l - 1] != 0)
			return false;
		else if (grid[d1 + 1][l - 2] != 0)
			return false;
		else if (grid[d1 + 2][l - 1] != 0)
			return false;
		return true;
	}
	virtual bool leftblockcheck2(int** grid)
	{
		if (grid[d1][l - 1] != 0)
			return false;
		else if (grid[d1 + 1][l] != 0)
			return false;
		return true;

	}
	virtual bool leftblockcheck3(int** grid)
	{
		for (int i = d1; i <= d1 + 2; i++)
			if (grid[i][l - 1] != 0)
				return false;
		return true;
	}
	bool left_boundry_hori(int lef1, int c)
	{
		if ((lef1 > 0) && (c >= 10))
			return true;
		return false;
	}
	virtual void if_left(sf::RenderWindow& window, int** grid)
	{
		if (angle == 0)
		{
			if ((left_boundry_hori(l, x7) == true) && (leftblockcheck0(grid) == true))
			{
				l--, r--, x7 -= 50;
			}
		}
		else if (angle == 90)
		{
			if ((left_boundry_hori(l - 1, x7) == true) && (leftblockcheck1(grid) == true))
			{
				l--, r--, x7 -= 50;
			}
		}
		else if (angle == 270)
		{
			if ((left_boundry_hori(l, x7) == true) && (leftblockcheck2(grid) == true))
			{
				l--, r--, x7 -= 50;
			}
		}
		else if (angle == 360)
		{
			if ((left_boundry_hori(l, x7) == true) && (leftblockcheck3(grid) == true))
			{
				l--, r--, x7 -= 50;
			}
		}

	}
	//right
	virtual bool rightblockcheck0(int** grid)
	{
		if (grid[d1][l + 3] != 0)
			return false;
		else if (grid[d1 - 1][l + 2] != 0)
			return false;
		return true;
	}
	virtual bool rightblockcheck1(int** grid)
	{
		for (int i = d1; i <= d1 + 2; i++)
			if (grid[i][l + 1] != 0)
				return false;
		return true;
	}
	virtual bool rightblockcheck2(int** grid)
	{
		if (grid[d1][l + 3] != 0)
			return false;
		else if (grid[d1 + 1][l + 2] != 0)
			return false;
		return true;
	}
	virtual bool rightblockcheck3(int** grid)
	{
		if (grid[d1][l + 1] != 0)
			return false;
		else if (grid[d1 + 1][l + 2] != 0)
			return false;
		else if (grid[d1 + 2][l + 1] != 0)
			return false;
		return true;
	}
	bool right_boundry_hori(int r1, int c)
	{
		if ((r1 <= 9) && (c <= 460))
			return true;
		return false;
	}
	virtual void if_right(sf::RenderWindow& window, int** grid)
	{
		if (angle == 0)
		{
			if ((right_boundry_hori(r + 1, x7) == true) && (rightblockcheck0(grid) == true))
			{
				l++, r++, x7 += 50;
			}
		}
		if (angle == 90)
		{
			if ((right_boundry_hori(r - 1, x7) == true) && (rightblockcheck1(grid) == true))
			{
				l++, r++, x7 += 50;
			}
		}
		if (angle == 270)
		{

			if ((right_boundry_hori(r + 1, x7) == true) && (rightblockcheck2(grid) == true))
			{
				l++, r++, x7 += 50;
			}
		}
		if (angle == 360)
		{
			if ((right_boundry_hori(r, x7) == true) && (rightblockcheck3(grid) == true))
			{
				l++, r++, x7 += 50;
			}
		}
	}
	~T()
	{}
};
class well :public tetrimino
{
	sf::RectangleShape rect;
	int x, y;
protected:
	int** grid;
public:
	well()
	{
		x = 500; y = 800;
		grid = new int* [20];
		for (int i = 0; i < 20; i++)
		{
			grid[i] = new int[10];
			for (int j = 0; j < 10; j++)
				grid[i][j] = 0;
		}
	}
	virtual bool upperboundry(int** grid)
	{
		for (int i = 0; i < 10; i++)
			if (grid[0][i] != 0)
				return true;
		return false;
	}
	int** get_well()
	{
		return grid;
	}
	sf::RectangleShape get_grid()
	{
		return rect;
	}
	void border(sf::RenderWindow& window)
	{
		rect.setPosition(10, 10);
		rect.setSize(sf::Vector2f(x, y));
		rect.setOutlineThickness(2);
		rect.setFillColor(sf::Color::Transparent);
		rect.setOutlineColor(sf::Color::Blue);
	}
	virtual void drawing(sf::RenderWindow& window)
	{
		border(window);
		window.draw(rect);
	}
	~well()
	{
		for (int i = 0; i < 20; i++)
		{
			delete[]grid[i];
		}
		delete[]grid;
	}
};
class game :public tetrimino, public I, public O, public L, public J, public S, public Z, public T, public well
{
	int block_num;
	int lines, points;
	int level;
	float time = 1000.0f;
	int c;
	string name;
public:
	game()
	{
		c = 0; level = 1; lines = 0; points = 0; block_num = rand() % 7;
	}
	int get_points()
	{
		return points;
	}
	void startingscreen()
	{
		sf::RenderWindow over(sf::VideoMode(1000, 900), "NOT TETRIS");
		sf::Font font, f, f2;
		sf::RectangleShape rect, r, r2;
		rect.setPosition(310, 70);
		rect.setSize(sf::Vector2f(370, 115));
		rect.setOutlineThickness(20);
		rect.setFillColor(sf::Color::Transparent);
		rect.setOutlineColor(sf::Color::Blue);
		sf::Text text("Type your name :   ", font, 50);
		text.setFillColor(sf::Color::Black);
		text.setPosition(50, 230);
		font.loadFromFile("Games-Italic.ttf");
		f.loadFromFile("SEASRN__.ttf");
		sf::Text logo("TETRIS", f, 100);
		logo.setFillColor(sf::Color::Color(237, 28, 36));
		logo.setPosition(320, 70);
		f2.loadFromFile("Antonio-Bold.ttf");
		sf::Text explaination("-This game consists of 8 levels", f2, 30);
		explaination.setFillColor(sf::Color::Black);
		explaination.setPosition(50, 300);
		sf::Text explaination2("-Game restarts once you surpass level 8", f2, 30);
		explaination2.setFillColor(sf::Color::Black);
		explaination2.setPosition(50, 350);
		sf::Text explaination3("-Speed increases when you pass a level", f2, 30);
		explaination3.setFillColor(sf::Color::Black);
		explaination3.setPosition(50, 400);
		r.setPosition(100, 550);
		r.setSize(sf::Vector2f(800, 315));
		r.setOutlineThickness(10);
		r.setFillColor(sf::Color::Transparent);
		r.setOutlineColor(sf::Color::Black);
		sf::Text l("LEADERBOARD", font, 70);
		l.setFillColor(sf::Color::Red);
		l.setPosition(270, 465);
		r2.setPosition(260, 480);
		r2.setSize(sf::Vector2f(480, 60));
		r2.setOutlineThickness(10);
		r2.setFillColor(sf::Color::Transparent);
		r2.setOutlineColor(sf::Color::Black);
		sf::Text player("Players", f2, 50);
		player.setFillColor(sf::Color::Color(50, 50, 5));
		player.setPosition(150, 560);
		sf::Text pts("Points", f2, 50);
		pts.setFillColor(sf::Color::Color(50, 50, 5));
		pts.setPosition(650, 560);
		string n1, n2, n3, n4, n5, n6;
		int p1 = 0, p2 = 0, p3 = 0, p4 = 0, p5 = 0;
		ifstream fin("score.txt");
		ifstream finn("names.txt");
		fin >> p1 >> p2 >> p3 >> p4 >> p5;
		getline(finn, n1);
		getline(finn, n2);
		getline(finn, n3);
		getline(finn, n4);
		getline(finn, n5);
		sf::Text name1;
		name1.setString(n1);
		name1.setFont(font);
		name1.setFillColor(sf::Color::White);
		name1.setCharacterSize(30);
		name1.setPosition(150, 620);
		sf::Text s1;
		s1.setFont(font);
		s1.setCharacterSize(30);
		s1.setString("" + std::to_string(p1));
		s1.setPosition(670, 620);
		sf::Text name2;
		name2.setString(n2);
		name2.setFont(font);
		name2.setFillColor(sf::Color::White);
		name2.setCharacterSize(30);
		name2.setPosition(150, 670);
		sf::Text s2;
		s2.setFont(font);
		s2.setCharacterSize(30);
		s2.setString("" + std::to_string(p2));
		s2.setPosition(670, 670);
		sf::Text name3;
		name3.setString(n3);
		name3.setFont(font);
		name3.setFillColor(sf::Color::White);
		name3.setCharacterSize(30);
		name3.setPosition(150, 720);
		sf::Text s3;
		s3.setFont(font);
		s3.setCharacterSize(30);
		s3.setString("" + std::to_string(p3));
		s3.setPosition(670, 720);
		sf::Text name4;
		name4.setString(n4);
		name4.setFont(font);
		name4.setFillColor(sf::Color::White);
		name4.setCharacterSize(30);
		name4.setPosition(150, 770);
		sf::Text s4;
		s4.setFont(font);
		s4.setCharacterSize(30);
		s4.setString("" + std::to_string(p4));
		s4.setPosition(670, 770);
		sf::Text name5;
		name5.setString(n5);
		name5.setFont(font);
		name5.setFillColor(sf::Color::White);
		name5.setCharacterSize(30);
		name5.setPosition(150, 820);
		sf::Text s5;
		s5.setFont(font);
		s5.setCharacterSize(30);
		s5.setString("" + std::to_string(p5));
		s5.setPosition(670, 820);
		while (over.isOpen())
		{
			sf::Event event;
			while (over.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					over.close();
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
					over.close();
				if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter)
					over.close();
				if (event.type == sf::Event::TextEntered)
				{
					if (event.text.unicode < 128)
					{
						name += static_cast<char>(event.text.unicode);
						text.setString("Type your name : " + name);
					}
				}
			}
			over.clear(sf::Color::Color(71, 168, 229)); over.draw(text); over.draw(logo); over.draw(rect); over.draw(explaination); over.draw(explaination2); over.draw(explaination3); over.draw(r); over.draw(r2);
			over.draw(l); over.draw(player); over.draw(pts); over.draw(name1); over.draw(s1); over.draw(name2); over.draw(s2); over.draw(name3); over.draw(s3); over.draw(name4); over.draw(s4); over.draw(name5);
			over.draw(s5);
			over.display();
		}
	}
	void endscreen()
	{
		sf::RenderWindow over(sf::VideoMode(1000, 900), "NOT TETRIS");
		while (over.isOpen())
		{
			sf::Event event;
			while (over.pollEvent(event))
			{
				if (event.type == sf::Event::Closed) {

					over.close();
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
					over.close();
			}
			sf::Font font;
			sf::Text text_p;

			font.loadFromFile("Games-Italic.ttf");

			text_p.setFont(font);
			text_p.setCharacterSize(30);
			text_p.setString("Points = " + std::to_string(points));
			text_p.setPosition(340, 150);

			sf::RectangleShape rec_p;
			rec_p.setPosition(320, 150);
			rec_p.setSize(sf::Vector2f(300, 40));
			rec_p.setOutlineThickness(2);
			rec_p.setFillColor(sf::Color::Transparent);
			rec_p.setOutlineColor(sf::Color::Color(220, 0, 222));

			sf::Text go("GAME OVER", font, 150);
			go.setFillColor(sf::Color::White);
			go.setPosition(90, 350);



			over.clear();
			over.draw(text_p);
			over.draw(go);
			over.draw(rec_p);
			over.display();
		}
	}
	void scoring(sf::RenderWindow& window)
	{
		sf::Font font;
		sf::Text text_p, text_l, text_lv, nam;
		font.loadFromFile("Games-Italic.ttf");
		nam.setFont(font);
		nam.setCharacterSize(25);
		nam.setString(name);
		nam.setPosition(670, 100);
		sf::Text nss("Next Shape", font, 30);
		nss.setPosition(655, 505);
		text_p.setFont(font);
		text_p.setCharacterSize(30);
		text_p.setString("Points = " + std::to_string(points));
		text_p.setPosition(670, 200);
		text_l.setFont(font);
		text_l.setCharacterSize(30);
		text_l.setString("Lines = " + std::to_string(lines));
		text_l.setPosition(670, 300);
		text_lv.setFont(font);
		text_lv.setCharacterSize(30);
		text_lv.setString("Level = " + std::to_string(level));
		text_lv.setPosition(670, 400);
		sf::RectangleShape rec_p, rec_l, rec_lv, n, ns;
		ns.setPosition(640, 540);
		ns.setSize(sf::Vector2f(200, 240));
		ns.setOutlineThickness(2);
		ns.setFillColor(sf::Color::Transparent);
		ns.setOutlineColor(sf::Color::Color(20, 220, 222));
		n.setPosition(650, 100);
		n.setSize(sf::Vector2f(300, 40));
		n.setOutlineThickness(2);
		n.setFillColor(sf::Color::Transparent);
		n.setOutlineColor(sf::Color::Color(220, 0, 222));
		rec_p.setPosition(650, 200);
		rec_p.setSize(sf::Vector2f(300, 40));
		rec_p.setOutlineThickness(2);
		rec_p.setFillColor(sf::Color::Transparent);
		rec_p.setOutlineColor(sf::Color::Color(220, 0, 222));
		rec_l.setPosition(650, 300);
		rec_l.setSize(sf::Vector2f(300, 40));
		rec_l.setOutlineThickness(2);
		rec_l.setFillColor(sf::Color::Transparent);
		rec_l.setOutlineColor(sf::Color::Color(220, 0, 222));
		rec_lv.setPosition(650, 400);
		rec_lv.setSize(sf::Vector2f(300, 40));
		rec_lv.setOutlineThickness(2);
		rec_lv.setFillColor(sf::Color::Transparent);
		rec_lv.setOutlineColor(sf::Color::Color(220, 0, 222));
		window.draw(rec_lv);
		window.draw(text_lv);
		window.draw(text_p);
		window.draw(text_l);
		window.draw(rec_p);
		window.draw(rec_l);
		window.draw(nam);
		window.draw(n);
		window.draw(ns);
		window.draw(nss);
	}
	void filling(sf::RenderWindow& window)
	{
		for (int i = 0; i < 20; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				if (grid[i][j] == 1)
				{
					I::fill_block(window, i, j);
					window.draw(I::get_f());
				}
				if (grid[i][j] == 2)
				{
					O::fill_block(window, i, j);
					window.draw(O::get_f());
				}
				if (grid[i][j] == 3)
				{
					L::fill_block(window, i, j);
					window.draw(L::get_f());
				}
				if (grid[i][j] == 4)
				{
					J::fill_block(window, i, j);
					window.draw(J::get_f());
				}
				if (grid[i][j] == 7)
				{
					T::fill_block(window, i, j);
					window.draw(T::get_f());
				}
				if (grid[i][j] == 5)
				{
					S::fill_block(window, i, j);
					window.draw(S::get_f());
				}
				if (grid[i][j] == 6)
				{
					Z::fill_block(window, i, j);
					window.draw(Z::get_f());
				}
			}
		}
	}
	bool checking_for_destroying(int i)
	{
		for (int j = 0; j < 10; j++)
			if (grid[i][j] == 0)
				return false;
		return true;
	}
	void bonus(sf::RenderWindow& window)
	{
		sf::Font f;
		f.loadFromFile("Antonio-Bold.ttf");
		sf::Text t("TETRIS", f, 200);
		t.setFont(f);
		t.setFillColor(sf::Color(255, 250, 250));
		t.setPosition(30, 440);
		window.draw(t);
	}
	void destroying(sf::RenderWindow& window)
	{
		c = 0;
		for (int i = 0; i < 20; i++)
		{
			if (checking_for_destroying(i) == true)
			{
				c++;
				for (int k = i; k > 0; k--)
				{
					for (int j = 0; j < 10; j++)
					{
						grid[k][j] = grid[k - 1][j];
					}
				}
				lines += 1;
				points += 100;
				if (lines == 10)
				{
					lines = 0;
					level++;
				}
			}
		}
	}
	void changingtime()
	{
		level = level % 9;
		if (level == 0)
			level = 1;
		if (level == 1)
			time = 1000.0f;
		else if (level == 2)
			time = 900.0f;
		else if (level == 3)
			time = 810.0f;
		else if (level == 4)
			time = 729.0f;
		else if (level == 5)
			time = 656.1f;
		else if (level == 6)
			time = 590.49;
		else if (level == 7)
			time = 531.441;
		else if (level == 8)
			time = 478.2969;
	}
	void filing()
	{
		string n1, n2, n3, n4, n5;
		int p1 = 0, p2 = 0, p3 = 0, p4 = 0, p5 = 0;
		ifstream fin("score.txt");
		fin >> p1 >> p2 >> p3 >> p4 >> p5;
		ifstream finn("names.txt");
		getline(finn, n1);
		getline(finn, n2);
		getline(finn, n3);
		getline(finn, n4);
		getline(finn, n5);
		if (points > p1)
		{
			int t1 = p1;
			p1 = points;
			int t2 = p2;
			p2 = t1;
			int t3 = p3;
			p3 = t2;
			int t4 = p4;
			p4 = t3;
			int t5 = p5;
			p5 = t4;
			string m1 = n1;
			n1 = name;
			string m2 = n2;
			n2 = m1;
			string m3 = n3;
			n3 = m2;
			string m4 = n4;
			n4 = m3;
			string m5 = n5;
			n5 = m4;
		}
		else if (points > p2)
		{
			int t2 = p2;
			p2 = points;
			int t3 = p3;
			p3 = t2;
			int t4 = p4;
			p4 = t3;
			int t5 = p5;
			p5 = t4;
			string m2 = n2;
			n2 = name;
			string m3 = n3;
			n3 = m2;
			string m4 = n4;
			n4 = m3;
			string m5 = n5;
			n5 = m4;
		}
		else if (points > p3)
		{
			int t3 = p3;
			p3 = points;
			int t4 = p4;
			p4 = t3;
			int t5 = p5;
			p5 = t4;
			string m3 = n3;
			n3 = name;
			string m4 = n4;
			n4 = m3;
			string m5 = n5;
			n5 = m4;
		}
		else if (points > p4)
		{
			int t4 = p4;
			p4 = points;
			int t5 = p5;
			p5 = t4;
			string m4 = n4;
			n4 = name;
			string m5 = n5;
			n5 = m4;
		}
		else if (points > p5)
		{
			p5 = points;
			n5 = name;
		}
		ofstream fout;
		fout.open("score.txt");
		ofstream foutt;
		foutt.open("names.txt");
		fout << p1 << endl;
		fout << p2 << endl;
		fout << p3 << endl;
		fout << p4 << endl;
		fout << p5;
		foutt << n1 << endl;
		foutt << n2 << endl;
		foutt << n3 << endl;
		foutt << n4 << endl;
		foutt << n5 << endl;
	}
	void start_game(sf::RenderWindow& window)
	{
		int h = rand() % 7;
		sf::Clock clock;
		float elapsed_time = 0.0f;
		well welobj;
		tetrimino* p[8];
		p[7] = &welobj;
		I obj0;
		O obj1;
		L obj2;
		J obj3;
		S obj4;
		Z obj5;
		T obj6;
		p[0] = &obj0;
		p[1] = &obj1;
		p[2] = &obj2;
		p[3] = &obj3;
		p[4] = &obj6;
		p[5] = &obj4;
		p[6] = &obj5;
		startingscreen();
		while (window.isOpen())
		{
			changingtime();
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
					window.close();
				if (event.type == sf::Event::KeyPressed)
				{
					if (event.key.code == sf::Keyboard::Left)
						p[block_num]->if_left(window, grid);
					else if (event.key.code == sf::Keyboard::Right)
						p[block_num]->if_right(window, grid);
					else if (event.key.code == sf::Keyboard::Up)
						p[block_num]->rotating(window, grid);
					else if (event.key.code == sf::Keyboard::Down)
						time = 0.000001f;
				}
			}
			window.clear(sf::Color::Color(50, 50, 50));
			p[7]->drawing(window);
			filling(window);
			scoring(window);
			p[block_num]->drawing(window);
			p[h]->nextshape(window);
			if (c == 4)
				bonus(window);
			if (c == 4)
			{
				window.display(); //1
				sf::sleep(sf::seconds(0.5));
				c = 0;
			}
			else
				window.display(); //2
			elapsed_time += clock.restart().asMilliseconds();
			if (elapsed_time >= time)
			{
				p[block_num]->droping(window);
				elapsed_time = 0.0f;
			}
			if ((p[block_num]->if_stop(grid, p[block_num]->get_left(), p[block_num]->get_right()) == true))//stoping condititon
			{
				p[block_num]->put_val_in_grid(grid);
				block_num = h;
				h = rand() % 7;
			}
			destroying(window);
			if (p[7]->upperboundry(grid) == true)//game end
			{
				window.close();
				endscreen();
				break;
			}
		}
		filing();
	}
	~game()
	{}
};
int main()
{

	srand(time(0));
	sf::RenderWindow window(sf::VideoMode(1000, 900), "NOT TETRIS");
	game Game;
	Game.start_game(window);
}