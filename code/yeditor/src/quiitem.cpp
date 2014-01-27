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
	, m_fAlpha(1.0f)
	, m_bGrabable(true)
	, m_iLayerWeight(0)
{
	QSizePolicy policy = QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	policy.setHeightForWidth(true);
	setSizePolicy(policy);
}

YCQUiItem::~YCQUiItem()
{
	if (NULL != m_pImage)
	{
		delete m_pImage;
		m_pImage = NULL;
	}
}

void YCQUiItem::paintEvent(QPaintEvent* pEvent)
{
	QPainter oPainter(this);

	if (NULL != m_pImage)
	{
		oPainter.setOpacity(m_fAlpha);
		oPainter.drawImage(rect(), *m_pImage);
	}

	if (m_bGrabed || m_bSelected)
	{
		oPainter.setOpacity(0.05f);
		oPainter.setBrush(QBrush(Qt::green));
		oPainter.drawRect(0, 0, size().width() - 1, size().height() - 1);
		oPainter.setBrush(Qt::NoBrush);
	}

	if (m_bGrabed)
	{
		oPainter.setOpacity(1.0f);
		oPainter.setPen(QPen(Qt::red));
		oPainter.drawRect(0, 0, size().width() - 1, size().height() - 1);
	}
	else if (m_bSelected)
	{
		oPainter.setOpacity(1.0f);
		oPainter.setPen(QPen(Qt::yellow));
		oPainter.drawRect(0, 0, size().width() - 1, size().height() - 1);
	}
}

void YCQUiItem::mousePressEvent(QMouseEvent* pEvent)
{
	onPressed(this);
	if (m_bGrabable)
	{
		m_bPressed = true;
		m_oPosMousePressStart = pEvent->screenPos();

		setGrabed(true);
	}
	setSelected(true);
}

void YCQUiItem::mouseReleaseEvent(QMouseEvent* pEvent)
{
	m_bPressed = false;

	setGrabed(false);
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

void YCQUiItem::setGrabable(const bool& rbGrabable)
{
	m_bGrabable = rbGrabable;
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
	if (YNULL == rpFormat)
	{
		return;
	}
	setImage(rpFormat->GetBound(), rpFormat->GetColorData());
	if (YNULL == rpFormat->GetColorData())
	{
		setAlpah(0.2f);
	}
	else
	{
		setAlpah(1.0f);
	}

	repaint();
}

void YCQUiItem::setWidget(const yam::base::YIWidget*& rpWidget)
{
	if (NULL == rpWidget)
	{
		return;
	}
	setImage(rpWidget->GetBound(), YNULL);
	setColor(qRgba(qrand(), qrand(), qrand(), qrand()));
	setAlpah(0.2f);

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

void YCQUiItem::setAlpah(const qreal& rfAlpha)
{
	m_fAlpha = rfAlpha;
}

void YCQUiItem::setImage(const yam::YRect2D& rstRect, const yam::ycolorptr& rpColorData)
{
	move(rstRect.Pos.X, rstRect.Pos.Y);
	resize(rstRect.Size.X, rstRect.Size.Y);

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

void YCQUiItem::setLayerWeight(const int& riLayerWeight)
{
	m_iLayerWeight = riLayerWeight;
}

int YCQUiItem::getLayerWeight() const
{
	return m_iLayerWeight;
}

QRgb YCQUiItem::convertFromYColor(const yam::ycolor& riColor) const
{
	using namespace yam;
	return qRgba(YGETCOLORBIT(riColor, YBITOFFSET_RED)
				, YGETCOLORBIT(riColor, YBITOFFSET_GREEN)
				, YGETCOLORBIT(riColor, YBITOFFSET_BLUE)
				, YGETCOLORBIT(riColor, YBITOFFSET_ALPHA));
}
