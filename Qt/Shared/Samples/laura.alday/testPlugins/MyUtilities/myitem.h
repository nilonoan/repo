#ifndef MYITEM_H
#define MYITEM_H

#include <QQuickItem>
#include <QPixmap>

class MyItem : public QQuickItem
{
    Q_OBJECT
    Q_DISABLE_COPY(MyItem)
    Q_PROPERTY(QString imageLocation READ getImageLocation WRITE setImageLocation NOTIFY imageLocationChanged)

public:
    MyItem(QQuickItem *parent = 0);
    ~MyItem();
    QSGNode * updatePaintNode( QSGNode * oldNode, UpdatePaintNodeData * );
    QPixmap m_pixmap;

    QString getImageLocation() const { return m_imageLocation; }
    void setImageLocation(const QString &imgLoc);
public slots:
    void setImage();
signals:
    void imageLocationChanged();
private:
    QString m_imageLocation;
};

#endif // MYITEM_H
