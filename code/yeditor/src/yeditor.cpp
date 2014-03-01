#include "yeditor.h"

#include "yexport.h"
#include "yrectpacker.h"
#include "quitreeitem.h"
#include "qdlgcreatewidget.h"
#include "qdlgexport.h"

#if defined(MSVC)
#include <crtdbg.h>
#endif

#include <QtWidgets/QApplication>
#include <QtWidgets/QFileDialog>
#include <QtWidgets/QBoxLayout>
#include <QtWidgets/QSpinBox>
#include <QtGui/QClipboard>

#include <QtGui/QPixmap>
#include <QtGui/QPainter>

#include <QtCore/QTime>

#if defined(MSVC)
#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")
#elif defined(GNUC)
//#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")
#endif

#define YEDITOR_VERSION_MAIN                0
#define YEDITOR_VERSION_SUB                 1
#ifdef _DEBUG
#define YEDITOR_VERSION_STRING              YTOSTRING(YEDITOR_VERSION_MAIN)"."YTOSTRING(YEDITOR_VERSION_SUB)" Build:["__DATE__" - "__TIME__"]"
#else // _DEBUG
#define YEDITOR_VERSION_STRING              YTOSTRING(YEDITOR_VERSION_MAIN)"."YTOSTRING(YEDITOR_VERSION_SUB)
#endif // _DEBUG
#define YEDITOR_TITLE                       YEDITOR_NAME" "YEDITOR_VERSION_STRING


yam::base::YCTree                           gs_FileTreeData;

YEditor::YEditor(QWidget* pParent /* = NULL */)
    : QMainWindow(pParent)
    , m_pTreeResHelper(NULL)
    , m_pTreeUiHelper(NULL)
{
    qsrand(QTime::currentTime().msec());

    m_Ui.setupUi(this);

    setWindowTitle(YEDITOR_TITLE);

    connect(m_Ui.resDock, SIGNAL(visibilityChanged(bool)), this, SLOT(onResDockVisibilityChanged(bool)));
    connect(m_Ui.uiDock, SIGNAL(visibilityChanged(bool)), this, SLOT(onUiDockVisibilityChanged(bool)));

    {
        QTreeWidgetItem* pHeaderItem = m_Ui.resTree->headerItem();
        if (NULL != pHeaderItem)
        {
            pHeaderItem->setText(0, tr("Tree"));
        }
    }
    {
        QTreeWidgetItem* pHeaderItem = m_Ui.resPropertyTreeWidget->headerItem();
        if (NULL != pHeaderItem)
        {
            pHeaderItem->setText(0, tr("Key"));
            pHeaderItem->setText(1, tr("Value"));
        }
    }
    {
        QTreeWidgetItem* pHeaderItem = m_Ui.uiTree->headerItem();
        if (NULL != pHeaderItem)
        {
            pHeaderItem->setText(0, tr("Tree"));
        }
    }
    {
        QTreeWidgetItem* pHeaderItem = m_Ui.uiPropertyTreeWidget->headerItem();
        if (NULL != pHeaderItem)
        {
            pHeaderItem->setText(0, tr("Key"));
            pHeaderItem->setText(1, tr("Value"));
        }
    }

    m_Ui.uiArea->setGrabable(false);

    parseArgument(QApplication::arguments());
}

YEditor::~YEditor()
{
    if (NULL != m_pTreeResHelper)
    {
        delete m_pTreeResHelper;
        m_pTreeResHelper = NULL;
    }
    if (NULL != m_pTreeUiHelper)
    {
        delete m_pTreeUiHelper;
        m_pTreeUiHelper = NULL;
    }
    //
}

void YEditor::onClickedOpen()
{
    m_sFileName = "";
    {
        QString sSelectedFilter = "";
        QString qsFileName = QFileDialog::getOpenFileName(this
            , tr("Open a yui file"), ""
            , tr("YUI (*.yui)"), &sSelectedFilter
            , QFileDialog::DontUseCustomDirectoryIcons
            | QFileDialog::DontUseSheet
            | QFileDialog::ReadOnly);
        m_sFileName.append(qsFileName.toLocal8Bit());
    }
    if (0 >= m_sFileName.size())
    {
        return;
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
    SConfigExport stConfig;
    if (!YCQDlgExport::showDialog(stConfig, this))
    {
        return;
    }

    json::Object jObj;
    {
        json::Object jObjLogic;
        {
            jObjLogic["name"] = stConfig._sLogicName.toLocal8Bit().data();
        }
        jObj["logic"] = jObjLogic;
    }
    {
        json::Array jObjAssetGroup;
        {
            json::Object jObjAsset;
            QFileInfo fileInfo(stConfig._sPngFileName);
            jObjAsset["name"] = fileInfo.baseName().toLocal8Bit().data();
            jObjAsset["type"] = "image";
            jObjAsset["file"] = fileInfo.fileName().toLocal8Bit().data();
            jObjAssetGroup.push_back(jObjAsset);
        }
        jObj["assetgroup"] = jObjAssetGroup;
    }
    {
        json::Object jObjRoot;
        {
            json::Object jObjLayoutStrategy;
            jObjLayoutStrategy["type"] = "layoutgridstrategy";
            {
                json::Object jObjLayoutStrategyValue;
                {
                    json::Array jArrRow;
                    jArrRow.push_back(100);
                    jArrRow.push_back(0);
                    jArrRow.push_back(0);
                    jObjLayoutStrategyValue["row"] = jArrRow;
                    json::Array jArrLine;
                    jArrLine.push_back(100);
                    jArrLine.push_back(0);
                    jArrLine.push_back(0);
                    jObjLayoutStrategyValue["line"] = jArrLine;
                }
                jObjLayoutStrategy["value"] = jObjLayoutStrategyValue;
            }
            jObjRoot["layoutstrategy"] = jObjLayoutStrategy;
        }
        jObjRoot["layer"] = 0;
        {
            json::Object jObjRootDst;
            {
                json::Object jObjRootDstPos;
                jObjRootDstPos["x"] = 0;
                jObjRootDstPos["y"] = 0;
                jObjRootDst["pos"] = jObjRootDstPos;
            }
            {
                json::Object jObjRootDstSizef;
                jObjRootDstSizef["x"] = 1.0f;
                jObjRootDstSizef["y"] = 1.0f;
                jObjRootDst["sizef"] = jObjRootDstSizef;
            }
            jObjRoot["dst"] = jObjRootDst;
        }
        {
            json::Array jObjWidgetGroup;
            {
                QTreeWidgetItem* pTreeItem = m_Ui.uiTree->topLevelItem(0);
                if (NULL != pTreeItem)
                {
                    json::Object jObjWidget;
                    exportUiTreeToJson(pTreeItem, jObjWidget);
                    jObjWidgetGroup.push_back(jObjWidget);
                }
            }
            jObjRoot["widgetgroup"] = jObjWidgetGroup;
        }
        jObj["root"] = jObjRoot;
    }

    std::string sRes = json::Serialize(jObj);
    sRes = "";

    /*QFile file(stConfig._sJsonFileName);
    file.open(QIODevice::WriteOnly);
    file.write(sRes.c_str());
    file.close();*/

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
    if (m_Ui.resDock->isVisible())
    {
        m_Ui.resDock->close();
    }
    else
    {
        m_Ui.resDock->show();
    }
}

void YEditor::onClickedMenuWindowDockUi()
{
    if (m_Ui.uiDock->isVisible())
    {
        m_Ui.uiDock->close();
    }
    else
    {
        m_Ui.uiDock->show();
    }
}

void YEditor::onClickedMenuWindowAreaRes()
{
    if (m_Ui.resAreaGroupBox->isVisible())
    {
        m_Ui.resAreaGroupBox->close();
    }
    else
    {
        m_Ui.resAreaGroupBox->show();
    }
}

void YEditor::onClickedMenuWindowAreaUi()
{
    if (m_Ui.uiAreaGroupBox->isVisible())
    {
        m_Ui.uiAreaGroupBox->close();
    }
    else
    {
        m_Ui.uiAreaGroupBox->show();
    }
}

void YEditor::onResTreeItemSelected(QTreeWidgetItem* pTreeItem, int iColumn)
{
    YCQUiItem* pUiItem = getUiItem(pTreeItem);
    m_Ui.resArea->setSelected(pUiItem);
    refreshResProperty(pUiItem);
}

void YEditor::onResTreeContextMenu(QPoint oPos)
{
    QModelIndex index = m_Ui.resTree->currentIndex();
    if (!index.isValid())
    {
        return;
    }
    QMenu menu;
    menu.addAction(tr("Copy Image Source"), this, SLOT(onClickedResMenuItem_CopyImageSource()));
    menu.addAction(tr("Tiled"), this, SLOT(onClickedResMenuItem_Tiled()));
    menu.exec(QCursor::pos());
}

void YEditor::onUiTreeItemSelected(QTreeWidgetItem* pTreeItem, int iColumn)
{
    YCQUiItem* pUiItem = getUiItem(pTreeItem);
    m_Ui.uiArea->setSelected(pUiItem);
    refreshUiProperty(pUiItem);
}

void YEditor::onUiTreeContextMenu(QPoint oPos)
{
    QTreeWidgetItem* pCurrentItem = m_Ui.uiTree->currentItem();

    QMenu menu;
    QMenu* pMenuCreate = menu.addMenu(tr("Create"));
    {
        QAction* pActionCreate = pMenuCreate->addAction(tr("Scene"), this, SLOT(onClickedUiMenuItem_CreateScene()));
        pActionCreate->setEnabled(0 == m_Ui.uiTree->topLevelItemCount());
    }

    {
        QAction* pActionCreate = pMenuCreate->addAction(tr("Panel"), this, SLOT(onClickedUiMenuItem_CreatePanel()));
        pActionCreate->setEnabled(NULL != pCurrentItem);
    }
    {
        QAction* pActionCreate = pMenuCreate->addAction(tr("Image"), this, SLOT(onClickedUiMenuItem_CreateImage()));
        pActionCreate->setEnabled(NULL != pCurrentItem);
    }
    {
        QAction* pActionCreate = pMenuCreate->addAction(tr("Button"), this, SLOT(onClickedUiMenuItem_CreateButton()));
        pActionCreate->setEnabled(NULL != pCurrentItem);
    }
    menu.exec(QCursor::pos());
}

void YEditor::onPressedResItem(YCQUiItem* pUiItem)
{
    YCQUiTreeItem* pTreeItem = getTreeItem(pUiItem);
    if (NULL == pTreeItem)
    {
        return;
    }
    m_Ui.resTree->setCurrentItem(pTreeItem);
}

void YEditor::onPressedUiItem(YCQUiItem* pUiItem)
{
    YCQUiTreeItem* pTreeItem = getTreeItem(pUiItem);
    if (NULL == pTreeItem)
    {
        return;
    }
    m_Ui.uiTree->setCurrentItem(pTreeItem);
}

void YEditor::onResDockVisibilityChanged(bool bVisible)
{
    m_Ui.actionDockRes->setChecked(bVisible);
    m_Ui.actionBarDockRes->setChecked(bVisible);
}

void YEditor::onResAreaVisibilityChanged(bool bVisible)
{
    m_Ui.actionAreaRes->setChecked(bVisible);
    m_Ui.actionBarAreaRes->setChecked(bVisible);
}

void YEditor::onClickedResMenuItem_CopyImageSource()
{
    YCQUiItem* pTreeItem = getUiItem(m_Ui.resTree->currentItem());
    if (NULL == pTreeItem)
    {
        return;
    }
    QApplication::clipboard()->setText(pTreeItem->getImageSource());
    QString msg("copy image source from res tree item - "); msg.append(pTreeItem->getImageSource());
    m_Ui.statusbar->showMessage(msg, 5000);
}

void YEditor::onClickedResMenuItem_Tiled()
{
    m_Ui.resArea->toTiled();
}

void YEditor::onUiDockVisibilityChanged(bool bVisible)
{
    m_Ui.actionDockUi->setChecked(bVisible);
    m_Ui.actionBarDockUi->setChecked(bVisible);
}

void YEditor::onUiAreaVisibilityChanged(bool bVisible)
{
    m_Ui.actionAreaUi->setChecked(bVisible);
    m_Ui.actionBarAreaUi->setChecked(bVisible);
}

void YEditor::onClickedUiMenuItem_CreateScene()
{
    SConfigCreateWidget stConfig;
    if (!YCQDlgCreateWidget::showDialog(stConfig, this))
    {
        return;
    }
    if (m_mRelationship.find(stConfig._sId.toLocal8Bit().data()) != m_mRelationship.end())
    {
        return;
    }

    yam::base::YIWidget* pWidget = new yam::base::YCWidget;
    pWidget->GetId() = stConfig._sId.toLocal8Bit().data();
    pWidget->GetType() = yam::eWidgetType_Scene;
    pWidget->GetBound().Size.X = 300;
    pWidget->GetBound().Size.Y = 300;

    YCQUiItem* pUiItem = m_Ui.uiArea->addChildItem(pWidget);
    connect(pUiItem, SIGNAL(onPressed(YCQUiItem*)), this, SLOT(onPressedUiItem(YCQUiItem*)));

    YCQUiTreeItem* pTreeItem = new YCQUiTreeItem;
    pTreeItem->setText(0, pWidget->GetId().c_str());
    m_Ui.uiTree->insertTopLevelItem(0, pTreeItem);

    SRelationship stRelationship;
    stRelationship._pUiItem = pUiItem;
    stRelationship._pTreeItem = pTreeItem;
    //m_mRelationship.insert(std::make_pair(getFullName(pWidget), stRelationship));
    m_mRelationship.insert(std::make_pair(pWidget->GetId().c_str(), stRelationship));

    delete pWidget;
    pWidget = YNULL;
}

void YEditor::onClickedUiMenuItem_CreatePanel()
{
    QTreeWidgetItem* pItem = m_Ui.uiTree->currentItem();
    if (NULL == pItem)
    {
        return;
    }

    SConfigCreateWidget stConfig;
    if (!YCQDlgCreateWidget::showDialog(stConfig, this))
    {
        return;
    }
    if (m_mRelationship.find(stConfig._sId.toLocal8Bit().data()) != m_mRelationship.end())
    {
        return;
    }

    yam::base::YIWidget* pWidget = new yam::base::YCWidget;
    pWidget->GetId() = stConfig._sId.toLocal8Bit().data();
    pWidget->GetType() = yam::eWidgetType_Panel;
    pWidget->GetBound().Size.X = 300;
    pWidget->GetBound().Size.Y = 300;

    YCQUiItem* pUiItem = m_Ui.uiArea->addChildItem(pWidget);
    connect(pUiItem, SIGNAL(onPressed(YCQUiItem*)), this, SLOT(onPressedUiItem(YCQUiItem*)));

    YCQUiTreeItem* pTreeItem = new YCQUiTreeItem;
    pTreeItem->setText(0, pWidget->GetId().c_str());
    pItem->addChild(pTreeItem);

    SRelationship stRelationship;
    stRelationship._pUiItem = pUiItem;
    stRelationship._pTreeItem = pTreeItem;
    m_mRelationship.insert(std::make_pair(getFullName(pWidget), stRelationship));

    YEDITOR_DELETE(pWidget);
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

    // clear
    m_Ui.resArea->clearChildrenItem();
    m_Ui.resTree->clear();
    m_Ui.resPropertyTreeWidget->clear();
    m_Ui.uiArea->clearChildrenItem();
    m_Ui.uiTree->clear();
    m_Ui.uiPropertyTreeWidget->clear();
    m_mRelationship.clear();
    gs_FileTreeData.Clear();

    // parse
    gs_FileTreeData << buffer;

    {
        yam::base::YITree* pTreePsRes = gs_FileTreeData.FindChild(YFILE_KEY_RESOURCE);
        if (YNULL != pTreePsRes && YOBJECT_GETCLASSNAME(yam::base::YCFormat) == pTreePsRes->GetClassName())
        {
            const yam::base::YIFormat* pRes = (yam::base::YIFormat*)pTreePsRes;
            reloadRes(pRes, NULL, NULL);
        }
    }
    m_Ui.resTree->expandAll();

    {
        yam::base::YITree* pTreeUi = gs_FileTreeData.FindChild(YFILE_KEY_UI);
        if (YNULL != pTreeUi && YOBJECT_GETCLASSNAME(yam::base::YCWidget) == pTreeUi->GetClassName())
        {
            const yam::base::YIWidget* pUi = (yam::base::YIWidget*)pTreeUi;
            reloadUi(pUi, NULL, NULL);
        }
    }
    m_Ui.uiTree->expandAll();
}

void YEditor::reloadRes(const yam::base::YIFormat*& rpFormat, YCQUiItem* pUiParent, QTreeWidgetItem* pTreeParent)
{
    if (YNULL == rpFormat)
    {
        return;
    }

    YCQUiItem* pUiItem = m_Ui.resArea->addChildItem(rpFormat);
    if (NULL != pUiItem)
    {
        pUiItem->setImageSource(getFullName(rpFormat));
        connect(pUiItem, SIGNAL(onPressed(YCQUiItem*)), this, SLOT(onPressedResItem(YCQUiItem*)));
    }

    YCQUiTreeItem* pTreeItem = new YCQUiTreeItem;
    pTreeItem->setText(0, rpFormat->GetId().c_str());
    pTreeItem->setDataProperty("imagesource", getFullName(rpFormat));
    if (NULL == pTreeParent)
    {
        m_Ui.resTree->insertTopLevelItem(0, pTreeItem);
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
    if (NULL == rpWidget)
    {
        return;
    }
    YCQUiItem* pUiItem = m_Ui.uiArea->addChildItem(rpWidget);
    if (NULL != pUiItem)
    {
        connect(pUiItem, SIGNAL(onPressed(YCQUiItem*)), this, SLOT(onPressedUiItem(YCQUiItem*)));
    }

    YCQUiTreeItem* pTreeItem = new YCQUiTreeItem;
    pTreeItem->setText(0, rpWidget->GetId().c_str());
    if (NULL == pTreeParent)
    {
        m_Ui.uiTree->insertTopLevelItem(0, pTreeItem);
    }
    else
    {
        pTreeParent->insertChild(0, pTreeItem);
    }

    SRelationship stRelationship;
    stRelationship._pUiItem = pUiItem;
    stRelationship._pTreeItem = pTreeItem;
    m_mRelationship.insert(std::make_pair(getFullName(rpWidget), stRelationship));

    const yam::base::YITree* pTreeNext = rpWidget->GetNext();
    if (YNULL != pTreeNext && YOBJECT_GETCLASSNAME(yam::base::YCWidget) == pTreeNext->GetClassName())
    {
        const yam::base::YIWidget* pFormatNext = (const yam::base::YIWidget*)pTreeNext;
        reloadUi(pFormatNext, pUiParent, pTreeParent);
    }

    const yam::base::YITree* pTreeChildren = rpWidget->GetChildren();
    if (YNULL != pTreeChildren && YOBJECT_GETCLASSNAME(yam::base::YCWidget) == pTreeChildren->GetClassName())
    {
        const yam::base::YIWidget* pFormatChildren = (const yam::base::YIWidget*)pTreeChildren;
        reloadUi(pFormatChildren, pUiItem, pTreeItem);
    }
}

QString YEditor::getFullName(const yam::base::YITree* pTree)
{
    QString sRes = "";
    if (YNULL == pTree)
    {
        return sRes;
    }
    const yam::base::YITree* pParent = pTree;
    while (YNULL != pParent)
    {
        if (0 < sRes.size())
        {
            sRes.insert(0, ".");
        }
        sRes.insert(0, pParent->GetId().c_str());
        pParent = pParent->GetParent();

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

YCQUiTreeItem* YEditor::getTreeItem(YCQUiItem* pUiItem) const
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

void YEditor::refreshResProperty(YCQUiItem*& rpResItem)
{
    m_Ui.resPropertyTreeWidget->clear();
    if (YNULL != rpResItem)
    {
        if (NULL != m_pTreeResHelper)
        {
            delete m_pTreeResHelper;
            m_pTreeResHelper = NULL;
        }
        m_pTreeResHelper = new YCQUiTreeResHelper(m_Ui.resPropertyTreeWidget);
        m_pTreeResHelper->setUiItem(rpResItem);

        m_Ui.resPropertyTreeWidget->expandAll();
    }
}

void YEditor::refreshUiProperty(YCQUiItem*& rpUiItem)
{
    m_Ui.uiPropertyTreeWidget->clear();
    if (NULL != rpUiItem)
    {
        if (NULL != m_pTreeUiHelper)
        {
            delete m_pTreeUiHelper;
            m_pTreeUiHelper = NULL;
        }
        m_pTreeUiHelper = new YCQUiTreeUiHelper(m_Ui.uiPropertyTreeWidget);
        m_pTreeUiHelper->setUiItem(rpUiItem);

        m_Ui.uiPropertyTreeWidget->expandAll();
    }
}

void YEditor::parseArgument(const QStringList& rvStr)
{
    if (rvStr.empty())
    {
        return;
    }
    if (2 == rvStr.size())
    {
        yam::ystring sFileName;
        sFileName.append(rvStr[1].toLocal8Bit());
        reloadFile(sFileName);
    }
}

void YEditor::exportUiTreeToJson(QTreeWidgetItem* pTreeItem, json::Object& rjObjSelf)
{
    if (NULL == pTreeItem)
    {
        return;
    }

    YCQUiItem* pUiItem = getUiItem(pTreeItem);
    if (NULL == pUiItem)
    {
        return;
    }

    rjObjSelf["type"] = YCQUiItem::convertFromWidgetType(pUiItem->getType());

    json::Object jObjValue;
    {
        pUiItem->exportToJson(jObjValue);

        jObjValue["id"] =  pTreeItem->text(0).toLocal8Bit().data();

        int iChildCount = pTreeItem->childCount();
        if (0 < iChildCount)
        {
            json::Array jArrWidgetGroup;
            for (int i = 0; i < iChildCount; ++i)
            {
                json::Object jObjWidget;
                exportUiTreeToJson(pTreeItem->child(i), jObjWidget);
                jArrWidgetGroup.push_back(jObjWidget);
            }
            jObjValue["widgetgroup"] = jArrWidgetGroup;
        }
    }

    rjObjSelf["value"] = jObjValue;
}

int main(int argc, char* argv[])
{
#if defined(MSVC)
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif

    QApplication a(argc, argv);
    YEditor editor;
    editor.show();
    return a.exec();
}
