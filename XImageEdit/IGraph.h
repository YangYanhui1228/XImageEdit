#pragma once
class QPainter;
class QImage;
class XModel;
class IGraph
{
public:
	virtual void Init(QPainter* p, QImage* s)
	{
		painter = p;
		src = s;
	}
	//»æÖÆÍ¼Ôª
	virtual void Draw(XModel* m) = 0;
protected:
	QPainter* painter = 0;
	//Ô­Í¼¡¢±³¾°Í¼
	QImage* src = 0;
};

