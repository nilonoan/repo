#include "myitem.h"
//#include <QSGSimpleRectNode>
#include <QSGSimpleTextureNode>
#include <QQuickWindow>
#include <QQmlEngine>
#include <QQmlContext>

MyItem::MyItem(QQuickItem *parent):
    QQuickItem(parent)
{
    // By default, QQuickItem does not draw anything. If you subclass
    // QQuickItem to create a visual item, you will need to uncomment the
    // following line and re-implement updatePaintNode()

     setFlag(ItemHasContents, true);
     qDebug() << "MyItem constructor.";

     QObject::connect(this, SIGNAL(imageLocationChanged()), this, SLOT(setImage()));


}

MyItem::~MyItem()
{
}

 QSGNode * MyItem::updatePaintNode( QSGNode * oldNode, UpdatePaintNodeData * )
 {
 /*     QSGSimpleRectNode *rectNode = static_cast<QSGSimpleRectNode*>(oldNode);

        if (!rectNode) {
         rectNode = new QSGSimpleRectNode;
         rectNode->setColor(QColor(Qt::blue));
        }
        rectNode->setRect(0, 0, width(), height());
        return rectNode;
*/
    QSGSimpleTextureNode *node = static_cast<QSGSimpleTextureNode *>(oldNode);
    if (!node) {
        node = new QSGSimpleTextureNode();
        QSGTexture *texture = window()->createTextureFromImage(m_pixmap.toImage());
        node->setTexture(texture);
    }
    node->setRect(0, 0, m_pixmap.rect().width(), m_pixmap.rect().height());
    return node;

 }

 void MyItem::setImageLocation(const QString &imgLoc)
 {
     m_imageLocation = imgLoc;
     emit imageLocationChanged();
 }

 void MyItem::setImage()
 {

     if(!m_pixmap.load(this->getImageLocation())){
         qWarning("Failed to load");
     }
 }
