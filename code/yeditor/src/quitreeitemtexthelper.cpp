#include "quitreeitemtexthelper.h"

#include <QtWidgets/QTreeWidgetItem>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QComboBox>

#include "quiitem.h"
#include "yexportyam.h"

YCQUiTreeItemTextHelper::YCQUiTreeItemTextHelper(QTreeWidget* pTreeRoot, QTreeWidgetItem* pTreeItem, const QString sName /*= "text"*/)
    : m_pleFace(NULL)
    , m_psbSize(NULL)
    , m_pcbAlignType(NULL)
    , m_pleValue(NULL)
{
    if (NULL == pTreeRoot || NULL == pTreeItem)
    {
        return;
    }

    QTreeWidgetItem* pTreeItemMain = new QTreeWidgetItem;
    pTreeItemMain->setText(0, sName);
    pTreeItem->addChild(pTreeItemMain);

    {
        m_pleFace = new QLineEdit;
        connect(m_pleFace, SIGNAL(textChanged(const QString&)), this, SLOT(onChangedFace(const QString&)));
        QTreeWidgetItem* ptwiFace = new QTreeWidgetItem;
        ptwiFace->setText(0, tr("face"));
        pTreeItemMain->addChild(ptwiFace);
        pTreeRoot->setItemWidget(ptwiFace, 1, m_pleFace);
    }

    {
        m_psbSize = new QSpinBox;
        m_psbSize->setRange(1, INT_MAX);
        m_psbSize->setValue(1);
        connect(m_psbSize, SIGNAL(valueChanged(int)), this, SLOT(onChangedSize(int)));
        QTreeWidgetItem* ptwiSize = new QTreeWidgetItem;
        ptwiSize->setText(0, tr("size"));
        pTreeItemMain->addChild(ptwiSize);
        pTreeRoot->setItemWidget(ptwiSize, 1, m_psbSize);
    }

    {
        m_pcbAlignType = new QComboBox;
        for (int i = 0; i < yam::eAlignType_Max; ++i)
        {
            m_pcbAlignType->addItem(yam::io::YCExportYam::GetNameByAlignType((yam::EAlignType)i).c_str());
        }
        m_pcbAlignType->setCurrentText(yam::io::YCExportYam::GetNameByAlignType((yam::EAlignType)0).c_str());
        connect(m_pcbAlignType, SIGNAL(currentIndexChanged(const QString&)), this, SLOT(onChangedAlignType(const QString&)));
        QTreeWidgetItem* ptwiAlignType = new QTreeWidgetItem;
        ptwiAlignType->setText(0, tr("align"));
        pTreeItemMain->addChild(ptwiAlignType);
        pTreeRoot->setItemWidget(ptwiAlignType, 1, m_pcbAlignType);
    }

    {
        m_pleValue = new QLineEdit;
        connect(m_pleValue, SIGNAL(textChanged(const QString&)), this, SLOT(onChangedValue(const QString&)));
        QTreeWidgetItem* ptwiValue = new QTreeWidgetItem;
        ptwiValue->setText(0, tr("value"));
        pTreeItemMain->addChild(ptwiValue);
        pTreeRoot->setItemWidget(ptwiValue, 1, m_pleValue);
    }
}

YCQUiTreeItemTextHelper::~YCQUiTreeItemTextHelper()
{
    //
}

void YCQUiTreeItemTextHelper::onChangedFace(const QString& rsFace)
{
    m_sFace = rsFace;
    onChanged(m_sFace, m_iSize, m_sAlignType, m_sValue);
}

void YCQUiTreeItemTextHelper::onChangedSize(int iSize)
{
    m_iSize = iSize;
    onChanged(m_sFace, m_iSize, m_sAlignType, m_sValue);
}

void YCQUiTreeItemTextHelper::onChangedAlignType(const QString& rsAlignType)
{
    m_sAlignType = rsAlignType;
    onChanged(m_sFace, m_iSize, m_sAlignType, m_sValue);
}

void YCQUiTreeItemTextHelper::onChangedValue(const QString& rsValue)
{
    m_sValue = rsValue;
    onChanged(m_sFace, m_iSize, m_sAlignType, m_sValue);
}

void YCQUiTreeItemTextHelper::setUiItem(YCQUiItem*& rpUiItem)
{
    if (NULL != m_pleFace)
    {
        m_pleFace->setText(rpUiItem->getTextFace().c_str());
    }
    if (NULL != m_psbSize)
    {
        m_psbSize->setValue(rpUiItem->getTextSize());
    }
    if (NULL != m_pcbAlignType)
    {
        m_pcbAlignType->setCurrentText(rpUiItem->getTextAlign().c_str());
    }
    if (NULL != m_pleValue)
    {
        m_pleValue->setText(rpUiItem->getTextValue().c_str());
    }
}
