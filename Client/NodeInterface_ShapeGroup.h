#pragma once

#include "NodeInterface.h"

/** @brief L'expert de groupe de forme de la COR*/
class NodeInterface_ShapeGroup : public NodeInterface {
public:
	NodeInterface_ShapeGroup(NodeInterface* ni);
	virtual ~NodeInterface_ShapeGroup();

	void executeRequest(XMLDocument& xml) override;

	const vector<Vector2D> retrieveVertices(XMLDocument& doc);
};