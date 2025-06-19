#ifndef QRCODEPROVIDER_H
#define QRCODEPROVIDER_H

#include <QQuickImageProvider>
#include <QImage>
#include <QPainter>
#include <QUrl>

class QRCodeProvider : public QQuickImageProvider
{
public:
    QRCodeProvider() : QQuickImageProvider(QQuickImageProvider::Image) {}

    QImage requestImage(const QString &id, QSize *size, const QSize &requestedSize) override
    {
        Q_UNUSED(requestedSize)
        // Здесь будет генерация QR-кода
        // Пока возвращаем заглушку
        QImage image(300, 300, QImage::Format_ARGB32);
        image.fill(Qt::white);
        
        QPainter painter(&image);
        painter.setPen(Qt::black);
        painter.drawText(image.rect(), Qt::AlignCenter, id);
        
        if (size)
            *size = image.size();
            
        return image;
    }
};

#endif // QRCODEPROVIDER_H 
