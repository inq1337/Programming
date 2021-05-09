#include "mainwindow.hpp"

#include <QApplication>

bool getBit(const QImage &img, int index) {
    int pixelIndex = index / 3;
    int x = pixelIndex % img.width();
    int y = pixelIndex / img.width();

    switch (index % 3) {
    case 0:
        return (img.pixel(x, y) >> 16) & 1;
    case 1:
        return (img.pixel(x, y) >> 8) & 1;
    default:
        return img.pixel(x, y) & 1;
    }
}

void setBit(QImage &img, int index, bool val) {
    int pixelIndex = index / 3;
    int x = pixelIndex % img.width();
    int y = pixelIndex / img.width();

    switch (index % 3) {
    case 0:
        img.setPixel(x, y, (img.pixel(x, y) & ~0x010000) | (val << 16));
    case 1:
        img.setPixel(x, y, (img.pixel(x, y) & ~0x000100) | (val << 8));
    default:
        img.setPixel(x, y, (img.pixel(x, y) & ~0x000001) | val);
    }
}

QByteArray readBytes(const QImage& img, uint begin, uint length) {
    QByteArray byteArray;
    char buf = 0;
    uint end = (begin + length) * 8;

    for (uint i = begin * 8; i < end; ++i) {
        buf = (buf << 1) | getBit(img, i);
        if (i % 8 == 7) {
            byteArray.push_back(buf);
            buf = 0;
        }
    }

    return byteArray;
}

void writeBytes(QImage& img, uint begin, QByteArray& byteArray) {
    uint end = (begin + byteArray.size()) * 8;

    for (uint i = begin * 8; i < end; ++i) {
        setBit(img, i, (byteArray[i / 8] >> (7 - i % 8)) & 1);
    }
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
