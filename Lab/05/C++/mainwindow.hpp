#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QImage>
#include <QFileDialog>
#include <QMessageBox>
#include <QBitArray>
#include <QFile>
#include <QTextStream>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void loadImage();
    void saveImage();
    void encodeText();
    void decodeText();
    void messageChanged();

private:
    Ui::MainWindow *ui;
    QImage image;
    bool isLoaded;
    uint imageCapacity, usedBytes = 0;

    const QList<char> indicator {
        static_cast<char>(0b11100010),
        static_cast<char>(0b10011101),
        static_cast<char>(0b10100100)
    };
};

#endif // MAINWINDOW_HPP
