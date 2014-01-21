#include "quiitem.h"

#include "quiarea.h"
#include <QtGui/QtEvents>
#include <QtGui/QPainter>
#include <QtWidgets/QPushButton>

YCQUiItem::YCQUiItem(YCQUiArea* parent /* = 0 */, Qt::WindowFlags f /* = 0 */)
	: QWidget(parent, f)
	, m_pUiArea(parent)
	, m_pImage(NULL)
	, m_bPressed(false)
	, m_bGrabed(false)
	, m_bSelected(false)
{
	//
}

YCQUiItem::~YCQUiItem()
{
	if (NULL != m_pImage)
	{
		delete m_pImage;
		m_pImage = NULL;
	}
}

void YCQUiItem::mousePressEvent(QMouseEvent* pEvent)
{
	// can't move item
	//m_bPressed = true;
	m_oPosMousePressStart = pEvent->screenPos();

	setGrabed(true);
}

void YCQUiItem::mouseReleaseEvent(QMouseEvent* pEvent)
{
	m_bPressed = false;

	setGrabed(false);
}

void YCQUiItem::mouseDoubleClickEvent(QMouseEvent* pEvent)
{
	m_bPressed = false;

	if (m_bSelected)
	{
		setSelected(false);
	}
	else
	{
		setSelected(true);
	}
}

void YCQUiItem::mouseMoveEvent(QMouseEvent* pEvent)
{
	if (!m_bPressed)
	{
		return;
	}
	QPointF oOffset = pEvent->screenPos() - m_oPosMousePressStart;
	move(pos() + oOffset.toPoint());
	m_oPosMousePressStart = pEvent->screenPos();
}

void YCQUiItem::paintEvent(QPaintEvent* pEvent)
{
	qDebug("YCQUiItem::paintEvent");

	QPainter oPainter(this);

	if (NULL != m_pImage)
	{
		oPainter.drawImage(0, 0, *m_pImage);
	}

	if (m_bGrabed)
	{
		oPainter.setPen(QPen(Qt::red));
		oPainter.drawLine(QPoint(0, 0), QPoint(size().width() - 1, 0));
		oPainter.drawLine(QPoint(0, 0), QPoint(0, size().height() - 1));
		oPainter.drawLine(QPoint(0, size().height() - 1), QPoint(size().width() - 1, size().height() - 1));
		oPainter.drawLine(QPoint(size().width() - 1, 0), QPoint(size().width() - 1, size().height() - 1));
	}
	else if (m_bSelected)
	{
		oPainter.setPen(QPen(Qt::yellow));
		oPainter.drawLine(QPoint(0, 0), QPoint(size().width() - 1, 0));
		oPainter.drawLine(QPoint(0, 0), QPoint(0, size().height() - 1));
		oPainter.drawLine(QPoint(0, size().height() - 1), QPoint(size().width() - 1, size().height() - 1));
		oPainter.drawLine(QPoint(size().width() - 1, 0), QPoint(size().width() - 1, size().height() - 1));
	}
}

void YCQUiItem::setGrabed(const bool& rbGrabed)
{
	if (m_bGrabed == rbGrabed)
	{
		return;
	}
	m_bGrabed = rbGrabed;

	repaint();
}

void YCQUiItem::setSelected(const bool& rbSelected)
{
	if (m_bSelected == rbSelected)
	{
		return;
	}
	m_bSelected = rbSelected;

	if (m_bSelected)
	{
		m_pUiArea->setSelected(this);
	}

	repaint();
}

void YCQUiItem::setFormat(const yam::base::YIFormat*& rpFormat)
{
	setFormat(rpFormat->GetBound(), rpFormat->GetColorData());

	repaint();
}

void YCQUiItem::setFormat(const yam::YRect2D& rstRect, const yam::ycolorptr& rpColorData)
{
	move(rstRect.Pos.X, rstRect.Pos.Y);
	resize(rstRect.Size.X, rstRect.Size.Y);

	//setColor(convertFromYColor(0xff0000ff));
	if (NULL != m_pImage)
	{
		delete m_pImage;
		m_pImage = NULL;
	}

	if (YNULL != rpColorData)
	{
		m_pImage = new QImage(QSize(rstRect.Size.X, rstRect.Size.Y), QImage::Format_RGBA8888);
		for (int y = 0; y < rstRect.Size.Y; ++y)
		{
			for (int x = 0; x < rstRect.Size.X; ++x)
			{
				m_pImage->setPixel(x, y, convertFromYColor(rpColorData[x + y * rstRect.Size.X]));
			}
		}
	}

	repaint();
}

void YCQUiItem::setColor(const uint& riColor)
{
	if (NULL == m_pImage)
	{
		m_pImage = new QImage(size(), QImage::Format_RGBA8888);
	}
	for (int j = 0; j < size().height(); ++j)
	{
		for (int i = 0; i < size().width(); ++i)
		{
			m_pImage->setPixel(i, j, riColor);
		}
	}
}

QRgb YCQUiItem::convertFromYColor(const yam::ycolor& riColor) const
{
	using namespace yam;
	return qRgba(YGETCOLORBIT(riColor, YBITOFFSET_RED)
				, YGETCOLORBIT(riColor, YBITOFFSET_GREEN)
				, YGETCOLORBIT(riColor, YBITOFFSET_BLUE)
				, YGETCOLORBIT(riColor, YBITOFFSET_ALPHA));
}
