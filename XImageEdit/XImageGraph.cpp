#include "XImageGraph.h"
#include <QPainter>

void XImageGraph::Draw(XModel* m)
{
	if (!painter || !m) return;
	painter->drawImage(0, 0, *src);
}
