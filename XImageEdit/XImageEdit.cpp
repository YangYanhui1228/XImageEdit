#include "XImageEdit.h"

XImageEdit::XImageEdit(QWidget *parent)
	: QWidget(parent)
{
	
	ui.setupUi(this);
	//点击事件，点击打开图片
	connect(ui.openB, SIGNAL(clicked()), ui.image, SLOT(Open()));
	connect(ui.penButton, SIGNAL(clicked()), ui.image, SLOT(SetPen()));
	connect(ui.eraserButton, SIGNAL(clicked()), ui.image, SLOT(SetEraser()));
	connect(ui.rectButton, SIGNAL(clicked()), ui.image, SLOT(SetRect()));
	connect(ui.undoButton, SIGNAL(clicked()), ui.image, SLOT(Undo()));
	connect(ui.redoButton, SIGNAL(clicked()), ui.image, SLOT(Redo()));
	connect(ui.penSizeSlider, SIGNAL(valueChanged(int)), ui.image, SLOT(SetPenSize(int)));
}
