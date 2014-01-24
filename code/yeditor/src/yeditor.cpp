#include "yeditor.h"

#include "yexport.h"
#include "yrectpacker.h"

#include <crtdbg.h>

#include <QtWidgets/QApplication>
#include <QtWidgets/QFileDialog>
#include <QtWidgets/QBoxLayout>

#include <QtGui/QPixmap>
#include <QtGui/QPainter>

#ifdef _WINDOWS
#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")
#endif // _WINDOWS_

const QString YEditor::ms_sTitle = "Yam Editor";

YEditor::YEditor(QWidget* pParent /* = NULL */)
	: QMainWindow(pParent)
{
	setWindowTitle(ms_sTitle);

	m_UI.setupUi(this);

	m_UI.resTree->setContextMenuPolicy(Qt::CustomContextMenu);

	connect(m_UI.resDock, SIGNAL(visibilityChanged(bool)), this, SLOT(onResDockVisibilityChanged(bool)));
	connect(m_UI.uiDock, SIGNAL(visibilityChanged(bool)), this, SLOT(onUiDockVisibilityChanged(bool)));
}

YEditor::~YEditor()
{
	//
}

void YEditor::onClickedOpen()
{
	qDebug("on clicked open");

	m_sFileName = "";
	{
		QString qsFileName = QFileDialog::getOpenFileName(this, tr("Open a yui file"), "", tr("YUI (*.yui)"));
		m_sFileName.append(qsFileName.toLocal8Bit());
	}
	reloadFile(m_sFileName);
}

void YEditor::onClickedSave()
{
	qDebug("on clicked save");
	//
}

void YEditor::onClickedExport()
{
	/*yam::yvvec2d vSize;
	yam::YVec2D stSize;
	stSize.X = qrand() % 80 + 1; stSize.Y = qrand() % 80 + 1;
	vSize.push_back(stSize);
	stSize.X = qrand() % 80 + 1; stSize.Y = qrand() % 80 + 1;
	vSize.push_back(stSize);
	stSize.X = qrand() % 80 + 1; stSize.Y = qrand() % 80 + 1;
	vSize.push_back(stSize);
	stSize.X = qrand() % 80 + 1; stSize.Y = qrand() % 80 + 1;
	vSize.push_back(stSize);
	stSize.X = qrand() % 80 + 1; stSize.Y = qrand() % 80 + 1;
	vSize.push_back(stSize);
	stSize.X = qrand() % 80 + 1; stSize.Y = qrand() % 80 + 1;
	vSize.push_back(stSize);
	stSize.X = qrand() % 80 + 1; stSize.Y = qrand() % 80 + 1;
	vSize.push_back(stSize);
	stSize.X = qrand() % 80 + 1; stSize.Y = qrand() % 80 + 1;
	vSize.push_back(stSize);
	stSize.X = qrand() % 80 + 1; stSize.Y = qrand() % 80 + 1;
	vSize.push_back(stSize);
	stSize.X = qrand() % 80 + 1; stSize.Y = qrand() % 80 + 1;
	vSize.push_back(stSize);
	stSize.X = 500; stSize.Y = 500;
	yam::yvrect vRect;
	YCRectPacker::Instance().Do(vSize, stSize, vRect);
	QVector<QRect> vQRects;
	yam::yvrect::const_iterator cit = vRect.begin();
	yam::yvrect::const_iterator citEnd = vRect.end();
	for (; cit != citEnd; ++cit)
	{
		const yam::YRect2D& rstRect2D = *cit;
		vQRects.push_back(QRect(rstRect2D.Pos.X, rstRect2D.Pos.Y, rstRect2D.Size.X, rstRect2D.Size.Y));
	}

	QImage oImage(stSize.X, stSize.Y, QImage::Format_ARGB32);
	oImage.fill(Qt::transparent);
	QPainter oPainter(&oImage);
	for (int i = 0; i < vQRects.size(); ++i)
	{
		QRgb rgb = qRgba((qrand() % 0xFF), (qrand() % 0xFF), (qrand() % 0xFF), ((qrand() % 0xFF) + 0x55) % 0xFF);
		QImage oImageBox(vQRects[i].width(), vQRects[i].height(), QImage::Format_ARGB32);
		oImageBox.fill(rgb);
		oPainter.drawImage(vQRects[i].x(), vQRects[i].y(), oImageBox);
	}
	oImage.save("D:\\workspace\\github\\temp\\temp.png", "PNG");*/
}

void YEditor::onClickedSync()
{
	reloadFile(m_sFileName);
}

void YEditor::onClickedMenuWindowDockRes()
{
	if (m_UI.resDock->isVisible())
	{
		m_UI.resDock->close();
	}
	else
	{
		m_UI.resDock->show();
	}
}

void YEditor::onClickedMenuWindowDockUi()
{
	if (m_UI.uiDock->isVisible())
	{
		m_UI.uiDock->close();
	}
	else
	{
		m_UI.uiDock->show();
	}
}

void YEditor::onClickedMenuWindowAreaRes()
{
	if (m_UI.resAreaGroupBox->isVisible())
	{
		m_UI.resAreaGroupBox->close();
	}
	else
	{
		m_UI.resAreaGroupBox->show();
	}
}

void YEditor::onClickedMenuWindowAreaUi()
{
	if (m_UI.uiAreaGroupBox->isVisible())
	{
		m_UI.uiAreaGroupBox->close();
	}
	else
	{
		m_UI.uiAreaGroupBox->show();
	}
}

void YEditor::onSelectedResTree(QTreeWidgetItem* pTreeItem, int iIndex)
{
	m_UI.resArea->setSelected(getUiItem(pTreeItem));
}

void YEditor::onResTreeContextMenu(QPoint oPos)
{
	QModelIndex index = m_UI.resTree->currentIndex();
	if (!index.isValid())
	{
		return;
	}
	QMenu menu;
	menu.addAction(tr("Show/Hide"), this, SLOT(onClickedResMenuItem_ShowHide()));
	menu.addAction(tr("Tiled"), this, SLOT(onClickedResMenuItem_Tiled()));
	menu.exec(QCursor::pos());
}

void YEditor::onUiTreeContextMenu(QPoint oPos)
{
	QModelIndex index = m_UI.uiTree->currentIndex();
	if (0 < m_UI.uiTree->children().size() && !index.isValid())
	{
		return;
	}

	QMenu menu;

	QMenu* pMenuCreate = menu.addMenu(tr("Create"));
	if (!index.isValid())
	{
		pMenuCreate->addAction(tr("Scene"), this, SLOT(onClickedUiMenuItem_CreateScene()));
		//
	}
	else
	{
		pMenuCreate->addAction(tr("Panel"), this, SLOT(onClickedUiMenuItem_CreatePanel()));
		pMenuCreate->addAction(tr("Image"), this, SLOT(onClickedUiMenuItem_CreateImage()));
		pMenuCreate->addAction(tr("Button"), this, SLOT(onClickedUiMenuItem_CreateButton()));
		//
	}
	menu.exec(QCursor::pos());
}

void YEditor::onPressedResItem(YCQUiItem* pUiItem)
{
	QTreeWidgetItem* pTreeItem = getTreeItem(pUiItem);
	if (NULL == pTreeItem)
	{
		return;
	}
	m_UI.resTree->setCurrentItem(pTreeItem);
}

void YEditor::onResDockVisibilityChanged(bool bVisible)
{
	m_UI.actionDockRes->setChecked(bVisible);
}

void YEditor::onResAreaVisibilityChanged(bool bVisible)
{
	m_UI.actionAreaRes->setChecked(bVisible);
}

void YEditor::onClickedResMenuItem_ShowHide()
{
	QList<QTreeWidgetItem*> lItems = m_UI.resTree->selectedItems();
	if (0 >= lItems.size())
	{
		return;
	}
	QList<QTreeWidgetItem*>::iterator it = lItems.begin();
	QList<QTreeWidgetItem*>::iterator itEnd = lItems.end();
	for (; it != itEnd; ++it)
	{
		YCQUiItem* pUiItem = getUiItem(*it);
		if (NULL == pUiItem)
		{
			continue;
		}
		pUiItem->setVisible(!pUiItem->isVisible());
	}
}

void YEditor::onClickedResMenuItem_Tiled()
{
	m_UI.resArea->toTiled();
}

void YEditor::onUiDockVisibilityChanged(bool bVisible)
{
	m_UI.actionDockUi->setChecked(bVisible);
}

void YEditor::onUiAreaVisibilityChanged(bool bVisible)
{
	m_UI.actionAreaUi->setChecked(bVisible);
}

void YEditor::onClickedUiMenuItem_CreateScene()
{
	//
}

void YEditor::onClickedUiMenuItem_CreatePanel()
{
	//
}

void YEditor::onClickedUiMenuItem_CreateImage()
{
	//
}

void YEditor::onClickedUiMenuItem_CreateButton()
{
	//
}

void YEditor::reloadFile(const yam::ystring& rsFileName)
{
	m_sFileName = rsFileName;

	yam::base::YCBuffer buffer;
	{
		yam::storage::YCFileReader file;
		file.Open(m_sFileName);
		file >> buffer;
		file.Close();
	}

	m_UI.resArea->clearChildrenItem();
	m_UI.resTree->clear();
	m_UI.uiArea->clearChildrenItem();
	m_mRelationship.clear();
	m_FileTreeData.Clear();

	m_FileTreeData << buffer;

	{
		yam::base::YITree* pTreePsRes = m_FileTreeData.FindChild(YNAME_FILE_PSFORMAT);
		if (YNULL != pTreePsRes && YOBJECT_GETCLASSNAME(yam::base::YCFormat) == pTreePsRes->GetClassName())
		{
			const yam::base::YIFormat* pRes = (yam::base::YIFormat*)pTreePsRes;
			reloadRes(pRes, NULL, NULL);
		}
	}
	{
		yam::base::YITree* pTreeUi = m_FileTreeData.FindChild(YNAME_FILE_UIWIDGET);
		if (YNULL != pTreeUi && YOBJECT_GETCLASSNAME(yam::base::YCWidget) == pTreeUi->GetClassName())
		{
			const yam::base::YIWidget* pUi = (yam::base::YIWidget*)pTreeUi;
			reloadUi(pUi, NULL, NULL);
		}
	}
}

void YEditor::reloadRes(const yam::base::YIFormat*& rpFormat, YCQUiItem* pUiParent, QTreeWidgetItem* pTreeParent)
{
	if (YNULL == rpFormat)
	{
		return;
	}

	YCQUiItem* pUiItem = m_UI.resArea->addChildItem(rpFormat);
	connect(pUiItem, SIGNAL(onPressed(YCQUiItem*)), this, SLOT(onPressedResItem(YCQUiItem*)));

	QTreeWidgetItem* pTreeItem = new QTreeWidgetItem;
	pTreeItem->setText(0, rpFormat->GetId().c_str());
	if (NULL == pTreeParent)
	{
		m_UI.resTree->insertTopLevelItem(0, pTreeItem);
	}
	else
	{
		pTreeParent->insertChild(0, pTreeItem);
	}

	SRelationship stRelationship;
	stRelationship._pUiItem = pUiItem;
	stRelationship._pTreeItem = pTreeItem;
	m_mRelationship.insert(std::make_pair(getFullName(rpFormat), stRelationship));

	const yam::base::YITree* pTreeNext = rpFormat->GetNext();
	if (YNULL != pTreeNext && YOBJECT_GETCLASSNAME(yam::base::YCFormat) == pTreeNext->GetClassName())
	{
		const yam::base::YIFormat* pFormatNext = (const yam::base::YIFormat*)pTreeNext;
		reloadRes(pFormatNext, pUiParent, pTreeParent);
	}

	const yam::base::YITree* pTreeChildren = rpFormat->GetChildren();
	if (YNULL != pTreeChildren && YOBJECT_GETCLASSNAME(yam::base::YCFormat) == pTreeChildren->GetClassName())
	{
		const yam::base::YIFormat* pFormatChildren = (const yam::base::YIFormat*)pTreeChildren;
		reloadRes(pFormatChildren, pUiItem, pTreeItem);
	}
}

void YEditor::reloadUi(const yam::base::YIWidget*& rpWidget, YCQUiItem* pUiParent, QTreeWidgetItem* pTreeParent)
{
	//
}

QString YEditor::getFullName(const yam::base::YITree* pTree)
{
	QString sRes = "";
	if (YNULL != pTree)
	{
		sRes.append(".");
		sRes.append(pTree->GetId().c_str());
		sRes.append(getFullName(pTree->GetParent()));
	}
	return sRes;
}

YCQUiItem* YEditor::getUiItem(QTreeWidgetItem* pTreeItem) const
{
	if (NULL == pTreeItem)
	{
		return NULL;
	}

	ymnamerelationship::const_iterator cit = m_mRelationship.begin();
	ymnamerelationship::const_iterator citEnd = m_mRelationship.end();
	for (; cit != citEnd; ++cit)
	{
		if (pTreeItem != cit->second._pTreeItem)
		{
			continue;
		}
		return cit->second._pUiItem;
	}
	return NULL;
}

QTreeWidgetItem* YEditor::getTreeItem(YCQUiItem* pUiItem) const
{
	if (NULL == pUiItem)
	{
		return NULL;
	}

	ymnamerelationship::const_iterator cit = m_mRelationship.begin();
	ymnamerelationship::const_iterator citEnd = m_mRelationship.end();
	for (; cit != citEnd; ++cit)
	{
		if (pUiItem != cit->second._pUiItem)
		{
			continue;
		}
		return cit->second._pTreeItem;
	}
	return NULL;
}

int main(int argc, char* argv[])
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	QApplication a(argc, argv);
	YEditor editor;
	editor.setWindowTitle(YEditor::ms_sTitle);
	editor.show();
	return a.exec();
}