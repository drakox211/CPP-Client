#include "stdafx.h"
#include "NodeInterface_Shape.h"

NodeInterface_Shape::NodeInterface_Shape(NodeInterface* ni) : NodeInterface(ni) {
	drawable = new Shape();
}

NodeInterface_Shape::~NodeInterface_Shape() {}

void NodeInterface_Shape::executeRequest(XMLDocument& xml) {
	ShapeManager::getInstance()->add (make_shared<Shape>(retrieveVertices(xml), retrieveColor(xml)));
}