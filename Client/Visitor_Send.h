#pragma once

#include "Visitor.h"

/**
	@brief Fonctionnalit� du DP Visieur.

	Envoie une requete au serveur distant.
*/
class Visitor_Send : public Visitor {
public:
	virtual void visit(Drawable* vd);
	virtual void visit(Shape* vs);
	virtual void visit(Circle* vc);
};