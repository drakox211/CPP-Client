#include "stdafx.h"
#include "VisitorXML.h"
#include "SocketInOut.h"
#include "SingletonWSA.h"

#include <memory>
#include <map>

string VisitorXML::strVector(const Vector2D& vs) const {
	stringstream oss;
	oss << makeMarkup("vertice", makeMarkup("x", vs.x) + makeMarkup("y", vs.y));
	return oss.str();
}

string VisitorXML::strColor(const shared_ptr<const Color>& col) const {
	stringstream oss;
	oss << makeMarkup("color", makeMarkup("r", col->x) + makeMarkup("g", col->y) + makeMarkup("b", col->z));
	return oss.str();
}

string  VisitorXML::strXML(const shared_ptr<Shape> vs, const string& param = "") const {
	stringstream result;
	string name = vs->getName();

	/* Retourne une chaine selon la nomenclature : Name - ID - Color - Param - Vertices
	   Les param�tres sont des attributs propres qui ne sont pas des sommets, comme 
	   le radius du cercle*/
	result << 
		"<" << name << " id=\"" << vs->getId() << "\">" << 
			strColor(vs->getColor()) << param <<
		"<vertices>";
			for (auto &vertice : vs->getVertices()) result << strVector(vertice);
	result << 
		"</vertices></" << name << ">";

	return string(result.str());
}

string  VisitorXML::visit(const shared_ptr<Shape> vs) const{
	return strXML(vs);
}

string  VisitorXML::visit(const shared_ptr<Circle> vs) const {
	stringstream param;
	//Un cercle poss�de un radius qui n'est pas un sommet. On l'ajoute donc en param�tre.
	param << makeMarkup("radius", vs->getRadius());

	return strXML(vs, param.str());
}

string  VisitorXML::visit(const shared_ptr<shape::Rectangle> vs) const {
	shared_ptr<Shape> rectangularShape(new Shape(vs->getCurrentVertices(), shared_ptr<const Color>(vs->getColor())));
	rectangularShape->setId(vs->getId());
	return strXML(rectangularShape);
}

string  VisitorXML::visit(const shared_ptr<ShapeGroup> vs) const
{
	stringstream oss;
	string str, name = vs->getName();
	oss << "<" << name << ">";
	for (auto &shape : vs->getShapes()) {
		str = shape->accept(new VisitorXML);
		oss << str;
	}
	oss << "</" << name << ">";
	return string(oss.str());
}

string VisitorXML::visit(const shared_ptr<ShapeManager> vs) const {
	stringstream XMLS;
	string suffix;
	vector<shared_ptr<Drawable>> m = vs->getShapes();
	for (auto s : m) {
		
		suffix = (s == m.back()) ? "" : "\r\n";
		XMLS << s->accept(new VisitorXML) << suffix;
	}
	return string(XMLS.str());
}
