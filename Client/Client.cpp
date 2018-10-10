// Client.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include <iostream>

#include "Shape.h"

using namespace std;

int main()
{
	Vector2D v3(3, 5);
	vector<Vector2D> sommets({
		Vector2D(-1, 1),
		Vector2D(1, 1),
		Vector2D(1, -1),
		Vector2D(-1, -1)
	});

	Shape carre(sommets, &Color::BLUE);

	carre.setColor(&Color::CYAN);
	cout << "color : " << carre.getColor() << endl;
	system("pause");
	return 0;
}

