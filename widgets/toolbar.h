#ifndef TOOLBAR_H
#define TOOLBAR_H

#include <QLabel>
#include <QPainter>
#include <DBlurEffectWidget>

#include <QLabel>
#include <QDebug>

#include "majtoolbar.h"
#include "subtoolbar.h"

DWIDGET_USE_NAMESPACE
class ToolBar : public DBlurEffectWidget {
    Q_OBJECT
public:
    ToolBar(QWidget* parent = 0);
    ~ToolBar();

signals:
    void buttonChecked(QString shapeType);
    void updateColor(QColor color);
    void requestSaveScreenshot();
    void shapePressed(QString tool);
    void saveBtnPressed(int index = 0);
    void saveSpecifiedPath();

public slots:
    bool isButtonChecked();
    void setExpand(bool expand, QString shapeType);
    void showAt(QPoint pos);
    int    getSaveQualityIndex();
    void specificedSavePath();


protected:
    void paintEvent(QPaintEvent *e);

private:
    MajToolBar* m_majToolbar;
    QLabel* m_hSeperatorLine;
    SubToolBar* m_subToolbar;
    QLabel* m_bgLabel;

    bool  m_expanded;
};

#endif // TOOLBAR_H
